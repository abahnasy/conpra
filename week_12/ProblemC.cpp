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
    void print() {
        cout << "(" <<this->x <<", " <<this->y << ")\n";
    }
};
typedef Point Line;
struct Ledge {
    Point l,r;
};

int compare (Ledge l1, Ledge l2) {
    if (max(l1.l.y, l1.r.y) < max(l2.l.y, l2.r.y))
        return 1;
    else if (max(l1.l.y, l1.r.y) == max(l2.l.y, l2.r.y))
        return 0;
    else
        return -1;
}

void print_ledges(vector<Ledge>& ledges) {
    for (auto ledge: ledges) {
        cout << "(" <<ledge.l.x <<", " <<ledge.l.y << "), (" << ledge.r.x << ", " << ledge.r.y<<  ")\n";
    }
}

Point cross_product (Point p1, Point p2) {
    // cross product between two points
    Point res;
    res.x = p1.y * p2.z - p1.z*p2.y;
    res.y = p1.z * p2.x - p1.x*p2.z;
    res.z = p1.x * p2.y - p1.y*p2.x;
    return res;
}

Point get_projection (Line l, Point p) {
    // get projection of point p on line l
    Line inf_dir = cross_product(l, Point{0, 0, 1});
    Line m = cross_product(p,Point{inf_dir.y, -inf_dir.x, 0});
    return cross_product(m,l);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
    freopen("../../week_12/samples_12/fallingwater/1.in", "r", stdin);
//    freopen("../../week_11/samples_11//2.in", "r", stdin);
//    freopen("../../week_11/samples_11//test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;
    int n;
    double x,y;
    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": "  << "\n";
        cin >> n >> x >> y;
        Point init_pos {x,y,1};
        vector<Ledge> ledges;
        for (int i = 0; i < n; ++i) {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Point l {x1,y1,1};
            Point r {x2,y2,1};
            ledges.push_back({l,r});
        }
        sort(ledges.begin(), ledges.end(), compare);
//        reverse(ledges.begin(), ledges.end());
//        print_ledges(ledges);

        while (!ledges.empty()) {
            Ledge temp = ledges.back();
            ledges.pop_back();
//            cout << "check projection on ledge \n" ; temp.l.print(); temp.r.print();
            Point proj = get_projection(cross_product(temp.r, temp.l), init_pos);
            proj.normalize();
            if(min(temp.l.x, temp.r.x) <= proj.x && max(temp.l.x, temp.r.x) >= proj.x) {
                // projection hit the ledge, check orientation
                if(temp.l.y > temp.r.y) {

                } else if (temp.l.y == temp.r.y) {

                } else {
                    // horizontal ledge
                }
            }
//            proj.print();
//            break;

        }







    }
}