#ifndef __LTC2620_H__
#define __LTC2620_H__
#include "main.h"

typedef enum
{
    LTC2620_COMMAND_WRITE_N             = 0x0,
    LTC2620_COMMAND_UPDATE_N            = 0x1,
    LTC2620_COMMAND_WRITE_N_UPDATE_ALL  = 0x2,
    LTC2620_COMMAND_WRITE_N_UPDATE_N    = 0x3,
    LTC2620_COMMAND_POWER_DOWN_N        = 0x4,
    LTC2620_COMMAND_NOTHING             = 0xF,
} LTC2620_Command_t;

typedef enum
{
    LTC2620_CHANNEL_A   = 0x0,
    LTC2620_CHANNEL_B   = 0x1,
    LTC2620_CHANNEL_C   = 0x2,
    LTC2620_CHANNEL_D   = 0x3,
    LTC2620_CHANNEL_E   = 0x4,
    LTC2620_CHANNEL_F   = 0x5,
    LTC2620_CHANNEL_G   = 0x6,
    LTC2620_CHANNEL_H   = 0x7,
    LTC2620_CHANNEL_ALL = 0xF,
} LTC2620_Channel_t;

#define LTC2620_VOLTAGE_REFERENCE  4.096
#define LTC2620_RESOLUTION         12

uint16_t voltCodeConvert(float volt);
void setVoltage(uint8_t *commandBuffer, uint16_t code);
void setCommand(uint8_t *commandBuffer, LTC2620_Command_t command);
void setChannel(uint8_t *commandBuffer, LTC2620_Channel_t channel);

#endif