
#include "include/part.h"
#include "include/main.h"
#include "include/debug.h"
#include "include/dataflash.h"
#include "include/nandflash.h"
#include "include/norflash.h"  
#include "include/gpio.h"

/*------------------------------------------------------------------------------*/
/* Function Name       : main													*/
/* Object              : Main function											*/
/* Input Parameters    : none													*/
/* Output Parameters   : True													*/
/*------------------------------------------------------------------------------*/

static void AT91F_SPI_Send_Data (unsigned long Data_To_Send){
	// IMPORTANT: Data_To_Send = TD (in fixed mode)
	// IMPORTANT: Data_To_Send = TD + PCS + LASTXFER (in variable mode)
	
	volatile unsigned int* SPI = (volatile unsigned int*)0xFFFA4000;
	
	Data_To_Send &= 0x010FFFFF; // mask non used bits
	while (*(SPI + 0)&0x2);
	*(SPI + 3)= Data_To_Send;
}

/* Write SPI register */
static inline void write_spi(unsigned int offset, const unsigned int value)
{
	writel(value, offset + AT91C_BASE_SPI);
}


int main(void) {
/* Address in dataflash */ 
unsigned int addr = 0; 
unsigned int jump_addr = 0;
unsigned int size = 0;
char buf[] = {0x81, 0, 0, 0};

/* ================== 1st step: Hardware Initialization ================= */
	/* Performs the hardware initialization */
	
	addr = hw_init();
	//dbg_print("chek1 \n\r");
	if (addr == IMG_ADDRESS_LOADER) { 
	//dbg_print("chek2 \n\r");
		jump_addr = JUMP_ADDR_LOADER;
		size = IMG_SIZE_LOADER;
	}
	else {
		jump_addr = JUMP_ADDR;
		size = IMG_SIZE;
	}

    addr = 0x8000;
    size = 0x100000;
    jump_addr = 0x20000000; 
                

	
/* ==================== 2nd step: Load from media ==================== */
	/* Load from Dataflash in RAM */
#ifdef CFG_DATAFLASH
	load_df(AT91C_SPI_PCS_DATAFLASH, addr, size, jump_addr);
#endif
   
	/* Load from Nandflash in RAM */
#ifdef CFG_NANDFLASH
	//load_nandflash(IMG_ADDRESS, IMG_SIZE, JUMP_ADDR);
#endif
 
	/* Load from Norflash in RAM */
#ifdef CFG_NORFLASH
	//load_norflash(IMG_ADDRESS, IMG_SIZE, JUMP_ADDR);
#endif

/* ==================== 3rd step:  Process the Image =================== */
	/* Uncompress the image */
#ifdef GUNZIP
	//decompress_image((void *)IMG_ADDRESS, (void *)JUMP_ADDR, IMG_SIZE);	/* NOT IMPLEMENTED YET */
#endif /* GUNZIP */

/* ==================== 4th step: Start the application =================== */
	/* Set linux arguments */
#ifdef LINUX_ARG
	//linux_arg(LINUX_ARG);	/* NOT IMPLEMENTED YET */
#endif /* LINUX_ARG */
	

	/* Jump to the Image Address */	
#if 0
	if (addr == IMG_ADDRESS_ERASE) {
		dbg_print("Erase command \n\r");
		AT91F_SPI_Send_Data(0x81);
		AT91F_SPI_Send_Data(0);
		AT91F_SPI_Send_Data(0);
		AT91F_SPI_Send_Data(0);
		
	write_spi(SPI_PTCR, AT91C_PDC_TXTDIS);				/* PDC Disable Tx */
 	write_spi(SPI_TPR, &buf);	/* PDC Set Tx */
	write_spi(SPI_TCR, 4);

 	write_spi(SPI_PTCR, AT91C_PDC_TXTEN);				/* PDC Enable Tx */
	
		return jump_addr;
	
	}
	else
#endif
	dbg_print("chek3 \n\r");
	if (addr == IMG_ADDRESS_LOADER) {
	//dbg_print("chek4 \n\r");
		return JUMP_ADDR_LOADER;
		
		}
	else
    {
        dbg_print("chek4 \n\r");
        return jump_addr;//jump_addr;//0x10000060; 
    }
		
} 

