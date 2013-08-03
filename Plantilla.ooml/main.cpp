#include <ooml/core.h>
#include <ooml/components.h>
#include <components/RoundedTablet.h> 
#include <parts/ArduinoUNO.h>
#include <parts/FutabaS3003.h>
#include <parts/BallWheelHolder.h>

#include "config.h"
#include <fstream>
#include <iostream>
 
using namespace std;
 
int main()
{
	IndentWriter body_writer;
	
	// Cuerpo principal de la cruz
	Component body       = Cube(11,70,4);   // Estructura básica.
	Component body_hole  = Cube(43,10,4).translate(0,20,0);
	Component cruz = body + body_hole;
	// Anilla para agarrar
	Component anil_ext = Cube(4,6,4);
	Component anil_int = Cylinder(1,1,6,100,true).translate(0,1,0);
    Component argolla = anil_ext - anil_int;
	
	Component crucifijo =  argolla.rotate(0,90,0).translate(0,38,0) + cruz;
    body_writer << crucifijo;
 
	ofstream file("cruz.scad");
	if (file){
		//generate OpenScad code of the translated cube and save it into file;
		file << body_writer;
		file.close();
	}else{
		cerr << "Error, cannot open the file" << endl;
	}
 
	cout << "Done" << endl;
 
	return 0;
}