

#include <bits/stdc++.h>


using namespace std;

int gcd (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        gcd (b,a%b);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_13/samples_13/grachten/1.in", "r", stdin);
//    freopen("../../week_13/samples_13//2.in", "r", stdin);
//    freopen("../../week_13/samples_13//test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;

    int ab, ac, bd;
    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        cin >> ab >> ac >> bd;
        int len_num = ab * ac;
        int len_den = bd - ac;
        int gcd_value = gcd(len_num, len_den);
        cout << (len_num/gcd_value) << "/" << (len_den/gcd_value) << "\n";



    }
}