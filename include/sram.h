
#ifndef SRAM_H_
#define SRAM_H_
	
extern volatile const unsigned int* AT91C_BASE_SMC;

/* Set SETUP */
#define	SMC_NWESETUP(A)		(AT91C_SMC_NWESETUP  & (A << 0))
#define	SMC_NCSSETUPWR(A)	(AT91C_SMC_NCSSETUPWR & (A << 8))
#define SMC_NRDSETUP(A)		(AT91C_SMC_NRDSETUP & (A << 16))
#define	SMC_NCSSETUPRD(A)	(AT91C_SMC_NCSSETUPRD & (A << 24))

/* Set PULSE */
#define	SMC_NWEPULSE(A)		(AT91C_SMC_NWEPULSE & (A <<  0))
#define	SMC_NCSPULSEWR(A)	(AT91C_SMC_NCSPULSEWR & (A <<  8))
#define	SMC_NRDPULSE(A)		(AT91C_SMC_NRDPULSE & (A << 16))
#define	SMC_NCSPULSERD(A)	(AT91C_SMC_NCSPULSERD & (A << 24))

/* Set CYCLE */
#define	SMC_NWECYCLE(A)		(AT91C_SMC_NWECYCLE & (A << 0))
#define	SMC_NRDCYCLE(A)		(AT91C_SMC_NRDCYCLE & (A << 16))

extern void	init_sram(void);

#endif /*SDRAMC_H_*/
