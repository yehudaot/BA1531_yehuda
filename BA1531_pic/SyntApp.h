/*******************************************************************************
File name: SyntApp.c                                                        ****
File description:   TX and RX Synthesizers (ADF-5355) Application manager.  ****
MCU:                PIC18F45k22                                             ****
Date modified: 28/01/2018 16:14.                                            ****
Author: RoeeZ (Comm-IT).                                                    ****
*******************************************************************************/

#ifndef SYNTAPP_H
#define	SYNTAPP_H

#include "SystemCommon.h"

#define SYNTH_DELAY_BETWEEN_WORDS_MSEC      250
#define NUM_OF_TOTAL_REGISTERS              13
#define NUM_OF_UPDATE_CYCLES                0x7

#define NUM_OF_UART_TX_UPDATE_REGS          5
#define NUM_OF_BYTES_UART_TX_UPDATE_REGS    5
#define IDX_SYNTH_OPER_STATE_PLACE          NUM_OF_BYTES_UART_TX_UPDATE_REGS * NUM_OF_UART_TX_UPDATE_REGS + 2

#define SYNTH_READ_CONDITION_MAX_DATA_SIZE  IDX_SYNTH_OPER_STATE_PLACE - MSG_DATA_LOCATION
#define SYNTH_READ_CONDITION_PACKET_SIZE    IDX_SYNTH_OPER_STATE_PLACE + 1 

#define SYNTH_LD_TRIES                      2
#define SYNTH_LD_NUM_BITS                   12

const uint32_t SYNTH_REGS[NUM_OF_TOTAL_REGISTERS] = 
{
    0x1041C,        /* R12  */
    0x61300B,       /* R11  */
    0xC0193A,       /* R10  */
    0x1110FCC9,     /* R09  */
    0x102D0428,     /* R08  */
    0x120000E7,     /* R07  */
    0x35006076,     /* R06  */
    0x800025,       /* R05  */
    0x800BF84,      /* R04  */
    0x3,            /* R03  */
    0x12,           /* R02  */
    0xC000001,      /* R01  */
    0x200680        /* R00  */
};

const uint8_t SYNTH_ADDRES[NUM_OF_TOTAL_REGISTERS] = 
{
    // SYNTH_TX + RX
    0x4,        // REG_0
    0x8,        // REG_1
    0xC,        // REG_2
    0x00,       // Reserved place for REG 3
    0x10,       // REG 4
    0x00,       // Reserved place  for REG 5
    0x14,       // REG 6
    0x00,       // Reserved place  for REG 7
    0x00,       // Reserved place  for REG 8
    0x00,       // Reserved place  for REG 9
    0x18,       // REG 10
    0x1C,       // Store fRf value
    0x00,       // Reserved place  for REG 12
};

typedef enum
{   
    UNLOCK  = 0x0,
    LOCK    = 0x1,            
} SYNTH_LD_STATE;


// define LD array (TX + RX)
volatile bool synthLdRxArray[SYNTH_LD_NUM_BITS];
volatile bool synthLdTxArray[SYNTH_LD_NUM_BITS];

void PLLInitialize(void);
void InitSynth(SPI_PERIPHERAL cType);
void UpdateSynthFreq(SPI_PERIPHERAL cType, char* data);
void SetSynthOper(SPI_PERIPHERAL cType);
void SynthReadData(SPI_PERIPHERAL cType, char* data);
void SynthLdDetect(void);

#endif	/* SYNTAPP_H */

