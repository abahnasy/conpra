//
// Created by abahnasy on 04.07.20.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long t[4*1001000];

//

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_11/samples_11/catmongo/1.in", "r", stdin);
//    freopen("../../week_11/samples_11/catmongo/2.in", "r", stdin);
//    freopen("../../week_11/samples_11/catmongo/test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;
    int n, k;
    for (int test_case = 1; test_case <= test_cases; ++test_case) {
        cin >> n >> k;

        int view [n+1];

        memset(view, 0 , sizeof(view));
        memset(t, 0, sizeof(t));
        long long ans = 0;

        char c; int p1,p2;
        for (int i = 1; i <= k; ++i) {
            cin >> c;
            if(c == 's') {
                cin >> p1;
                view[p1]++;
                update(1,  1, n, p1, view[p1]);
//                cout << "DEBUG: Insertion of position " << p1 << " current total, " << sum(1, 1, n, 1, n) << "\n";
            } else if (c =='d') {
                cin >> p1;
                if(view[p1] > 0) {
                    view[p1]--;
                    update(1,  1, n, p1, view[p1]);
//                    cout << "DEBUG: Deletion of position " << p1 << " current total, " << sum(1, 1, n, 1, n) << "\n";
                }
            } else {
                // collect
                cin >> p1 >>p2;
                int temp = sum(1, 1, n, p1, p2);
                ans += temp;
//                cout << "DEBUG: Collecting from positions " << p1 << ", " << p2 << " " << temp << "\n";
                for (int i = p1; i <= p2; ++i ){
                    update(1, 1, n, i,0);
                    if(view[i] > 0)
                        view[i]--;
                }
//                cout << "DEBUG:  current total after collecting, " << sum(1, 1, n, 1, n) << "\n";


            }
        }
        cout << "Case #" << test_case << ": " << ans << "\n";

    }
}