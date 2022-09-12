/*
 * ret2nw_s.c
 *
 * Created: 5/23/2022 11:51:47 AM
 *  Author: andy2
 */ 

#include "ret2nw_s.h"


void print_s(char* input)
{
	char buf[4];
	memcpy(buf, input, 28);
	return;
}

typedef int __attribute__((cmse_nonsecure_call)) chk_func_ptr(void);
void print_and_chk_s(char* input)
{
	int driver_status;
	chk_func_ptr *check_fp;
	check_fp = cmse_nsfptr_create(fp);
 	char buf[4];
 	memcpy(buf, input, 12);
	chk_blxns(check_fp);
	driver_status = check_fp();
	if (driver_status == 0) {
		// do something...	
	}
	return;
}

void __attribute__((naked)) chk_blxns(void* pt)
{
	__ASM volatile(
	".syntax unified\n\t"
	".thumb\n\t"
		"push {lr}\n\t"
		"mrs r3, ipsr\n\t"
		"cbnz r3, 1f\n\t"
		"mrs r3, control_ns\n\t"
		"mov r2, #1\n\t"
		"ands r3, r2\n\t"
		"cbnz r3, 2f\n\t"
	"1:\n\t"
		"tta r1, r0\n\t"
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

void chk_pointer(void* pt)
{
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