#include "ltc2620.h"

uint16_t voltCodeConvert(float volt) {

    uint16_t code = floor((volt * pow(2, LTC2620_RESOLUTION)) / LTC2620_VOLTAGE_REFERENCE);

    return code;
}

/*! A test class */
void setVoltage(uint8_t *commandBuffer, uint16_t code) {
    commandBuffer[1] = (uint8_t)((code >> 8) & 0xFF);
    commandBuffer[2] = (uint8_t)(code & 0xFF);
}

/*! A test class */
void setCommand(uint8_t *commandBuffer, LTC2620_Command_t command) {
    commandBuffer[0] = (commandBuffer[0] & 0x0F) | ((command & 0x0F) << 4);
}


/// @brief This method adds two integers.
/// @param a First integer to add.
/// @param b Second integer to add.
/// @return The sum of both parameters.
void setChannel(uint8_t *commandBuffer, LTC2620_Channel_t channel) {
    commandBuffer[0] = (commandBuffer[0] & 0xF0) | (channel & 0x0F);
}

/*! A test class */
void SPI_SendBytes(SPI_TypeDef* SPIx, uint8_t* data, uint16_t length)
{
    for(uint16_t i = 0; i < length; i++)
    {
        while (!LL_SPI_IsActiveFlag_TXE(SPIx)) { }
        LL_SPI_TransmitData8(SPIx, data[i]);

        // Depending on your needs, you might check for RXNE, read the data, etc.
        //while (!LL_SPI_IsActiveFlag_RXNE(SPIx)) { }
        //(void)LL_SPI_ReceiveData8(SPIx);
    }
}