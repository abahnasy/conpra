//
// Created by abahnasy on 30.06.20.
//

#include <bits/stdc++.h>
using namespace std;

struct Point
{

    long double x, y;
    Point(long double x = 0, long double y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

Point operator+ (Point a, Point b)
{
    return Point(a.x+b.x,a.y+b.y);
}

Point operator- (Point a, Point b)
{
    return Point(a.x-b.x,a.y-b.y);
}


int cross_product(Point a, Point b, Point c)
{
    Point p = b - a, q = c - b;
    return p.x * q.y - q.x * p.y;
}
Point v[100100];

long double A, Cx, Cy;

bool check(Point l, Point r, Point cen){
    //intersection of center of mass and base line
    long double k = ((r.y-l.y) * (cen.x-l.x) - (r.x-l.x) * (cen.y-l.y)) / ((r.y-l.y)*(r.y-l.y) + (r.x-l.x)*(r.x-l.x));
    long double kx = cen.x - k * (r.y - l.y);
    long double ky = cen.y + k * (r.x - l.x);

    if(kx >= min(l.x, r.x) && kx <= max(l.x, r.x))
        if(ky >= min(l.y, r.y) && ky <= max(l.y, r.y)){

            return true;
        }

    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
//        freopen("../../week_10/samples_10/fragileletters/1.in", "r", stdin);
//    freopen("../../week_10/samples_10/fragileletters/2.in", "r", stdin);
//    freopen("../../week_10/samples_10/fragileletters/test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; ++t) {
    long double a, b;
    int n;


        int ans = 0;
        cin>>n;
        for(int i = 0; i < n; ++i){
            cin>>a>>b;
            v[i] = Point(a, b);
        }
        A = Cx = Cy = 0.0; // for center of mass
        v[n] = v[0];

        // getting center of mass
        for(int i = 0; i < n; ++i)
            Cx += v[i].x, Cy += v[i].y;
        Cx = Cx / (1.0 * n), Cy = Cy / (1.0 * n);
        Point center = Point(Cx, Cy);

        for(int i = 0; i < n; ++i){
            int l = i, r = (i + 1) % n;
            Point ll = v[l];
            Point rr = v[r];

            int c2 = 0;

            for(int j = 0; j < n; ++j){
                if(j != l && j != r){
                    Point temp = v[j];
                    int c1 = cross_product(ll, rr, temp);
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
//                cout<<ll.x<<" "<<ll.y<<endl;
//                cout<<rr.x<<" "<<rr.y<<endl;
//                cout<<"bb"<<endl;
                if(check(ll, rr, center) == true){
                    ++ans;
//                    cout<<ll.x<<" "<<ll.y<<" "<<rr.x<<" "<<rr.y<<endl;
                }
            }
        }

        cout<<"Case #"<<t<<": "<<ans<<endl;

    }
    return 0;
}