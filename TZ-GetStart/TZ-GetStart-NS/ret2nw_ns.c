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

void SVC_Handler_Main(unsigned int *svc_args)
{
	uint32_t svc_number = 1;
	// stack contains: r0, r1, r2, r3, r12, r14, the return address and xPSR
	svc_number = ((char *)svc_args[6])[-2];
	switch (svc_number)
	{
		case 0:
		print_in_s_handler((char *)svc_args[0]);
		break;
		default:
		break;
	}
}

void SVC_Handler(void)
{
	__asm volatile(
	"mov r0, lr\n\t"
	"mov r1, sp\n\t"
	"b      SVC_Handler_Main; ");
	/*
	__asm volatile(
	  "TST    LR, #0b0100;      "
	  "ITE    EQ;               "
	  "MRSEQ  R0, MSP;          "
	  "MRSNE  R0, PSP;          "
	  "MOV    R1, LR;           "
	  "B      SVC_Handler_Main;  ");*/
}

void print_in_s_handler(char* content)
{
	print_nsc(content);
}

void print_in_s_ns(char* user_str)
{
	__asm volatile (
		"ldr r0, [sp, #0];"
		"svc #0;"
	);
}

void ret2nw_ns()
{
	DROP_NS_PRIVILEGES;
	print_in_s_ns(user_input);
}