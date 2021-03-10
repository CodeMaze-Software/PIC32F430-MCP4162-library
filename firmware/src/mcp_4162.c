/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "mcp_4162.h"
#include <stdlib.h>
#include "definitions.h"

static uint8_t cmd;
static uint8_t payload;

uint8_t mcp_4162_init(void)
{
    CS_ENABLE();
    CS_SET();
    
    return mcp_4162_eeprom_read();
}

void mcp_4162_write(uint8_t value)
{
    cmd = WRITE_CMD;
    
    CS_CLEAR();
    SPI1_Write(&cmd, sizeof(uint8_t));
    SPI1_Write(&value, sizeof(uint8_t));
    CS_SET();
    
    mcp_4162_eeprom_write(value);
}

void mcp_4162_eeprom_write(uint8_t value)
{
    cmd = NVM_WRITE;
    
    CS_CLEAR();
    SPI1_Write(&cmd, sizeof(uint8_t));
    SPI1_Write(&value, sizeof(uint8_t));
    CS_SET();    
}

uint8_t mcp_4162_read(void)
{
    cmd = READ_CMD;
        
    CS_CLEAR();
    SPI1_Write(&cmd, sizeof(uint8_t));
    SPI1_Read(&payload, sizeof(uint8_t));
    CS_SET();
    
    return payload;
}

uint8_t mcp_4162_eeprom_read(void)
{
    cmd = NVM_READ;
        
    CS_CLEAR();
    SPI1_Write(&cmd, sizeof(uint8_t));
    SPI1_Read(&payload, sizeof(uint8_t));
    CS_SET();
    
    return payload;
}





/* *****************************************************************************
 End of File
 */
