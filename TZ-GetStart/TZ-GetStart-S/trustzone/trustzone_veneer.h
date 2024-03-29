/**
 * \file
 *
 * \brief TrustZone secure gateway veneer header file.
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

#ifndef _TRUSTZONE_VENEER_H_INCLUDED
#define _TRUSTZONE_VENEER_H_INCLUDED

#include <compiler.h>

void __attribute__((naked)) chk_bxns();
void chk_pt();
/* ======== Non-secure callable functions defined by customer ======== */
/* Add your function declaration here */

extern void print_nsc(char* content);
extern void print_chk_nsc(char* content);

/* ======== Secure callable functions initialization ======== */

typedef int __attribute__((cmse_nonsecure_call)) tdef_nsfunc_o_int_i_void(void);
extern int pass_nsfunc_ptr_o_int_i_void(tdef_nsfunc_o_int_i_void *callback);
tdef_nsfunc_o_int_i_void *fp;

#endif /* _TRUSTZONE_VENEER_H_INCLUDED */
