=================
TrustZone Manager
=================

TrustZone for ARMv8-M technology is enabled in Microchip SAM L11 MCU and
provides hardware-enforced isolation between the trusted and the untrusted
resources on the device.

This TrustZone Manager component provides means to configure global TrustZone
settings of an SAM L11 MCU, which is based on Cortex-M23 core.


There are two types of TrustZone for ARMv8-M based projects:

* Secure project: TrustZone Manager component MUST be added into the project to get access to the global TrustZone settings.
* Non-Secure project: **Don't** add TrustZone Manager component into the project as the Non-Secure project will rely on a Secure project for TrustZone global settings.



Features
--------

* Memory secure attribution settings

  * UROW.AS: Flash Application Secure Size = AS*0x100
  * UROW.ANSC: Flash Application Non-Secure Callable Size = ANSC*0x20
  * UROW.RS: RAM Secure Size = RS*0x80
  * UROW.DS: DATA Flash Secure Size = DS*0x100
  * BOCOR.BOOTPROT: Boot Protection size = BOOTPROT*0x100
  * BOCOR.BS: Boot Flash Secure Size = BS*0x100
  * BOCOR.BNSC: Boot Flash Non-Secure Callable Size = BNSC*0x20

* Peripheral secure attribution settings

  * NONSECA: Peripherals Non-Secure Status Fuses for Bridge A
  * NONSECB: Peripherals Non-Secure Status Fuses for Bridge B
  * NONSECC: Peripherals Non-Secure Status Fuses for Bridge C

* NVIC Interrupt Target Non-Secure state attribution settings

* Port Security Attribution of I/O Pins

* Set stack size for secure and non-secure project

* Generate secure gateway veneer code

Usage Notes:
^^^^^^^^^^^^
* For secure consideration, always configure clock related peripherals as secure peripheral, such as MCLK, GCLK  etc. The secure project will initialize the clock setting, and the non-project just uses that clock setting.
* Always configure Mix-Secure Peripheral as secure peripheral, such as EIC, EVSYS and PORT.
* In START, only add secure peripheral driver in secure project.
* In START, only add non-secure peripheral driver in non-secure project.
* Mix-Secure peripheral driver can be added into both secure and non-secure project

  * In secure project, it configures which resources inside Mix-Secure peripheral can be used in non-secure project, and configures only secure resources used in the project.
  * In non-secure project, it configures only non-secure resources inside Mix-Secure peripheral used in the project.

* After reset is released, the CPU starts fetching from the Boot ROM, then finally jumping to the Flash in Secure state.

Linker files for secure and non-secure project
----------------------------------------------

Atmel Studio & GCC
^^^^^^^^^^^^^^^^^^

Two linker files will be generated according to the TrustZone settings:

* Device_Startup/saml11_secure.ld : GCC linker script for secure project
* Device_Startup/saml11_nonsecure.ld : GCC linker script for non-secure project

IAR
^^^

Two linker files will be generated according to the TrustZone settings:

* toolchain/iar/linker/saml11_secure.icf : IAR linker script for secure project
* toolchain/iar/linker/saml11_nonsecure.icf : IAR linker script for non-secure project

Keil MDK
^^^^^^^^

Two linker files will be generated according to the TrustZone settings:

* toolchain/keil/linker/saml11_secure.sct : Keil Scatter-Loading Description File for secure project
* toolchain/keil/linker/saml11_nonsecure.sct : Keil Scatter-Loading Description File for non-secure project

**Note:** stack size configuration in TrustZone Manager is not included in above generated Keil scatter file. Please update it in startup_<device>.s file in the project according your application.

Toolchain Settings for Secure Project
-------------------------------------

For secure project, the toolchain settings can be configured in START UI.
Click project name block in START to show toolchain settings UI.

Atmel Studio
^^^^^^^^^^^^

* Compiler configuration

Default with "-std=gnu99 -mcmse" compiler flag.
"-mcmse" flag is used to enable compiler for creating CMSE secure executable files.

* Linker configuration

Default with "-Wl,--out-implib=libsecure_gateway_veneer.lib -Wl,--cmse-implib" flag for generating a secure gateway veneer and a symbol in an import library. If don't want to generating a secure gateway library, just remove it and keep the text box empty.

IAR and Keil MDK
^^^^^^^^^^^^^^^^

No START UI support. Need manually update toolchain settings in the project, see Atmel START help documentation.


Dependencies
------------

* This middleware is available for SAM L11 MCU only.

Limitation
----------

* Keil MDK use another way (debug configuration file) to program UROW settings. TrustZone middleware generates a reference file here: toolchain/keil/DebugConfig/SAML11.dbgconf