difference() {
  difference() {
    union() {
      cube(size=[100.000, 14.000, 5.000], center=true);
      translate(v=[0.000, 0.000, 0.000]) {
      rotate([-180.000,-180.000,-90.000]){
        cube(size=[100.000, 14.000, 5.000], center=true);
      } // End rotate
      } // End translate
      translate(v=[7.000, 0.000, 13.000]) {
      rotate([-180.000,-90.000,-180.000]){
        linear_extrude(height=14.000, twist=0, $fn=100, convexity=10, center=false) {
          polygon(points=[[21.213, 0.000], [-10.607, 18.371], [-10.607, -18.371]], path=[0, 1, 2]);
        } // End linear_extrude
      } // End rotate
      } // End translate
      translate(v=[0.000, 7.000, 13.000]) {
      rotate([-180.000,-90.000,-90.000]){
        linear_extrude(height=14.000, twist=0, $fn=100, convexity=10, center=false) {
          polygon(points=[[21.213, 0.000], [-10.607, 18.371], [-10.607, -18.371]], path=[0, 1, 2]);
        } // End linear_extrude
      } // End rotate
      } // End translate
    } // End union
    color([0.150, 0.150, 0.150, 1.000]) {
      translate(v=[0.000, 0.000, 2.500]) {
      rotate([-180.000,-180.000,-180.000]){
        cylinder(h=61.000, r1=3.900, r2=3.900, $fn=90, center=false);
      } // End rotate
      } // End translate
    } // End color
  } // End difference
  translate(v=[0.000, 0.000, 40.000]) {
  rotate([-180.000,-180.000,-180.000]){
    cube(size=[20.000, 20.000, 36.000], center=true);
  } // End rotate
  } // End translate
} // End difference
