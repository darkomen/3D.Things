#ifndef TOWERPROSG90SERVO_H
#define TOWERPROSG90SERVO_H


#include "basicservo.h"

class TowerProSG90servo: public BasicServo
{
public:
    TowerProSG90servo();

protected:
    virtual void set_horn( int arms, bool visibility = true, double cut = 0);
};

#endif // TOWERPROSG90SERVO_H
