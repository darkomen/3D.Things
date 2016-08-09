threaded_rod_diameter = 8.5;
outer_diameter = (threaded_rod_diameter-0.0)/2+2.4;
module nut(d,h,horizontal=true){
cornerdiameter =  (d / 2) / cos (180 / 6);
cylinder(h = h, r = cornerdiameter, $fn = 6);
if(horizontal){
for(i = [1:6]){
	rotate([0,0,60*i]) translate([-cornerdiameter-0.2,0,0]) rotate([0,0,-45]) cube(size = [2,2,h]);
}}
}

module barclamp(){


difference(){
	union(){
		
		translate([outer_diameter, outer_diameter, 0])cylinder(h =outer_diameter*2, r = outer_diameter, $fn = 20);
		translate([outer_diameter, 0, 0])cube([outer_diameter+1.5,outer_diameter*2,outer_diameter*2]);
		translate([18, 2*outer_diameter, outer_diameter])rotate([90, 0, 0]) rotate([00, 0, 0]) nut(outer_diameter*2,outer_diameter*2,false);
	}


	translate([18, outer_diameter, 9])cube([18,05,20], center=true);
	translate([outer_diameter, outer_diameter, -1]) #cylinder(h =20, r = threaded_rod_diameter/2-0.4, $fn = 18);
	translate([17, 17, 7.5]) rotate([90, 0, 0]) #cylinder(h =20, r = threaded_rod_diameter/2, $fn = 20);
}
}

barclamp();
