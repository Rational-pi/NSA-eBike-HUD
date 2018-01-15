#include "usrdata.h"

uint16_t UsrData::version=V1;

UsrData *UsrData::read(uint16_t memoryOffset){
    UsrData *ret=new UsrData();
    ret->memoryOffset=memoryOffset;
    if (eeprom_read_byte(0+memoryOffset)==((char*)(&version))[0] &&
            eeprom_read_byte(1+memoryOffset)==((char*)(&version))[1])
    {
        for (unsigned int t=0; t<sizeof(UsrData); t++)
            *((char*)ret + t) = eeprom_read_byte(t+2+memoryOffset);
        return ret;
    }
    delete ret;
    return nullptr;
}

void UsrData::wright(UsrData *x){
    eeprom_write_byte(0+x->memoryOffset, ((char*)&version)[0]);
    eeprom_write_byte(1+x->memoryOffset, ((char*)&version)[1]);
    for (unsigned int t=0; t<sizeof(UsrData); t++)
        eeprom_write_byte(t+2+x->memoryOffset, *((char*)x + t));
}

/// give property to the UsrData
UsrData *UsrData::build(uint16_t memoryOffset){
    UsrData *ret=UsrData::read(memoryOffset);
    if (ret==nullptr){
        ret=new UsrData();
        ret->loadedFromEEprom=false;
    }else ret->loadedFromEEprom=true;
    return ret;
}



UsrData::UsrData(){}
