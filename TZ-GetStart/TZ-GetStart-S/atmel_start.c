#include <atmel_start.h>

/**
 * Initializes MCU, drivers and middleware in the project
 **/
void atmel_start_init(void)
{
	system_init();
	trustzone_manager_init();
}

void mpu_ns_init(void)
{
	__DMB();
	
	ARM_MPU_Disable_NS();      /* Disable MPU */
	uint32_t dregion = (MPU->TYPE & MPU_TYPE_DREGION_Msk) >> MPU_TYPE_DREGION_Pos;     /* Check number of supported MPU regions */
	
	int8_t mem_attr = ARM_MPU_ATTR(ARM_MPU_ATTR_NON_CACHEABLE, ARM_MPU_ATTR_NON_CACHEABLE);
	ARM_MPU_SetMemAttr_NS(0, mem_attr);
	
	uint32_t rbar = ARM_MPU_RBAR(0x8300, ARM_MPU_SH_NON, MPU_RO, MPU_UP_ALLOWED, MPU_EXE);
	uint32_t rlar = ARM_MPU_RLAR(0x8380, 0);
	ARM_MPU_SetRegion_NS(0, rbar, rlar);
	
	rbar = ARM_MPU_RBAR(0x8460, ARM_MPU_SH_NON, MPU_RO, MPU_UP_ALLOWED, MPU_EXE);
	rlar = ARM_MPU_RLAR(0x84a0, 0);
	ARM_MPU_SetRegion_NS(1, rbar, rlar);
	
	rbar = ARM_MPU_RBAR(0x20000000, ARM_MPU_SH_NON, MPU_RW, MPU_UP_ALLOWED, MPU_NO_EXE);
	rlar = ARM_MPU_RLAR(0x3FFFFFFF, 0);
	ARM_MPU_SetRegion_NS(2, rbar, rlar);
	
	for (uint32_t i=2; i < dregion; i++)
	{
		ARM_MPU_ClrRegion_NS(i);
	}
	
	/* Enable MPU and the default memory map as a background region (acts as region number -1) for privileged access only (MPU_CTRL.PRIVDEFENA). */
	ARM_MPU_Enable_NS(5);
	
	__DSB();
	__ISB();
}

void check_pointer(void)
{
	void *p1 = (void *)0x82f0;
	cmse_address_info_t result1 = cmse_TTA(p1);
	
	void *p2 = (void *)0x8350;
	cmse_address_info_t result2 = cmse_TTA(p2);
	
	void *p3 = (void *)0x8460;
	cmse_address_info_t result3 = cmse_TTA(p3);
	
	while (1) {}
}