//
// Created by abahnasy on 28.06.20.
//

// https://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/

#include <bits/stdc++.h>
using namespace std;
#define INF 10000


struct Point
{
    int x;
    int y;
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

bool isInside(vector<pair<Point, Point>>& polygon, int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;

    // Create a point for line segment from p to infinite
    Point extreme = {1010, p.y+1010};

    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
//        int next = (i+1)%n;

        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i].first, polygon[i].second, p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i].first, p, polygon[i].second) == 0)
                return onSegment(polygon[i].first, p, polygon[i].second);

            count++;
        }
        i = (i+1)%n;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_10/samples_10/meteorite/1.in", "r", stdin);
//    freopen("../../week_10/samples_10/meteorite/2.in", "r", stdin);
//    freopen("../../week_10/samples_10/meteorite/test.in", "r", stdin);


    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; ++t) {
        int n;
        int x_imp, y_imp;
        cin  >> x_imp >> y_imp >> n;
        vector<pair<Point, Point>> polygon;
        for (int i = 0; i < n; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Point p1 = {x1,y1};
            Point p2 = {x2, y2};
            polygon.push_back(make_pair(p1,p2));
        }

        cout << "Case #" << t << ": ";
        if(isInside(polygon, n, {x_imp, y_imp})) {
            cout << "jackpot\n";
        } else {
            cout << "too bad\n";
        }

    }
}
