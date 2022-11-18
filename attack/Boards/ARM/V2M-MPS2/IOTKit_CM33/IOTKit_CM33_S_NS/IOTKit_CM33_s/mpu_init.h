#include <arm_cmse.h>
#include <stdio.h>
#include "IOTKit_CM33_FP.h" /* Device header */

#define __ROM_BASE      0x00200000
#define __UPRIV_BASE    ( __ROM_BASE + 0x10000 )
#define __UPRIV_END     ( __UPRIV_BASE + 0x20000 )

void mpu_ns_init(void);

#define MPU_RO (1U)
#define MPU_RW (0U)
#define MPU_UP_ALLOWED (1U)
#define MPU_UP_BLOCK (0U)
#define MPU_NO_EXE (1U)
#define MPU_EXE (0U)