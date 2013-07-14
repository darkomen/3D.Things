#include "basicsquaredpcb.h"

BasicSquaredPCB::BasicSquaredPCB(double thickness, double side, double drill_diam, double drill_x, double drill_y)
{
    this->thickness = thickness;
    this->side = side;
    this->drill_diam = drill_diam;
    this->drill_x = drill_x;
    this->drill_y = drill_y;

}

//-- Data interface:
double BasicSquaredPCB::get_thickness() { return thickness; }
double BasicSquaredPCB::get_side()	    { return side; }
double BasicSquaredPCB::get_drill_diam() { return drill_diam; }
double BasicSquaredPCB::get_drill_x()    { return drill_x; }
double BasicSquaredPCB::get_drill_y()    { return drill_y; }


Component BasicSquaredPCB::build()
{
    //-- PCB:
    Component pcb = RoundedTablet( side, side, thickness, side/20 );

    //-- Holes:
    Component hole_base = Cylinder( drill_diam/2.0, thickness + 0.1);
    Component hole01 = hole_base.translatedCopy(  drill_x/2.0,  drill_y/2.0, 0);
    Component hole02 = hole_base.translatedCopy( -drill_x/2.0,  drill_y/2.0, 0);
    Component hole03 = hole_base.translatedCopy(  drill_x/2.0, -drill_y/2.0, 0);
    Component hole04 = hole_base.translatedCopy( -drill_x/2.0, -drill_y/2.0, 0);
    Component holes = hole01 + hole02 + hole03 + hole04;

    //-- Make board:
    Component basic_board = pcb - holes;

    //-- Add some links:
    //-- 4 for the upper side drills:
    basic_board.addLink( RefSys(  drill_x/2.0,  drill_y/2.0, thickness/2.0));
    basic_board.addLink( RefSys( -drill_x/2.0,  drill_y/2.0, thickness/2.0));
    basic_board.addLink( RefSys(  drill_x/2.0, -drill_y/2.0, thickness/2.0));
    basic_board.addLink( RefSys( -drill_x/2.0, -drill_y/2.0, thickness/2.0));

    //-- 4 for the lower side drills (looking downwards):
    basic_board.addLink( RefSys(  drill_x/2.0,  drill_y/2.0, -thickness/2.0).relRotate(180,0,0));
    basic_board.addLink( RefSys( -drill_x/2.0,  drill_y/2.0, -thickness/2.0).relRotate(180,0,0));
    basic_board.addLink( RefSys(  drill_x/2.0, -drill_y/2.0, -thickness/2.0).relRotate(180,0,0));
    basic_board.addLink( RefSys( -drill_x/2.0, -drill_y/2.0, -thickness/2.0).relRotate(180,0,0));

    //-- Put some color:
    basic_board.color( 0.2, 0.2, 0.5);

    return basic_board;
}
