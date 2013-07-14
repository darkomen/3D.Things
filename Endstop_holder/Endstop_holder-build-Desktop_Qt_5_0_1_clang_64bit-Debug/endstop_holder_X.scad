union() {
  difference() {
    difference() {
      difference() {
        cube(size=[25.800, 11.656, 6.100], center=true);
        translate(v=[5.200, 0.000, 0.000]) {
        rotate([-90.000,-180.000,-180.000]){
          cylinder(h=20.000, r1=1.800, r2=1.800, $fn=100, center=true);
        } // End rotate
        } // End translate
      } // End difference
      translate(v=[-5.200, 0.000, 0.000]) {
      rotate([-90.000,-180.000,-180.000]){
        cylinder(h=20.000, r1=1.800, r2=1.800, $fn=100, center=true);
      } // End rotate
      } // End translate
    } // End difference
    translate(v=[0.000, 0.000, 0.000]) {
    rotate([-180.000,-180.000,-180.000]){
      cube(size=[20.800, 6.656, 10.100], center=true);
    } // End rotate
    } // End translate
  } // End difference
  translate(v=[33.900, 0.000, 0.000]) {
  rotate([-90.000,180.000,0.000]){
    difference() {
      difference() {
        difference() {
          union() {
            cylinder(h=11.656, r1=6.550, r2=6.550, $fn=100, center=true);
            translate(v=[0.000, 6.550, 0.000]) {
            rotate([-180.000,-180.000,-180.000]){
              cube(size=[13.100, 13.100, 11.656], center=true);
            } // End rotate
            } // End translate
          } // End union
          cylinder(h=13.656, r1=4.050, r2=4.050, $fn=100, center=true);
        } // End difference
        translate(v=[0.000, 12.000, 0.000]) {
        rotate([-180.000,-180.000,-180.000]){
          cube(size=[8.100, 23.100, 12.000], center=true);
        } // End rotate
        } // End translate
      } // End difference
      translate(v=[0.000, 8.100, 0.000]) {
      rotate([-180.000,90.000,-180.000]){
        cylinder(h=20.000, r1=2.025, r2=2.025, $fn=100, center=true);
      } // End rotate
      } // End translate
    } // End difference
  } // End rotate
  } // End translate
} // End union
