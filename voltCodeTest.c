#include <stdio.h>
#include <stdint.h>
#include <math.h>

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

uint16_t voltCodeConvert(float volt) {

    uint16_t code = floor((volt * pow(2, 12)) / 4.096);

    return code;
}

int main() {
    uint8_t commandBuffer[3];
    uint16_t code = voltCodeConvert(3.512);
    setVoltage(commandBuffer, code);
    setCommand(commandBuffer, LTC2620_COMMAND_WRITE_N_UPDATE_N);
    setChannel(commandBuffer, LTC2620_CHANNEL_G);

    printBinary()

    return 0;
}


void print_binary(int value)
{
    unsigned mask = ~(~0u >> 1);  // set highest bit

    // iterate over all bits:
    for (size_t i = 0; i < sizeof(value) * CHAR_BIT; ++i) {
        putchar('0' + !!(value & mask));  // !! converts to bool 0 or 1
        mask >>= 1;  // shift to next lower bit
    }
}

void setVoltage(uint8_t *commandBuffer, uint16_t code) {
    commandBuffer[1] = (uint8_t)((code >> 8) & 0xFF);
    commandBuffer[2] = (uint8_t)(code & 0xFF);
}

void setCommand(uint8_t *commandBuffer, LTC2620_Command_t command) {
    commandBuffer[0] = (commandBuffer[0] & 0x0F) | ((command & 0x0F) << 4);
}

void setChannel(uint8_t *commandBuffer, LTC2620_Channel_t channel) {
    commandBuffer[0] = (commandBuffer[0] & 0xF0) | (channel & 0x0F);
}