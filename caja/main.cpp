#include <ooml/core.h>
#include <ooml/components.h>
 
#include <fstream>
#include <iostream>
 
using namespace std;
 
int main()
{
 	Component a = Cube(10,10,10);

    IndentWriter writer;
    writer << a;
 
	ofstream file("box.scad");
	if (file){
		//generate OpenScad code of the translated cube and save it into file;
		file << writer;
		file.close();
	}else{
		cerr << "Error, cannot open the file" << endl;
	}
 
	cout << "Done" << endl;
 
	return 0;
}