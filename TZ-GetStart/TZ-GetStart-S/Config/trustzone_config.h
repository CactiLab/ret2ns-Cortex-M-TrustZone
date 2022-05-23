/* Auto-generated config file trustzone_config.h */
#ifndef TRUSTZONE_CONFIG_H
#define TRUSTZONE_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

/**
 * \file
 *
 * \brief TrustZone manager configuration header file.
 *
 * Copyright (c) 2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

/*
 * Configuration for TrustZone settings, which are included in
 * NVM User Row (UROW) and NVM Boot Configuration Row (BOCOR).
 */

#include <compiler.h>
#include <utils_assert.h>

#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U))
#include <arm_cmse.h>
#endif

// =========  TrustZone settings in User Row (UROW) =========

// <h> User Row (UROW)

// <o> Enable UROW fuse programming
// <i> Enable user row fuse programming when debugging code in IDE.
// <i> Note: Only enable this option when your IDE supports this feature.
// <0=>Disable
// <1=>Enable
// <id> urow_fuse_programming_enable
#ifndef CONF_UROW_PROGRAMMING_ENABLE
#define CONF_UROW_PROGRAMMING_ENABLE 1
#endif

// <h> User Row (UROW) - TrustZone related

// <o> USER_WORD_2.IDAU_AS <0x0-0xFF>
// <i> Flash Application Secure Size = AS*0x100
// <id> urow_idau_as
#ifndef CONF_UROW_IDAU_AS
#define CONF_UROW_IDAU_AS 0x80
#endif

// <o> USER_WORD_2.IDAU_ANSC <0x0-0x3F>
// <i> Flash Application Non-Secure Callable Size = ANSC*0x20
// <id> urow_idau_ansc
#ifndef CONF_UROW_IDAU_ANSC
#define CONF_UROW_IDAU_ANSC 0x20
#endif

// <o> USER_WORD_2.IDAU_DS <0x0-0xF>
// <i> DATA Flash Secure Size = DS*0x100
// <id> urow_idau_ds
#ifndef CONF_UROW_IDAU_DS
#define CONF_UROW_IDAU_DS 0x8
#endif

// <o> USER_WORD_2.IDAU_RS <0x0-0x7F>
// <i> RAM Secure Size = RS*0x80
// <id> urow_idau_rs
#ifndef CONF_UROW_IDAU_RS
#define CONF_UROW_IDAU_RS 0x40
#endif

// PAC: The PAC Peripheral is always secured regardless of its bit value
#ifndef CONF_UROW_BOOTROM_NONSECA_PAC
#define CONF_UROW_BOOTROM_NONSECA_PAC 0
#endif

// <q> USER_WORD_4.NONSECA.PM
// <i> PM: Peripheral PM Non-Secure
// <id> urow_bootrom_nonseca_pm
#ifndef CONF_UROW_BOOTROM_NONSECA_PM
#define CONF_UROW_BOOTROM_NONSECA_PM 0
#endif

// <q> USER_WORD_4.NONSECA.MCLK
// <i> MCLK: Peripheral MCLK Non-Secure
// <id> urow_bootrom_nonseca_mclk
#ifndef CONF_UROW_BOOTROM_NONSECA_MCLK
#define CONF_UROW_BOOTROM_NONSECA_MCLK 0
#endif

// <q> USER_WORD_4.NONSECA.RSTC
// <i> RSTC: Peripheral RSTC Non-Secure
// <id> urow_bootrom_nonseca_rstc
#ifndef CONF_UROW_BOOTROM_NONSECA_RSTC
#define CONF_UROW_BOOTROM_NONSECA_RSTC 0
#endif

// <q> USER_WORD_4.NONSECA.OSCCTRL
// <i> OSCCTRL: Peripheral OSCCTRL Non-Secure
// <id> urow_bootrom_nonseca_oscctrl
#ifndef CONF_UROW_BOOTROM_NONSECA_OSCCTRL
#define CONF_UROW_BOOTROM_NONSECA_OSCCTRL 0
#endif

// <q> USER_WORD_4.NONSECA.OSC32KCTRL
// <i> OSC32KCTRL: Peripheral OSC32KCTRL Non-Secure
// <id> urow_bootrom_nonseca_osc32kctrl
#ifndef CONF_UROW_BOOTROM_NONSECA_OSC32KCTRL
#define CONF_UROW_BOOTROM_NONSECA_OSC32KCTRL 0
#endif

// <q> USER_WORD_4.NONSECA.SUPC
// <i> SUPC: Peripheral SUPC Non-Secure
// <id> urow_bootrom_nonseca_supc
#ifndef CONF_UROW_BOOTROM_NONSECA_SUPC
#define CONF_UROW_BOOTROM_NONSECA_SUPC 0
#endif

// <q> USER_WORD_4.NONSECA.GCLK
// <i> GCLK: Peripheral GCLK Non-Secure
// <id> urow_bootrom_nonseca_gclk
#ifndef CONF_UROW_BOOTROM_NONSECA_GCLK
#define CONF_UROW_BOOTROM_NONSECA_GCLK 0
#endif

// <q> USER_WORD_4.NONSECA.WDT
// <i> WDT: Peripheral WDT Non-Secure
// <id> urow_bootrom_nonseca_wdt
#ifndef CONF_UROW_BOOTROM_NONSECA_WDT
#define CONF_UROW_BOOTROM_NONSECA_WDT 0
#endif

// <q> USER_WORD_4.NONSECA.RTC
// <i> RTC: Peripheral RTC Non-Secure
// <id> urow_bootrom_nonseca_rtc
#ifndef CONF_UROW_BOOTROM_NONSECA_RTC
#define CONF_UROW_BOOTROM_NONSECA_RTC 0
#endif

// <q> USER_WORD_4.NONSECA.EIC
// <i> EIC: Peripheral EIC Non-Secure
// <id> urow_bootrom_nonseca_eic
#ifndef CONF_UROW_BOOTROM_NONSECA_EIC
#define CONF_UROW_BOOTROM_NONSECA_EIC 0
#endif

// <q> USER_WORD_4.NONSECA.FREQM
// <i> FREQM: Peripheral FREQM Non-Secure
// <id> urow_bootrom_nonseca_freqm
#ifndef CONF_UROW_BOOTROM_NONSECA_FREQM
#define CONF_UROW_BOOTROM_NONSECA_FREQM 0
#endif

// <q> USER_WORD_4.NONSECA.PORT
// <i> PORT: Peripheral PORT Non-Secure
// <id> urow_bootrom_nonseca_port
#ifndef CONF_UROW_BOOTROM_NONSECA_PORT
#define CONF_UROW_BOOTROM_NONSECA_PORT 0
#endif

// <q> USER_WORD_4.NONSECA.AC
// <i> AC: Peripheral AC Non-Secure
// <id> urow_bootrom_nonseca_ac
#ifndef CONF_UROW_BOOTROM_NONSECA_AC
#define CONF_UROW_BOOTROM_NONSECA_AC 0
#endif

// The IDAU peripheral is always secured regardless of their bit values.
#ifndef CONF_UROW_BOOTROM_NONSECB_IDAU
#define CONF_UROW_BOOTROM_NONSECB_IDAU 0
#endif

// The DSU peripheral is always non-secured regardless of its bit value.
#ifndef CONF_UROW_BOOTROM_NONSECB_DSU
#define CONF_UROW_BOOTROM_NONSECB_DSU 0
#endif

// The NVMCTRL peripheral is always secured regardless of their bit values.
#ifndef CONF_UROW_BOOTROM_NONSECB_NVMCTRL
#define CONF_UROW_BOOTROM_NONSECB_NVMCTRL 0
#endif

// <q> USER_WORD_5.NONSECB.DMAC
// <i> DMAC: Peripheral DMAC Non-Secure
// <id> urow_bootrom_nonsecb_dmac
#ifndef CONF_UROW_BOOTROM_NONSECB_DMAC
#define CONF_UROW_BOOTROM_NONSECB_DMAC 0
#endif

// <q> USER_WORD_5.NONSECB.HMATRIXHS
// <i> HMATRIXHS: Peripheral HMATRIXHS Non-Secure
// <id> urow_bootrom_nonsecb_hmatrixhs
#ifndef CONF_UROW_BOOTROM_NONSECB_HMATRIXHS
#define CONF_UROW_BOOTROM_NONSECB_HMATRIXHS 0
#endif

// <q> USER_WORD_6.NONSECC.EVSYS
// <i>  EVSYS: Peripheral EVSYS Non-Secure
// <id> urow_bootrom_nonsecc_evsys
#ifndef CONF_UROW_BOOTROM_NONSECC_EVSYS
#define CONF_UROW_BOOTROM_NONSECC_EVSYS 0
#endif

// <q> USER_WORD_6.NONSECC.SERCOM0
// <i>  SERCOM0: Peripheral SERCOM0 Non-Secure
// <id> urow_bootrom_nonsecc_sercom0
#ifndef CONF_UROW_BOOTROM_NONSECC_SERCOM0
#define CONF_UROW_BOOTROM_NONSECC_SERCOM0 0
#endif

// <q> USER_WORD_6.NONSECC.SERCOM1
// <i>  SERCOM1: Peripheral SERCOM1 Non-Secure
// <id> urow_bootrom_nonsecc_sercom1
#ifndef CONF_UROW_BOOTROM_NONSECC_SERCOM1
#define CONF_UROW_BOOTROM_NONSECC_SERCOM1 0
#endif

// <q> USER_WORD_6.NONSECC.SERCOM2
// <i>  SERCOM2: Peripheral SERCOM2 Non-Secure
// <id> urow_bootrom_nonsecc_sercom2
#ifndef CONF_UROW_BOOTROM_NONSECC_SERCOM2
#define CONF_UROW_BOOTROM_NONSECC_SERCOM2 0
#endif

// <q> USER_WORD_6.NONSECC.TC0
// <i>  TC0: Peripheral TC0 Non-Secure
// <id> urow_bootrom_nonsecc_tc0
#ifndef CONF_UROW_BOOTROM_NONSECC_TC0
#define CONF_UROW_BOOTROM_NONSECC_TC0 0
#endif

// <q> USER_WORD_6.NONSECC.TC1
// <i>  TC1: Peripheral TC1 Non-Secure
// <id> urow_bootrom_nonsecc_tc1
#ifndef CONF_UROW_BOOTROM_NONSECC_TC1
#define CONF_UROW_BOOTROM_NONSECC_TC1 0
#endif

// <q> USER_WORD_6.NONSECC.TC2
// <i>  TC2: Peripheral TC2 Non-Secure
// <id> urow_bootrom_nonsecc_tc2
#ifndef CONF_UROW_BOOTROM_NONSECC_TC2
#define CONF_UROW_BOOTROM_NONSECC_TC2 0
#endif

// <q> USER_WORD_6.NONSECC.ADC
// <i>  ADC: Peripheral ADC Non-Secure
// <id> urow_bootrom_nonsecc_adc
#ifndef CONF_UROW_BOOTROM_NONSECC_ADC
#define CONF_UROW_BOOTROM_NONSECC_ADC 0
#endif

// <q> USER_WORD_6.NONSECC.DAC
// <i>  DAC: Peripheral DAC Non-Secure
// <id> urow_bootrom_nonsecc_dac
#ifndef CONF_UROW_BOOTROM_NONSECC_DAC
#define CONF_UROW_BOOTROM_NONSECC_DAC 0
#endif

// <q> USER_WORD_6.NONSECC.PTC
// <i>  PTC: Peripheral PTC Non-Secure
// <id> urow_bootrom_nonsecc_ptc
#ifndef CONF_UROW_BOOTROM_NONSECC_PTC
#define CONF_UROW_BOOTROM_NONSECC_PTC 0
#endif

// <q> USER_WORD_6.NONSECC.TRNG
// <i>  TRNG: Peripheral TRNG Non-Secure
// <id> urow_bootrom_nonsecc_trng
#ifndef CONF_UROW_BOOTROM_NONSECC_TRNG
#define CONF_UROW_BOOTROM_NONSECC_TRNG 0
#endif

// <q> USER_WORD_6.NONSECC.CCL
// <i>  CCL: Peripheral CCL Non-Secure
// <id> urow_bootrom_nonsecc_ccl
#ifndef CONF_UROW_BOOTROM_NONSECC_CCL
#define CONF_UROW_BOOTROM_NONSECC_CCL 0
#endif

// <q> USER_WORD_6.NONSECC.OPAMP
// <i>  OPAMP: Peripheral OPAMP Non-Secure
// <id> urow_bootrom_nonsecc_opamp
#ifndef CONF_UROW_BOOTROM_NONSECC_OPAMP
#define CONF_UROW_BOOTROM_NONSECC_OPAMP 0
#endif

// <q> USER_WORD_6.NONSECC.TRAM
// <i>  TRAM: Peripheral TRAM Non-Secure
// <id> urow_bootrom_nonsecc_tram
#ifndef CONF_UROW_BOOTROM_NONSECC_TRAM
#define CONF_UROW_BOOTROM_NONSECC_TRAM 0
#endif

// </h>

// <e> User Row (UROW) - TrustZone not related
// <id> urow_non_trustzone_setting_enable
#ifndef UROW_NON_TRUSTZONE_SETTING_ENABLE
#define UROW_NON_TRUSTZONE_SETTING_ENABLE 0
#endif

// <o> USER_WORD_0.NVMCTRL_SULCK <0x0-0x07>
// <i> NVM Secure Region UnLock Bits
// <id> urow_nvmctrl_sulck
#ifndef CONF_UROW_NVMCTRL_SULCK
#define CONF_UROW_NVMCTRL_SULCK 0x7
#endif

// <o> USER_WORD_0.NVMCTRL_NSULCK <0x0-0x07>
// <i> NVM Non-Secure Region UnLock Bits
// <id> urow_nvmctrl_nsulck
#ifndef CONF_UROW_NVMCTRL_NSULCK
#define CONF_UROW_NVMCTRL_NSULCK 0x7
#endif

// <o> USER_WORD_0.BOD33USERLEVEL <0x0-0x3F>
// <i> BOD33 threshold level at power-on
// <id> urow_bod33userlevel
#ifndef CONF_UROW_BOD33USERLEVEL
#define CONF_UROW_BOD33USERLEVEL 0x6
#endif

// <q> USER_WORD_0.BOD33_DIS
// <i> BOD33 Disable at power-on
// <id> urow_nvmctrl_bod33_dis
#ifndef CONF_UROW_NVMCTRL_BOD33_DIS
#define CONF_UROW_NVMCTRL_BOD33_DIS 0
#endif

// <o> USER_WORD_0.BOD33_ACTION <0x0-0x3>
// <i> BOD33 Action at power-on
// <id> urow_bod33_action
#ifndef CONF_UROW_BOD33_ACTION
#define CONF_UROW_BOD33_ACTION 0x1
#endif

// <q> USER_WORD_0.WDT_RUNSTDBY
// <i> WDT Runstdby at power-on
// <id> urow_wdt_runstdby
#ifndef CONF_UROW_WDT_RUNSTDBY
#define CONF_UROW_WDT_RUNSTDBY 0
#endif

// <q> USER_WORD_0.WDT_ENABLE
// <i> WDT Enable at power-on
// <id> urow_wdt_enable
#ifndef CONF_UROW_WDT_ENABLE
#define CONF_UROW_WDT_ENABLE 0
#endif

// <q> USER_WORD_0.WDT_ALWAYSON
// <i> WDT Always-On at power-on
// <id> urow_wdt_alwayson
#ifndef CONF_UROW_WDT_ALWAYSON
#define CONF_UROW_WDT_ALWAYSON 0
#endif

// <o> USER_WORD_0.WDT_PER <0x0-0xF>
// <i> WDT Period at power-on
// <id> urow_wdt_per
#ifndef CONF_UROW_WDT_PER
#define CONF_UROW_WDT_PER 0xb
#endif

// <o> USER_WORD_1.WDT_WINDOW <0x0-0xF>
// <i> WDT Window mode time-out at power-on
// <id> urow_wdt_window
#ifndef CONF_UROW_WDT_WINDOW
#define CONF_UROW_WDT_WINDOW 0xb
#endif

// <o> USER_WORD_1.WDT_EWOFFSET <0x0-0xF>
// <i> WDT Early Warning Interrupt Time Offset at power-on
// <id> urow_wdt_ewoffset
#ifndef CONF_UROW_WDT_EWOFFSET
#define CONF_UROW_WDT_EWOFFSET 0xb
#endif

// <q> USER_WORD_1.WDT_WEN
// <i> WDT Timer Window Mode Enable at power-on
// <id> urow_wdt_wen
#ifndef CONF_UROW_WDT_WEN
#define CONF_UROW_WDT_WEN 0
#endif

// <q> USER_WORD_1.BOD33_HYST
// <i> BOD33 Hysteresis configuration at power-on
// <id> urow_bod33_hyst
#ifndef CONF_UROW_BOD33_HYST
#define CONF_UROW_BOD33_HYST 0
#endif

// <q> USER_WORD_1.BOOTROM_RXN
// <i> RAM is eXecute Never
// <id> urow_bootrom_rxn
#ifndef CONF_UROW_BOOTROM_RXN
#define CONF_UROW_BOOTROM_RXN 1
#endif

// <q> USER_WORD_1.BOOTROM_DXN
// <i> DATA Flash is eXecute Never
// <id> urow_bootrom_dxn
#ifndef CONF_UROW_BOOTROM_DXN
#define CONF_UROW_BOOTROM_DXN 1
#endif

// <q> USER_WORD_3.NVMCTRL_URWEN
// <i> User Row Write Enable
// <id> urow_nvmctrl_urwen
#ifndef CONF_UROW_NVMCTRL_URWEN
#define CONF_UROW_NVMCTRL_URWEN 1
#endif

// </e>

/*
 * NVM_USER_WORD_X: User Row (UROW) Word X definitions
 */
/* WORD0: BOD, Watchdog and Misc settings */
#define NVM_USER_WORD_0                                                                                                \
	(NVMCTRL_FUSES_SULCK(CONF_UROW_NVMCTRL_SULCK) | NVMCTRL_FUSES_NSULCK(CONF_UROW_NVMCTRL_NSULCK)                     \
	 | FUSES_BOD33USERLEVEL(CONF_UROW_BOD33USERLEVEL) | (CONF_UROW_NVMCTRL_BOD33_DIS << FUSES_BOD33_DIS_Pos)           \
	 | FUSES_BOD33_ACTION(CONF_UROW_BOD33_ACTION)                                                                      \
	 | 0x8FU << 16 /* BOD12 Calib */ | (CONF_UROW_WDT_ENABLE << WDT_FUSES_ENABLE_Pos)                                  \
	 | (CONF_UROW_WDT_ALWAYSON << WDT_FUSES_ALWAYSON_Pos) | ((uint32_t)(CONF_UROW_WDT_PER) << WDT_FUSES_PER_Pos))

/* WORD1: Watchdog and Misc settings */
#define NVM_USER_WORD_1                                                                                                \
	(WDT_FUSES_WINDOW(CONF_UROW_WDT_WINDOW) | WDT_FUSES_EWOFFSET(CONF_UROW_WDT_EWOFFSET)                               \
	 | (CONF_UROW_WDT_WEN << WDT_FUSES_ENABLE_Pos) | (CONF_UROW_BOD33_HYST << FUSES_BOD33_HYST_Pos)                    \
	 | (CONF_UROW_BOOTROM_RXN << FUSES_BOOTROM_RXN_Pos) | (CONF_UROW_BOOTROM_DXN << FUSES_BOOTROM_DXN_Pos))

/* WORD2: Memories Security Attribution: AS, ANSC, RS */
#define NVM_USER_WORD_2                                                                                                \
	((CONF_UROW_IDAU_AS << (64 % 32)) | (CONF_UROW_IDAU_ANSC << (72 % 32)) | (CONF_UROW_IDAU_DS << (80 % 32))          \
	 | (CONF_UROW_IDAU_RS << (88 % 32)))

/* WORD3: User Row Write Enable */
#define NVM_USER_WORD_3 (CONF_UROW_NVMCTRL_URWEN << NVMCTRL_FUSES_URWEN_Pos)

/* WORD4: Peripherals Security Attribution Bridge A (NONSECA) */
#define NVM_USER_WORD_4                                                                                                \
	((CONF_UROW_BOOTROM_NONSECA_PAC << PAC_NONSECA_PAC_Pos) | (CONF_UROW_BOOTROM_NONSECA_PM << PAC_NONSECA_PM_Pos)     \
	 | (CONF_UROW_BOOTROM_NONSECA_MCLK << PAC_NONSECA_MCLK_Pos)                                                        \
	 | (CONF_UROW_BOOTROM_NONSECA_RSTC << PAC_NONSECA_RSTC_Pos)                                                        \
	 | (CONF_UROW_BOOTROM_NONSECA_OSCCTRL << PAC_NONSECA_OSCCTRL_Pos)                                                  \
	 | (CONF_UROW_BOOTROM_NONSECA_OSC32KCTRL << PAC_NONSECA_OSC32KCTRL_Pos)                                            \
	 | (CONF_UROW_BOOTROM_NONSECA_SUPC << PAC_NONSECA_SUPC_Pos)                                                        \
	 | (CONF_UROW_BOOTROM_NONSECA_GCLK << PAC_NONSECA_GCLK_Pos)                                                        \
	 | (CONF_UROW_BOOTROM_NONSECA_WDT << PAC_NONSECA_WDT_Pos) | (CONF_UROW_BOOTROM_NONSECA_RTC << PAC_NONSECA_RTC_Pos) \
	 | (CONF_UROW_BOOTROM_NONSECA_EIC << PAC_NONSECA_EIC_Pos)                                                          \
	 | (CONF_UROW_BOOTROM_NONSECA_FREQM << PAC_NONSECA_FREQM_Pos)                                                      \
	 | (CONF_UROW_BOOTROM_NONSECA_PORT << PAC_NONSECA_PORT_Pos)                                                        \
	 | (CONF_UROW_BOOTROM_NONSECA_AC << PAC_NONSECA_AC_Pos))

/* WORD5: Peripherals Security Attribution Bridge B (NONSECB) */
#define NVM_USER_WORD_5                                                                                                \
	((CONF_UROW_BOOTROM_NONSECB_IDAU << PAC_NONSECB_IDAU_Pos) | (CONF_UROW_BOOTROM_NONSECB_DSU << PAC_NONSECB_DSU_Pos) \
	 | (CONF_UROW_BOOTROM_NONSECB_NVMCTRL << PAC_NONSECB_NVMCTRL_Pos)                                                  \
	 | (CONF_UROW_BOOTROM_NONSECB_DMAC << PAC_NONSECB_DMAC_Pos))

/* WORD6: Peripherals Security Attribution Bridge C (NONSECC) */
#define NVM_USER_WORD_6                                                                                                \
	((CONF_UROW_BOOTROM_NONSECC_EVSYS << PAC_NONSECC_EVSYS_Pos)                                                        \
	 | (CONF_UROW_BOOTROM_NONSECC_SERCOM0 << PAC_NONSECC_SERCOM0_Pos)                                                  \
	 | (CONF_UROW_BOOTROM_NONSECC_SERCOM1 << PAC_NONSECC_SERCOM1_Pos)                                                  \
	 | (CONF_UROW_BOOTROM_NONSECC_SERCOM2 << PAC_NONSECC_SERCOM2_Pos)                                                  \
	 | (CONF_UROW_BOOTROM_NONSECC_TC0 << PAC_NONSECC_TC0_Pos) | (CONF_UROW_BOOTROM_NONSECC_TC1 << PAC_NONSECC_TC1_Pos) \
	 | (CONF_UROW_BOOTROM_NONSECC_TC2 << PAC_NONSECC_TC2_Pos) | (CONF_UROW_BOOTROM_NONSECC_ADC << PAC_NONSECC_ADC_Pos) \
	 | (CONF_UROW_BOOTROM_NONSECC_DAC << PAC_NONSECC_DAC_Pos) | (CONF_UROW_BOOTROM_NONSECC_PTC << PAC_NONSECC_PTC_Pos) \
	 | (CONF_UROW_BOOTROM_NONSECC_TRNG << PAC_NONSECC_TRNG_Pos)                                                        \
	 | (CONF_UROW_BOOTROM_NONSECC_CCL << PAC_NONSECC_CCL_Pos)                                                          \
	 | (CONF_UROW_BOOTROM_NONSECC_OPAMP << PAC_NONSECC_OPAMP_Pos)                                                      \
	 | (CONF_UROW_BOOTROM_NONSECC_TRAM << PAC_NONSECC_TRAM_Pos))

// </h>

// =========  TrustZone settings in Boot Configuration Row (BOCOR) =========

// <h> Boot Configuration Row (BOCOR)

// <o> Enable BOCOR fuse programming
// <i> Enable boot configuration row fuse programming when debugging code in IDE.
// <i> Note: This option is always disabled for now.
// <0=>Disable
// <id> bocor_fuse_programming_enable
#ifndef CONF_BOCOR_PROGRAMMING_ENABLE
#define CONF_BOCOR_PROGRAMMING_ENABLE 0
#endif

// <o> BOCOR_WORD_0.IDAU_BOOTPROT <0x0-0xFF>
// <i> Boot Protection size = BOOTPROT*0x100
// <id> bocor_idau_bootprot
#ifndef CONF_BOCOR_IDAU_BOOTPROT
#define CONF_BOCOR_IDAU_BOOTPROT 0x0
#endif

// </h>

// =========  NVIC Interrupt Target Non-Secure settings =========

// <h> NVIC Interrupt Target Non-Secure state attribution

// <q> IRQ0 SYSTEM: Non-Secure enable
// <id> nvic_init_itns_irq0_system
#ifndef CONF_NVIC_INIT_ITNS_IRQ0_SYSTEM
#define CONF_NVIC_INIT_ITNS_IRQ0_SYSTEM 0
#endif

// <q> IRQ1 WDT: Non-Secure enable
// <id> nvic_init_itns_irq1_wdt
#ifndef CONF_NVIC_INIT_ITNS_IRQ1_WDT
#define CONF_NVIC_INIT_ITNS_IRQ1_WDT 0
#endif

// <q> IRQ2 RTC: Non-Secure enable
// <id> nvic_init_itns_irq2_rtc
#ifndef CONF_NVIC_INIT_ITNS_IRQ2_RTC
#define CONF_NVIC_INIT_ITNS_IRQ2_RTC 0
#endif

// <q> IRQ3 EIC_0: Non-Secure enable
// <id> nvic_init_itns_irq3_eic_0
#ifndef CONF_NVIC_INIT_ITNS_IRQ3_EIC_0
#define CONF_NVIC_INIT_ITNS_IRQ3_EIC_0 0
#endif

// <q> IRQ4 EIC_1: Non-Secure enable
// <id> nvic_init_itns_irq4_eic_1
#ifndef CONF_NVIC_INIT_ITNS_IRQ4_EIC_1
#define CONF_NVIC_INIT_ITNS_IRQ4_EIC_1 0
#endif

// <q> IRQ5 EIC_2: Non-Secure enable
// <id> nvic_init_itns_irq5_eic_2
#ifndef CONF_NVIC_INIT_ITNS_IRQ5_EIC_2
#define CONF_NVIC_INIT_ITNS_IRQ5_EIC_2 0
#endif

// <q> IRQ6 EIC_3: Non-Secure enable
// <id> nvic_init_itns_irq6_eic_3
#ifndef CONF_NVIC_INIT_ITNS_IRQ6_EIC_3
#define CONF_NVIC_INIT_ITNS_IRQ6_EIC_3 0
#endif

// <q> IRQ7 EIC_OTHER: Non-Secure enable
// <id> nvic_init_itns_irq7_eic_other
#ifndef CONF_NVIC_INIT_ITNS_IRQ7_EIC_OTHER
#define CONF_NVIC_INIT_ITNS_IRQ7_EIC_OTHER 0
#endif

// <q> IRQ8 FREQM: Non-Secure enable
// <id> nvic_init_itns_irq8_freqm
#ifndef CONF_NVIC_INIT_ITNS_IRQ8_FREQM
#define CONF_NVIC_INIT_ITNS_IRQ8_FREQM 0
#endif

// <q> IRQ9 NVMCTRL: Non-Secure enable
// <id> nvic_init_itns_irq9_nvmctrl
#ifndef CONF_NVIC_INIT_ITNS_IRQ9_NVMCTRL
#define CONF_NVIC_INIT_ITNS_IRQ9_NVMCTRL 0
#endif

// <q> IRQ10 PORT: Non-Secure enable
// <id> nvic_init_itns_irq10_port
#ifndef CONF_NVIC_INIT_ITNS_IRQ10_PORT
#define CONF_NVIC_INIT_ITNS_IRQ10_PORT 0
#endif

// <q> IRQ11 DMAC_0: Non-Secure enable
// <id> nvic_init_itns_irq11_dmac_0
#ifndef CONF_NVIC_INIT_ITNS_IRQ11_DMAC_0
#define CONF_NVIC_INIT_ITNS_IRQ11_DMAC_0 0
#endif

// <q> IRQ12 DMAC_1: Non-Secure enable
// <id> nvic_init_itns_irq12_dmac_1
#ifndef CONF_NVIC_INIT_ITNS_IRQ12_DMAC_1
#define CONF_NVIC_INIT_ITNS_IRQ12_DMAC_1 0
#endif

// <q> IRQ13 DMAC_2: Non-Secure enable
// <id> nvic_init_itns_irq13_dmac_2
#ifndef CONF_NVIC_INIT_ITNS_IRQ13_DMAC_2
#define CONF_NVIC_INIT_ITNS_IRQ13_DMAC_2 0
#endif

// <q> IRQ14 DMAC_3: Non-Secure enable
// <id> nvic_init_itns_irq14_dmac_3
#ifndef CONF_NVIC_INIT_ITNS_IRQ14_DMAC_3
#define CONF_NVIC_INIT_ITNS_IRQ14_DMAC_3 0
#endif

// <q> IRQ15 DMAC_OTHER: Non-Secure enable
// <id> nvic_init_itns_irq15_dmac_OTHER
#ifndef CONF_NVIC_INIT_ITNS_IRQ15_DMAC_OTHER
#define CONF_NVIC_INIT_ITNS_IRQ15_DMAC_OTHER 0
#endif

// <q> IRQ16 EVSYS_0: Non-Secure enable
// <id> nvic_init_itns_irq16_evsys_0
#ifndef CONF_NVIC_INIT_ITNS_IRQ16_EVSYS_0
#define CONF_NVIC_INIT_ITNS_IRQ16_EVSYS_0 0
#endif

// <q> IRQ17 EVSYS_1: Non-Secure enable
// <id> nvic_init_itns_irq17_evsys_1
#ifndef CONF_NVIC_INIT_ITNS_IRQ17_EVSYS_1
#define CONF_NVIC_INIT_ITNS_IRQ17_EVSYS_1 0
#endif

// <q> IRQ18 EVSYS_2: Non-Secure enable
// <id> nvic_init_itns_irq18_evsys_2
#ifndef CONF_NVIC_INIT_ITNS_IRQ18_EVSYS_2
#define CONF_NVIC_INIT_ITNS_IRQ18_EVSYS_2 0
#endif

// <q> IRQ19 EVSYS_3: Non-Secure enable
// <id> nvic_init_itns_irq19_evsys_3
#ifndef CONF_NVIC_INIT_ITNS_IRQ19_EVSYS_3
#define CONF_NVIC_INIT_ITNS_IRQ19_EVSYS_3 0
#endif

// <q> IRQ20 EVSYS_NSCHK: Non-Secure enable
// <id> nvic_init_itns_irq20_evsys_NSCHK
#ifndef CONF_NVIC_INIT_ITNS_IRQ20_EVSYS_NSCHK
#define CONF_NVIC_INIT_ITNS_IRQ20_EVSYS_NSCHK 0
#endif

// <q> IRQ21 PAC: Non-Secure enable
// <id> nvic_init_itns_irq21_pac
#ifndef CONF_NVIC_INIT_ITNS_IRQ21_PAC
#define CONF_NVIC_INIT_ITNS_IRQ21_PAC 0
#endif

// <q> IRQ22 SERCOM0_0: Non-Secure enable
// <id> nvic_init_itns_irq22_sercom0_0
#ifndef CONF_NVIC_INIT_ITNS_IRQ22_SERCOM0_0
#define CONF_NVIC_INIT_ITNS_IRQ22_SERCOM0_0 0
#endif

// <q> IRQ23 SERCOM0_1: Non-Secure enable
// <id> nvic_init_itns_irq23_sercom0_1
#ifndef CONF_NVIC_INIT_ITNS_IRQ23_SERCOM0_1
#define CONF_NVIC_INIT_ITNS_IRQ23_SERCOM0_1 0
#endif

// <q> IRQ24 SERCOM0_2: Non-Secure enable
// <id> nvic_init_itns_irq24_sercom0_2
#ifndef CONF_NVIC_INIT_ITNS_IRQ24_SERCOM0_2
#define CONF_NVIC_INIT_ITNS_IRQ24_SERCOM0_2 0
#endif

// <q> IRQ25 SERCOM0_OTHER: Non-Secure enable
// <id> nvic_init_itns_irq25_sercom0_other
#ifndef CONF_NVIC_INIT_ITNS_IRQ25_SERCOM0_OTHER
#define CONF_NVIC_INIT_ITNS_IRQ25_SERCOM0_OTHER 0
#endif

// <q> IRQ26 SERCOM1_0: Non-Secure enable
// <id> nvic_init_itns_irq26_sercom1_0
#ifndef CONF_NVIC_INIT_ITNS_IRQ26_SERCOM1_0
#define CONF_NVIC_INIT_ITNS_IRQ26_SERCOM1_0 0
#endif

// <q> IRQ27 SERCOM1_1: Non-Secure enable
// <id> nvic_init_itns_irq27_sercom1_1
#ifndef CONF_NVIC_INIT_ITNS_IRQ27_SERCOM1_1
#define CONF_NVIC_INIT_ITNS_IRQ27_SERCOM1_1 0
#endif

// <q> IRQ28 SERCOM1_2: Non-Secure enable
// <id> nvic_init_itns_irq28_sercom1_2
#ifndef CONF_NVIC_INIT_ITNS_IRQ28_SERCOM1_2
#define CONF_NVIC_INIT_ITNS_IRQ28_SERCOM1_2 0
#endif

// <q> IRQ29 SERCOM1_OTHER: Non-Secure enable
// <id> nvic_init_itns_irq29_sercom1_other
#ifndef CONF_NVIC_INIT_ITNS_IRQ29_SERCOM1_OTHER
#define CONF_NVIC_INIT_ITNS_IRQ29_SERCOM1_OTHER 0
#endif

// <q> IRQ30 SERCOM2_0: Non-Secure enable
// <id> nvic_init_itns_irq30_sercom2_0
#ifndef CONF_NVIC_INIT_ITNS_IRQ30_SERCOM2_0
#define CONF_NVIC_INIT_ITNS_IRQ30_SERCOM2_0 0
#endif

// <q> IRQ31 SERCOM2_1: Non-Secure enable
// <id> nvic_init_itns_irq31_sercom2_1
#ifndef CONF_NVIC_INIT_ITNS_IRQ31_SERCOM2_1
#define CONF_NVIC_INIT_ITNS_IRQ31_SERCOM2_1 0
#endif

// <q> IRQ32 SERCOM2_2: Non-Secure enable
// <id> nvic_init_itns_irq32_sercom2_2
#ifndef CONF_NVIC_INIT_ITNS_IRQ32_SERCOM2_2
#define CONF_NVIC_INIT_ITNS_IRQ32_SERCOM2_2 0
#endif

// <q> IRQ33 SERCOM2_OTHER: Non-Secure enable
// <id> nvic_init_itns_irq33_sercom2_other
#ifndef CONF_NVIC_INIT_ITNS_IRQ33_SERCOM2_OTHER
#define CONF_NVIC_INIT_ITNS_IRQ33_SERCOM2_OTHER 0
#endif

// <q> IRQ34 TC0: Non-Secure enable
// <id> nvic_init_itns_irq34_tc0
#ifndef CONF_NVIC_INIT_ITNS_IRQ34_TC0
#define CONF_NVIC_INIT_ITNS_IRQ34_TC0 0
#endif

// <q> IRQ35 TC1: Non-Secure enable
// <id> nvic_init_itns_irq35_tc1
#ifndef CONF_NVIC_INIT_ITNS_IRQ35_TC1
#define CONF_NVIC_INIT_ITNS_IRQ35_TC1 0
#endif

// <q> IRQ36 TC2: Non-Secure enable
// <id> nvic_init_itns_irq36_tc2
#ifndef CONF_NVIC_INIT_ITNS_IRQ36_TC2
#define CONF_NVIC_INIT_ITNS_IRQ36_TC2 0
#endif

// <q> IRQ37 ADC_OTHER: Non-Secure enable
// <id> nvic_init_itns_irq37_adc_other
#ifndef CONF_NVIC_INIT_ITNS_IRQ37_ADC_OTHER
#define CONF_NVIC_INIT_ITNS_IRQ37_ADC_OTHER 0
#endif

// <q> IRQ38 ADC_RESRDY: Non-Secure enable
// <id> nvic_init_itns_irq38_adc_resrdy
#ifndef CONF_NVIC_INIT_ITNS_IRQ38_ADC_RESRDY
#define CONF_NVIC_INIT_ITNS_IRQ38_ADC_RESRDY 0
#endif

// <q> IRQ39 AC: Non-Secure enable
// <id> nvic_init_itns_irq39_ac
#ifndef CONF_NVIC_INIT_ITNS_IRQ39_AC
#define CONF_NVIC_INIT_ITNS_IRQ39_AC 0
#endif

// <q> IRQ40 DAC_UNDERRUN: Non-Secure enable
// <id> nvic_init_itns_irq40_dac_underrun
#ifndef CONF_NVIC_INIT_ITNS_IRQ40_DAC_UNDERRUN
#define CONF_NVIC_INIT_ITNS_IRQ40_DAC_UNDERRUN 0
#endif

// <q> IRQ41 DAC_EMPTY: Non-Secure enable
// <id> nvic_init_itns_irq41_dac_empty
#ifndef CONF_NVIC_INIT_ITNS_IRQ41_DAC_EMPTY
#define CONF_NVIC_INIT_ITNS_IRQ41_DAC_EMPTY 0
#endif

// <q> IRQ42 PTC: Non-Secure enable
// <id> nvic_init_itns_irq42_ptc
#ifndef CONF_NVIC_INIT_ITNS_IRQ42_PTC
#define CONF_NVIC_INIT_ITNS_IRQ42_PTC 0
#endif

// <q> IRQ43 TRNG: Non-Secure enable
// <id> nvic_init_itns_irq43_trng
#ifndef CONF_NVIC_INIT_ITNS_IRQ43_TRNG
#define CONF_NVIC_INIT_ITNS_IRQ43_TRNG 0
#endif

// <q> IRQ44 TRAM: Non-Secure enable
// <id> nvic_init_itns_irq44_tram
#ifndef CONF_NVIC_INIT_ITNS_IRQ44_TRAM
#define CONF_NVIC_INIT_ITNS_IRQ44_TRAM 0
#endif

/* Initial Value of ITNS 0 (Interrupts 0..31) */
#define CONF_NVIC_INIT_ITNS0_VAL                                                                                       \
	((CONF_NVIC_INIT_ITNS_IRQ0_SYSTEM << 0) | (CONF_NVIC_INIT_ITNS_IRQ1_WDT << 1)                                      \
	 | (CONF_NVIC_INIT_ITNS_IRQ2_RTC << 2) | (CONF_NVIC_INIT_ITNS_IRQ3_EIC_0 << 3)                                     \
	 | (CONF_NVIC_INIT_ITNS_IRQ4_EIC_1 << 4) | (CONF_NVIC_INIT_ITNS_IRQ5_EIC_2 << 5)                                   \
	 | (CONF_NVIC_INIT_ITNS_IRQ6_EIC_3 << 6) | (CONF_NVIC_INIT_ITNS_IRQ7_EIC_OTHER << 7)                               \
	 | (CONF_NVIC_INIT_ITNS_IRQ8_FREQM << 8) | (CONF_NVIC_INIT_ITNS_IRQ9_NVMCTRL << 9)                                 \
	 | (CONF_NVIC_INIT_ITNS_IRQ10_PORT << 10) | (CONF_NVIC_INIT_ITNS_IRQ11_DMAC_0 << 11)                               \
	 | (CONF_NVIC_INIT_ITNS_IRQ12_DMAC_1 << 12) | (CONF_NVIC_INIT_ITNS_IRQ13_DMAC_2 << 13)                             \
	 | (CONF_NVIC_INIT_ITNS_IRQ14_DMAC_3 << 14) | (CONF_NVIC_INIT_ITNS_IRQ15_DMAC_OTHER << 15)                         \
	 | (CONF_NVIC_INIT_ITNS_IRQ16_EVSYS_0 << 16) | (CONF_NVIC_INIT_ITNS_IRQ17_EVSYS_1 << 17)                           \
	 | (CONF_NVIC_INIT_ITNS_IRQ18_EVSYS_2 << 18) | (CONF_NVIC_INIT_ITNS_IRQ19_EVSYS_3 << 19)                           \
	 | (CONF_NVIC_INIT_ITNS_IRQ20_EVSYS_NSCHK << 20) | (CONF_NVIC_INIT_ITNS_IRQ21_PAC << 21)                           \
	 | (CONF_NVIC_INIT_ITNS_IRQ22_SERCOM0_0 << 22) | (CONF_NVIC_INIT_ITNS_IRQ23_SERCOM0_1 << 23)                       \
	 | (CONF_NVIC_INIT_ITNS_IRQ24_SERCOM0_2 << 24) | (CONF_NVIC_INIT_ITNS_IRQ25_SERCOM0_OTHER << 25)                   \
	 | (CONF_NVIC_INIT_ITNS_IRQ26_SERCOM1_0 << 26) | (CONF_NVIC_INIT_ITNS_IRQ27_SERCOM1_1 << 27)                       \
	 | (CONF_NVIC_INIT_ITNS_IRQ28_SERCOM1_2 << 28) | (CONF_NVIC_INIT_ITNS_IRQ29_SERCOM1_OTHER << 29)                   \
	 | (CONF_NVIC_INIT_ITNS_IRQ30_SERCOM2_0 << 30) | (CONF_NVIC_INIT_ITNS_IRQ31_SERCOM2_1 << 31))

/* Initial Value of ITNS 1 (Interrupts 32..63) */
#define CONF_NVIC_INIT_ITNS1_VAL                                                                                       \
	((CONF_NVIC_INIT_ITNS_IRQ32_SERCOM2_2 << 0) | (CONF_NVIC_INIT_ITNS_IRQ33_SERCOM2_OTHER << 1)                       \
	 | (CONF_NVIC_INIT_ITNS_IRQ34_TC0 << 2) | (CONF_NVIC_INIT_ITNS_IRQ35_TC1 << 3)                                     \
	 | (CONF_NVIC_INIT_ITNS_IRQ36_TC2 << 4) | (CONF_NVIC_INIT_ITNS_IRQ37_ADC_OTHER << 5)                               \
	 | (CONF_NVIC_INIT_ITNS_IRQ38_ADC_RESRDY << 6) | (CONF_NVIC_INIT_ITNS_IRQ39_AC << 7)                               \
	 | (CONF_NVIC_INIT_ITNS_IRQ40_DAC_UNDERRUN << 8) | (CONF_NVIC_INIT_ITNS_IRQ41_DAC_EMPTY << 9)                      \
	 | (CONF_NVIC_INIT_ITNS_IRQ42_PTC << 10) | (CONF_NVIC_INIT_ITNS_IRQ43_TRNG << 11)                                  \
	 | (CONF_NVIC_INIT_ITNS_IRQ44_TRAM << 12))

// </h>

// =========  Port Security Attribution Setting =========

// <h> Port Security Attribution

// <q> PA00 Non-Secure I/O enable
// <id> port_nonsec_pa00
#ifndef CONF_PORT_NONSEC_PA00
#define CONF_PORT_NONSEC_PA00 0
#endif

// <q> PA01 Non-Secure I/O enable
// <id> port_nonsec_pa01
#ifndef CONF_PORT_NONSEC_PA01
#define CONF_PORT_NONSEC_PA01 0
#endif

// <q> PA02 Non-Secure I/O enable
// <id> port_nonsec_pa02
#ifndef CONF_PORT_NONSEC_PA02
#define CONF_PORT_NONSEC_PA02 0
#endif

// <q> PA03 Non-Secure I/O enable
// <id> port_nonsec_pa03
#ifndef CONF_PORT_NONSEC_PA03
#define CONF_PORT_NONSEC_PA03 0
#endif

// <q> PA04 Non-Secure I/O enable
// <id> port_nonsec_pa04
#ifndef CONF_PORT_NONSEC_PA04
#define CONF_PORT_NONSEC_PA04 0
#endif

// <q> PA05 Non-Secure I/O enable
// <id> port_nonsec_pa05
#ifndef CONF_PORT_NONSEC_PA05
#define CONF_PORT_NONSEC_PA05 0
#endif

// <q> PA06 Non-Secure I/O enable
// <id> port_nonsec_pa06
#ifndef CONF_PORT_NONSEC_PA06
#define CONF_PORT_NONSEC_PA06 0
#endif

// <q> PA07 Non-Secure I/O enable
// <id> port_nonsec_pa07
#ifndef CONF_PORT_NONSEC_PA07
#define CONF_PORT_NONSEC_PA07 0
#endif

// <q> PA08 Non-Secure I/O enable
// <id> port_nonsec_pa08
#ifndef CONF_PORT_NONSEC_PA08
#define CONF_PORT_NONSEC_PA08 0
#endif

// <q> PA09 Non-Secure I/O enable
// <id> port_nonsec_pa09
#ifndef CONF_PORT_NONSEC_PA09
#define CONF_PORT_NONSEC_PA09 0
#endif

// <q> PA10 Non-Secure I/O enable
// <id> port_nonsec_pa10
#ifndef CONF_PORT_NONSEC_PA10
#define CONF_PORT_NONSEC_PA10 0
#endif

// <q> PA11 Non-Secure I/O enable
// <id> port_nonsec_pa11
#ifndef CONF_PORT_NONSEC_PA11
#define CONF_PORT_NONSEC_PA11 0
#endif

// <q> PA12 Non-Secure I/O enable
// <id> port_nonsec_pa12
#ifndef CONF_PORT_NONSEC_PA12
#define CONF_PORT_NONSEC_PA12 0
#endif

// <q> PA13 Non-Secure I/O enable
// <id> port_nonsec_pa13
#ifndef CONF_PORT_NONSEC_PA13
#define CONF_PORT_NONSEC_PA13 0
#endif

// <q> PA14 Non-Secure I/O enable
// <id> port_nonsec_pa14
#ifndef CONF_PORT_NONSEC_PA14
#define CONF_PORT_NONSEC_PA14 0
#endif

// <q> PA15 Non-Secure I/O enable
// <id> port_nonsec_pa15
#ifndef CONF_PORT_NONSEC_PA15
#define CONF_PORT_NONSEC_PA15 0
#endif

// <q> PA16 Non-Secure I/O enable
// <id> port_nonsec_pa16
#ifndef CONF_PORT_NONSEC_PA16
#define CONF_PORT_NONSEC_PA16 0
#endif

// <q> PA17 Non-Secure I/O enable
// <id> port_nonsec_pa17
#ifndef CONF_PORT_NONSEC_PA17
#define CONF_PORT_NONSEC_PA17 0
#endif

// <q> PA18 Non-Secure I/O enable
// <id> port_nonsec_pa18
#ifndef CONF_PORT_NONSEC_PA18
#define CONF_PORT_NONSEC_PA18 0
#endif

// <q> PA19 Non-Secure I/O enable
// <id> port_nonsec_pa19
#ifndef CONF_PORT_NONSEC_PA19
#define CONF_PORT_NONSEC_PA19 0
#endif

// <q> PA20 Non-Secure I/O enable
// <id> port_nonsec_pa20
#ifndef CONF_PORT_NONSEC_PA20
#define CONF_PORT_NONSEC_PA20 0
#endif

// <q> PA21 Non-Secure I/O enable
// <id> port_nonsec_pa21
#ifndef CONF_PORT_NONSEC_PA21
#define CONF_PORT_NONSEC_PA21 0
#endif

// <q> PA22 Non-Secure I/O enable
// <id> port_nonsec_pa22
#ifndef CONF_PORT_NONSEC_PA22
#define CONF_PORT_NONSEC_PA22 0
#endif

// <q> PA23 Non-Secure I/O enable
// <id> port_nonsec_pa23
#ifndef CONF_PORT_NONSEC_PA23
#define CONF_PORT_NONSEC_PA23 0
#endif

// <q> PA24 Non-Secure I/O enable
// <id> port_nonsec_pa24
#ifndef CONF_PORT_NONSEC_PA24
#define CONF_PORT_NONSEC_PA24 0
#endif

// <q> PA25 Non-Secure I/O enable
// <id> port_nonsec_pa25
#ifndef CONF_PORT_NONSEC_PA25
#define CONF_PORT_NONSEC_PA25 0
#endif

// <q> PA26 Non-Secure I/O enable
// <id> port_nonsec_pa26
#ifndef CONF_PORT_NONSEC_PA26
#define CONF_PORT_NONSEC_PA26 0
#endif

// <q> PA27 Non-Secure I/O enable
// <id> port_nonsec_pa27
#ifndef CONF_PORT_NONSEC_PA27
#define CONF_PORT_NONSEC_PA27 0
#endif

// <q> PA28 Non-Secure I/O enable
// <id> port_nonsec_pa28
#ifndef CONF_PORT_NONSEC_PA28
#define CONF_PORT_NONSEC_PA28 0
#endif

// <q> PA29 Non-Secure I/O enable
// <id> port_nonsec_pa29
#ifndef CONF_PORT_NONSEC_PA29
#define CONF_PORT_NONSEC_PA29 0
#endif

// <q> PA30 Non-Secure I/O enable
// <id> port_nonsec_pa30
#ifndef CONF_PORT_NONSEC_PA30
#define CONF_PORT_NONSEC_PA30 0
#endif

// <q> PA31 Non-Secure I/O enable
// <id> port_nonsec_pa31
#ifndef CONF_PORT_NONSEC_PA31
#define CONF_PORT_NONSEC_PA31 0
#endif

// </h>

/* Initial Value of Port NONSEC (PAxx) */
#define CONF_PORT_INIT_NONSEC0_VAL                                                                                     \
	((CONF_PORT_NONSEC_PA00 << 0) | (CONF_PORT_NONSEC_PA01 << 1) | (CONF_PORT_NONSEC_PA02 << 2)                        \
	 | (CONF_PORT_NONSEC_PA03 << 3) | (CONF_PORT_NONSEC_PA04 << 4) | (CONF_PORT_NONSEC_PA05 << 5)                      \
	 | (CONF_PORT_NONSEC_PA06 << 6) | (CONF_PORT_NONSEC_PA07 << 7) | (CONF_PORT_NONSEC_PA08 << 8)                      \
	 | (CONF_PORT_NONSEC_PA09 << 9) | (CONF_PORT_NONSEC_PA10 << 10) | (CONF_PORT_NONSEC_PA11 << 11)                    \
	 | (CONF_PORT_NONSEC_PA12 << 12) | (CONF_PORT_NONSEC_PA13 << 13) | (CONF_PORT_NONSEC_PA14 << 14)                   \
	 | (CONF_PORT_NONSEC_PA15 << 15) | (CONF_PORT_NONSEC_PA16 << 16) | (CONF_PORT_NONSEC_PA17 << 17)                   \
	 | (CONF_PORT_NONSEC_PA18 << 18) | (CONF_PORT_NONSEC_PA19 << 19) | (CONF_PORT_NONSEC_PA20 << 20)                   \
	 | (CONF_PORT_NONSEC_PA21 << 21) | (CONF_PORT_NONSEC_PA22 << 22) | (CONF_PORT_NONSEC_PA23 << 23)                   \
	 | (CONF_PORT_NONSEC_PA24 << 24) | (CONF_PORT_NONSEC_PA25 << 25) | (CONF_PORT_NONSEC_PA26 << 26)                   \
	 | (CONF_PORT_NONSEC_PA27 << 27) | (CONF_PORT_NONSEC_PA28 << 28) | (CONF_PORT_NONSEC_PA29 << 29)                   \
	 | (CONF_PORT_NONSEC_PA30 << 30) | (CONF_PORT_NONSEC_PA31 << 31))

// =========  Miscellaneous Settings =========

// <h> Stack Size Configuration

// <o> Stack Size for Secure Project <0x0-0x4000>
// <i> This value will be used in generated linker script for secure project.
// <id> stack_size_secure_project
#ifndef CONF_STACK_SIZE_SECURE_PROJECT
#define CONF_STACK_SIZE_SECURE_PROJECT 0x400
#endif

// <o> Stack Size for Non-Secure Project <0x0-0x4000>
// <i> This value will be used in generated linker script for non-secure project.
// <id> stack_size_nonsecure_project
#ifndef CONF_STACK_SIZE_NONSECURE_PROJECT
#define CONF_STACK_SIZE_NONSECURE_PROJECT 0x400
#endif

// </h>

// <h> Secure Gateway Veneer Code

// <q> Enable secure gateway veneer common driver code
// <i> Enable to include secure gateway veneer common driver APIs.
// <i> This MUST be enabled if peripheral drivers are used in non-secure project.
// <id> sg_veneer_common_code_enable
#ifndef CONF_SG_VENEER_COMMON_CODE_ENABLE
#define CONF_SG_VENEER_COMMON_CODE_ENABLE 0
#endif

// <q> Enable secure gateway veneer code for Getting Started Example
// <i> Enable to include secure gateway veneer code for Getting Started Example.
// <id> sg_veneer_getting_started_code_enable
#ifndef CONF_SG_VENEER_GETTING_STARTED_CODE_ENABLE
#define CONF_SG_VENEER_GETTING_STARTED_CODE_ENABLE 1
#endif

// <q> Enable secure gateway veneer code for Secure Driver Example
// <i> Enable to include secure gateway veneer code for Secure Driver Example.
// <id> sg_veneer_secure_driver_example_code_enable
#ifndef CONF_SG_VENEER_SECURE_DRIVER_EXAMPLE_CODE_ENABLE
#define CONF_SG_VENEER_SECURE_DRIVER_EXAMPLE_CODE_ENABLE 0
#endif

// <q> Enable secure gateway veneer code for Mix-Secure EIC Example
// <i> Enable to include secure gateway veneer code for Mix-Secure EIC Example.
// <id> sg_veneer_mixsecure_eic_example_code_enable
#ifndef CONF_SG_VENEER_MIXSECURE_EIC_EXAMPLE_CODE_ENABLE
#define CONF_SG_VENEER_MIXSECURE_EIC_EXAMPLE_CODE_ENABLE 0
#endif

// </h>

// Start address of non-secure application
#ifndef CONF_TZ_START_NS
#define CONF_TZ_START_NS (CONF_BOCOR_IDAU_BOOTPROT + CONF_UROW_IDAU_AS) * 0x100
#endif

// <<< end of configuration section >>>

#endif // TRUSTZONE_CONFIG_H
