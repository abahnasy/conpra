//
// Created by abahnasy on 28.06.20.
//

#include <bits/stdc++.h>
using namespace std;
# define ERROR 0.000001f;
#define PI 3.14159265358979323846f;

struct Point {
    double x;
    double y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(17);
    // redirect input stream to samples files
//    freopen("../../week_10/samples_10/surveillance/1.in", "r", stdin);
//    freopen("../../week_10/samples_10/surveillance/2.in", "r", stdin);
//    freopen("../../week_10/samples_10/surveillance/test.in", "r", stdin);


    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        vector<Point> cameras;
        double xi, yi;
        for (int i = 0; i < n; ++i) {
            cin >> xi >> yi;
            cameras.push_back({xi, yi});
        }

        // get min p0pi
        double min_p0_pi = sqrt(pow(abs(cameras[0].x - cameras[1].x),2) +
                                pow(abs(cameras[0].y - cameras[1].y),2));
        for (int i = 2; i < n; ++i) {
            double res = sqrt(pow(abs(cameras[0].x - cameras[i].x),2) +
                                      pow(abs(cameras[0].y - cameras[i].y),2));
            if (res < min_p0_pi)
                min_p0_pi = res;
        }
//        cout << "min_p0_pi is: " << min_p0_pi << "\n";
        //special case n == 2
        if (n == 2) {
            double area_op1 = 3.14159265358979323846f * pow(min_p0_pi,2);
            double area_op2 = 2 * 3.14159265358979323846f * pow(min_p0_pi/2.0,2);
            if (area_op1 - area_op2 > 0)
                cout << area_op1 << "\n";
            else
                cout << area_op2 << "\n";

            continue;
        }

        //get min pipj

        double min_pi_pj = sqrt(pow(abs(cameras[1].x - cameras[2].x),2) +
                                pow(abs(cameras[1].y - cameras[2].y),2));
        for (int i =1; i < n; ++i ) {
            for (int j = i+1; j < n; ++j) {
                double res = sqrt(pow(abs(cameras[i].x - cameras[j].x),2) +
                                  pow(abs(cameras[i].y - cameras[j].y),2));
            if(res < min_pi_pj)
                min_pi_pj = res;
            }
        }
//        cout << "min_pi_pj is: " << min_pi_pj << "\n";




        // if min_p0_pi == min_pi_pj, all radii are the same
        if(abs(min_p0_pi - min_pi_pj) <= 0.000001f) {
            double area_op1 = n * 3.14159265358979323846f * pow(min_p0_pi/2.0,2);
            double area_op2 = 3.14159265358979323846f * pow(min_p0_pi,2);
            if (area_op1 - area_op2 > 0)
                cout << area_op1 << "\n";
            else
                cout << area_op2 << "\n";

        } else if ((min_pi_pj/2.0 - min_p0_pi) > 0.000001f) {
            // when half min dist between points are larger than min dist between main camera and res cameras
            double area = (n-1) * 3.14159265358979323846f * pow(min_p0_pi,2);
            cout << area << "\n";
        } else if ((min_p0_pi - min_pi_pj/2.0) > 0.000001f) {
            double area_op1 = 3.14159265358979323846f * pow(min_p0_pi,2);
            double area_op2 = (n-1) * 3.14159265358979323846f * pow(min_pi_pj/2.0,2);
            area_op2+= 3.14159265358979323846f * pow(min_p0_pi - (min_pi_pj/2.0) ,2);
            if (area_op1 - area_op2 > 0)
                cout << area_op1 << "\n";
            else
                cout << area_op2 << "\n";
        }








    }
}
