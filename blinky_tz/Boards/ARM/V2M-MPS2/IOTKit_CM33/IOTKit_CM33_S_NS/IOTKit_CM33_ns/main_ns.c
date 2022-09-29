/*----------------------------------------------------------------------------
 * Name:    main_ns.c
 * Purpose: Main function non-secure mode
 *----------------------------------------------------------------------------*/

#include <arm_cmse.h>
#include <stdio.h>
#include "IOTKit_CM33_FP.h"                    /* Device header */
#include "Board_LED.h"                         /* ::Board Support:LED */
#include "..\IOTKit_CM33_s\Secure_Functions.h" /* Secure Code Entry Points */

char text[] = "Hello World (non-secure)\r\n";

#define ARM_CM_DEMCR (*(uint32_t *)0xE000EDFC)
#define ARM_CM_DWT_CTRL (*(uint32_t *)0xE0001000)
#define ARM_CM_DWT_CYCCNT (*(uint32_t *)0xE0001004)

// #define TEST_MACRO
#define TEST_MICRO

/*----------------------------------------------------------------------------
  NonSecure functions used for callbacks
 *----------------------------------------------------------------------------*/
int32_t NonSecure_LED_On(uint32_t num);
int32_t NonSecure_LED_On(uint32_t num)
{
    return LED_On(num);
}

int32_t NonSecure_LED_Off(uint32_t num);
int32_t NonSecure_LED_Off(uint32_t num)
{
    return LED_Off(num);
}

/*----------------------------------------------------------------------------
  SysTick IRQ Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void);
void SysTick_Handler(void)
{
    static uint32_t ticks;

    switch (ticks++)
    {
    case 10:
        LED_On(7u);
        break;
    case 20:
        Secure_LED_On(6u);
        break;
    case 30:
        LED_Off(7u);
        break;
    case 50:
        Secure_LED_Off(6u);
        break;
    case 99:
        ticks = 0;
        break;
    default:
        if (ticks > 99)
        {
            ticks = 0;
        }
    }
}

static uint32_t x;
/*----------------------------------------------------------------------------
  Main function
 *----------------------------------------------------------------------------*/
int main(void)
{
    uint32_t i;
    uint32_t j;
    uint32_t k;

    /* exercise some floating point instructions */
    volatile uint32_t fpuType = SCB_GetFPUType();
    volatile float x1 = 12.4567f;
    volatile float x2 = 0.6637967f;
    volatile float x3 = 24.1111118f;

    x3 = x3 * (x1 / x2);

    /* exercise some core register from Non Secure Mode */
    x = __get_MSP();
    x = __get_PSP();

    /* register NonSecure callbacks in Secure application */
    Secure_LED_On_callback(NonSecure_LED_On);
    Secure_LED_Off_callback(NonSecure_LED_Off);

#if 0
    LED_Initialize ();                      /* already done in Secure part */
#endif
    
    if (ARM_CM_DWT_CTRL != 0)
    {                            // See if DWT is available
        ARM_CM_DEMCR |= 1 << 24; // Set bit 24
        ARM_CM_DWT_CYCCNT = 0;
        ARM_CM_DWT_CTRL |= 1 << 0; // Set bit 0
    }
    uint32_t start;
    uint32_t stop;
    uint32_t delta;
    
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 100); /* Generate interrupt each 10 ms */

    #ifdef TEST_MICRO
    for (i = 0; i < 10; i++)
    {
        for (k = 0; k < 0x100000; k++)
            __NOP();
        
        start = ARM_CM_DWT_CYCCNT;
        Secure_printf(text);
        stop = ARM_CM_DWT_CYCCNT;

        delta = stop - start;
        Secure_printf_int(delta);
    }
    #endif

    #ifdef TEST_MACRO
    for (i = 0; i < 10; i++)
    {
        start = ARM_CM_DWT_CYCCNT;
        for (j = 0; j < 50; j++)
        {
            LED_On(5u);
            for (k = 0; k < 0x100000; k++)
                __NOP();
            LED_Off(5u);
            for (k = 0; k < 0x100000; k++)
                __NOP();
            Secure_LED_On(4u);
            for (k = 0; k < 0x100000; k++)
                __NOP();
            Secure_LED_Off(4u);
            for (k = 0; k < 0x100000; k++)
                __NOP();

            Secure_printf(text);
        }
        stop = ARM_CM_DWT_CYCCNT;
        delta = stop - start;
        Secure_printf_int(delta);
    }
    #endif

    while (1) {}
}
