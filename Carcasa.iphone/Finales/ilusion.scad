module iphone(){
import("../Carcasa/iPhone.stl");
}

module nombre(){
rotate([180,0,90])
scale([0.4,0.4,0])
import("../Nombres/ilusion.stl");
}
module agujero(){
translate([30,20,0])
cylinder (r=5.5,h=100,$fn=100,center=true);

}

difference(){
iphone();
translate([10,10,-0.2])
nombre();

}
