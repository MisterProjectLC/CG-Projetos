#include <iostream>
#include <fstream>
#include <string>
#include "model.h"

using namespace std;

int main() {

    // Read from file
    ifstream myfile(".\\data\\icosahedron.obj");

    if (myfile.is_open()) {
        Model m = Model(myfile);
        cout << m.print() << "\n";
    }

    myfile.close();
    return 0;

}