//
// Created by abahnasy on 28.06.20.
//




#include<bits/stdc++.h>
using namespace std;

struct Point
{

    long double x;
    long double y;
};

Point operator+ (Point a, Point b)
{
    return Point {a.x+b.x,a.y+b.y};
}

Point operator- (Point a, Point b)
{
    return Point {a.x-b.x,a.y-b.y};
}


int cross_product(Point a, Point b, Point c)
{
    Point p = b - a, q = c - b;
    return p.x * q.y - q.x * p.y;
}

bool intersect(Point l, Point r, Point cen){
    //intersection of center of mass and base line
    long double k = ((r.y-l.y) * (cen.x-l.x) - (r.x-l.x) * (cen.y-l.y)) / ((r.y-l.y)*(r.y-l.y) + (r.x-l.x)*(r.x-l.x));
    long double xp = cen.x - k * (r.y - l.y);
    long double yp = cen.y + k * (r.x - l.x);

    if(xp >= min(l.x, r.x) && xp <= max(l.x, r.x))
        if(yp >= min(l.y, r.y) && yp <= max(l.y, r.y)){

            return true;
        }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_10/samples_10/fragileletters/1.in", "r", stdin);
//    freopen("../../week_10/samples_10/fragileletters/2.in", "r", stdin);
//    freopen("../../week_10/samples_10/fragileletters/test.in", "r", stdin);


    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; ++t) {
        int n;
        cin >> n;
        long double x, y;
        vector<Point> points;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            Point point = {x,y};
            points.push_back(point);
        }
        // getting center of mass
        Point center {0,0};

        for(int i = 0; i < n; ++i)
            center.x += points[i].x, center.y += points[i].y;
        center.x = center.x / (1.0 * n), center.y = center.y / (1.0 * n);

        int count = 0;

        for(int i = 0; i < n; ++i){
            int l = i, r = (i + 1) % n;
            Point v1 = points[l];
            Point v2 = points[r];

            int c2 = 0;

            for(int j = 0; j < n; ++j){
                if(j != l && j != r){
                    Point temp = points[j];
                    int c1 = cross_product(v1, v2, temp);
                    // colinear more than one edge touching the ground
                    if(c1 == 0){
                        c2 = 0;
                        break;
                    }
                    if(c2 == 0)
                        c2 = c1;
                        // check all points are on the same side, valid sid to touch the ground
                    else{
                        if(c2 < 0 && c1 > 0){
                            c2 = 0;
                            break;
                        }
                        if(c2 > 0 && c1 < 0){
                            c2 = 0;
                            break;
                        }
                    }
                }
            }

            if(c2 != 0){
                if(intersect(v1, v2, center)){
                    ++count;
                }
            }
        }




        cout << "Case #" << t << ": " << count <<  "\n";
    }
}