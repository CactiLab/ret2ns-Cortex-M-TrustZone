/**
 * \file
 *
 * \brief TrustZone manager configuration header file.
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

#ifndef _TRUSTZONE_MANAGER_H_INCLUDED
#define _TRUSTZONE_MANAGER_H_INCLUDED

#include <trustzone_config.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief TrustZone Manager Initialization.
 */
static inline void trustzone_manager_init(void)
{
	/* Setup Port Security Attribution of I/O Pins */
	PORT_SEC->Group[0].NONSEC.reg = CONF_PORT_INIT_NONSEC0_VAL;

	/* Setup NVIC Interrupt Target Non-Secure state */
	NVIC->ITNS[0] = CONF_NVIC_INIT_ITNS0_VAL;
	NVIC->ITNS[1] = CONF_NVIC_INIT_ITNS1_VAL;
}

#ifdef __cplusplus
}
#endif

#endif // _TRUSTZONE_MANAGER_H_INCLUDED
