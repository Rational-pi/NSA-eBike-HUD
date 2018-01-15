#include "usrdatausr_base.h"
#include "usrdata.h"

UsrDataUsr_base::UsrDataUsr_base(UsrData *ParentusrData)
{
    this->ParentusrData=ParentusrData;
}

UsrDataUsr_base::~UsrDataUsr_base()
{
    UsrData::wright(ParentusrData);
}
