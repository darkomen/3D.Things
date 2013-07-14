#include <ooml/core.h>
#include <ooml/components.h>
#include <components/RoundedTablet.h>
#include <parts/Nuts.h>
#include <parts/SeeedUSSensor.h>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    IndentWriter endstop_holder_Y;
    IndentWriter endstop_holder_X;
    //Variables
    double diametro = 8.1;
    double angulo = 180;
    double open_x = 2*(diametro/2)*sin(angulo*0.008766);  //Basado en el código de Juan Gonzalez. (obijuan)
    double tolerance = 1.04;
    double wall_th = 5;
    //double endstop_dimm[3] = {13*tolerance,6*tolerance,7};  // X,Y,Z [mm]
    //endstop de los grandes
    double endstop_dimm[3] = {20*tolerance,6.4*tolerance,10.1};  // X,Y,Z [mm]
    double carcasa_dimm[3]= {endstop_dimm[0]+wall_th,endstop_dimm[1]+wall_th,endstop_dimm[2]-4};// X,Y,Z [mm]

    ////////////
    // Endstop //
    ////////////
    //Rectanculo del endstop
    Component endstop    = Cube(endstop_dimm[0],endstop_dimm[1],endstop_dimm[2],true);
    //Añadimos los links de la posición de los taladros
    //endstop_body.addLink(RefSys(((endstop_dimm[0]/2)-2-1.2),0,-((endstop_dimm[2]/2)-2)).relRotate(90,0,0));
    //endstop_body.addLink(RefSys(-((endstop_dimm[0]/2)-2-1.2),0,-((endstop_dimm[2]/2)-2)).relRotate(90,0,0));
    //*
    //ENDTOPS GRANDES
    //endstop_body.addLink(RefSys(((endstop_dimm[0]/2)-4-1.2),0,-((endstop_dimm[2]/2)-1.8-1.2)).relRotate(90,0,0));
    //endstop_body.addLink(RefSys(-((endstop_dimm[0]/2)-4-1.2),0,-((endstop_dimm[2]/2)-1.8-1.2)).relRotate(90,0,0));
    //*/
    //HAcemos los traladors al cuerpo.
    //Component endstop = endstop_body
    //                      + Cylinder(1.5,20,100,true).moveToLink(endstop_body,0)
    //                      + Cylinder(1.5,20,100,true).moveToLink(endstop_body,1)
    //                      ;

    ////////////
    // carcasa //
    ////////////
    Component carcasa_body    = Cube(carcasa_dimm[0],carcasa_dimm[1],carcasa_dimm[2],true);
    carcasa_body.addLink(RefSys(0,0,0));  //link 0 para el endstop
    carcasa_body.addLink(RefSys((carcasa_dimm[0]/2)+((diametro)/2),0,0));  //link 1 para la barclamp
    //taladros
    carcasa_body.addLink(RefSys(((endstop_dimm[0]/2)-4-1.2),0,0).relRotate(90,0,0)); //link 2 cilindro
    carcasa_body.addLink(RefSys(-((endstop_dimm[0]/2)-4-1.2),0,0).relRotate(90,0,0)); //link 3 cilindro


    ////////////
    // barclamp //
    ////////////
    Component barclamp = Cylinder(((diametro+wall_th)/2),endstop_dimm[1]+wall_th,100,true)
            + Cube((diametro+wall_th),diametro+wall_th,endstop_dimm[1]+wall_th).relTranslate(0,(diametro+wall_th)/2,0)
                         - Cylinder((diametro/2),endstop_dimm[1]+wall_th+2,100,true)
                         - Cube(open_x,diametro+wall_th+10,12).relTranslate(0,12,0)
                        - Cylinder((diametro/4),20,100,true).translate(0,diametro,0).relRotate(0,90,0)
;

    //endstop_holder_Y << LinksView(carcasa_body);

    endstop_holder_Y << carcasa_body
                      - Cylinder(1.8,20,100,true).moveToLink(carcasa_body,2)
                      - Cylinder(1.8,20,100,true).moveToLink(carcasa_body,3)
                      - endstop.moveToLink(carcasa_body,0)
                      //+ barclamp.translate((81)+wall_th,0,0).relRotate(-0,-90,-90);
                        + barclamp.moveToLink(carcasa_body,1).relRotate(-0,-90,-90);

      cout << "Generando fichero endstop_holder_y.scad" << endl;
    ofstream file("endstop_holder_y.scad");
    if (file){
        //generate OpenScad code of the translated cube and save it into file;
        file << endstop_holder_Y;
        file.close();
    }else{
        cerr << "Error, cannot open the file" << endl;
    }
     cout << "Generado fichero endstop_holder_y.scad !" << endl;

    //endstop_holder_X << LinksView(carcasa_body);
    //endstop_holder_X << LinksView(barclamp);
    endstop_holder_X << carcasa_body
                        - Cylinder(1.8,20,100,true).moveToLink(carcasa_body,2)
                        - Cylinder(1.8,20,100,true).moveToLink(carcasa_body,3)
                        - endstop.moveToLink(carcasa_body,0)
                        + barclamp.moveToLink(carcasa_body,1).relRotate(0,0,-90);


    cout << "Generando fichero endstop_holder_X.scad" << endl;


    ofstream file2("endstop_holder_X.scad");
    if (file2){
        //generate OpenScad code of the translated cube and save it into file;
        file2 << endstop_holder_X;
        file2.close();
    }else{
        cerr << "Error, cannot open the file" << endl;
    }
    cout << "Generado fichero endstop_holder_X.scad!" << endl;

    cout << "Done" << endl;

    return 0;
}
