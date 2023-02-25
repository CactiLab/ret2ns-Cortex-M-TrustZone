Return-to-Non-Secure Vulnerabilities on ARM Cortex-M TrustZone: Attack and Defense
========================

This repo demonstrates the Return-to-Non-Secure (ret2ns) vulnerabilities on ARM Cortex-M TrustZone. It contains the attack and defense demonstration, as well as the defense overhead evaluation.

The results of this project was published in the paper entitled "Return-to-Non-Secure Vulnerabilities on ARM Cortex-M TrustZone: Attack and Defense" in the ACM/IEEE Design Automation Conference (DAC) 2023. If you want to cite our paper in your work, please use the following BibTeX entry.

```
@inproceedings{ma2023dac,
  title = {Return-to-Non-Secure Vulnerabilities on ARM Cortex-M TrustZone: Attack and Defense},
  author = {Ma, Zheyuan and Tan, Xi and Ziarek, Lukasz and Zhang, Ning and Hu, Hongxin and Zhao, Ziming},
  booktitle = {ACM/IEEE Design Automation Conference},
  year = {2023},
}

```

Target environments
------------------

The projects are tested for the ARM **IOTKit_CM33** microcontroller using ARM **V2M-MPS2+** Evaluation Board (uses onboard CMSIS-DAP as the debugger). The code is compliant with Cortex Microcontroller Software Interface Standard (CMSIS).
- MPS2+ image: AN505 (+ MB BIOS image V2.2.0)

Attack and Defense Demonstration
---------------------
The attack and defense demonstration project is in the `attack` folder.

The four attack variants are:
- Attack 1: the Non-secure handler calls a secure NSC function, and then returns with BXNS (shared IPSR).
- Attack 2: the Non-secure handler calls a secure NSC function, and then the secure NSC calls another non-secure function with BLXNS (IPSR changes with the non-secure function call)
- Attack 3: the Non-secure privileged thread program calls a secure NSC function, and then returns with BXNS (banked CONTROL_NS.nPRIV)
- Attack 4: the Non-secure privileged thread program calls a secure NSC function, and then the secure NSC calls another non-secure function (IPSR changes with the non-secure function call)

The two secure NSC functions are:
- `print_LCD_nsc`: this function has a buffer overflow vulnerability, which can be exploited to overwrite the NSC return address on the stack (change the BXNS target).
- `blxns_nsc`: this function has a buffer overflow vulnerability, which can be exploited to overwrite the non-secure function pointer on the stack (change the BLXNS target).

Usage:
- There are four macros defined in `main_ns.c` to control the attack variant to be demonstrated. The default is Attack 1. Toggling the macros to demonstrate other attack variants.
- There are two macros defined in `main_s.c` to enable two defenses: MPU-assisted address sanitizer (`RET2NS_PROTECTION_MPU`) and address masking (`RET2NS_PROTECTION_MASKING`). The default is no defense. Toggling the macros to enable the defenses.

Defense Overhead Evaluation
---------------------
The defense overhead evaluation project is in the `blinky_tz` folder. The Blinky application is a cross-world project with both non-secure and secure state programs, and it works on a system with 3 LEDs and a UART peripheral.
We enabled the non-secure MPU for all the evaluation experiments.

In the modified Blinky application, the secure and non-secure programs configure the SysTick timer for its corresponding state, respectively, to generate a SysTick interrupt every $S$ ms (around $T = S \times 20 \times 10^3$ CPU cycles).

The secure state program provides three NSC functions for 1) switching on an LED; 2) switching off an LED; 3) sending messages to the UART peripheral.
All three NSC functions return with `bxns` instructions.

The non-secure main program is a loop that calls the three NSC functions to toggle LED-1 and send a message to the UART. 
There are $N$ `nop` instructions before each NSC function call, and each `nop` instruction consumes one CPU cycle.

The secure SysTick handler calls two non-secure functions to toggle LED-2 using `blxns` instructions.
The non-secure SysTick handler also calls the NSC functions to toggle LED-3.

The cross-state calls in the SysTick handlers represent the routine two-way communications between the states, 
whereas the NSC function calls in the non-secure main loop represent ad-hoc service requests.
By configuring $T$ and $N$, we can simulate applications with different state-crossing frequencies.
Higher $T$ means less frequent routine communications between the states, and higher $N$ means less frequent service requests from the non-secure state to the secure state.

Usage:
- There are two macros defined in `main_ns.c`. `T` controls the SysTick timer frequency (unit is CPU cycle), and `N` controls the number of `nop` instructions before each NSC function call.
- There are three macros defined in `main_s.c`. `T` controls the SysTick timer frequency (unit is CPU cycle). `RET2NS_PROTECTION_MPU` enables the MPU-assisted address sanitizer, and `RET2NS_PROTECTION_MASKING` enables the address masking mechanism.