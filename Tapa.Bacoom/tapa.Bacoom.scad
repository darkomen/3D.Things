longitud = 25; //mm
radio_ext = 5.6; //mm
ancho = 1;		//mm
tapa= 2;
rotate([0,180,0])
difference(){
	cylinder(r=radio_ext,h=longitud,$fn=100);
	cylinder(r=(radio_ext-ancho),h=(longitud-tapa));

}