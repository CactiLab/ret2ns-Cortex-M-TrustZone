/*----------------------------------------------------------------------------
 * Name:    main_ns.c
 * Purpose: Main function non-secure mode
 *----------------------------------------------------------------------------*/

#include <arm_cmse.h>
#include "IOTKit_CM33_FP.h"                        /* Device header */
#include "Board_LED.h"                             /* ::Board Support:LED */
#include "..\IOTKit_CM33_s\Secure_Functions.h"     /* Secure Code Entry Points */


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
void SysTick_Handler (void);
void SysTick_Handler (void) {
  static uint32_t ticks;

  switch (ticks++) {
    case  10:
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
      if (ticks > 99) {
        ticks = 0;
      }
  }
}

/* change privileged mode */
void SVC_Handler_Main(unsigned int *svc_args)
{
   //	DISABLE_IRQ;
   //	#ifdef MISSED_CYCLES
   //		elapsed_time_start(2);
   //	#endif
   uint32_t svc_number;
   /* stack contains: r0, r1, r2, r3, r12, r14, the return address and xPSR */
   svc_number = ((char *)svc_args[6])[-2];
   switch (svc_number)
   {
   case 0: /* EnablePrivilegeMode*/
      __set_CONTROL(__get_CONTROL() & ~CONTROL_nPRIV_Msk);
      break;

   default:
      break;
   }
}

void SVC_Handler(void)
{
   __asm volatile(
       "TST    LR, #0b0100;      "
       "ITE    EQ;               "
       "MRSEQ  R0, MSP;          "
       "MRSNE  R0, PSP;          "
       "MOV    R1, LR;           "
       "B      SVC_Handler_Main;  ");
}

static uint32_t x;
/*----------------------------------------------------------------------------
  Main function
 *----------------------------------------------------------------------------*/
int main (void)
{
  uint32_t i;

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
  SysTick_Config(SystemCoreClock / 100);  /* Generate interrupt each 10 ms */

  while (1) {
    LED_On (5u);
    for (i = 0; i < 0x100000; i++) __NOP();
    LED_Off(5u);
    for (i = 0; i < 0x100000; i++) __NOP();
    Secure_LED_On (4u);
    for (i = 0; i < 0x100000; i++) __NOP();
    Secure_LED_Off(4u);
    for (i = 0; i < 0x100000; i++) __NOP();

    Secure_printf(text);
  }
}
