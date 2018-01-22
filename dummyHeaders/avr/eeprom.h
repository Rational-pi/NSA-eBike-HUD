#ifndef EEPROMDUMMY
#define EEPROMDUMMY
#include "inttypes.h"

char eeprom_read_byte(uint8_t  pos){ return 0;}
void eeprom_write_byte(uint8_t pos, char byte){}

#endif
