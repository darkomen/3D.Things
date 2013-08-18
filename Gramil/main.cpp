#include <ooml/core.h>
#include <ooml/core/ColorDecorator.h>
#include <ooml/components.h>
#include <components/RoundedTablet.h> 
#include <parts/Nuts.h>
//#include <PolygonalPiramid.h>



#include <fstream>
#include <iostream>
 
using namespace std;
//Declaración de variables.
int altura = 12;
int radio = 4;
int thickness = 4;



int main()
{
	IndentWriter sujeccion_writer;
	IndentWriter soporte_writer;
	
	///////////////////////////////////////
	///////////////////////////////////////    				
    ///////////////////////////////////////
    // Programacion de la sujeccion

	// Cuerpo principal del gramil
	Component prisma = Cylinder((0.01+radio+thickness), altura, 6, true).translate(0,-((radio+thickness))/1.99,0)   //Hexagono
					 + Cube(((radio+thickness+7.99)), (radio+thickness), altura,true)   //Cubo
					 //+ Cylinder((radio+thickness), altura, 50, true).translate(0,((radio+thickness))/1.99,0) ; //Cilindro
					 + Cube(16, (radio+thickness+20) ,altura, true).translate(0,((radio+thickness))/0.8,0) ; //Cilindro

	Component agujero = Cylinder(radio, altura+thickness, 6, true).translate(0,-(radio+thickness)/1.99,0)  //Hexagono
					  + Cube(((radio+thickness+2)*2),(radio+thickness),altura+thickness,true).translate(thickness+2,0,0)  //cubo
					  + Cylinder(radio, altura+thickness, 50, true).translate(0,((radio+thickness))/1.99,0) ;   // Cilindro
	//Links
	prisma.addLink(RefSys(0,-((((radio+thickness)/2.2)+((radio+thickness)/2)+((radio-thickness)/1.99))),0)); //Link 0
	prisma.addLink(RefSys(0,14,0)); //Link 1
	prisma.addLink(RefSys(0,20,0)); //Link 2
	Component tuerca = NutShape(M3,3.5)
					 + Cylinder(1.6,10,90,true);


	
    Component Sujecion =	    prisma 
    				- tuerca.moveToLink(prisma,0).relRotate(90,0,0)
    				+ NutShape(M3,3).moveToLink(prisma,2).relRotate(90,0,0).color(0.150,0.150,0.150,true) //tuerca emptrada p ara el lapicero
    				- Cylinder(1.6,15,90,true).moveToLink(prisma,2).relRotate(90,0,0)  //tuerca emptrada p ara el lapicero
    				- Cube(7,3,13,true).moveToLink(prisma,2).relTranslate(0,0,4) //tuerca emptrada p ara el lapicero
    				- agujero
    				- Cylinder(4.5, 25, 50, true).moveToLink(prisma,1).relRotate(0,90,0).color(0.150,0.150,0.150,true) //Lapicero
    				- Cylinder(radio, 25, 50, true).translate(0,((radio+thickness))/1.99,0).color(0.150,0.150,0.150,true)  //Mastil
    				;
 
    ///////////////////////////////////////
	///////////////////////////////////////    				
    ///////////////////////////////////////
    // Programacion del soporte.

    Component cruz = Cube(100,14,5,true)
    				+ Cube(100,14,5,true).relRotate(0,0,90);
    Component triangulo = RegularPrism(3, 30.0, 14.0).rotate(0,-90,0).translate(7,0,13.0);
    

 	
	Component soporte = cruz
					+ triangulo
					+ triangulo.rotatedCopy(0,0,90)
					- Cylinder(3.9,61,90,false).translate(0,0,2.5).color(0.150,0.150,0.150,true)
					- Cube(20,20,36).translate(0,0,40)
					

	;

 	///////////////////////////////////////
	///////////////////////////////////////    				
    ///////////////////////////////////////

 	//body_writer << LinksView(prisma);
 	sujeccion_writer << Sujecion;
 	//body_writer << soporte;
	ofstream file("gramil.scad");
	if (file){
		//generate OpenScad code of the translated cube and save it into file;
		file << sujeccion_writer;
		file.close();
	}else{
		cerr << "Error, cannot open the file" << endl;
	}
 
 	soporte_writer << soporte;
 	
	ofstream file2("soporte.scad");
	if (file2){
		//generate OpenScad code of the translated cube and save it into file;
		file2 << soporte_writer;
		file2.close();
	}else{
		cerr << "Error, cannot open the file" << endl;
	}
	cout << "Done" << endl;
 
	return 0;
}