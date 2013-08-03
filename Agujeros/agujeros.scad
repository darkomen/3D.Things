//Código basado en el de Juan Gonzalez (obijuan)
//PAra poder crear aperturas en los cilindros

include <./math.scad>
altura = 3;  //Altura del cilindro
dim_interior = 18; //Diametro interior de la pieza
dim_exterior = dim_interior + 2;  //Diametro exterior de la pieza
angulo =40;   //Ángulo que se desea abrir en el cilindro

open_x = (dim_interior)*sin(angulo/2);  //Calculamos el tamaño de la apertura

difference (){
	//Cilindro exterior.
	cylinder(r=(dim_exterior/2),h=3,$fn=100,center=true);
	//Cilindro interior.
	cylinder(r=(dim_interior/2),h=altura+10,$fn=100,center=true);
	//Agujero.
	translate([0,dim_interior/2,0])
	cube([open_x,dim_exterior/1.5,altura+2],center=true);

}
