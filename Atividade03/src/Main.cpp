#include <iostream>
#include <fstream>
#include <string>
#include "model.h"

using namespace std;

int main() {

    // Read from file
    ifstream myfile(".\\data\\icosahedron.obj");
    cout << "AAAA\n";

    if (myfile.is_open()) {
        cout << "AAAA\n";
        Model m = Model(myfile);
        cout << m.print() << "\n";
    }

    myfile.close();
    return 0;

}