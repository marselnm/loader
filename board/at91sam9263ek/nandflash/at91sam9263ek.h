/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support  -  ROUSSET  -
 * ----------------------------------------------------------------------------
 * Copyright (c) 2006, Atmel Corporation

 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the disclaimer below in the documentation and/or
 * other materials provided with the distribution.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 * File Name           : at91sam9263ek.h
 * Object              :
 * Creation            : NLe Aug 8th 2006
 *-----------------------------------------------------------------------------
 */
#ifndef _AT91SAM9263EK_H
#define _AT91SAM9263EK_H

/* ******************************************************************* */
/* PMC Settings                                                        */
/*                                                                     */
/* The main oscillator is enabled as soon as possible in the c_startup */
/* and MCK is switched on the main oscillator.                         */
/* PLL initialization is done later in the hw_init() function          */
/* ******************************************************************* */
#define	CRYSTAL_16_36766MHZ	1

#ifdef CRYSTAL_16_36766MHZ
	#define MASTER_CLOCK		(199919000/2)
	#define PLL_LOCK_TIMEOUT	1000000
	#define PLLA_SETTINGS		0x20AABF0E
	#define PLLB_SETTINGS		0x10483F0E
#endif

#ifdef CRYSTAL_18_432MHZ
	#define MASTER_CLOCK		(198656000/2)
	#define PLL_LOCK_TIMEOUT	1000000
	#define PLLA_SETTINGS		0x2060BF09
	#define PLLB_SETTINGS		0x10483F0E
#endif

/* Switch MCK on PLLA output PCK = PLLA = 2 * MCK */
#define MCKR_SETTINGS	(AT91C_PMC_CSS_PLLA_CLK | AT91C_PMC_PRES_CLK | AT91C_PMC_MDIV_2)

/* ******************************************************************* */
/* NandFlash Settings                                                  */
/*                                                                     */
/* ******************************************************************* */
#define AT91C_SMARTMEDIA_BASE	0x40000000

#define AT91_SMART_MEDIA_ALE    (1 << 21)	/* our ALE is AD21 */
#define AT91_SMART_MEDIA_CLE    (1 << 22)	/* our CLE is AD22 */

#define NAND_DISABLE_CE() do { *(volatile unsigned int *)AT91C_PIOD_SODR = AT91C_PIO_PD15;} while(0)
#define NAND_ENABLE_CE()  do { *(volatile unsigned int *)AT91C_PIOD_CODR = AT91C_PIO_PD15;} while(0)
#define NAND_WAIT_READY() while (!(*(volatile unsigned int *)AT91C_PIOA_PDSR & AT91C_PIO_PA22))

/* ******************************************************************* */
/* SDRAMC Settings                                                     */
/*                                                                     */
/* ******************************************************************* */
#define AT91C_BASE_SDRAMC 	AT91C_BASE_SDRAMC0
#define AT91C_EBI_SDRAM		AT91C_EBI0_SDRAM

/* ******************************************************************** */
/* SMC Chip Select 3 Timings for NandFlash for MASTER_CLOCK = 100000000.*/
/* Please refer to SMC section in AT91SAM9x datasheet to learn how 	*/
/* to generate these values. 						*/
/* ******************************************************************** */
#define AT91C_SM_NWE_SETUP	(1 << 0)
#define AT91C_SM_NCS_WR_SETUP	(1 << 8)
#define AT91C_SM_NRD_SETUP	(1 << 16)
#define AT91C_SM_NCS_RD_SETUP	(1 << 24)
  
#define AT91C_SM_NWE_PULSE 	(3 << 0)
#define AT91C_SM_NCS_WR_PULSE	(3 << 8)
#define AT91C_SM_NRD_PULSE	(3 << 16)
#define AT91C_SM_NCS_RD_PULSE	(3 << 24)
  
#define AT91C_SM_NWE_CYCLE 	(5 << 0)
#define AT91C_SM_NRD_CYCLE	(5 << 16)

#define AT91C_SM_TDF	        (2 << 16)

/* ******************************************************************* */
/* BootStrap Settings                                                  */
/*                                                                     */
/* ******************************************************************* */
#define IMG_ADDRESS 	0x20000		/* Image Address in NandFlash */
#define	IMG_SIZE	0x30000		/* Image Size in NandFlash    */

#define MACH_TYPE       1202       	/* AT91SAM9263-EK */
#define JUMP_ADDR	0x23F00000	/* Final Jump Address 	      */

/* ******************************************************************* */
/* Application Settings                                                */
/* ******************************************************************* */
#undef CFG_DEBUG
#undef CFG_DATAFLASH

#define CFG_NANDFLASH
#undef	NANDFLASH_SMALL_BLOCKS	/* NANDFLASH_LARGE_BLOCKS used instead */

#define CFG_HW_INIT
#define CFG_SDRAM


#endif	/* _AT91SAM9263EK_H */
