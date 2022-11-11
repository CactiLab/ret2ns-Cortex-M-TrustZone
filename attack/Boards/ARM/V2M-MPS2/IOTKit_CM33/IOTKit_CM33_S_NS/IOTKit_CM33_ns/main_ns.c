/*----------------------------------------------------------------------------
 * Name:    main_ns.c
 * Purpose: Main function non-secure mode
 *----------------------------------------------------------------------------*/

#include <arm_cmse.h>
#include "IOTKit_CM33_FP.h"                    /* Device header */
#include "Board_LED.h"                         /* ::Board Support:LED */
#include "..\IOTKit_CM33_s\Secure_Functions.h" /* Secure Code Entry Points */

#define DROP_NS_PRIVILEGES __asm("msr CONTROL, %[reg] " ::[reg] "r"(1) \
: "memory")

#define SET_NS_PRIVILEGES __asm("msr CONTROL, %[reg] " ::[reg] "r"(0) \
: "memory")

void attacker_controlled(void);
void print_LCD(char *msg);

char text[] = "Hello World (non-secure)\r\n";

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

/*----------------------------------------------------------------------------
  SVC IRQ Handler
 *----------------------------------------------------------------------------*/

void SVC_Handler_Main(uint32_t exc_return_code, uint32_t msp_val)
{
    uint32_t stack_frame_addr;
    unsigned int *svc_args;
    uint8_t svc_number;
    // Determines which stack pointer was used
    if (exc_return_code & 0x4) stack_frame_addr = __get_PSP();
    else stack_frame_addr = msp_val;
    // Determines whether additional state context is present
    if (exc_return_code & 0x20) {
        svc_args = (unsigned *) stack_frame_addr;}
    else {// additional state context present (only for Secure SVC)
        svc_args = (unsigned *) (stack_frame_addr+40);}
    // extracts SVC number
    svc_number = ((char *) svc_args[6])[-2]; // Memory[(stacked_pc)-2]
    switch (svc_number)
    {
        case 0:
            print_LCD_nsc((char *) svc_args[0]);
            break;
        default:
            break;
    }
}

void __attribute__((naked)) SVC_Handler(void)
{
    __asm volatile(
        "mov r0, lr\n\t"
        "mov r1, sp\n\t"
        "b   SVC_Handler_Main\n\t"
    );
}

void print_LCD(char *msg)
{
    register char* r0 __asm("r0") = msg;
	__asm volatile("svc #0"
		:
		: "r"  (r0)
	);
}

void attacker_controlled(void)
{
    while (1)
    {}
}

static uint32_t x;
/*----------------------------------------------------------------------------
  Main function
 *----------------------------------------------------------------------------*/
int main(void)
{
    uint32_t i;

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

    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 100); /* Generate interrupt each 10 ms */

    DROP_NS_PRIVILEGES;

    char user_input[28] = {
		0x20,0x20,0x20,0x20,
		0xc0,0x05,0x00,0x20,
		0x0b,0x01,0x00,0x00,
		0x22,0x22,0x22,0x22,
		0x23,0x23,0x23,0x23,
		0x24,0x24,0x24,0x24,
		0x76,0x83,0x00,0x00};
    print_LCD(user_input);

    while (1)
    {

    }
}
