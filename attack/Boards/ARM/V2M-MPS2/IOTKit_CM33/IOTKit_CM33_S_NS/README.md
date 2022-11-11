IOTKit_CM33_S_NS project
========================

The **IOTKit_CM33_S_NS** project is a simple demo program for
ARM **IOTKit_CM33** microcontroller using ARM **V2M-MPS2+** Evaluation Board.
Compliant to Cortex Microcontroller Software Interface Standard (CMSIS).

Example functionality
---------------------
Clock Settings:
 - XTAL  =  50 MHz
 - CCLK  =  25 MHz

The example demonstrates the interworking between secure and un-secure mode
on an IOTKit Cortex-M33 microcontroller.

Secure Application:
 - Setup core.
 - Initialize LEDs.
 - Initialize GLCD.
 - LED0:  function call from Secure to Secure code                                    using Secure SysTick.
 - LED1:  function call from Secure to NonSecure code via registered function pointer using Secure SysTick.
 - Output text on serial port USART0 (via USART  CMSIS driver)
   - USART0 settings: 115200 baud, 8 data bits, no parity, 1 stop bit

NonSecure Application:
 - LED7:  function call from NonSecure to NonSecure code                             using NonSecure SysTick.
 - LED6:  function call from NonSecure to Secure Code via exported Secure functions  using NonSecure SysTick.
 - LED5:  function call from NonSecure to NonSecure code                             using while loop.
 - LED4:  function call from NonSecure to Secure code via exported Secure functions  using while loop.
 - Output text on serial port USART0 (via exported Secure function)


Available targets
-----------------
 - FVP:        configured for Fast Models Fixed Virtual Platforms
 - V2M-MPS2+:  configured for MPS2+ (uses onboard CMSIS-DAP as debugger)

MPS2+ image: AN505 (+ MB BIOS image V2.2.0)
