#include "towerprosg90servo.h"


TowerProSG90servo::TowerProSG90servo(): BasicServo()
{
    //-- Servo body dimensions:
    //---------------------------------------------------------------------------------
    //-- Main dimensions:
    width = 12.7;
    length = 22.7;
    height = 27;

    //-- Leg dimensions:
    leg_h = 15.7;
    leg_x = 12;
    leg_y = 5;
    leg_z = 2.5;

    //-- Leg holes
    num_holes = 2;
    hole_r = 1.1;
    hole_x = 0;
    hole_y = 2.5;

    //-- Axis dimensions:
    axis_h = 2.5;
    axis_r = 4.7/2.0;
    axis_y = 17;

    //-- Horn placement:
    horn_dist_axis = 3.5;

    //-- Tolerances by default:
    width_tol = 0;
    length_tol = 0;
    height_tol = 0;

    //-- Color (blue):
    servo_color.push_back( 0); //-- Red
    servo_color.push_back( 0.); //-- Green
    servo_color.push_back( 1); //-- Blue
    servo_color.push_back( 1.0); //-- Alpha channel

    //-- Horn dimensions:
    //----------------------------------------------------------------------------------
    set_horn( 1 );

    rebuild();
}

void TowerProSG90servo::set_horn( int arms, bool visibility, double cut)
{
    //-- Common settings:
    //--------------------------------------------------------------------
    horn_num_arms = arms;
    display_horn = visibility;
    horn_cut = cut;

    horn_tol = 0;

    //-- Color (white)
    horn_color.push_back( 1); //-- Red
    horn_color.push_back( 1); //-- Green
    horn_color.push_back( 1); //-- Blue
    horn_color.push_back( 1.0); //-- Alpha channel

    //-- Set parameters depending on the number of arms of the servo horn:
    //--------------------------------------------------------------------
    switch( horn_num_arms )
    {
    default:
	horn_num_arms = 2;

    case 1:
	//-- 1-arm horn:
	horn_h_top = 1.7;
	horn_r_top = 7.2 / 2.0;
	horn_h_axis = 2.7;
	horn_r_axis = 7.2 / 2.0;
	horn_arm_r = 3.6/2.0;
	horn_arm_shift = 0;
	horn_arm_dist = 19.6 -horn_r_top -horn_arm_r;
	break;

    case 2:
	//-- 2-arms horn:
	horn_h_top = 1.7;
	horn_r_top = 7.2 / 2.0;
	horn_h_axis = 2.7;
	horn_r_axis = 7.2 / 2.0;
	horn_arm_r = 3.6 / 2.0;
	horn_arm_shift = 0;
	horn_arm_dist = 32 /2.0 - horn_arm_r / 2.0;
	break;

    case 4:
	//-- 4-arms horn:
	horn_h_top = 1.7;
	horn_r_top = 8 / 2.0;
	horn_h_axis = 2.8;
	horn_r_axis = 7.2 / 2.0;
	horn_arm_r = 3.6 / 2.0;
	horn_arm_shift = 7;
	horn_arm_dist = 18 - 4.5 / 2.0;
	break;
    }

    rebuild();
}

