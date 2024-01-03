
#include "../include/part.h"
#include "../include/gpio.h"
#include "../include/sram.h"
#include "../include/main.h"

extern volatile const unsigned int* AT91C_BASE_SMC = (volatile unsigned int*)0xFFFFE400;

	inline	static	void delay(void) {
		volatile unsigned int	i;
		for(i = 0; i < 10000; i++); 
	}
	
	/*-----------------------------------------------------------------------------
	 * Function Name       : sram_pio_init
	 * Object              : Init PIO for SRAM
	 *-----------------------------------------------------------------------------*/
	inline static	void sram_pio_init(void) {

		/* Configure PIOs */
		const struct pio_desc sram_pio[] = {
			{"D16", AT91C_PIN_PD(16), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D17", AT91C_PIN_PD(17), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D18", AT91C_PIN_PD(18), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D19", AT91C_PIN_PD(19), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D20", AT91C_PIN_PD(20), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D21", AT91C_PIN_PD(21), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D22", AT91C_PIN_PD(22), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D23", AT91C_PIN_PD(23), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D24", AT91C_PIN_PD(24), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D25", AT91C_PIN_PD(25), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D26", AT91C_PIN_PD(26), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D27", AT91C_PIN_PD(27), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D28", AT91C_PIN_PD(28), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D29", AT91C_PIN_PD(29), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D30", AT91C_PIN_PD(30), 0, PIO_DEFAULT, PIO_PERIPH_A},
			{"D31", AT91C_PIN_PD(31), 0, PIO_DEFAULT, PIO_PERIPH_A}};

		pio_setup(sram_pio);

	}	
	 
	/*-----------------------------------------------------------------------------
	 * Function Name       : init_sram
	 * Object              : Init external SRAM
	 *-----------------------------------------------------------------------------*/
	void	init_sram(void) {
		volatile unsigned int* pSram = (volatile unsigned int*)	AT91C_BASE_SMC;				
		/* Init PIO for SRAM */
		sram_pio_init();
		
		/* Init SMC_SETUP0 */
		*(pSram + 0) = (SMC_NWESETUP(0)							// 2
									| SMC_NCSSETUPWR(0)			// 1
									| SMC_NRDSETUP(0)			// 2
									| SMC_NCSSETUPRD(0));		// 1 
		/* Init SMC_PULSE0 */					
		*(pSram + 1) = (SMC_NWEPULSE(3)							// 3
									| SMC_NCSPULSEWR(3)			// 5
									| SMC_NRDPULSE(3)			// 3
									| SMC_NCSPULSERD(3));		// 5
		/* Init SMC_CYCLE0 */					
		*(pSram + 2) = (SMC_NWECYCLE(4)							// 7
									| SMC_NRDCYCLE(4));			// 7 
		
		/* Init SMC_CYCLE0 */		
		*(pSram + 3) = (AT91C_SMC_READMODE
									| AT91C_SMC_WRITEMODE
									//| AT91C_SMC_NWAITM_NWAIT_ENABLE_READY//AT91C_SMC_NWAITM_NWAIT_DISABLE
									// | AT91C_SMC_BAT
									| AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS ); 
									//| ((0x1 << 16) & AT91C_SMC_TDF));
		/* Some delay */
		delay();
	}
