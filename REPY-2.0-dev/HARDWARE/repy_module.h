//------------------------------------------------------
//-- REPY-2.0
//------------------------------------------------------
//
//------------------------------------------------------
//-- Author: David Estevez (DEF)
//------------------------------------------------------
//-- Based on REPY module, by
//-- Juan Gonzalez-Gomez (Obijuan)
//------------------------------------------------------

#ifndef REPY_MODULE_H
#define REPY_MODULE_H

#include <ooml/core.h>
#include <ooml/components.h>

#include "basicservo.h"
#include "skymegaboard.h"


class REPY_module : public AbstractPart
{
public:
    REPY_module(BasicServo& servo,  BasicSquaredPCB& pcb);

protected:
    virtual Component build();

private:
    Component lower_part();
    Component upper_part();
    Component make_ear( double base, double height, double thickness, double shift, double radius);

    //-- Needed components that define the module:
    BasicServo * servo;
    BasicSquaredPCB * pcb;
    Component fake_axis, fake_axis_with_tol;

    //-- Needed dimensions
    //--------------------------------------------
    //-- General:
    double board_safe;

    //-- Lower part:
    double lower_base_thickness;
    double lower_front_ear_thickness;
    double lower_back_ear_thickness;
    double lower_ear_shift;
    double lower_ear_radius;
    double lower_screw_safe;
    double lower_border_safe;

    //-- Upper part:
    double upper_base_thickness;
    double upper_front_ear_thickness;
    double upper_back_ear_thickness;
    double upper_ear_shift;
    double upper_ear_radius;
    double upper_screw_safe;
    double upper_border_safe;

    //-- Tolerances:
    double body_servo_x_tol;	//-- Clearance to insert the servo, x axis
    double body_servo_y_tol;	//-- Clearance to insert the servo, y axis
    double ear_clearance_tol;	//-- Clearance between touching ears
    double fake_axis_tol;	//-- Clearance for the fake axis

    //-- Visibility flags:
    bool show_servo;
    bool show_assembly; //-- (show assembly/print)
    bool show_lower;	//-- (show lower part)
    bool show_upper;	//-- (show upper part)

    //-- Dimensions calculated automatically by the software:
    double side;
    double central_part;
};

#endif // REPY_MODULE_H
