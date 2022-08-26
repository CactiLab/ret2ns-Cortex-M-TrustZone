/**
 * \file
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

#include "atmel_start.h"
#include "trustzone_config.h"

/** Typedef for non-secure callback functions */
typedef void (*funcptr_void)(void) __attribute__((cmse_nonsecure_call));

/*
 * The Secure Application:
 * - Initializes MCU, drivers and middleware
 * - Sets the non-secure main stack (MSP_NS)
 * - Gets the non-secure reset handler
 * - Jumps to the non-secure software application
 */
int main(void)
{
	funcptr_void NonSecure_ResetHandler;

	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	mpu_ns_init();

	/* Set non-secure main stack (MSP_NS) */
	__TZ_set_MSP_NS(*((uint32_t *)(CONF_TZ_START_NS)));

	/* Get non-secure reset handler */
	NonSecure_ResetHandler = (funcptr_void)(*((uint32_t *)((CONF_TZ_START_NS) + 4U)));
	check_pointer();
	/* Start non-secure state software application */
	NonSecure_ResetHandler();

	/* Replace with your application code */
	while (1) {
		__NOP();
	}
}
