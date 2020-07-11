//
// Created by abahnasy on 28.06.20.
//

//TODO: clean the code and remove the dirty nested loop for permutaions
//TODO: check if the combinations of rectangle vertices is enough?!

#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << x << "\n";


void comb(vector<vector<int>>& combinations, int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask

    do {
        vector<int> temp;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
//                std::cout << " " << i;
            temp.push_back(i);
        }
//        std::cout << std::endl;
        combinations.push_back(temp);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

void print_2d_vector(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}


struct Point {
    int x;
    int y;
};
void print_point(Point p) {
    cout << p.x << " " << p.y;
}

int cmp (const void *vp1, const void *vp2) {

    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    if (p1->x < p2->y) {
        return 1;
    } else if (p1->x == p2->x) {
        return (p1->y < p2->y);
    } else {
        return 0;
    }

    return 0;
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

bool checkOrtho(Point a, Point b, Point c, Point d) {
    int m1, m2;
    // Both lines have infinite slope
    if (b.x - a.x == 0 && d.x - c.x == 0)
        return false;
        // Only line 1 has infinite slope
    else if (b.x - a.x == 0) {
        m2 = (d.y - c.y) / (d.x - c.x);
        if (m2 == 0)
            return true;
        else
            return false;
    }
        // Only line 2 has infinite slope
    else if (d.x - c.x == 0) {

        m1 = (b.y - a.y) / (b.x - a.x);

        if (m1 == 0)
            return true;
        else
            return false;
    }
    else {
        // Find slopes of the lines
        m1 = (b.y - a.y) / (b.x - a.x);
        m2 = (d.y - c.y) / (d.x - c.x);

        // Check if their product is -1
        if (m1 * m2 == -1)
            return true;
        else
            return false;
    }
}
// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
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
//    freopen("../../week_10/samples_10/azrieli/1.in", "r", stdin);
//    freopen("../../week_10/samples_10/azrieli/2.in", "r", stdin);
    freopen("../../week_10/samples_10/azrieli/test.in", "r", stdin);


    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        int exit_flag = false;
        int n;
        cin >> n;
        vector<Point> c;
        for (int i = 0; i < n; ++i) {
            int xi, yi;
            cin >> xi >> yi;
            c.push_back({xi, yi});
        }

        // brute force loop over all permutations of a rectangle
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j)
                        continue;
                    for (int l = 0; l < n; ++l) {
                        if (l == i || l == j || l == k)
                            continue;
                        int o1 = orientation(c[i], c[j], c[k]);
                        int o2 = orientation(c[i], c[j], c[l]);
                        //check if k, l are on the same side of i, j
                        if (o1 == o2) {
                            // check intersection of ab, bc, cd, da
                            if(checkOrtho(c[i], c[j], c[j], c[k]) &&
                                    checkOrtho(c[j], c[k], c[k], c[l]) &&
                                    checkOrtho(c[k], c[l], c[l], c[i]) &&
                                    checkOrtho(c[l], c[i], c[i], c[j])) {
//                                DEBUG("====================================")
//                                DEBUG("Possible Rectangles " << i << " "<< j << " " << k << " " <<l);
                                // consitute rectangle vector
                                vector<pair<Point, Point>> rec;
                                rec.push_back(make_pair(c[i], c[j]));
                                rec.push_back(make_pair(c[j], c[k]));
                                rec.push_back(make_pair(c[k], c[l]));
                                rec.push_back(make_pair(c[l], c[i]));
                                // get available indices for triangle
                                vector<int> poss_tri_idx;
                                for(int rec_it = 0; rec_it < n ; ++rec_it) {
                                    if (rec_it != i && rec_it != j && rec_it != k && rec_it != l) {
                                        poss_tri_idx.push_back(rec_it);
                                    }
                                }
//                                DEBUG ("possible points for triangles are ");
//                                for (auto x: poss_tri_idx) {
//                                    cout << x <<", ";
//                                }
//                                cout << "\n";
                                // generate all possible triangles
                                vector<vector<int>> combinations;
                                comb(combinations, poss_tri_idx.size(),3);
//                                DEBUG("possible combinations are");
//                                print_2d_vector(combinations);
                                for (auto try_tri: combinations) {
                                 // check all triangle vertices are outside the rectangle
//                                 cout << "checking triangle points: "; print_point(c[poss_tri_idx[try_tri[0]]]); print_point(c[poss_tri_idx[try_tri[1]]]); print_point(c[poss_tri_idx[try_tri[2]]]); cout <<"\n";
                                    if(!(isInside(rec, 4, c[poss_tri_idx[try_tri[0]]]) || isInside(rec, 4, c[poss_tri_idx[try_tri[1]]]) || isInside(rec, 4, c[poss_tri_idx[try_tri[2]]]))) {
                                        // check the intersection of triangles diagonals with rectangle diagonals
//                                        bool intersect_flag = false;
                                        bool intersect_flag_1 = doIntersect(rec[0].first, rec[0].second, c[poss_tri_idx[try_tri[0]]], c[poss_tri_idx[try_tri[1]]]);
                                        bool intersect_flag_2 = doIntersect(rec[1].first, rec[1].second, c[poss_tri_idx[try_tri[0]]], c[poss_tri_idx[try_tri[1]]]);
                                        bool intersect_flag_3 = doIntersect(rec[2].first, rec[2].second, c[poss_tri_idx[try_tri[0]]], c[poss_tri_idx[try_tri[1]]]);
                                        bool intersect_flag_4 = doIntersect(rec[3].first, rec[3].second, c[poss_tri_idx[try_tri[0]]], c[poss_tri_idx[try_tri[1]]]);

                                        bool intersect_flag_5 = doIntersect(rec[0].first, rec[0].second, c[poss_tri_idx[try_tri[1]]], c[poss_tri_idx[try_tri[2]]]);
                                        bool intersect_flag_6 = doIntersect(rec[1].first, rec[1].second, c[poss_tri_idx[try_tri[1]]], c[poss_tri_idx[try_tri[2]]]);
                                        bool intersect_flag_7 = doIntersect(rec[2].first, rec[2].second, c[poss_tri_idx[try_tri[1]]], c[poss_tri_idx[try_tri[2]]]);
                                        bool intersect_flag_8 = doIntersect(rec[3].first, rec[3].second, c[poss_tri_idx[try_tri[1]]], c[poss_tri_idx[try_tri[2]]]);

                                        bool intersect_flag_9 = doIntersect(rec[0].first, rec[0].second, c[poss_tri_idx[try_tri[2]]], c[poss_tri_idx[try_tri[0]]]);
                                        bool intersect_flag_10 = doIntersect(rec[1].first, rec[1].second, c[poss_tri_idx[try_tri[2]]], c[poss_tri_idx[try_tri[0]]]);
                                        bool intersect_flag_11 = doIntersect(rec[2].first, rec[2].second, c[poss_tri_idx[try_tri[2]]], c[poss_tri_idx[try_tri[0]]]);
                                        bool intersect_flag_12 = doIntersect(rec[3].first, rec[3].second, c[poss_tri_idx[try_tri[2]]], c[poss_tri_idx[try_tri[0]]]);

                                        if(!(intersect_flag_1 || intersect_flag_2 || intersect_flag_3 || intersect_flag_4|| intersect_flag_5||
                                        intersect_flag_6|| intersect_flag_7|| intersect_flag_8|| intersect_flag_9|| intersect_flag_10|| intersect_flag_11|| intersect_flag_12)) {
                                            // no intersection, possible design
                                            cout << "possible\n";
                                            print_point(c[i]);
                                            cout << "\n";
                                            print_point(c[j]);
                                            cout << "\n";
                                            print_point(c[k]);
                                            cout << "\n";
                                            print_point(c[l]);
                                            cout << "\n";
                                            print_point(c[poss_tri_idx[try_tri[0]]]);
                                            cout << "\n";
                                            print_point(c[poss_tri_idx[try_tri[1]]]);
                                            cout << "\n";
                                            print_point(c[poss_tri_idx[try_tri[2]]]);
                                            cout << "\n";
                                            exit_flag = true;
                                            break;
                                        }




                                    }

                                }
                                if(exit_flag)
                                    break;
                            }
                            if(exit_flag)
                                break;
                        }
                        if(exit_flag)
                            break;

                    }
                    if(exit_flag)
                        break;
                }
                if(exit_flag)
                    break;
            }
            if(exit_flag)
                break;
        }
        if(exit_flag)
            continue;
        else
            cout << "impossible\n";
    }
}