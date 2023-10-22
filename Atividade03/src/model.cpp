#include "model.h"

vec3 Model::create_point(string line) {
    size_t pos = 0;
    int index = 0;
    vector<double> v;
    while ((pos = line.find(delimiter)) != string::npos) {
        v.push_back(stod(line.substr(0, pos)));
        line.erase(0, pos + delimiter.length());
        index++;
    }
    v.push_back(stod(line.substr(0, pos)));
    return vec3(v[0], v[1], v[2]);
}


vector<int> Model::create_face(string line) {
    size_t pos = 0;
    int index = 0;
    vector<int> returned;
    while ((pos = line.find(delimiter)) != string::npos) {
        returned.push_back(stoi(line.substr(0, pos)));
        line.erase(0, pos + delimiter.length());
        index++;
    }
    returned.push_back(stoi(line.substr(0, pos)));
    return returned;
}


Model::Model(ifstream &obj_file) {
    string myline;
    if (!obj_file.is_open())
        return;

    while (getline(obj_file, myline)) {
        if (myline.size() <= 0)
            continue;

        switch (myline[0])
        {
        case 'v':
            points.push_back(create_point(myline.substr(2)));
            break;
        case 'f':
            faces.push_back(create_face(myline.substr(2)));
            break;
        default:
            break;
        }
    }
}


string Model::print() {
    string s;

    s += "POINTS\n";
    for (int i = 0; i < points.size(); i++)
        s += to_string(points[i][0]) + " " + to_string(points[i][1]) + " " + to_string(points[i][2]) + "\n";

    s += "FACES\n";
    for (int i = 0; i < faces.size(); i++) {
        for (int j = 0; j < faces[i].size(); j++)
            s += to_string(faces[i][j]) + " ";
        s += "\n";
    }

    return s;
}