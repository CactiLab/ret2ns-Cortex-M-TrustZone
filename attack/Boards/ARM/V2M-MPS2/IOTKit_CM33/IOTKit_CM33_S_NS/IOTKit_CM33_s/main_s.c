/*----------------------------------------------------------------------------
 * Name:    main_s.c
 * Purpose: Main function secure mode
 *----------------------------------------------------------------------------*/

#include <arm_cmse.h>
#include <stdio.h>
#include <string.h>
#include "mpu_init.h"
#include "IOTKit_CM33_FP.h" /* Device header */
#include "Board_LED.h"      /* ::Board Support:LED */
#include "Board_GLCD.h"     /* ::Board Support:Graphic LCD */
#include "GLCD_Config.h"    /* Keil.SAM4E-EK::Board Support:Graphic LCD */

/*----------------------------------------------------------------------------
  Macros to enable the MPU-assisted address sanitizer or the address masking mechanism,
  eithor of which can be used to mitigate the ret2ns attacks
 *----------------------------------------------------------------------------*/
// #define RET2NS_PROTECTION_MPU
#define RET2NS_PROTECTION_MASKING

/* Start address of non-secure application */
#define NONSECURE_START (0x00200000u)
#define MAX_LEN 8
#define _TIME_STAMP "UNKNOWN"
#define _SYSTEM_STATUS "OK"

extern GLCD_FONT GLCD_Font_16x24;
extern int stdout_init(void);
typedef void (*NonSecure_fpVoid)(void) __attribute__((cmse_nonsecure_call));
typedef int __attribute__((cmse_nonsecure_call)) chk_func_ptr(void);

int32_t _driver_LCD_ready(void) __attribute__((optnone));
int32_t _driver_LCD_ready(void)
{
    return 1;
}

int32_t _driver_LCD_print(char *msg);
int32_t _driver_LCD_print(char *msg)
{
    printf("%s\r\n", msg);
    return 0;
}

/*----------------------------------------------------------------------------
  NonSecure callback functions initialization
 *----------------------------------------------------------------------------*/
/* Secure callable functions initialization */
void default_callback(void);
void default_callback(void)
{
    __BKPT(0);
}

/*
 * Declare function pointer *fp
 * fp can point to either a secure or a non-secure function
 * Initialized to a default callback
 */
/* typedef for NonSecure callback function */
typedef int __attribute__((cmse_nonsecure_call)) tdef_nsfunc_o_int_i_void(void);
tdef_nsfunc_o_int_i_void *fp = (tdef_nsfunc_o_int_i_void *)default_callback;

// This is a Secure API with a function pointer as an input parameter
int __attribute__((cmse_nonsecure_entry)) pass_nsfunc_ptr_o_int_i_void(tdef_nsfunc_o_int_i_void *callback)
{
    // Result for the function pointer
    cmse_address_info_t tt_payload;
    tt_payload = cmse_TTA_fptr(callback);
    if (tt_payload.flags.nonsecure_read_ok)
    {
        fp = cmse_nsfptr_create(callback); // Non-secure function pointer
        return (0);
    }
    else
        return (1); // Function pointer is not accessible from the Non-secure side
}

/*----------------------------------------------------------------------------
  Secure functions exported to NonSecure application (NSC)
 *----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
  Vulnerable NSC function: this function has a buffer overflow vulnerability,
    which can be exploited to overwrite the NSC return address on the stack
    (BXNS)
 *----------------------------------------------------------------------------*/
int32_t print_LCD_nsc(char *msg) __attribute__((cmse_nonsecure_entry));
int32_t print_LCD_nsc(char *msg)
{
    char buf[MAX_LEN] = {0};
    int32_t val = -1;
    if (_driver_LCD_ready())
    {
        sprintf(buf, "%s %s: %c%c%c%c", _TIME_STAMP, _SYSTEM_STATUS, msg[0], msg[1], msg[2], msg[3]);

        val = _driver_LCD_print(buf);
    }
#ifdef RET2NS_PROTECTION_MPU
    __ASM volatile(
        ".syntax unified\n\t"
        ".thumb\n\t"
        "ldr r0, [sp, #0x1c]\n\t"
        "mrs r3, ipsr\n\t"
        "cbnz r3, #6\n\t"
        "mrs r3, control_ns\n\t"
        "lsls r3, r3, #31\n\t"
        "bne #28\n\t"
        "tta r0, r0\n\t"
        "lsls r3, r0, #15\n\t"
        "bpl #20\n\t"
        "uxtb r0, r0\n\t"
        "movw r3, #0xed98\n\t"
        "movt r3, #0xe002\n\t"
        "str r0, [r3, #0]\n\t"
        "ldr r0, [r3, #4]\n\t"
        "lsls r0, r0, #30\n\t"
        "beq #2\n\t"
        "cpsid i\n\t"
        "b .\n\t");
#elif defined RET2NS_PROTECTION_MASKING
    __ASM volatile(
        ".syntax unified\n\t"
        ".thumb\n\t"
        "ldr r1, [sp, #0x1c]\n\t"
        "mrs r2, ipsr\n\t"
        "cbnz r2, #6\n\t"
        "mrs r2, control_ns\n\t"
        "lsls r2, r2, #31\n\t"
        "bne #8\n\t"
        "cmn r1, #0x100\n\t"
        "itt cc\n\t"
        "movtcc r1, #0x21\n\t"
        "strcc r1, [sp, #0x1c]\n\t");
#endif
    return val;
}

/*----------------------------------------------------------------------------
  Vulnerable NSC function: this function has a buffer overflow vulnerability,
    which can be exploited to overwrite the non-secure function pointer on the stack
    (BLXNS)
 *----------------------------------------------------------------------------*/
int32_t blxns_nsc(char *msg) __attribute__((cmse_nonsecure_entry, optnone));
int32_t blxns_nsc(char *msg)
{
    int32_t val = -1;
    int driver_status;
    chk_func_ptr *check_fp;
    check_fp = cmse_nsfptr_create(fp);

    char buf[MAX_LEN];
    sprintf(buf, "%s %s: %c%c%c%c", _TIME_STAMP, _SYSTEM_STATUS, msg[0], msg[1], msg[2], msg[3]);

#ifdef RET2NS_PROTECTION_MPU
    __ASM volatile(
        ".syntax unified\n\t"
        ".thumb\n\t"
        "ldr r0, [sp, #0x20]\n\t"
        "mrs r3, ipsr\n\t"
        "cbnz r3, #6\n\t"
        "mrs r3, control_ns\n\t"
        "lsls r3, r3, #31\n\t"
        "bne #28\n\t"
        "tta r0, r0\n\t"
        "lsls r3, r0, #15\n\t"
        "bpl #20\n\t"
        "uxtb r0, r0\n\t"
        "movw r3, #0xed98\n\t"
        "movt r3, #0xe002\n\t"
        "str r0, [r3, #0]\n\t"
        "ldr r0, [r3, #4]\n\t"
        "lsls r0, r0, #30\n\t"
        "beq #2\n\t"
        "cpsid i\n\t"
        "b .\n\t");
#elif defined RET2NS_PROTECTION_MASKING
    __ASM volatile(
        ".syntax unified\n\t"
        ".thumb\n\t"
        "ldr r1, [sp, #0x20]\n\t"
        "mrs r2, ipsr\n\t"
        "cbnz r2, #6\n\t"
        "mrs r2, control_ns\n\t"
        "lsls r2, r2, #31\n\t"
        "bne #8\n\t"
        "cmn r1, #0x100\n\t"
        "itt cc\n\t"
        "movtcc r1, #0x21\n\t"
        "strcc r1, [sp, #0x20]\n\t");
#endif
    driver_status = check_fp();
    if (driver_status == 0)
    {
        val = _driver_LCD_print(buf);
    }
    return val;
}

static uint32_t x;
/*----------------------------------------------------------------------------
  Main function
 *----------------------------------------------------------------------------*/
int main(void)
{
    uint32_t NonSecure_StackPointer = (*((uint32_t *)(NONSECURE_START + 0u)));
    NonSecure_fpVoid NonSecure_ResetHandler = (NonSecure_fpVoid)(*((uint32_t *)(NONSECURE_START + 4u)));

    /* Initialize NS MPU */
    mpu_ns_init();

    /* exercise some core register from Secure Mode */
    x = __get_MSP();
    x = __get_PSP();
    __TZ_set_MSP_NS(NonSecure_StackPointer);
    x = __TZ_get_MSP_NS();
    __TZ_set_PSP_NS(0x22000000u);
    x = __TZ_get_PSP_NS();

    SystemCoreClockUpdate();
    SysTick->CTRL = 0;

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
    GLCD_DrawString(0 * 16, 2 * 24, "   ret2ns Attack    ");

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

    NonSecure_ResetHandler();
}
