//
// Created by abahnasy on 04.07.20.
//

#include <bits/stdc++.h>
using namespace std;


#define MOD 1000000007
using namespace std;
typedef long long ll;

long long st[4*1001000], z[4*1001000];

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
        z[p] %= MOD;
        st[p] += (((ll)(r-l+1))*delta);
        st[p] %= MOD;
        return;
    }

    //partial overlap
    int mid = (l+r) / 2;
    if(z[p]!= 0) {
        st[2*p] += (ll(mid - l +1)*z[p]) %MOD;
        st[2*p+1] += (ll (r - (mid+1) + 1) * z[p]) %MOD;
        st[2*p] %= MOD;
        st[2*p+1] %= MOD;

        z[2*p] += z[p];
        z[2*p +1] += z[p];
        z[2*p] %= MOD;
        z [2*p+1] %= MOD;
        z[p] = 0;


    }
    if(lr <= mid)
        update(l,mid,p*2, lr, rr, delta);
    if(rr>mid)
        update(mid+1, r, p*2+1, lr, rr, delta);
    st[p] = (st[p*2] + st[p*2+1]) %MOD;
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
        z[2*p] %= MOD;
        z[2*p+1] %= MOD;

        st[2*p] += ((ll)(mid - l +1)*z[p]) %MOD;
        st[2*p+1] += ((ll) (r - (mid+1) + 1) * z[p]) %MOD;
        st[2*p] %= MOD;
        st[2*p+1] %= MOD;

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
//    freopen("../../week_11/samples_11/jandjs/1.in", "r", stdin);
//    freopen("../../week_11/samples_11/jandjs/2.in", "r", stdin);
//    freopen("../../week_11/samples_11/jandjs/test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;
    int n, k, q, l, r;
    char ch;
    for (int t = 1; t <= test_cases; ++t) {
        cin>>n>>q;

        memset(z, 0, sizeof(z));
        memset(st, 0, sizeof(st));


        long long ans = 0;
        for(int i = 1; i <= q; ++i)
        {
            cin>>ch;
            if(ch == 'i')
            {
                cin>>l>>r>>k;
                update(1, n, 1, l, r, k);
            }
            else
            {
                cin>>k;
                long long v = query(1, n, 1, k);
                //cout<<v<<endl;
                ans = (ans + v) % MOD;
            }

        }


        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}

