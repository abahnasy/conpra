//
// Created by abahnasy on 20.06.20.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ull;
// C function for extended Euclidean Algorithm
ull gcdExtended(ull a, ull b, ull *x, ull *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ull x1, y1; // To store results of recursive call
    ull gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

// Function to find modulo inverse of a
ull modInverse(ull a, ull m)
{
    ull x, y;
    ull g = gcdExtended(a, m, &x, &y);
    if (g != 1) {
//        cout << "Inverse doesn't exist";
        return -1;
    }
    else
    {
        // m is added to handle negative x
        ull res = (x%m + m) % m;
//        cout << "Modular multiplicative inverse is " << res;
        return res;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_9/samples_09/breakin/1.in", "r", stdin);
//    freopen("../../week_9/samples_09/breakin/2.in", "r", stdin);
//    freopen("../../week_9/samples_09/breakin/test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;

    int n, y;
    for (int t = 1; t <= test_cases; ++t) {
        cin >> n >> y;
        ull m = pow(10,n);
        cout << "Case #" << t << ": " <<modInverse(y, m) << "\n";


    }


    return 0;
}