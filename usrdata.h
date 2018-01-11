#ifndef USRDATA_H
#define USRDATA_H

#include <avr/eeprom.h>
#include <inttypes.h>

#define V1 0x0001

struct UsrData{
    bool loadedFromEEprom;
    uint64_t num;
    static UsrData *read(){
        UsrData *ret=new UsrData();
        if (eeprom_read_byte(0)==((char*)(&version))[0] &&
            eeprom_read_byte(1)==((char*)(&version))[1])
        {
            for (unsigned int t=0; t<sizeof(UsrData); t++)
                  *((char*)ret + t) = eeprom_read_byte(t+2);
            return ret;
        }
        delete ret;
        return nullptr;
    }
    static void wright(UsrData *x){
        eeprom_write_byte(0, ((char*)&version)[0]);
        eeprom_write_byte(1, ((char*)&version)[1]);
        for (unsigned int t=0; t<sizeof(UsrData); t++)
            eeprom_write_byte(t+2, *((char*)x + t));
    }
    static UsrData *build(){
        UsrData *ret=UsrData::read();
        if (ret==nullptr){
            ret=new UsrData();
            ret->loadedFromEEprom=false;
        }else ret->loadedFromEEprom=true;
        return ret;
    }
private:
    UsrData(){}
        static uint16_t version;
};

uint16_t UsrData::version=V1;


#endif // USRDATA_H
