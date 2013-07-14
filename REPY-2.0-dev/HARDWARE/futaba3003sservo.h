#ifndef FUTABA3003SSERVO_H
#define FUTABA3003SSERVO_H

#include "basicservo.h"

class Futaba3003sServo : public BasicServo
{
public:
    Futaba3003sServo();

protected:
    virtual void set_horn( int arms, bool visibility = true, double cut = 0);

};

#endif // FUTABA3003SSERVO_H
