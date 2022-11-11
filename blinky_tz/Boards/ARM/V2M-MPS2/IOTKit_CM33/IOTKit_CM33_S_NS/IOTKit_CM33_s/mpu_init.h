#include <arm_cmse.h>
#include <stdio.h>
#include "IOTKit_CM33_FP.h" /* Device header */


void mpu_ns_init(void);

#define MPU_RO (1U)
#define MPU_RW (0U)
#define MPU_UP_ALLOWED (1U)
#define MPU_UP_BLOCK (0U)
#define MPU_NO_EXE (1U)
#define MPU_EXE (0U)