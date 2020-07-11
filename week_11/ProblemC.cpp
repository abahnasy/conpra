//
// Created by abahnasy on 04.07.20.
//

#include <bits/stdc++.h>
using namespace std;



using namespace std;
typedef long long ll;

long long st[4*1000000], z[4*1000000];

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
        z[p] = delta ;
        st[p] = delta;
        return;
    }
    //partial overlap
    int mid = (l+r) / 2;
    if(z[p]!= 0) {
        st[2*p] = z[p];
        st[2*p+1] =z[p];
        z[2*p] = z[p];
        z[2*p +1] = z[p];
        z[p] = 0;
    }
    if(lr <= mid)
        update(l,mid,p*2, lr, rr, delta);
    if(rr>mid)
        update(mid+1, r, p*2+1, lr, rr, delta);
    st[p] = max(st[p*2],st[p*2+1]);
}


// max query
ll query (int l, int r, int p, int lq, int rq) {
    if (lq <= l &&  rq >= r) {
        return st[p];
    }
    int mid = (l+r)/2;
    if(z[p]!= 0) {
        st[2*p] = z[p];
        st[2*p+1] = z[p];
        z[2*p] = z[p];
        z[2*p +1] = z[p];
        z[p] = 0;
    }
    int res1 = -1, res2 = -1;
    if(lq <= mid)
        res1 = query(l, mid, p*2, lq, rq);
    if (rq >  mid )
        res2 = query(mid+1, r, p*2+1, lq, rq);

    return max(res1, res2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_11/samples_11/brokentetris/1.in", "r", stdin);
//    freopen("../../week_11/samples_11/brokentetris/2.in", "r", stdin);
//    freopen("../../week_11/samples_11/brokentetris/test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;

    int n, k;
    for (int t = 1; t <= test_cases; ++t) {
        cout<<"Case #"<<t<<": ";
        cin>>n>>k;
        memset(z, 0, sizeof(z));
        memset(st, 0, sizeof(st));

        int w,h,p;
        for (int i = 0; i < k; ++i) {
            cin >>w >>h >>p;

            // get max in area
            int max = query(1,n,1,p+1,p+w);
            // update with new height

            update(1,n,1,p+1,p+w,max+h);
            // print current max height
            cout << query(1,n,1,1,n) << " ";
        }
        cout << "\n";
    }
}

