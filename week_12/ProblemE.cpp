//
// Created by abahnasy on 04.07.20.
//


#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x,  y;
};

string production(map<char, string>& prods, string s) {
    string res = "";
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '+' || s[i] == '-') {
            res += s[i];
        } else {
            // decode the character from the map
            res+= prods[s[i]];
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(7);
    // redirect input stream to samples files
//    freopen("../../week_12/samples_12/fractals/1.in", "r", stdin);

    int test_cases;
    cin >> test_cases;
    int n, d, a; string s;
    map<char, string> prods;
    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ":\n";
        prods.clear();
        cin >> n >> d >> a >> s;
        // build map between characters and strings
        for (int i = 0; i < n; ++i) {
            string temp;
            cin >> temp;
            prods[temp[0]] = temp.substr(3,temp.length());
        }
        // run the productions to decode the final string
        for (int i = 0; i < d; ++i) {
            s = production(prods, s);
        }
        Point init_pos = {0,0};
        int init_angle = 0;
        cout << fixed <<init_pos.x << " " << init_pos.y << "\n";
        // loop over the decoded string
        for (int i = 0; i < s.length(); ++i) {

            if(s[i] == '+')
                init_angle+= a;
            else if(s[i] == '-')
                init_angle -= a;
            else {
                init_pos.x += cos((M_PI/180)* init_angle);
                init_pos.y += sin((M_PI/180)* init_angle);
                cout << fixed <<init_pos.x << " " << init_pos.y << "\n";
            }
        }
        // print final position
        //cout << fixed <<init_pos.x << " " << init_pos.y << "\n";








    }
}