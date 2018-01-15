#ifndef USRDATAUSR_BASE_H
#define USRDATAUSR_BASE_H

struct UsrData;
struct UsrDataUsr_base
{
    UsrDataUsr_base(UsrData* ParentusrData);
    ~UsrDataUsr_base();
protected:
    UsrData* ParentusrData;
};

#endif // USRDATAUSR_BASE_H
