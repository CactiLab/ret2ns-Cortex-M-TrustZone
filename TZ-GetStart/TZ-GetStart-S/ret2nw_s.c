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
	chk_pointer(check_fp);
	driver_status = check_fp();
	if (driver_status == 0) {
		// do something...	
	}
	return;
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