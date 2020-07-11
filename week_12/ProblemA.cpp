//
// Created by abahnasy on 04.07.20.
//


#include <bits/stdc++.h>

#define EPS 0.00001
using namespace std;


struct Point {
    // normal point
    double x,y,z;

    Point() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Point (double x, double y, double z = 1){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    bool is_infinite() {
        if(abs(this->z) < EPS) {
            return true;
        }
        return false;
    }
    void normalize() {
        if(!this->is_infinite()) {
            this->x = this->x/this->z;
            this->y = this->y/this->z;
            this->z = 1;
        }
    }
};

typedef Point Line;


Point cross_product (Point p1, Point p2) {
    // cross product between two points
    Point res;
    res.x = p1.y * p2.z - p1.z*p2.y;
    res.y = p1.z * p2.x - p1.x*p2.z;
    res.z = p1.x * p2.y - p1.y*p2.x;
    return res;
}
Line make_line(Point p1, Point p2) {
    return cross_product(p1, p2);
}
Point get_projection (Line l, Point p) {
    // get projection of point p on line l
    Line inf_dir = cross_product(l, Point{0, 0, 1});
    Line m = cross_product(p,Point{inf_dir.y, -inf_dir.x, 0});
    return cross_product(m,l);

}
pair<double, double> conv_2D(Point l)
{
    pair<double, double> p;
    l.normalize();
    p.first = l.x;
    p.second = l.y;
    return p;
}

bool check_points(Point x1, Point x, Point m)
{
    pair<double, double> p1 = conv_2D(x1);
    pair<double, double> p2 = conv_2D(x);
    pair<double, double> p3 = conv_2D(m);

    int res1 = (p3.first - p1.first)*(p2.first - p3.first);
    int res2 = (p3.second - p1.second)*(p2.second - p3.second);
    if(res1 >= 0 && res2 >= 0)
    {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_12/samples_12/swordfighting/1.in", "r", stdin);
//    freopen("../../week_12/samples_12/swordfighting/2.in", "r", stdin);
//    freopen("../../week_12/samples_12/swordfighting/test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;

    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        vector<Point> s1, s2;
        double x, y;
        // scan the first sword
        for (int i = 0; i < 3; ++i) {
            cin >> x >> y;
            s1.push_back({x,y,1});
        }
        // scan the second sword
        for (int i = 0; i < 3; ++i) {
            cin >> x >> y;
            s2.push_back({x,y,1});
        }


        //form line from point 1 and point 2
        //get the projection of point 3 on line from 1 to 2
        Point s1_proj = get_projection(make_line(s1[0], s1[1]), s1[2]);
//        s1_proj.normalize();
        Point s2_proj = get_projection(make_line(s2[0], s2[1]), s2[2]);
//        s2_proj.normalize();
        Point intersection = cross_product(cross_product(s1[2], s1_proj)  , cross_product(s2[2], s2_proj));
        intersection.normalize();
        if(intersection.is_infinite()) {
            cout << "strange\n";
        } else {
            if(!check_points(s1[2], intersection, s1_proj) || !check_points(s2[2], intersection, s2_proj))
            {
                cout << "strange"<<endl;
            }
            else {
                cout.precision(4);
                cout << fixed << intersection.x << " " << intersection.y << "\n";
            }
        }
        // do the same for the other sword
        // get the intesection of lines of point 3 and projection between two swords
        // check the intersection point is at infinity, so print strange
        // otherwise, print the intersection point.










    }
}