#ifndef ATMEL_START_H_INCLUDED
#define ATMEL_START_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "driver_init.h"
#include "trustzone/trustzone_manager.h"

/**
 * Initializes MCU, drivers and middleware in the project
 **/
void atmel_start_init(void);
void mpu_ns_init(void);
void check_pointer(void);

#define MPU_RO (1U)
#define MPU_RW (0U)
#define MPU_UP_ALLOWED (1U)
#define MPU_UP_BLOCK (0U)
#define MPU_NO_EXE (1U)
#define MPU_EXE (0U)

#ifdef __cplusplus
}
#endif
#endif
