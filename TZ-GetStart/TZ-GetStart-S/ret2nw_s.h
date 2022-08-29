/*
 * ret2nw_s.h
 *
 * Created: 5/23/2022 11:51:29 AM
 *  Author: andy2
 */ 


#ifndef RET2NW_S_H_
#define RET2NW_S_H_

#include <string.h>
#include "atmel_start.h"
#include "trustzone_veneer.h"

void print_s(char* input);
void print_and_chk_s(char* input);
void chk_pointer(void* pt);


#endif /* RET2NW_S_H_ */