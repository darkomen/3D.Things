#include "futaba3003sservo.h"

Futaba3003sServo::Futaba3003sServo(): BasicServo()
{
    //-- Servo body dimensions:
    //---------------------------------------------------------------------------------
    //-- Main dimensions:
    width = 20.;
    length = 40.5;
    height = 37.5;

    //-- Leg dimensions:
    leg_h = 27;
    leg_x = 20;
    leg_y = 7.5;
    leg_z = 4;

    //-- Leg holes
    num_holes = 4;
    hole_r = 4.5/2.0;
    hole_x = 5;
    hole_y = 3;

    //-- Axis dimensions:
    axis_h = 4.5;
    axis_r = 3;
    axis_y = 30;

    //-- Horn placement:
    horn_dist_axis = 4;

    //-- Tolerances by default:
    width_tol = 0;
    length_tol = 0;
    height_tol = 0;

    //-- Color (black):
    servo_color.push_back( 0.5); //-- Red
    servo_color.push_back( 0.5); //-- Green
    servo_color.push_back( 0.5); //-- Blue
    servo_color.push_back( 1.0); //-- Alpha channel

    //-- Horn dimensions:
    //----------------------------------------------------------------------------------
    set_horn( 0 );

    rebuild();
}

void Futaba3003sServo::set_horn( int arms, bool visibility, double cut)
{
    //-- Common settings:
    //--------------------------------------------------------------------
    horn_num_arms = arms;
    display_horn = visibility;
    horn_cut = cut;

    horn_tol = 0;

    //-- Color (black)
    horn_color.push_back( 0.5); //-- Red
    horn_color.push_back( 0.5); //-- Green
    horn_color.push_back( 0.5); //-- Blue
    horn_color.push_back( 1.0); //-- Alpha channel

    //-- Set parameters depending on the number of arms of the servo horn:
    //--------------------------------------------------------------------
    switch( horn_num_arms )
    {
    default:
	horn_num_arms = 0;

    case 0:
	//-- Rounded horn:
	horn_h_top = 3;
	horn_r_top = 20.5 / 2.0;
	horn_h_axis = 3.5;
	horn_r_axis = 9 / 2.0;
	//-- Not needed for rounded horn:
	horn_arm_r = 0;
	horn_arm_shift = 0;
	horn_arm_dist = 0;
	break;

    case 2:
	//-- 2-arms horn:
	horn_h_top = 3;
	horn_r_top = 12.5 / 2.0;
	horn_h_axis = 3;
	horn_r_axis = 9 / 2.0;
	horn_arm_r = 5 / 2.0;
	horn_arm_shift = 0;
	horn_arm_dist = 19 - 5 / 2.0;
	break;

    case 4:
	//-- 4-arms horn:
	horn_h_top = 3;
	horn_r_top = 13.5 / 2.0;
	horn_h_axis = 3;
	horn_r_axis = 9 / 2.0;
	horn_arm_r = 4.5 / 2.0;
	horn_arm_shift = 7;
	horn_arm_dist = 18 - 4.5 / 2.0;
	break;

    case 6:
	//-- 6-arms horn:
	horn_h_top = 3;
	horn_r_top = 15 / 2.0;
	horn_h_axis = 3;
	horn_r_axis = 9 / 2.0;
	horn_arm_r = 5 / 2.0;
	horn_arm_shift = 0;
	horn_arm_dist = (31.5 - 5) / 2.0;
	break;
    }

    rebuild();
}
