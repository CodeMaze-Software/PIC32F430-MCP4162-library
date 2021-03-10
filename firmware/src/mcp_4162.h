/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H

#include <stdint.h> 

#define CS_SET()               (LATDSET = (1<<4))
#define CS_CLEAR()             (LATDCLR = (1<<4))
#define CS_ENABLE()            (TRISDCLR = (1<<4))
#define WRITE_CMD              (0x00)
#define READ_CMD               (0x0C)
#define NVM_WRITE              (0x60)
#define NVM_READ               (0x6C)

uint8_t mcp_4162_init(void);
void mcp_4162_write(uint8_t value);
void mcp_4162_eeprom_write(uint8_t value);
uint8_t mcp_4162_read(void);
uint8_t mcp_4162_eeprom_read(void);




#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
