/*******************************************************************************
File name: FlashApp.h                                                       ****
File description:   Flash driver application manager.                       ****
MCU:                PIC18F45k22                                             ****
Date modified: 29/01/2018 16:14.                                            ****
Author: RoeeZ (Comm-IT).                                                    ****
*******************************************************************************/

#ifndef FLASHAPP_H
#define	FLASHAPP_H

#include <stdint.h>
#include "SystemCommon.h"

// Manage flash
#define SAMPLE_START_ADDRESS        0x4580     // Need to be in multiple of 64
#define SAMPLE_END_ADDRESS          0x7FF0
#define PROGRAM_START_ADDRESS       0xe
#define MAX_NUMBER_BYTES_IN_TEST    128
#define NUM_SAMPLE_IN_PACKET        2
#define FLASH_FREE_SPACE_THRESHOLD  75 

// Flash state
#define FLASH_READ_CONDITION_MAX_DATA_SIZE 4

// Define TX packets type, locations and size
#define FLASH_TX_PACKET_SIZE WRITE_FLASH_BLOCKSIZE + MSG_DATA_LOCATION 
#define FLASH_READ_CONDITION_PACKET_SIZE FLASH_READ_CONDITION_MAX_DATA_SIZE + MSG_DATA_LOCATION 

// EEPRM Address
#define EEPROM_SYNTH_TX_REGS_ADDRESS_OFSEET     (0)
#define EEPROM_SYNTH_RX_REGS_ADDRESS_OFSEET     (0x20)

#define EEPROM_DAC_REGS_ADDRESS_OFSEET          (0x40)

// Flash routines:
void FlashSampleWrite(adc_result_t sampleData, uint8_t channelNum);
void FlashReadUart(char* data);
void FlashEreaseMem(void);
void FlashReadCondition(void);
bool CheckFlashPrecentage(void);

// EEPROMM routines:
uint8_t EepromRead(uint8_t address);
void EepromWrite(uint8_t address, uint8_t data);

#endif	/* FLASHAPP_H */

