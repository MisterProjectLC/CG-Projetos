#include "hittable_model.h"


HittableModel::HittableModel(ifstream& obj_file) {
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


vec3 HittableModel::create_point(string line) {
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


HittableFace HittableModel::create_face(string line) {
    size_t pos = 0;
    int index = 0;
    vector<vec3> returned;
    while ((pos = line.find(delimiter)) != string::npos) {
        returned.push_back(points[stoi(line.substr(0, pos)) - 1]);
        line.erase(0, pos + delimiter.length());
        index++;
    }
    returned.push_back(points[stoi(line.substr(0, pos)) - 1]);
    return HittableFace(returned);
}


vec3 HittableModel::get_point(int index) {
    return points[index];
}

HittableFace HittableModel::get_face(int index) {
    return faces[index];
}


string HittableModel::print() {
    string s;

    s += "POINTS\n";
    for (int i = 0; i < points.size(); i++)
        s += points[i].to_string() + "\n";

    s += "FACES\n";
    for (int i = 0; i < faces.size(); i++) {
        for (int j = 0; j < faces[i].get_points().size(); j++)
            s += faces[i].to_string() + " ";
        s += "\n";
    }

    return s;
}


bool HittableModel::hit(const Ray& r, Interval ray_t, HitRecord& rec) const {
    bool hit_smth = false;
    for (HittableFace f : faces) {
        double lowest_t = infinity;

        HitRecord this_rec;
        if (f.hit(r, ray_t, this_rec) and this_rec.t < lowest_t) {
            rec.set_t(r, this_rec.t);
            rec.set_face_normal(r, this_rec.normal);
            hit_smth = true;
        }
    }

    return hit_smth;
}