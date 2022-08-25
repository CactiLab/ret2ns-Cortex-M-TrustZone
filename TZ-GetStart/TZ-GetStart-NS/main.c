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
#include "arm_cmse.h"
#include "trustzone_veneer.h"
#include "ret2nw_ns.h"

volatile int gs_val[2];

void check_pointer_ns(void)
{
	void *p1 = (void *)0x8320;
	cmse_address_info_t result1 = cmse_TT(p1);
	
	void *p2 = (void *)0x8394;
	cmse_address_info_t result2 = cmse_TT(p2);
	
	void *p3 = (void *)0x8420;
	cmse_address_info_t result3 = cmse_TT(p3);
	
	while (1) {}
}
/* Non-secure main() */
int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	check_pointer_ns();
	int status;
	status = pass_nsfunc_ptr_o_int_i_void(&get_driver_status);
	
	if (status!=0) {
		__BKPT(0);
		while(1);
	}
	
// 	DROP_NS_PRIVILEGES;
	ret2nw_ns();
// 	ret2nw_2_ns();
// 	ret2nw_3_ns();
// 	ret2nw_4_ns();
	
	/* Call non-secure callable function 1 */
	gs_val[0] = nsc_func_plus3(1);

	/* Call non-secure callable function 2 */
	gs_val[1] = nsc_func_minus2(7);

	/* Replace with your application code */
	while (1) {
		__NOP();
	}
}
