/**
 * \file
 *
 * \brief TrustZone secure gateway veneer implementation.
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
#include "trustzone_veneer.h"
#include "trustzone_config.h"

/* ======== Non-secure callable functions defined by customer ======== */
/*
 * You may add your secure gateway veneer functions in this file
 * and the function declaration into trustzone_veneer.h.
 */

#include "ret2nw_s.h"

/*
 * \brief Non-secure callable function print_nsc
 */
#if defined(__ICCARM__) /* IAR EWARM */
__cmse_nonsecure_entry void print_nsc(char* content)
#else /* GCC, Keil MDK with ARM Compiler 6 */
void __attribute__((cmse_nonsecure_entry)) print_nsc(char* content)
#endif
{
	print_s(content);
	chk_bxns();
}

void __attribute__((naked)) chk_bxns()
{
	__ASM volatile(
	".syntax unified\n\t"
	".thumb\n\t"
		"ldr r1, [sp, #12]\n\t"
		"push {lr}\n\t"
		"mrs r3, ipsr\n\t"
		"cbnz r3, 1f\n\t"
		"mrs r3, control_ns\n\t"
		"mov r2, #1\n\t"
		"ands r3, r2\n\t"
		"cbnz r3, 2f\n\t"
	"1:\n\t"
		"tta r1, r1\n\t"
		"movw r3, #0\n\t"
		"movt r3, #1\n\t"
		"ands r3, r1\n\t"
		"cbz r3, 2f\n\t"
		"movw r3, #60816\n\t"
		"movt r3, #57346\n\t"
		"mov r2, #255\n\t"
		"ands r2, r1\n\t"
		"str r2, [r3, #8]\n\t"
		"ldr r3, [r3, #12]\n\t"
		"mov r2, #2\n\t"
		"ands r3, r2\n\t"
		"cbz r3, 2f\n\t"
		"b HardFault_Handler\n\t"
	"2:\n\t"
		"pop {pc}\n\t"
	);
}

void chk_pt()
{
	void* pt;
	__ASM(
		"mov %0, r1\n\t"
		: "=r" (pt)
	);
	if (__get_IPSR() || !(__TZ_get_CONTROL_NS() & 0b01))
	{
		cmse_address_info_t tt_payload = cmse_TTA(pt);
		if (tt_payload.flags.mpu_region_valid)
		{
			MPU_NS->RNR = tt_payload.flags.mpu_region;
			if (MPU_NS->RBAR & 0b10)  /* UP read access */
			{
				/* ERROR Handling */
				HardFault_Handler();
			}
		}
	}
}

/*
 * \brief Non-secure callable function print_chk_nsc
 */
#if defined(__ICCARM__) /* IAR EWARM */
__cmse_nonsecure_entry void print_chk_nsc(char* content)
#else /* GCC, Keil MDK with ARM Compiler 6 */
void __attribute__((cmse_nonsecure_entry)) print_chk_nsc(char* content)
#endif
{
	return print_and_chk_s(content);
}


/* ======== Secure callable functions initialization ======== */

void default_callback(void);
void default_callback(void) {
	__BKPT(0);
	while(1);
}

/*
 * Declare function pointer *fp
 * fp can point to either a secure or a non-secure function
 * Initialized to a default callback
*/
tdef_nsfunc_o_int_i_void *fp = (tdef_nsfunc_o_int_i_void *) default_callback;

// This is a Secure API with a function pointer as an input parameter
#if defined(__ICCARM__) /* IAR EWARM */
__cmse_nonsecure_entry int pass_nsfunc_ptr_o_int_i_void(tdef_nsfunc_o_int_i_void *callback)
#else /* GCC, Keil MDK with ARM Compiler 6 */
int __attribute__((cmse_nonsecure_entry)) pass_nsfunc_ptr_o_int_i_void(tdef_nsfunc_o_int_i_void *callback)
#endif
{
	// Result for the function pointer
	cmse_address_info_t tt_payload;
	tt_payload = cmse_TTA_fptr(callback);
	if (tt_payload.flags.nonsecure_read_ok) {
		fp = cmse_nsfptr_create(callback); // Non-secure function pointer
// 		fp();
		return (0);
	} else {
		return (1); // Function pointer is not accessible from the Non-secure side
	}
}