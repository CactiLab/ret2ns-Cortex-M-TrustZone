Introduction
============

This example demonstrates the use of TrustZone for Cortex-M device for Getting
Started.

Two simple secure math operation functions are provided by secure project,
and will be called by non-secure project. In debug mode, the results of the
functions can be checked.

There are two combined projects for the example:

* TZ-GetStart-S for secure Project
* TZ-GetStart-NS for non-secure Project


Supported evaluation kit
------------------------
 - ATSAML11-XPRO


Drivers & Middleware in Secure Project
--------------------------------------
* TrustZone middleware

  * Configure memory and peripherals secure attribution
  * Enable related secure gateway veneer code


Drivers & Middleware in Non-Secure Project
------------------------------------------
* None


Debugging the example with Atmel Studio
---------------------------------------

#. Download the TZ-GetStart secure project and non-secure project from START
#. Import the secure project into Atmel Studio and compile it
#. In secure project solution, import the non-secure project with "Add To Solution" option, and then compile non-secure project
#. Open properties dialog of secure project, add elf file of non-secure project into "Advanced->Additional module"
#. Open properties dialog of non-secure project, add elf file of secure project into "Advanced->Additional module"
#. Start debugging