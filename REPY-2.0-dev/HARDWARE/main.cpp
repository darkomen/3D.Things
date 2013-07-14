//------------------------------------------------------
//-- REPY-2.0
//------------------------------------------------------
//-- This file generates all the scad and stl files
//-- for the lower part, the upper part with each kind
//-- of servo horn and the assembly view.
//------------------------------------------------------
//-- Author: David Estevez (DEF)
//------------------------------------------------------
//-- Based on REPY module, by
//-- Juan Gonzalez-Gomez (Obijuan)
//------------------------------------------------------

#include <ooml/core.h>
#include <ooml/components.h>
#include <iostream>
#include <fstream>

#include "fakefutaba3003sservo.h"
#include "towerprosg90servo.h"
#include "skymegaboard.h"
#include "repy_module.h"

using namespace std;

int main()
{
    cout << "Testing lower part of REPY component...";
    cout << endl << "[+] Making board... ";
    //SkyMegaBoard myBoard;
    BasicSquaredPCB myBoard( 15, 35, 3, 30, 30);

    cout << "[ok]\n[+] Making servo... ";
    FakeFutaba3003sServo myServo;
    cout << "[ok]\n[+] Making test module... ";
    REPY_module myTest( myServo, myBoard);


    //-- Printing the upper part
    IndentWriter writer;
    writer << myTest << RefSysView( myTest);

    ofstream file("./scad/REPY-2.0_test_new_repy.scad");
    if (file)
    {
	file << "//-------------------------------------------------------------------------" << endl;
	file << "//-- REPY-2.0_test.scad" << endl;
	file << "//-------------------------------------------------------------------------" << endl;
	file << "//--This file has been generated automatically according to your data."<< endl;
	file << "//--For more info, visit: http://iearobotics.com/oomlwiki/"<< endl;
	file << "//--------------------------------------------------------------------------" << endl << endl;
	file << writer;
	file.close();
	//cout << "REPY-2.0_assembly.scad created succesfully." << endl;
    }
    else
    {
	cerr << "Error, cannot open the file" << endl;
    }
    cout << "[ok]\n";
    //cout << writer << endl << endl;

 /*   //-- This file will generate all the .scad files for all the parts when executed:

    system( "mkdir scad");

    //-- Lower part:
    //--------------------------------------------------------------------------------------------------------------------
    REPY_lower lower_part;   Component horn = axis;
    lower_part.showServo(false);

    //-- Printing the lower part
    IndentWriter writer_lower;
    writer_lower << lower_part;
    //cout << writer_lower << endl << endl;

    ofstream file_lower("./scad/REPY-2.0_lower.scad");
    if (file_lower)
    {
        file_lower << "//-------------------------------------------------------------------------" << endl;
        file_lower << "//-- REPY-2.0_lower.scad" << endl;
        file_lower << "//-------------------------------------------------------------------------" << endl;
        file_lower << "//--This file has been generated automatically according to your data."<< endl;
        file_lower << "//--For more info, visit: http://iearobotics.com/oomlwiki/"<< endl;
        file_lower << "//--------------------------------------------------------------------------" << endl << endl;
        file_lower << writer_lower;
        file_lower.close();
        cout << "REPY-2.0_lower.scad created succesfully." << endl;
    }
    else
    {
        cerr << "Error, cannot open the file" << endl;
    }



    //-- Upper part
    //---------------------------------------------------------------------------------------------------------------------

    //-- Rounded horn:
    //-------------------------------------------------------
    REPY_upper upper_part;
    upper_part.hornType(1);

    //-- Printing the upper part
    IndentWriter writer_upper;
    writer_upper << upper_part;
    //cout << writer_upper << endl << endl;

    ofstream file_upper("./scad/REPY-2.0_upper_rounded_horn.scad");
    if (file_upper)
    {
        file_upper << "//-------------------------------------------------------------------------" << endl;
        file_upper << "//-- REPY-2.0_upper_rounded_horn.scad" << endl;
        file_upper << "//-------------------------------------------------------------------------" << endl;
        file_upper << "//--This file has been generated automatically according to your data."<< endl;
        file_upper << "//--For more info, visit: http://iearobotics.com/oomlwiki/"<< endl;
        file_upper << "//--------------------------------------------------------------------------" << endl << endl;
        file_upper << writer_upper;
        file_upper.close();
        cout <<  "REPY-2.0_upper_rounded_horn.scad created succesfully." << endl;
    }
    else
    {
        cerr << "Error, cannot open the file" << endl;
    }


    //-- 2 arms horn:
    //-------------------------------------------------------
    upper_part.hornType(2);

    IndentWriter writer_upper_2;
    writer_upper_2 << upper_part;


    file_upper.open("./scad/REPY-2.0_upper_2_arms_horn.scad");
    if (file_upper)
    {
        file_upper << "//-------------------------------------------------------------------------" << endl;
        file_upper << "//-- REPY-2.0_upper_2_arms_horn.scad" << endl;
        file_upper << "//-------------------------------------------------------------------------" << endl;
        file_upper << "//--This file has been generated automatically according to your data."<< endl;
        file_upper << "//--For more info, visit: http://iearobotics.com/oomlwiki/"<< endl;
        file_upper << "//--------------------------------------------------------------------------" << endl << endl;
        file_upper << writer_upper_2;
        file_upper.close();
        cout <<  "REPY-2.0_upper_2_arms_horn.scad created succesfully." << endl;
    }
    else
    {
        cerr << "Error, cannot open the file" << endl;
    }


    //-- 4 arms horn:
    //-------------------------------------------------------
    upper_part.hornType(4);

    IndentWriter writer_upper_4;
    writer_upper_4 << upper_part;


    file_upper.open("./scad/REPY-2.0_upper_4_arms_horn.scad");
    if (file_upper)
    {
        file_upper << "//-------------------------------------------------------------------------" << endl;
        file_upper << "//-- REPY-2.0_upper_4_arms_horn.scad" << endl;
        file_upper << "//-------------------------------------------------------------------------" << endl;
        file_upper << "//--This file has been generated automatically according to your data."<< endl;
        file_upper << "//--For more info, visit: http://iearobotics.com/oomlwiki/"<< endl;
        file_upper << "//--------------------------------------------------------------------------" << endl << endl;
        file_upper << writer_upper_4;
        file_upper.close();
        cout << "REPY-2.0_upper_4_arms_horn.scad created succesfully." << endl;
    }
    else
    {
        cerr << "Error, cannot open the file" << endl;
    }




    //--6 arms horn:
    //-------------------------------------------------------
    upper_part.hornType(6);

    IndentWriter writer_upper_6;
    writer_upper_6 << upper_part;


    file_upper.open("./scad/REPY-2.0_upper_6_arms_horn.scad");
    if (file_upper)
    {
        file_upper << "//-------------------------------------------------------------------------" << endl;
        file_upper << "//-- REPY-2.0_upper_6_arms_horn.scad" << endl;
        file_upper << "//-------------------------------------------------------------------------" << endl;
        file_upper << "//--This file has been generated automatically according to your data."<< endl;
        file_upper << "//--For more info, visit: http://iearobotics.com/oomlwiki/"<< endl;
        file_upper << "//--------------------------------------------------------------------------" << endl << endl;
        file_upper << writer_upper_6;
        file_upper.close();
        cout << "REPY-2.0_upper_6_arms_horn.scad created succesfully." << endl;
    }
    else
    {
        cerr << "Error, cannot open the file" << endl;
    }



    //-- Assembly
    //---------------------------------------------------------------------------------------------------------------------

    lower_part.showServo(true);
    upper_part.showHorn(true);
    upper_part.hornType(6);

    Component rotated_upper_part = upper_part.translate(0,0,-(SERVO_AXIS_Y+SERVO_LEG_Y+/*thickness_base*//* 4/2))
	    .rotate(0, 180, 0)
	    .translate(0,0, (SERVO_AXIS_Y+SERVO_LEG_Y+/*thickness_base*//*4/2));
    //-- Assembly
    Component assembly = rotated_upper_part + lower_part;

    //-- Printing the upper part
    IndentWriter writer_assembly;
    writer_assembly << assembly;
    //cout << writer_assembly << endl << endl;

    ofstream file_assembly("./scad/REPY-2.0_assembly.scad");
    if (file_assembly)
    {
        file_assembly << "//-------------------------------------------------------------------------" << endl;
        file_assembly << "//-- REPY-2.0_assembly.scad" << endl;
        file_assembly << "//-------------------------------------------------------------------------" << endl;
        file_assembly << "//--This file has been generated automatically according to your data."<< endl;
        file_assembly << "//--For more info, visit: http://iearobotics.com/oomlwiki/"<< endl;
        file_assembly << "//--------------------------------------------------------------------------" << endl << endl;
        file_assembly << writer_assembly;
        file_assembly.close();
        cout << "REPY-2.0_assembly.scad created succesfully." << endl;
    }
    else
    {
        cerr << "Error, cannot open the file" << endl;
    }


    //-- Create stls
    //----------------------------------------------------------------------------------------------------------------------
    char ans[3];
    cout << "Would you like to generate the stl files?\nThis operation may take a long time.(yes/no)" << endl;
    cin >> ans;

    if (ans[0]  == 'y' || ans[0] == 'Y')
    {
        //-- Generating stl's:
        system("mkdir stl");

        system( "openscad -o ./stl/REPY-2.0_lower.stl ./scad/REPY-2.0_lower.scad");
        cout << "REPY-2.0_lower.stl created" << endl;

        system( "openscad -o ./stl/REPY-2.0_upper_rounded_horn.stl  ./scad/REPY-2.0_upper_rounded_horn.scad ");
        cout << "REPY-2.0_upper_rounded_horn.stl created" << endl;

        system( "openscad -o ./stl/REPY-2.0_upper_2_arms_horn.stl ./scad/REPY-2.0_upper_2_arms_horn.scad");
        cout << "REPY-2.0_upper_2_arms_horn.stl created" << endl;

        system( "openscad -o ./stl/REPY-2.0_upper_4_arms_horn.stl ./scad/REPY-2.0_upper_4_arms_horn.scad");
        cout << "REPY-2.0_upper_4_arms_horn.stl created" << endl;

        system( "openscad -o ./stl/REPY-2.0_upper_6_arms_horn.stl ./scad/REPY-2.0_upper_6_arms_horn.scad");
        cout << "REPY-2.0_upper_6_arms_horn.stl created" << endl;
    }

    return 0;
*/
}

