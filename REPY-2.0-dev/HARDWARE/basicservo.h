//------------------------------------------------------
//-- Basic servo
//------------------------------------------------------
//-- A simple servo
//-- It is used for creating the module.
//-- New servo component should inherit from this one.
//------------------------------------------------------
//-- Author: David Estevez (DEF)
//------------------------------------------------------

#ifndef BASIC_SERVO_H
#define BASIC_SERVO_H

#include <ooml/core.h>
#include <ooml/components.h>


class BasicServo: public AbstractPart
{
public:
    //-- Object dimensions interface:
    //---------------------------------------
    //-- Main dimensions:
    double get_width();
    double get_length();
    double get_height();

    //-- Leg dimensions:
    double get_leg_h();
    double get_leg_x();
    double get_leg_y();
    double get_leg_z();

    //-- Leg holes
    int get_num_holes();
    double get_hole_r();
    double get_hole_x();
    double get_hole_y();

    //-- Axis dimensions:
    double get_axis_h();
    double get_axis_r();
    double get_axis_y();

    //-- Horn positioning:
    double get_horn_dist_axis();

    //-- Tolerances:
    double get_width_tol();
    double get_length_tol();
    double get_height_tol();

    //-- Horn dimensions:
    double get_horn_num_arms();
    double get_horn_h_top();
    double get_horn_r_top();
    double get_horn_h_axis();
    double get_horn_r_axis();
    double get_horn_arm_r();
    double get_horn_arm_shift();
    double get_horn_tol();
    double get_horn_cut();

    //-- Horn (others:)
    bool horn_shown();
    Component get_horn();

    //-- Servo configuration:
    //-----------------------------------------------------------------
    virtual void set_horn( int arms, bool visibility = true, double cut = 0) = 0;
    void set_tolerances( double width_tol, double length_tol, double height_tol );

protected:
    BasicServo();

    virtual Component build();

    virtual Component make_horn();

    //-- Servo characteristics:
    //---------------------------------------
    //-- Main dimensions:
    double width, length, height;

    //-- Leg dimensions:
    double leg_h, leg_x, leg_y, leg_z;

    //-- Leg holes
    int num_holes;
    double  hole_r, hole_x, hole_y;

    //-- Axis dimensions:
    double axis_h, axis_r, axis_y;

    //-- Horn positioning:
    double horn_dist_axis;

    //-- Tolerances:
    double width_tol;
    double length_tol;
    double height_tol;

    //-- Color:
    std::vector<double> servo_color;

    //-- Horn characteristics:
    //----------------------------------------
    Component horn;
    bool display_horn;

    int horn_num_arms;
    double horn_h_top, horn_r_top;
    double horn_h_axis, horn_r_axis;
    double horn_arm_r, horn_arm_shift, horn_arm_dist;
    double horn_tol;
    double horn_cut; //-- For cutting the round horn.

    std::vector<double> horn_color;
};


#endif // BASIC_SERVO_H
