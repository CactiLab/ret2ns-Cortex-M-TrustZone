/*
 * ret2nw_ns.h
 *
 * Created: 5/23/2022 11:23:15 AM
 *  Author: andy2
 */ 


#ifndef RET2NW_NS_H_
#define RET2NW_NS_H_


#define DROP_NS_PRIVILEGES __asm("msr CONTROL, %[reg] " ::[reg] "r"(1) \
: "memory")

#define SET_NS_PRIVILEGES __asm("msr CONTROL, %[reg] " ::[reg] "r"(0) \
: "memory")

void ret2nw_ns();
void ret2nw_2_ns();
void ret2nw_3_ns();

int get_driver_status();

#endif /* RET2NW_NS_H_ */