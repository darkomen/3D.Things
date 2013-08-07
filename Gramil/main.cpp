#include <ooml/core.h>
#include <ooml/core/ColorDecorator.h>
#include <ooml/components.h>
#include <components/RoundedTablet.h> 
#include <parts/Nuts.h>

#include <fstream>
#include <iostream>
 
using namespace std;
//Declaración de variables.
int altura = 20;
int radio = 8;
int thickness = 4;



int main()
{
	IndentWriter body_writer;
	
	// Cuerpo principal del gramil
	Component prisma = Cylinder(radio+thickness, altura, 6, true).translate(0,-((radio+thickness))/1.99,0)   //Hexagono
					 + Cube(((radio+thickness)*2), (radio+thickness), altura,true)   //Cubo
					 //+ Cylinder((radio+thickness), altura, 50, true).translate(0,((radio+thickness))/1.99,0) ; //Cilindro
					 + Cube(24, (radio+thickness+9) ,altura, true).translate(0,((radio+thickness))/1.99,0) ; //Cilindro
	Component agujero = Cylinder(radio, altura+thickness, 6, true).translate(0,-(radio+thickness)/1.99,0)  //Hexagono
					  + Cube(((radio+thickness+2)*2),(radio+thickness),altura+thickness,true).translate(thickness+2,0,0)  //cubo
					  + Cylinder(radio, altura+thickness, 50, true).translate(0,((radio+thickness))/1.99,0) ;   // Cilindro
	//Links
	prisma.addLink(RefSys(0,-((((radio+thickness)/2.2)+((radio+thickness)/2)+((radio-thickness)/1.99))),0)); //Link 0
	
	Component tuerca = NutShape(M3,3).moveToLink(prisma,0).relRotate(90,0,0)
					 + Cylinder(2.8,10,90,true).moveToLink(prisma,0).relRotate(90,0,0) ;


	//body_writer << LinksView(prisma);
    body_writer <<  prisma 
    				- tuerca
    				- agujero
    				//+ Cylinder(radio, 100, 50, true).translate(0,((radio+thickness))/1.99,0).color(0.150,0.150,0.150,true) 
    				//+ Cylinder(2.8,30,90,true).moveToLink(prisma,0).relRotate(90,0,0).color(0.150,0.150,0.150,true)

    				;
 
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