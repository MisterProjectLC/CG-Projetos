#include "hittable_model.h"


HittableModel::HittableModel(ifstream& obj_file, shared_ptr<Material> _material) {
    string myline;
    mat = _material;

    if (!obj_file.is_open())
        return;

    while (getline(obj_file, myline)) {
        if (myline.size() <= 0)
            continue;

        switch (myline[0])
        {
        case 'v':
            if (myline[1] == ' ')
                points.push_back(create_point(myline.substr(2)));
            else if (myline[1] == 'n')
                set_point_normal(myline.substr(3));

            break;
        case 'f':
            faces.push_back(create_face(myline.substr(2)));
            break;
        default:
            break;
        }
    }
}


Point HittableModel::create_point(string line) {
    size_t pos = 0;
    vector<double> v;
    while ((pos = line.find(delimiter)) != string::npos) {
        v.push_back(stod(line.substr(0, pos)));
        line.erase(0, pos + delimiter.length());
    }
    v.push_back(stod(line.substr(0, pos)));

    return Point(vec3(v[0], v[1], v[2]));
}


void HittableModel::set_point_normal(string line) {
    size_t pos = 0;
    int index = 0;
    vec3 v;
    while ((pos = line.find(delimiter)) != string::npos) {
        v[index] = stod(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());
        index++;
    }
    v[index] = stod(line.substr(0, pos));

    points[point_normal_index].set_custom_normal(v);
    point_normal_index++;
}


HittableFace HittableModel::create_face(string line) {
    size_t pos = 0;
    vector<Point> returned;
    while ((pos = line.find(delimiter)) != string::npos) {
        returned.push_back(points[stoi(line.substr(0, pos)) - 1]);
        line.erase(0, pos + delimiter.length());
    }
    returned.push_back(points[stoi(line.substr(0, pos)) - 1]);
    return HittableFace(returned, mat);
}


Point HittableModel::get_point(int index) {
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
        if (f.hit(r, ray_t, this_rec)) {
            rec.set_t(r, this_rec.t);
            rec.set_face_normal(r, this_rec.normal);

            ray_t.max = rec.t;
            hit_smth = true;
            rec = this_rec;
        }
    }

    return hit_smth;
}