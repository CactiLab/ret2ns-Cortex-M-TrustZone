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


void ret2nw_ns();

#endif /* RET2NW_NS_H_ */