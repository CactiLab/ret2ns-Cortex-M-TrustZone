/*----------------------------------------------------------------------------
 * Name:    main_s.c
 * Purpose: Main function secure mode
 *----------------------------------------------------------------------------*/

#include <arm_cmse.h>
#include <stdio.h>
#include "IOTKit_CM33_FP.h" /* Device header */
#include "Board_LED.h"      /* ::Board Support:LED */
#include "Board_GLCD.h"     /* ::Board Support:Graphic LCD */
#include "GLCD_Config.h"    /* Keil.SAM4E-EK::Board Support:Graphic LCD */

//#define RET2NS_PROTECTION

/* Start address of non-secure application */
#define NONSECURE_START (0x00200000u)

extern GLCD_FONT GLCD_Font_16x24;

extern int stdout_init(void);

/* typedef for NonSecure callback functions */
typedef int32_t (*NonSecure_fpParam)(uint32_t) __attribute__((cmse_nonsecure_call));
typedef void (*NonSecure_fpVoid)(void) __attribute__((cmse_nonsecure_call));

char text[] = "Hello World (secure)\r\n";

/*----------------------------------------------------------------------------
  NonSecure callback functions
 *----------------------------------------------------------------------------*/
extern NonSecure_fpParam pfNonSecure_LED_On;
NonSecure_fpParam pfNonSecure_LED_On = (NonSecure_fpParam)NULL;
extern NonSecure_fpParam pfNonSecure_LED_Off;
NonSecure_fpParam pfNonSecure_LED_Off = (NonSecure_fpParam)NULL;

/*----------------------------------------------------------------------------
  Secure functions exported to NonSecure application
 *----------------------------------------------------------------------------*/
int32_t Secure_LED_On(uint32_t num) __attribute__((cmse_nonsecure_entry));
int32_t Secure_LED_On(uint32_t num)
{
    int32_t val = LED_On(num);
    #ifdef RET2NS_PROTECTION
    __ASM volatile(
        ".syntax unified\n\t"
        ".thumb\n\t"
        "ldr r0, [sp, #4]\n\t"
        "mrs r3, ipsr\n\t"
        "cbnz r3, #10\n\t"
        "mrs r3, control_ns\n\t"
        "mov r2, #1\n\t"
        "ands r3, r2\n\t"
        "cbnz r3, #44\n\t"
        "tta r0, r0\n\t"
        "movw r3, #0\n\t"
        "movt r3, #1\n\t"
        "ands r3, r0\n\t"
        "cbz r3, #28\n\t"
        "movw r3, #60816\n\t"
        "movt r3, #57346\n\t"
        "mov r2, #255\n\t"
        "ands r2, r0\n\t"
        "str r2, [r3, #8]\n\t"
        "ldr r3, [r3, #12]\n\t"
        "mov r2, #2\n\t"
        "ands r3, r2\n\t"
        "cbz r3, #2\n\t"
        "b HardFault_Handler\n\t"
    );
    #endif
    return val;
}

int32_t Secure_LED_Off(uint32_t num) __attribute__((cmse_nonsecure_entry));
int32_t Secure_LED_Off(uint32_t num)
{
    int32_t val = LED_Off(num);
    #ifdef RET2NS_PROTECTION
    __ASM volatile(
        ".syntax unified\n\t"
        ".thumb\n\t"
        "ldr r0, [sp, #4]\n\t"
        "mrs r3, ipsr\n\t"
        "cbnz r3, #10\n\t"
        "mrs r3, control_ns\n\t"
        "mov r2, #1\n\t"
        "ands r3, r2\n\t"
        "cbnz r3, #44\n\t"
        "tta r0, r0\n\t"
        "movw r3, #0\n\t"
        "movt r3, #1\n\t"
        "ands r3, r0\n\t"
        "cbz r3, #28\n\t"
        "movw r3, #60816\n\t"
        "movt r3, #57346\n\t"
        "mov r2, #255\n\t"
        "ands r2, r0\n\t"
        "str r2, [r3, #8]\n\t"
        "ldr r3, [r3, #12]\n\t"
        "mov r2, #2\n\t"
        "ands r3, r2\n\t"
        "cbz r3, #2\n\t"
        "b HardFault_Handler\n\t"
    );
    #endif
    return val;
}

void Secure_printf(char *pString) __attribute__((cmse_nonsecure_entry));
void Secure_printf(char *pString)
{
    printf("%s", pString);
    #ifdef RET2NS_PROTECTION
    __ASM volatile(
        ".syntax unified\n\t"
        ".thumb\n\t"
        "ldr r0, [sp, #4]\n\t"
        "mrs r3, ipsr\n\t"
        "cbnz r3, #10\n\t"
        "mrs r3, control_ns\n\t"
        "mov r2, #1\n\t"
        "ands r3, r2\n\t"
        "cbnz r3, #44\n\t"
        "tta r0, r0\n\t"
        "movw r3, #0\n\t"
        "movt r3, #1\n\t"
        "ands r3, r0\n\t"
        "cbz r3, #28\n\t"
        "movw r3, #60816\n\t"
        "movt r3, #57346\n\t"
        "mov r2, #255\n\t"
        "ands r2, r0\n\t"
        "str r2, [r3, #8]\n\t"
        "ldr r3, [r3, #12]\n\t"
        "mov r2, #2\n\t"
        "ands r3, r2\n\t"
        "cbz r3, #2\n\t"
        "b HardFault_Handler\n\t"
    );
    #endif
}

void __attribute__((optnone)) empty_function(void)
{
    return;
}

void Secure_empty(void) __attribute__((cmse_nonsecure_entry));
void Secure_empty(void)
{
    empty_function();
    #ifdef RET2NS_PROTECTION
    __ASM volatile(
        ".syntax unified\n\t"
        ".thumb\n\t"
        "ldr r0, [sp, #4]\n\t"
        "mrs r3, ipsr\n\t"
        "cbnz r3, #10\n\t"
        "mrs r3, control_ns\n\t"
        "mov r2, #1\n\t"
        "ands r3, r2\n\t"
        "cbnz r3, #44\n\t"
        "tta r0, r0\n\t"
        "movw r3, #0\n\t"
        "movt r3, #1\n\t"
        "ands r3, r0\n\t"
        "cbz r3, #28\n\t"
        "movw r3, #60816\n\t"
        "movt r3, #57346\n\t"
        "mov r2, #255\n\t"
        "ands r2, r0\n\t"
        "str r2, [r3, #8]\n\t"
        "ldr r3, [r3, #12]\n\t"
        "mov r2, #2\n\t"
        "ands r3, r2\n\t"
        "cbz r3, #2\n\t"
        "b HardFault_Handler\n\t"
    );
    #endif
}



void Secure_printf_int(uint32_t value) __attribute__((cmse_nonsecure_entry));
void Secure_printf_int(uint32_t value)
{
    printf("(EVL)cycles: %d\n", value);
}

/*----------------------------------------------------------------------------
  Secure function for NonSecure callbacks exported to NonSecure application
 *----------------------------------------------------------------------------*/
int32_t Secure_LED_On_callback(NonSecure_fpParam callback) __attribute__((cmse_nonsecure_entry));
int32_t Secure_LED_On_callback(NonSecure_fpParam callback)
{
    pfNonSecure_LED_On = callback;
    return 0;
}

int32_t Secure_LED_Off_callback(NonSecure_fpParam callback) __attribute__((cmse_nonsecure_entry));
int32_t Secure_LED_Off_callback(NonSecure_fpParam callback)
{
    pfNonSecure_LED_Off = callback;
    return 0;
}

/*----------------------------------------------------------------------------
  SysTick IRQ Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void);
void SysTick_Handler(void)
{
    static uint32_t ticks = 0;
    static uint32_t ticks_printf = 0;

    switch (ticks++)
    {
    case 10:
        LED_On(0u);
        break;
    case 20:
        LED_Off(0u);
        break;
    case 30:
        if (pfNonSecure_LED_On != NULL)
        {
            #ifdef RET2NS_PROTECTION
            __ASM volatile(
                ".syntax unified\n\t"
                ".thumb\n\t"
                "mrs r3, ipsr\n\t"
                "cbnz r3, #10\n\t"
                "mrs r3, control_ns\n\t"
                "mov r2, #1\n\t"
                "ands r3, r2\n\t"
                "cbnz r3, #44\n\t"
                "tta r0, r0\n\t"
                "movw r3, #0\n\t"
                "movt r3, #1\n\t"
                "ands r3, r0\n\t"
                "cbz r3, #28\n\t"
                "movw r3, #60816\n\t"
                "movt r3, #57346\n\t"
                "mov r2, #255\n\t"
                "ands r2, r0\n\t"
                "str r2, [r3, #8]\n\t"
                "ldr r3, [r3, #12]\n\t"
                "mov r2, #2\n\t"
                "ands r3, r2\n\t"
                "cbz r3, #2\n\t"
                "b HardFault_Handler\n\t"
            );
            #endif
            pfNonSecure_LED_On(1u);
        }
        break;
    case 50:
        if (pfNonSecure_LED_Off != NULL)
        {
            #ifdef RET2NS_PROTECTION
            __ASM volatile(
                ".syntax unified\n\t"
                ".thumb\n\t"
                "mrs r3, ipsr\n\t"
                "cbnz r3, #10\n\t"
                "mrs r3, control_ns\n\t"
                "mov r2, #1\n\t"
                "ands r3, r2\n\t"
                "cbnz r3, #44\n\t"
                "tta r0, r0\n\t"
                "movw r3, #0\n\t"
                "movt r3, #1\n\t"
                "ands r3, r0\n\t"
                "cbz r3, #28\n\t"
                "movw r3, #60816\n\t"
                "movt r3, #57346\n\t"
                "mov r2, #255\n\t"
                "ands r2, r0\n\t"
                "str r2, [r3, #8]\n\t"
                "ldr r3, [r3, #12]\n\t"
                "mov r2, #2\n\t"
                "ands r3, r2\n\t"
                "cbz r3, #2\n\t"
                "b HardFault_Handler\n\t"
            );
            #endif
            pfNonSecure_LED_Off(1u);
        }
        break;
    case 99:
        ticks = 0;
        if (ticks_printf++ == 3)
        {
            printf("%s", text);
            ticks_printf = 0;
        }
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
    uint32_t NonSecure_StackPointer = (*((uint32_t *)(NONSECURE_START + 0u)));
    NonSecure_fpVoid NonSecure_ResetHandler = (NonSecure_fpVoid)(*((uint32_t *)(NONSECURE_START + 4u)));

    /* exercise some floating point instructions from Secure Mode */
    volatile uint32_t fpuType = SCB_GetFPUType();
    volatile float x1 = 12.4567f;
    volatile float x2 = 0.6637967f;
    volatile float x3 = 24.1111118f;

    x3 = x3 * (x1 / x2);

    /* exercise some core register from Secure Mode */
    x = __get_MSP();
    x = __get_PSP();
    __TZ_set_MSP_NS(NonSecure_StackPointer);
    x = __TZ_get_MSP_NS();
    __TZ_set_PSP_NS(0x22000000u);
    x = __TZ_get_PSP_NS();

    SystemCoreClockUpdate();

    stdout_init(); /* Initialize Serial interface */
    LED_Initialize();
    GLCD_Initialize();

    /* display initial screen */
    GLCD_SetFont(&GLCD_Font_16x24);
    GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
    GLCD_ClearScreen();
    GLCD_SetBackgroundColor(GLCD_COLOR_BLUE);
    GLCD_SetForegroundColor(GLCD_COLOR_RED);
    GLCD_DrawString(0 * 16, 0 * 24, "   V2M-MPS2+ Demo   ");
    GLCD_DrawString(0 * 16, 1 * 24, " Secure/Non-Secure  ");
    GLCD_DrawString(0 * 16, 2 * 24, "   www.keil.com     ");

    GLCD_SetBackgroundColor(GLCD_COLOR_WHITE);
    GLCD_SetForegroundColor(GLCD_COLOR_BLACK);
    switch ((SCB->CPUID >> 4) & 0xFFF)
    {
    case 0xD20:
        GLCD_DrawString(0 * 16, 4 * 24, "  Cortex-M23        ");
        break;
    case 0xD21:
        GLCD_DrawString(0 * 16, 4 * 24, "  Cortex-M33        ");
        break;
    default:
        GLCD_DrawString(0 * 16, 4 * 24, "  unknown Cortex-M  ");
        break;
    }

    SysTick_Config(SystemCoreClock / 100); /* Generate interrupt each 10 ms */

    NonSecure_ResetHandler();
}
