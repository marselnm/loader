/*
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

/* Enable the main oscillator */
#define	CRYSTAL_18_432MHZ	1

#ifdef CRYSTAL_16_36766MHZ

	#define MASTER_CLOCK		(199919000/2)
	#define PLL_LOCK_TIMEOUT	1000000

	#define PLLA_SETTINGS		0x20AABF0E
	#define PLLB_SETTINGS		0x10483F0E

#endif

#ifdef CRYSTAL_18_432MHZ

	//#define MASTER_CLOCK		(196608000/2)
	//#define PLL_LOCK_TIMEOUT	1000000

	//#define PLLA_SETTINGS		0x200BBF01
	//#define PLLB_SETTINGS		0x10483F0E
	
	#define MASTER_CLOCK		(18432000*11/2)//(221184000/2)
	#define PLL_LOCK_TIMEOUT	1000000

	#define PLLA_SETTINGS	0x200ABF01
	#define PLLB_SETTINGS	0x10483F0E

#endif


#ifdef CRYSTAL_14_7456MHZ

	#define MASTER_CLOCK		(199884800/2)
	#define PLL_LOCK_TIMEOUT	1000000

	#define PLLA_SETTINGS		0x2079BF09  
	#define PLLB_SETTINGS		0x10483F0E

#endif


/* Switch MCK on PLLA output PCK = PLLA = 2 * MCK */
#define MCKR_SETTINGS	(AT91C_PMC_CSS_PLLA_CLK | AT91C_PMC_PRES_CLK | AT91C_PMC_MDIV_2)

/* ******************************************************************* */
/* DataFlash Settings                                                  */
/*                                                                     */
/* ******************************************************************* */
#define AT91C_BASE_SPI	AT91C_BASE_SPI0
#define AT91C_ID_SPI	AT91C_ID_SPI0

/* SPI CLOCK */
#define AT91C_SPI_CLK 		 8000000
/* AC characteristics */
/* DLYBS = tCSS= 250ns min and DLYBCT = tCSH = 250ns */
#define DATAFLASH_TCSS		(0x1a << 16)	/* 250ns min (tCSS) <=> 12/48000000 = 250ns */
#define DATAFLASH_TCHS		(0x1 << 24)	/* 250ns min (tCSH) <=> (64*1+SCBR)/(2*48000000) */

#define DF_CS_SETTINGS 		(AT91C_SPI_NCPHA | (AT91C_SPI_DLYBS & DATAFLASH_TCSS) | (AT91C_SPI_DLYBCT & DATAFLASH_TCHS) | ((MASTER_CLOCK / AT91C_SPI_CLK) << 8))

/* ******************************************************************* */
/* SDRAMC Settings                                                     */
/*                                                                     */
/* ******************************************************************* */
#define AT91C_BASE_SDRAMC 	AT91C_BASE_SDRAMC0
#define AT91C_EBI_SDRAM		AT91C_EBI0_SDRAM

/* ******************************************************************* */
/* BootStrap Settings                                                  */
/*                                                                     */
/* ******************************************************************* */
#define AT91C_SPI_PCS_DATAFLASH		AT91C_SPI_PCS0_DATAFLASH				/* Boot on SPI NCS0 */

#define IMG_ADDRESS 		0x8000			/* Image Address in DataFlash */
#define IMG_ADDRESS_LOADER 	0x108000/* Image Address erase boot in DataFlash */
#define	IMG_SIZE			0x100000			/* Image Size in DataFlash    */
#define	IMG_SIZE_LOADER		0x4000			

#define MACH_TYPE       	0x4B2       	/* AT91SAM9263-EK */
#define JUMP_ADDR			0x10000040		/* Final Jump Address */
#define JUMP_ADDR_LOADER	0x302000		

#define	LOADER_CODE			0x32AD5149

/* ******************************************************************* */
/* Application Settings                                                */
/* ******************************************************************* */
#define CFG_HW_INIT
#define CFG_SDRAM
#define CFG_SRAM
#define CFG_DEBUG
#define CFG_DATAFLASH

#endif	/* _AT91SAM9263EK_H */
