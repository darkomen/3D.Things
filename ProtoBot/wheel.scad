union() {
  difference() {
    difference() {
      difference() {
        difference() {
          cylinder(h=6.000, r1=28.000, r2=28.000, $fn=100, center=false);
          translate(v=[0.000, 0.000, -0.100]) {
          rotate([-180.000,-180.000,-180.000]){
            cylinder(h=6.100, r1=4.200, r2=4.200, $fn=20, center=false);
          } // End rotate
          } // End translate
        } // End difference
        translate(v=[0.000, 0.000, 4.100]) {
        rotate([-180.000,-180.000,-180.000]){
          cylinder(h=2.100, r1=10.700, r2=10.700, $fn=50, center=false);
        } // End rotate
        } // End translate
      } // End difference
      translate(v=[0.000, 0.000, 3.000]) {
      rotate([-180.000,-180.000,-180.000]){
        rotate_extrude(convexity=10, $fn=100) {
          translate(v=[28.000, 0.000, 0.000]) {
          rotate([-180.000,-180.000,-180.000]){
            circle(r=1.300, $fn=100);
          } // End rotate
          } // End translate
        } // End rotate_extrude
      } // End rotate
      } // End translate
    } // End difference
    translate(v=[0.000, 0.000, -0.100]) {
    rotate([-180.000,-180.000,-180.000]){
      difference() {
        cylinder(h=6.200, r1=22.000, r2=22.000, $fn=100, center=false);
        cylinder(h=6.300, r1=12.000, r2=12.000, $fn=100, center=false);
      } // End difference
    } // End rotate
    } // End translate
  } // End difference
  translate(v=[18.500, 0.000, 1.500]) {
  rotate([-180.000,-180.000,-180.000]){
    cube(size=[15.000, 8.000, 3.000], center=true);
  } // End rotate
  } // End translate
  translate(v=[18.500, 0.000, 3.000]) {
  rotate([-180.000,-180.000,-180.000]){
    cube(size=[15.000, 3.000, 6.000], center=true);
  } // End rotate
  } // End translate
  translate(v=[0.000, 0.000, 0.000]) {
  rotate([-180.000,-180.000,-60.000]){
    union() {
      translate(v=[18.500, 0.000, 1.500]) {
      rotate([-180.000,-180.000,-180.000]){
        cube(size=[15.000, 8.000, 3.000], center=true);
      } // End rotate
      } // End translate
      translate(v=[18.500, 0.000, 3.000]) {
      rotate([-180.000,-180.000,-180.000]){
        cube(size=[15.000, 3.000, 6.000], center=true);
      } // End rotate
      } // End translate
    } // End union
  } // End rotate
  } // End translate
  translate(v=[0.000, 0.000, 0.000]) {
  rotate([-180.000,-180.000,60.000]){
    union() {
      translate(v=[18.500, 0.000, 1.500]) {
      rotate([-180.000,-180.000,-180.000]){
        cube(size=[15.000, 8.000, 3.000], center=true);
      } // End rotate
      } // End translate
      translate(v=[18.500, 0.000, 3.000]) {
      rotate([-180.000,-180.000,-180.000]){
        cube(size=[15.000, 3.000, 6.000], center=true);
      } // End rotate
      } // End translate
    } // End union
  } // End rotate
  } // End translate
} // End union
