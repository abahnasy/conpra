//
// Created by abahnasy on 04.07.20.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long t[4*1001000], z[4*1001000];

//

void update(int l, int r, int p, int lr, int rr, ll delta) {
//    if(l>r) // cross the boundaries
//        return;
    // no overlap
//    if(lr>r || rr < l) {
//        return;
//    }
    // total overlap
    if(lr <= l && rr >= r) {
        z[p] += delta ;
        z[p] ;
        st[p] += (((ll)(r-l+1))*delta);
        st[p] ;
        return;
    }

    //partial overlap
    int mid = (l+r) / 2;
    if(z[p]!= 0) {
        st[2*p] += (ll(mid - l +1)*z[p]) ;
        st[2*p+1] += (ll (r - (mid+1) + 1) * z[p]);


        z[2*p] += z[p];
        z[2*p +1] += z[p];

        z[p] = 0;


    }
    if(lr <= mid)
        update(l,mid,p*2, lr, rr, delta);
    if(rr>mid)
        update(mid+1, r, p*2+1, lr, rr, delta);
    st[p] = (st[p*2] + st[p*2+1]) ;
}


// sum query
ll query (int l, int r, int p, int q) {

    if (l == r) {
        return st[p];
    }
    int mid = (l+r)/2;
    if(z[p]!= 0) {
        z[2*p] += z[p];
        z[2*p +1] += z[p];
        z[2*p] ;
        z[2*p+1] ;

        t[2*p] += ((ll)(mid - l +1)*z[p]) ;
        t[2*p+1] += ((ll) (r - (mid+1) + 1) * z[p]) ;
        t[2*p] ;
        t[2*p+1] ;

        z[p] = 0;

    }

    if(q <= mid)
        return query(l, mid, p*2, q);
    return query(mid+1, r, p*2+1, q);



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
                update(1,  1, n, p1, p1, view[p1]);
//                cout << "DEBUG: Insertion of position " << p1 << " current total, " << sum(1, 1, n, 1, n) << "\n";
            } else if (c =='d') {
                cin >> p1;
                if(view[p1] > 0) {
                    view[p1]--;
                    update(1,  1, n, p1, p1, view[p1]);
//                    cout << "DEBUG: Deletion of position " << p1 << " current total, " << sum(1, 1, n, 1, n) << "\n";
                }
            } else {
                // collect
                cin >> p1 >>p2;
                int temp = 0;

//                cout << "DEBUG: Collecting from positions " << p1 << ", " << p2 << " " << temp << "\n";
                for (int i = p1; i <= p2; ++i ){
                    temp += query(1, 1, n, i);
                    update(1, 1, n,i, i,0);
                    if(view[i] > 0)
                        view[i]--;
                }
                ans += temp;
//                cout << "DEBUG:  current total after collecting, " << sum(1, 1, n, 1, n) << "\n";


            }
        }
        cout << "Case #" << test_case << ": " << ans << "\n";

    }
}