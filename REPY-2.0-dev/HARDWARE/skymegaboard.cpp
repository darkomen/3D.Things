#include "skymegaboard.h"

//-- Default constructor
SkyMegaBoard::SkyMegaBoard() : BasicSquaredPCB( 3, 52, 3, 30, 30)
{
    //-- Dimensions: thickness, side, drill_diam, drill_x, drill_y

    rebuild();
}
