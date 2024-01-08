/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
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
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "../include/pit.h"

#define BOARD_MAINOSC           18432000
/// Master clock frequency in Hz when using the board default LowLevelInit
#define BOARD_MCK               ((BOARD_MAINOSC * 11 / 1) / 2)

//------------------------------------------------------------------------------
//         Global Functions
//------------------------------------------------------------------------------
void initPIT()
{
    AT91C_BASE_PITC->PITC_PIMR = BOARD_MCK / (16 * 1000) - 1;
    AT91C_BASE_PITC->PITC_PIMR |= (1 << 24);
}

void disablePIT()
{
    AT91C_BASE_PITC->PITC_PIMR &= 0xFEFFFFFF;
}

int getPSR() 
{
    return (AT91C_BASE_PITC->PITC_PISR & AT91C_PITC_PITS);
}

int getPVR()
{
    return AT91C_BASE_PITC->PITC_PIVR;
}

int getPIR()
{
    return (AT91C_BASE_PITC->PITC_PIIR & 0xFFFFF);
}