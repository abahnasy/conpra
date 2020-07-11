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

Point compute_mid_point(Point p1, Point p2) {
    Point res{0,0,1};
    p1.normalize();
    p2.normalize();
    res.x = (p1.x + p2.x) /2;
    res.y = (p1.y + p2.y) /2;
    return res;
}
Point get_projection (Line l, Point p) {
    // get projection of point p on line l
    Line inf_dir = cross_product(l, Point{0, 0, 1});
    Line m = cross_product(p,Point{inf_dir.y, -inf_dir.x, 0});
    return cross_product(m,l);

}

Line get_prep_line_at_point (Line l, Point p) {
    // get projection of point p on line l
    Line inf_dir = cross_product(l, Point{0, 0, 1});
    Line m = cross_product(p,Point{inf_dir.y, -inf_dir.x, 0});
    return m;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_12/samples_12/eulerline/1.in", "r", stdin);
//    freopen("../../week_12/samples_12/eulerline/2.in", "r", stdin);
//    freopen("../../week_11/samples_11/eulerline/test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;

    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": \n";
        vector<Point> vertices;
        double x, y;
        for (int i = 0; i < 3; ++i) {
            cin >> x >> y;
            vertices.push_back({x, y, 1});
        }
        // calculating centroid
        Point mid_0_1 = compute_mid_point(vertices[0], vertices[1]);
        Point mid_0_2 = compute_mid_point(vertices[0], vertices[2]);
        Point centroid = cross_product(cross_product(vertices[1], mid_0_2), cross_product(vertices[2], mid_0_1));
        centroid.normalize();
        cout.precision(6);
        cout << fixed << centroid.x << " " << centroid.y << "\n";
//         calculating orthocenter
        Point proj_0 = get_projection(cross_product(vertices[1], vertices[2]), vertices[0]);
        Point proj_2 = get_projection(cross_product(vertices[0], vertices[1]), vertices[2]);
        Point orthcenter = cross_product(cross_product(vertices[0], proj_0), cross_product(vertices[2], proj_2));
        orthcenter.normalize();
        cout.precision(6);
        cout << fixed <<orthcenter.x << " " << orthcenter.y << "\n";
//         calculating circumcenter

        Line bisector_0_1 = get_prep_line_at_point(cross_product(vertices[0], vertices[1]), mid_0_1);
        Line bisector_0_2 = get_prep_line_at_point(cross_product(vertices[0], vertices[2]), mid_0_2);
        Point circumcenter = cross_product(bisector_0_1, bisector_0_2);
        circumcenter.normalize();
        cout.precision(6);
        cout <<fixed << circumcenter.x << " " << circumcenter.y << "\n";


    }










}