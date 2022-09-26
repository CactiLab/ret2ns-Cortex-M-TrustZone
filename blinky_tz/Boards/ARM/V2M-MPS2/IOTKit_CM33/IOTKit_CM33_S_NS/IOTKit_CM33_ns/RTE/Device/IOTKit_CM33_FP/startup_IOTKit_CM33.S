/******************************************************************************
 * @file     startup_IOTKit_CM33.S
 * @brief    CMSIS Startup File for IOTKit_CM33 Device
 ******************************************************************************/
/* Copyright (c) 2022 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


                .syntax  unified
                .arch    armv8-m.main

                #define __INITIAL_SP     Image$$ARM_LIB_STACK$$ZI$$Limit
                #define __STACK_LIMIT    Image$$ARM_LIB_STACK$$ZI$$Base
                #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
                #define __STACK_SEAL     Image$$STACKSEAL$$ZI$$Base
                #endif

                .section RESET
                .align   2
                .globl   __Vectors
                .globl   __Vectors_End
                .globl   __Vectors_Size
__Vectors:
                /* Exceptions */
                .long    __INITIAL_SP                       /*     Initial Stack Pointer */
                .long    Reset_Handler                      /*     Reset Handler */
                .long    NMI_Handler                        /* -14 NMI Handler */
                .long    HardFault_Handler                  /* -13 Hard Fault Handler */
                .long    MemManage_Handler                  /* -12 MPU Fault Handler */
                .long    BusFault_Handler                   /* -11 Bus Fault Handler */
                .long    UsageFault_Handler                 /* -10 Usage Fault Handler */
                .long    SecureFault_Handler                /*  -9 Secure Fault Handler */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    SVC_Handler                        /*  -5 SVC Handler */
                .long    DebugMon_Handler                   /*  -4 Debug Monitor Handler */
                .long    0                                  /*     Reserved */
                .long    PendSV_Handler                     /*  -2 PendSV Handler */
                .long    SysTick_Handler                    /*  -1 SysTick Handler */

                /* Core IoT Interrupts */
                .long    NONSEC_WATCHDOG_RESET_Handler      /*   0 Non-Secure Watchdog Reset Handler */
                .long    NONSEC_WATCHDOG_Handler            /*   1 Non-Secure Watchdog Handler */
                .long    S32K_TIMER_Handler                 /*   2 S32K Timer Handler */
                .long    TIMER0_Handler                     /*   3 TIMER 0 Handler */
                .long    TIMER1_Handler                     /*   4 TIMER 1 Handler */
                .long    DUALTIMER_Handler                  /*   5 Dual Timer Handler */
                .long    0                                  /*   6 Reserved */
                .long    0                                  /*   7 Reserved */
                .long    0                                  /*   8 Reserved */
                .long    MPC_Handler                        /*   9 MPC Combined (Secure) Handler */
                .long    PPC_Handler                        /*  10 PPC Combined (Secure) Handler */
                .long    MSC_Handler                        /*  11 MSC Combined (Secure) Handler */
                .long    BRIDGE_ERROR_Handler               /*  12 Bridge Error Combined (Secure) Handler */
                .long    0                                  /*  13 Reserved */
                .long    0                                  /*  14 Reserved */
                .long    0                                  /*  15 Reserved */
                .long    0                                  /*  16 Reserved */
                .long    0                                  /*  17 Reserved */
                .long    0                                  /*  18 Reserved */
                .long    0                                  /*  19 Reserved */
                .long    0                                  /*  20 Reserved */
                .long    0                                  /*  21 Reserved */
                .long    0                                  /*  22 Reserved */
                .long    0                                  /*  23 Reserved */
                .long    0                                  /*  24 Reserved */
                .long    0                                  /*  25 Reserved */
                .long    0                                  /*  26 Reserved */
                .long    0                                  /*  27 Reserved */
                .long    0                                  /*  28 Reserved */
                .long    0                                  /*  29 Reserved */
                .long    0                                  /*  30 Reserved */
                .long    0                                  /*  31 Reserved */

                /* External Interrupts */
                .long    UART0RX_Handler                    /*  32 UART 0 RX Handler */
                .long    UART0TX_Handler                    /*  33 UART 0 TX Handler */
                .long    UART1RX_Handler                    /*  34 UART 1 RX Handler */
                .long    UART1TX_Handler                    /*  35 UART 1 TX Handler */
                .long    UART2RX_Handler                    /*  36 UART 2 RX Handler */
                .long    UART2TX_Handler                    /*  37 UART 2 TX Handler */
                .long    UART3RX_Handler                    /*  38 UART 2 RX Handler */
                .long    UART3TX_Handler                    /*  39 UART 2 TX Handler */
                .long    UART4RX_Handler                    /*  40 UART 2 RX Handler */
                .long    UART4TX_Handler                    /*  41 UART 2 TX Handler */
                .long    UART0_Handler                      /*  42 UART 0 combined Handler */
                .long    UART1_Handler                      /*  43 UART 1 combined Handler */
                .long    UART2_Handler                      /*  44 UART 2 combined Handler */
                .long    UART3_Handler                      /*  45 UART 3 combined Handler */
                .long    UART4_Handler                      /*  46 UART 4 combined Handler */
                .long    UARTOVF_Handler                    /*  47 UART 0,1,2,3,4 Overflow Handler */
                .long    ETHERNET_Handler                   /*  48 Ethernet Handler */
                .long    I2S_Handler                        /*  49 I2S Handler */
                .long    TSC_Handler                        /*  50 Touch Screen Handler */
                .long    SPI0_Handler                       /*  51 SPI 0 Handler */
                .long    SPI1_Handler                       /*  52 SPI 1 Handler */
                .long    SPI2_Handler                       /*  53 SPI 2 Handler */
                .long    SPI3_Handler                       /*  54 SPI 3 Handler */
                .long    SPI4_Handler                       /*  55 SPI 4 Handler */
                .long    DMA0_ERROR_Handler                 /*  56 DMA 0 Error Handler */
                .long    DMA0_TC_Handler                    /*  57 DMA 0 Terminal Count Handler */
                .long    DMA0_Handler                       /*  58 DMA 0 Combined Handler */
                .long    DMA1_ERROR_Handler                 /*  59 DMA 1 Error Handler */
                .long    DMA1_TC_Handler                    /*  60 DMA 1 Terminal Count Handler */
                .long    DMA1_Handler                       /*  61 DMA 1 Combined Handler */
                .long    DMA2_ERROR_Handler                 /*  62 DMA 2 Error Handler */
                .long    DMA2_TC_Handler                    /*  63 DMA 2 Terminal Count Handler */
                .long    DMA2_Handler                       /*  64 DMA 2 Combined Handler */
                .long    DMA3_ERROR_Handler                 /*  65 DMA 3 Error Handler */
                .long    DMA3_TC_Handler                    /*  66 DMA 3 Terminal Count Handler */
                .long    DMA3_Handler                       /*  67 DMA 3 Combined Handler */
                .long    GPIO0_Handler                      /*  68 GPIO 0 Combined Handler */
                .long    GPIO1_Handler                      /*  69 GPIO 1 Combined Handler */
                .long    GPIO2_Handler                      /*  70 GPIO 2 Combined Handler */
                .long    GPIO3_Handler                      /*  71 GPIO 3 Combined Handler */
                .long    GPIO0_0_Handler                    /*  72 */       /* All P0 I/O pins used as irq source */
                .long    GPIO0_1_Handler                    /*  73 */       /* There are 16 pins in total         */
                .long    GPIO0_2_Handler                    /*  74 */
                .long    GPIO0_3_Handler                    /*  75 */
                .long    GPIO0_4_Handler                    /*  76 */
                .long    GPIO0_5_Handler                    /*  77 */
                .long    GPIO0_6_Handler                    /*  78 */
                .long    GPIO0_7_Handler                    /*  79 */
                .long    GPIO0_8_Handler                    /*  80 */
                .long    GPIO0_9_Handler                    /*  81 */
                .long    GPIO0_10_Handler                   /*  82 */
                .long    GPIO0_11_Handler                   /*  83 */
                .long    GPIO0_12_Handler                   /*  84 */
                .long    GPIO0_13_Handler                   /*  85 */
                .long    GPIO0_14_Handler                   /*  86 */
                .long    GPIO0_15_Handler                   /*  87 */
                .long    GPIO1_0_Handler                    /*  88 */       /* All P1 I/O pins used as irq source */
                .long    GPIO1_1_Handler                    /*  89 */       /* There are 16 pins in total         */
                .long    GPIO1_2_Handler                    /*  90 */
                .long    GPIO1_3_Handler                    /*  91 */
                .long    GPIO1_4_Handler                    /*  92 */
                .long    GPIO1_5_Handler                    /*  93 */
                .long    GPIO1_6_Handler                    /*  94 */
                .long    GPIO1_7_Handler                    /*  95 */
                .long    GPIO1_8_Handler                    /*  96 */
                .long    GPIO1_9_Handler                    /*  97 */
                .long    GPIO1_10_Handler                   /*  98 */
                .long    GPIO1_11_Handler                   /*  99 */
                .long    GPIO1_12_Handler                   /* 100 */
                .long    GPIO1_13_Handler                   /* 101 */
                .long    GPIO1_14_Handler                   /* 102 */
                .long    GPIO1_15_Handler                   /* 103 */
                .long    GPIO2_0_Handler                    /* 104 */       /* All P2 I/O pins used as irq source */
                .long    GPIO2_1_Handler                    /* 105 */       /* There are 16 pins in total         */
                .long    GPIO2_2_Handler                    /* 106 */
                .long    GPIO2_3_Handler                    /* 107 */
                .long    GPIO2_4_Handler                    /* 108 */
                .long    GPIO2_5_Handler                    /* 109 */
                .long    GPIO2_6_Handler                    /* 110 */
                .long    GPIO2_7_Handler                    /* 111 */
                .long    GPIO2_8_Handler                    /* 112 */
                .long    GPIO2_9_Handler                    /* 113 */
                .long    GPIO2_10_Handler                   /* 114 */
                .long    GPIO2_11_Handler                   /* 115 */
                .long    GPIO2_12_Handler                   /* 116 */
                .long    GPIO2_13_Handler                   /* 117 */
                .long    GPIO2_14_Handler                   /* 118 */
                .long    GPIO2_15_Handler                   /* 119 */
                .long    GPIO3_0_Handler                    /* 120 */       /* All P3 I/O pins used as irq source */
                .long    GPIO3_1_Handler                    /* 121 */       /* There are 4 pins in total          */
                .long    GPIO3_2_Handler                    /* 122 */
                .long    GPIO3_3_Handler                    /* 123 */
                .long    0                                  /* 124 Reserved */
                .long    0                                  /* 125 Reserved */
                .long    0                                  /* 126 Reserved */
                .long    0                                  /* 127 Reserved */
                .long    0                                  /* 128 Reserved */
                .long    0                                  /* 129 Reserved */
                .long    0                                  /* 130 Reserved */
                .long    0                                  /* 131 Reserved */
                .long    0                                  /* 132 Reserved */
                .long    0                                  /* 133 Reserved */
                .long    0                                  /* 134 Reserved */
                .long    0                                  /* 135 Reserved */
                .long    0                                  /* 136 Reserved */
                .long    0                                  /* 137 Reserved */
                .long    0                                  /* 138 Reserved */
                .long    0                                  /* 139 Reserved */
                .long    0                                  /* 140 Reserved */
                .long    0                                  /* 141 Reserved */
                .long    0                                  /* 142 Reserved */
                .long    0                                  /* 143 Reserved */
                .long    0                                  /* 144 Reserved */
                .long    0                                  /* 145 Reserved */
                .long    0                                  /* 146 Reserved */
                .long    0                                  /* 147 Reserved */
                .long    0                                  /* 148 Reserved */
                .long    0                                  /* 149 Reserved */
                .long    0                                  /* 150 Reserved */
                .long    0                                  /* 151 Reserved */
                .long    0                                  /* 152 Reserved */
                .long    0                                  /* 153 Reserved */
                .long    0                                  /* 154 Reserved */
                .long    0                                  /* 155 Reserved */
                .long    0                                  /* 156 Reserved */
                .long    0                                  /* 157 Reserved */
                .long    0                                  /* 158 Reserved */
                .long    0                                  /* 159 Reserved */
                .long    0                                  /* 160 Reserved */
                .long    0                                  /* 161 Reserved */
                .long    0                                  /* 162 Reserved */
                .long    0                                  /* 163 Reserved */
                .long    0                                  /* 164 Reserved */
                .long    0                                  /* 165 Reserved */
                .long    0                                  /* 166 Reserved */
                .long    0                                  /* 167 Reserved */
                .long    0                                  /* 168 Reserved */
                .long    0                                  /* 169 Reserved */
                .long    0                                  /* 170 Reserved */
                .long    0                                  /* 171 Reserved */
                .long    0                                  /* 172 Reserved */
                .long    0                                  /* 173 Reserved */
                .long    0                                  /* 174 Reserved */
                .long    0                                  /* 175 Reserved */
                .long    0                                  /* 176 Reserved */
                .long    0                                  /* 177 Reserved */
                .long    0                                  /* 178 Reserved */
                .long    0                                  /* 179 Reserved */
                .long    0                                  /* 180 Reserved */
                .long    0                                  /* 181 Reserved */
                .long    0                                  /* 182 Reserved */
                .long    0                                  /* 183 Reserved */
                .long    0                                  /* 184 Reserved */
                .long    0                                  /* 185 Reserved */
                .long    0                                  /* 186 Reserved */
                .long    0                                  /* 187 Reserved */
                .long    0                                  /* 188 Reserved */
                .long    0                                  /* 189 Reserved */
                .long    0                                  /* 190 Reserved */
                .long    0                                  /* 191 Reserved */
                .long    0                                  /* 192 Reserved */
                .long    0                                  /* 193 Reserved */
                .long    0                                  /* 194 Reserved */
                .long    0                                  /* 195 Reserved */
                .long    0                                  /* 196 Reserved */
                .long    0                                  /* 197 Reserved */
                .long    0                                  /* 198 Reserved */
                .long    0                                  /* 199 Reserved */
                .long    0                                  /* 200 Reserved */
                .long    0                                  /* 201 Reserved */
                .long    0                                  /* 202 Reserved */
                .long    0                                  /* 203 Reserved */
                .long    0                                  /* 204 Reserved */
                .long    0                                  /* 205 Reserved */
                .long    0                                  /* 206 Reserved */
                .long    0                                  /* 207 Reserved */
                .long    0                                  /* 208 Reserved */
                .long    0                                  /* 209 Reserved */
                .long    0                                  /* 210 Reserved */
                .long    0                                  /* 211 Reserved */
                .long    0                                  /* 212 Reserved */
                .long    0                                  /* 213 Reserved */
                .long    0                                  /* 214 Reserved */
                .long    0                                  /* 215 Reserved */
                .long    0                                  /* 216 Reserved */
                .long    0                                  /* 217 Reserved */
                .long    0                                  /* 218 Reserved */
                .long    0                                  /* 219 Reserved */
                .long    0                                  /* 220 Reserved */
                .long    0                                  /* 221 Reserved */
                .long    0                                  /* 222 Reserved */
                .long    0                                  /* 223 Reserved */
                #if defined (IOTKit_CM33_VHT) || defined (IOTKit_CM33_FP_VHT)
                .long    ARM_VSI0_Handler                   /* 224 VSI 0 interrupt */
                .long    ARM_VSI1_Handler                   /* 225 VSI 1 interrupt */
                .long    ARM_VSI2_Handler                   /* 226 VSI 2 interrupt */
                .long    ARM_VSI3_Handler                   /* 227 VSI 3 interrupt */
                .long    ARM_VSI4_Handler                   /* 228 VSI 4 interrupt */
                .long    ARM_VSI5_Handler                   /* 229 VSI 5 interrupt */
                .long    ARM_VSI6_Handler                   /* 230 VSI 6 interrupt */
                .long    ARM_VSI7_Handler                   /* 231 VSI 7 interrupt */
                #else
                .long    0                                  /* 224 Reserved */
                .long    0                                  /* 225 Reserved */
                .long    0                                  /* 226 Reserved */
                .long    0                                  /* 227 Reserved */
                .long    0                                  /* 228 Reserved */
                .long    0                                  /* 229 Reserved */
                .long    0                                  /* 230 Reserved */
                .long    0                                  /* 231 Reserved */
                #endif
__Vectors_End:
                .equ     __Vectors_Size, __Vectors_End - __Vectors
                .size    __Vectors, . - __Vectors


                .thumb
                .section .text
                .align   2

                .thumb_func
                .type    Reset_Handler, %function
                .globl   Reset_Handler
                .fnstart
Reset_Handler:
                ldr      r0, =__INITIAL_SP
                msr      psp, r0

                ldr      r0, =__STACK_LIMIT
                msr      msplim, r0
                msr      psplim, r0

                #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
                ldr      r0, =__STACK_SEAL
                ldr      r1, =0xFEF5EDA5U
                strd     r1,r1,[r0,#0]
                #endif

                bl       SystemInit

                bl       __main

                .fnend
                .size    Reset_Handler, . - Reset_Handler


/* The default macro is not used for HardFault_Handler
 * because this results in a poor debug illusion.
 */
                .thumb_func
                .type    HardFault_Handler, %function
                .weak    HardFault_Handler
                .fnstart
HardFault_Handler:
                b        .
                .fnend
                .size    HardFault_Handler, . - HardFault_Handler

                .thumb_func
                .type    Default_Handler, %function
                .weak    Default_Handler
                .fnstart
Default_Handler:
                b        .
                .fnend
                .size    Default_Handler, . - Default_Handler

/* Macro to define default exception/interrupt handlers.
 * Default handler are weak symbols with an endless loop.
 * They can be overwritten by real handlers.
 */
                .macro   Set_Default_Handler  Handler_Name
                .weak    \Handler_Name
                .set     \Handler_Name, Default_Handler
                .endm


/* Default exception/interrupt handler */

                Set_Default_Handler  NMI_Handler
                Set_Default_Handler  MemManage_Handler
                Set_Default_Handler  BusFault_Handler
                Set_Default_Handler  UsageFault_Handler
                Set_Default_Handler  SecureFault_Handler
                Set_Default_Handler  SVC_Handler
                Set_Default_Handler  DebugMon_Handler
                Set_Default_Handler  PendSV_Handler
                Set_Default_Handler  SysTick_Handler

                Set_Default_Handler  NONSEC_WATCHDOG_RESET_Handler
                Set_Default_Handler  NONSEC_WATCHDOG_Handler
                Set_Default_Handler  S32K_TIMER_Handler
                Set_Default_Handler  TIMER0_Handler
                Set_Default_Handler  TIMER1_Handler
                Set_Default_Handler  DUALTIMER_Handler
                Set_Default_Handler  MPC_Handler
                Set_Default_Handler  PPC_Handler
                Set_Default_Handler  MSC_Handler
                Set_Default_Handler  BRIDGE_ERROR_Handler

                Set_Default_Handler  UART0RX_Handler
                Set_Default_Handler  UART0TX_Handler
                Set_Default_Handler  UART1RX_Handler
                Set_Default_Handler  UART1TX_Handler
                Set_Default_Handler  UART2RX_Handler
                Set_Default_Handler  UART2TX_Handler
                Set_Default_Handler  UART3RX_Handler
                Set_Default_Handler  UART3TX_Handler
                Set_Default_Handler  UART4RX_Handler
                Set_Default_Handler  UART4TX_Handler
                Set_Default_Handler  UART0_Handler
                Set_Default_Handler  UART1_Handler
                Set_Default_Handler  UART2_Handler
                Set_Default_Handler  UART3_Handler
                Set_Default_Handler  UART4_Handler
                Set_Default_Handler  UARTOVF_Handler
                Set_Default_Handler  ETHERNET_Handler
                Set_Default_Handler  I2S_Handler
                Set_Default_Handler  TSC_Handler
                Set_Default_Handler  SPI0_Handler
                Set_Default_Handler  SPI1_Handler
                Set_Default_Handler  SPI2_Handler
                Set_Default_Handler  SPI3_Handler
                Set_Default_Handler  SPI4_Handler
                Set_Default_Handler  DMA0_ERROR_Handler
                Set_Default_Handler  DMA0_TC_Handler
                Set_Default_Handler  DMA0_Handler
                Set_Default_Handler  DMA1_ERROR_Handler
                Set_Default_Handler  DMA1_TC_Handler
                Set_Default_Handler  DMA1_Handler
                Set_Default_Handler  DMA2_ERROR_Handler
                Set_Default_Handler  DMA2_TC_Handler
                Set_Default_Handler  DMA2_Handler
                Set_Default_Handler  DMA3_ERROR_Handler
                Set_Default_Handler  DMA3_TC_Handler
                Set_Default_Handler  DMA3_Handler
                Set_Default_Handler  GPIO0_Handler
                Set_Default_Handler  GPIO1_Handler
                Set_Default_Handler  GPIO2_Handler
                Set_Default_Handler  GPIO3_Handler
                Set_Default_Handler  GPIO0_0_Handler
                Set_Default_Handler  GPIO0_1_Handler
                Set_Default_Handler  GPIO0_2_Handler
                Set_Default_Handler  GPIO0_3_Handler
                Set_Default_Handler  GPIO0_4_Handler
                Set_Default_Handler  GPIO0_5_Handler
                Set_Default_Handler  GPIO0_6_Handler
                Set_Default_Handler  GPIO0_7_Handler
                Set_Default_Handler  GPIO0_8_Handler
                Set_Default_Handler  GPIO0_9_Handler
                Set_Default_Handler  GPIO0_10_Handler
                Set_Default_Handler  GPIO0_11_Handler
                Set_Default_Handler  GPIO0_12_Handler
                Set_Default_Handler  GPIO0_13_Handler
                Set_Default_Handler  GPIO0_14_Handler
                Set_Default_Handler  GPIO0_15_Handler
                Set_Default_Handler  GPIO1_0_Handler
                Set_Default_Handler  GPIO1_1_Handler
                Set_Default_Handler  GPIO1_2_Handler
                Set_Default_Handler  GPIO1_3_Handler
                Set_Default_Handler  GPIO1_4_Handler
                Set_Default_Handler  GPIO1_5_Handler
                Set_Default_Handler  GPIO1_6_Handler
                Set_Default_Handler  GPIO1_7_Handler
                Set_Default_Handler  GPIO1_8_Handler
                Set_Default_Handler  GPIO1_9_Handler
                Set_Default_Handler  GPIO1_10_Handler
                Set_Default_Handler  GPIO1_11_Handler
                Set_Default_Handler  GPIO1_12_Handler
                Set_Default_Handler  GPIO1_13_Handler
                Set_Default_Handler  GPIO1_14_Handler
                Set_Default_Handler  GPIO1_15_Handler
                Set_Default_Handler  GPIO2_0_Handler
                Set_Default_Handler  GPIO2_1_Handler
                Set_Default_Handler  GPIO2_2_Handler
                Set_Default_Handler  GPIO2_3_Handler
                Set_Default_Handler  GPIO2_4_Handler
                Set_Default_Handler  GPIO2_5_Handler
                Set_Default_Handler  GPIO2_6_Handler
                Set_Default_Handler  GPIO2_7_Handler
                Set_Default_Handler  GPIO2_8_Handler
                Set_Default_Handler  GPIO2_9_Handler
                Set_Default_Handler  GPIO2_10_Handler
                Set_Default_Handler  GPIO2_11_Handler
                Set_Default_Handler  GPIO2_12_Handler
                Set_Default_Handler  GPIO2_13_Handler
                Set_Default_Handler  GPIO2_14_Handler
                Set_Default_Handler  GPIO2_15_Handler
                Set_Default_Handler  GPIO3_0_Handler
                Set_Default_Handler  GPIO3_1_Handler
                Set_Default_Handler  GPIO3_2_Handler
                Set_Default_Handler  GPIO3_3_Handler
#if defined (IOTKit_CM33_VHT) || defined (IOTKit_CM33_FP_VHT)
                Set_Default_Handler  ARM_VSI0_Handler
                Set_Default_Handler  ARM_VSI1_Handler
                Set_Default_Handler  ARM_VSI2_Handler
                Set_Default_Handler  ARM_VSI3_Handler
                Set_Default_Handler  ARM_VSI4_Handler
                Set_Default_Handler  ARM_VSI5_Handler
                Set_Default_Handler  ARM_VSI6_Handler
                Set_Default_Handler  ARM_VSI7_Handler
#endif

                .end
