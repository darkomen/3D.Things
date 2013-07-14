union() {
  translate(v=[25.000, -10.000, 0.000]) {
  rotate([-180.000,-180.000,-180.000]){
    union() {
      difference() {
        cylinder(h=7.000, r1=5.000, r2=5.000, $fn=30, center=false);
        translate(v=[0.000, 0.000, -1.000]) {
        rotate([-180.000,-180.000,-180.000]){
          cylinder(h=12.000, r1=2.000, r2=2.000, $fn=30, center=false);
        } // End rotate
        } // End translate
      } // End difference
      translate(v=[0.000, 13.000, 0.000]) {
      rotate([-180.000,-180.000,-180.000]){
        difference() {
          cylinder(h=7.000, r1=5.000, r2=5.000, $fn=30, center=false);
          translate(v=[0.000, 0.000, -1.000]) {
          rotate([-180.000,-180.000,-180.000]){
            cylinder(h=12.000, r1=2.000, r2=2.000, $fn=30, center=false);
          } // End rotate
          } // End translate
        } // End difference
      } // End rotate
      } // End translate
      translate(v=[0.000, 26.000, 0.000]) {
      rotate([-180.000,-180.000,-180.000]){
        difference() {
          cylinder(h=7.000, r1=5.000, r2=5.000, $fn=30, center=false);
          translate(v=[0.000, 0.000, -1.000]) {
          rotate([-180.000,-180.000,-180.000]){
            cylinder(h=12.000, r1=2.000, r2=2.000, $fn=30, center=false);
          } // End rotate
          } // End translate
        } // End difference
      } // End rotate
      } // End translate
    } // End union
  } // End rotate
  } // End translate
  difference() {
    union() {
      cylinder(h=3.000, r1=7.000, r2=7.000, $fn=100, center=false);
      cylinder(h=14.000, r1=5.000, r2=5.000, $fn=30, center=false);
      translate(v=[0.000, 0.000, 13.900]) {
      rotate([-180.000,-180.000,-180.000]){
        cylinder(h=12.000, r1=5.000, r2=10.000, $fn=100, center=false);
      } // End rotate
      } // End translate
    } // End union
    translate(v=[0.000, 0.000, -1.000]) {
    rotate([-180.000,-180.000,-180.000]){
      cylinder(h=30.000, r1=1.500, r2=1.500, $fn=30, center=false);
    } // End rotate
    } // End translate
  } // End difference
} // End union
