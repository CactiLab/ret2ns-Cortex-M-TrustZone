#include "mpu_init.h"

void mpu_ns_init(void)
{
	__DMB();
	
	ARM_MPU_Disable_NS();      /* Disable MPU */
	uint32_t dregion = (MPU->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;     /* Check number of supported MPU regions */
	
	int8_t mem_attr = ARM_MPU_ATTR(ARM_MPU_ATTR_NON_CACHEABLE, ARM_MPU_ATTR_NON_CACHEABLE);
	ARM_MPU_SetMemAttr_NS(0, mem_attr);
	
	uint32_t rbar = ARM_MPU_RBAR(0x20000000, ARM_MPU_SH_NON, MPU_RW, MPU_UP_ALLOWED, MPU_NO_EXE);
	uint32_t rlar = ARM_MPU_RLAR(0x3FFFFFFF, 0);
	ARM_MPU_SetRegion_NS(0, rbar, rlar);
	
// 	rbar = ARM_MPU_RBAR(0x00210000, ARM_MPU_SH_NON, MPU_RO, MPU_UP_BLOCK, MPU_EXE);
// 	rlar = ARM_MPU_RLAR(0x00230000, 0);
// 	ARM_MPU_SetRegion_NS(1, rbar, rlar);
	
	rbar = ARM_MPU_RBAR(0x00200000, ARM_MPU_SH_NON, MPU_RO, MPU_UP_ALLOWED, MPU_EXE);
	rlar = ARM_MPU_RLAR(0x0020a000, 0);
	ARM_MPU_SetRegion_NS(1, rbar, rlar);
	
	for (uint32_t i=2; i < dregion; i++)
	{
		ARM_MPU_ClrRegion_NS(i);
	}
	
	/* Enable MPU and the default memory map as a background region (acts as region number -1) for privileged access only (MPU_CTRL.PRIVDEFENA). */
	ARM_MPU_Enable_NS(5);
	
	__DSB();
	__ISB();
}
