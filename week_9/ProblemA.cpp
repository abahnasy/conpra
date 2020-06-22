//
// Created by abahnasy on 20.06.20.
//

#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b) {
    if(b == 0 )
        return a;
    else {
        return gcd(b,  a%b);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_9/samples_09/commanderinchief/1.in", "r", stdin);
//    freopen("../../week_9/samples_09/commanderinchief/2.in", "r", stdin);
//    freopen("../../week_9/samples_09/commanderinchief/test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;

    for (int t = 1; t <= test_cases; ++t) {
        int n;
        cin >> n;
        vector<int> army_size;
        int a,b;
        cin >> a >> b;
        int res = gcd(a,b);
        for (int i = 2; i < n; ++i) {
            int temp;
            cin >> temp;
            res = gcd(res, temp);
        }

        cout << "Case #"<<t<<": " << res << "\n";

    }
    return 0;
}
