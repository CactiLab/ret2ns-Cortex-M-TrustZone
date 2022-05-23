/**
 * \file
 *
 * \brief TrustZone manager configuration implementation.
 *
 * Copyright (c) 2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#include <trustzone_config.h>

#if CONF_UROW_PROGRAMMING_ENABLE
#if defined(__GNUC__) && (__ARMCOMPILER_VERSION > 6000000) /*  Keil MDK with ARM Compiler 6 */
/* Use debug configuration file in Keil MDK to setup UROW programing */
/* const uint32_t nvm_user_row[] __attribute__((used)) __attribute__((section(".userrowsec"))) = */
const uint32_t nvm_user_row[] =
#elif defined(__GNUC__)   /* GCC */
/* "userrowsec" section should be correctly defined in your linker file */
__attribute__((section(".userrowsec"))) const uint32_t nvm_user_row[] =
#elif defined(__ICCARM__) /* IAR EWARM */
/* "nvm_user_page" section should be correctly defined in your linker file */
__root const uint32_t nvm_user_row[] @ ".nvm_user_page" =
#else
#warning "This IDE can't support USER Row fuse programming."
#endif
#else
const uint32_t nvm_user_row[] =
#endif
    {
        NVM_USER_WORD_0,
        NVM_USER_WORD_1,
        NVM_USER_WORD_2,
        NVM_USER_WORD_3,
        NVM_USER_WORD_4,
        NVM_USER_WORD_5,
        NVM_USER_WORD_6,
        0 /* reserved for CRC */
    };
