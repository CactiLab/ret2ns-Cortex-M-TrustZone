/*
 * ret2nw_ns.c
 *
 * Created: 5/23/2022 11:24:27 AM
 *  Author: andy2
 */ 

#include "ret2nw_ns.h"
#include "trustzone_veneer.h"

char user_input[] = "AAAA Hello World (ns)\r\n";

void print_in_s_handler(char* content);

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
	// stack contains: r0, r1, r2, r3, r12, r14, the return address and xPSR
	// extracts SVC number
	svc_number = ((char *) svc_args[6])[-2]; // Memory[(stacked_pc)-2]
	stacked_r0 = (char *) svc_args[0];
	switch (svc_number)
	{
		case 0:
		print_in_s_handler(stacked_r0);
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
}

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
	print_in_s_ns(user_input);
}