#include <ooml/core.h>
#include <ooml/components.h>
#include <components/RoundedTablet.h> 

#include <fstream>
#include <iostream>
 
using namespace std;
//Declaración de variables.
int altura = 10;
int radio = 8;
int thickness = 2;



int main()
{
	IndentWriter body_writer;
	
	// Cuerpo principal del gramil
	Component prisma = Cylinder(radio+thickness, altura, 6, true).translate(0,-((radio+thickness))/1.99,0)
					 + Cube(((radio+thickness)*2), (radio+thickness), altura,true)
					 + Cylinder((radio+thickness), altura, 50, true).translate(0,((radio+thickness))/1.99,0) ; 
	
	Component agujero = Cylinder(radio, altura+thickness, 6, true).translate(0,-(radio+thickness)/1.99,0)  //Hexagono
					  + Cube(((radio+thickness+2)*2),(radio+thickness),altura+thickness,true).translate(thickness+2,0,0)  //cubo
					  + Cylinder(radio, altura+thickness, 50, true).translate(0,((radio+thickness))/1.99,0) ;   // Cilindro
    body_writer <<  prisma 
    			-	agujero;
 
	ofstream file("gramil.scad");
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