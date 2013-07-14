filament_d = 3;
spring_d = 8;
countersink = true;
include</Users/santiagolopezpina/Programacion/OOML/MCAD/stepper.scad>;

module base() difference() {
	linear_extrude(height = 15, convexity = 5) difference() {
		union() {
			square([31, 10], center = true);
			translate([-15.5, 0, 0]) rotate(120) {
				translate([0, -5, 0]) square([5, 10]);
				translate([5, 0, 0]) circle(5);
				translate([5, 0, 0]) rotate(-150 - 9 / 2) square([15, 5]);			
			}
			for (side = [1, -1]) translate([side * 15.5, 0, 0]) circle(5);
		}
		for (side = [1, -1]) translate([side * 15.5, 0, 0]) circle(3 * 7/12, $fn = 6);
		translate([0, -15.5, 0]) circle(12);
	}
	translate([0, 0, 4.4]) linear_extrude(height = 15, convexity = 5) {
		translate([-15.5, 0, 0]) rotate(30) translate([0, 5, 0]) rotate(-60 - 9 / 2) translate([-5, 5, 0]) square(100);
		translate([0, -10, 0]) square(100);
	}
	if (countersink) translate([-15.5, 0, 15 - 4]) cylinder(r1 = 0, r2 = 8, h = 8, $fn = 6);
	translate([-15.5, 0, 4.4 + 10.6 / 2]) rotate([90, 0, 150 - 4.5]) translate([0, 0, 4]) cylinder(r = spring_d * 7/12, h = 10, $fn = 6);
}
module printrbot_mount(){
import("./printrbot_mount.stl");
}
//BDAS MOUNT
module budasnozzle_mount(){
translate([29.55,-11.9,-13.4])
rotate([90,0,180])
import("./budaschnozzle_mount.stl");
}
//FILAMENTO
module filamento(){
cylinder(r=2,h=100,$fn=100,center=true);
}
module motor_(){
translate([0,-6.5,14.2])
rotate([90,0,0])
motor(Nema17, NemaMedium, dualAxis=false);

}
//TORNILLOS
module tornillos(){
color("red")
translate([21-15,7.5-5.50,0])
cylinder(r=1.5,h=30,$fn=100,center=true);


translate([(21-5.5),(7.5-5.50),(4.75-4)])
rotate([90,0,0])
cylinder(r=1.6,h=30,$fn=100,center=true);

translate([-(21-5.5),(7.5-5.50),(4.75-4)])
rotate([90,0,0])
cylinder(r=1.6,h=30,$fn=100,center=true);
}
//PIEZA BAJA
module pieza(){
rotate([0,180,0])
difference(){
//translate([6,0,0])
translate([-0.2,0,2])
cube([41.5,15,9.5],center=true);
tornillos();
translate([0,-6,-9])
rotate([90,0,0])
cylinder(r=8,$fn=100,h=3);
}
}






//motor_();
union(){
translate([-20.5,-7.5,1])
cube([4,4.4,28]);
translate([17,-7.5,-1])
cube([4,4.4,30]);
translate([0,-7.5,30])
rotate([90,0,180])
base();
}
pieza();
color("black")

budasnozzle_mount();

