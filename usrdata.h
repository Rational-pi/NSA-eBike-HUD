#ifndef USRDATA_H
#define USRDATA_H

#include <avr/eeprom.h>
#include <inttypes.h>

///eeprom parser
template <typename Type>
struct EEParser{
    static void read(Type *data,uint16_t eepromAdresse){
        for (unsigned int t=0; t<sizeof(Type); t++)
            *((char*)data + t) = eeprom_read_byte(eepromAdresse+t);
    }

    static void wright(Type *data,uint16_t eepromAdresse){
        for (unsigned int t=0; t<sizeof(Type); t++)
            eeprom_write_byte(eepromAdresse+t, *((char*)data + t));
    }
};



#endif // USRDATA_H
