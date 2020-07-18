

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct Point {
    int x, y;
};

bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{
    // If one rectangle is on left side of other
    if (l1.x >= r2.x || l2.x >= r1.x)
        return false;

    // If one rectangle is above other
    if (l1.y >= r2.y || l2.y >= r1.y)
        return false;

    return true;
}

ll overlappingArea(Point l1, Point r1,
                    Point l2, Point r2)
{
//    // Area of 1st Rectangle
//    int area1 = abs(l1.x - r1.x) *
//                abs(l1.y - r1.y);
//
//    // Area of 2nd Rectangle
//    int area2 = abs(l2.x - r2.x) *
//                abs(l2.y - r2.y);

    // Length of intersecting part i.e
    // start from max(l1.x, l2.x) of
    // x-coordinate and end at min(r1.x,
    // r2.x) x-coordinate by subtracting
    // start from end we get required
    // lengths
    ll areaI = (min(r1.x, r2.x) -
                 max(l1.x, l2.x)) *
                (min(r1.y, r2.y) -
                 max(l1.y, l2.y));
    return areaI;

//    return (area1 + area2 - areaI);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_13/samples_13/boxunion/1.in", "r", stdin);
//    freopen("../../week_13/samples_13//2.in", "r", stdin);
//    freopen("../../week_13/samples_13//test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;

    int n;

    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        cin >> n;
        vector<pair<Point, Point>> rectangles;
        vector<ll> areas;
        ll total_area = 0;
        Point l, r;
        for (int i = 0; i < n; ++i) {
            cin >> l.x >> l.y >> r.x >> r.y;
            rectangles.push_back({l, r});
            ll area = (r.x - l.x) *(r.y- l.y);
            total_area += area;
            areas.push_back(area);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if(doOverlap(rectangles[i].first, rectangles[i].second, rectangles[j].first, rectangles[j].second)) {
                    ll areaI = overlappingArea(rectangles[i].first, rectangles[i].second, rectangles[j].first, rectangles[j].second);
                    total_area -= areaI;
                }

            }
        }

        cout << total_area << "\n";






    }
}