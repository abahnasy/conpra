//
// Created by abahnasy on 20.06.20.
//

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll gcd(ll a, ll b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

ll lcm(vector<ll>& arr, ll n)
{
    ll ans = arr[0];
    for (ll i=1; i<n; i++)
        ans = ( ((arr[i]*ans)) /
                (gcd(arr[i], ans)) );

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_9/samples_09/candies/1.in", "r", stdin);
//    freopen("../../week_9/samples_09/candies/2.in", "r", stdin);
//    freopen("../../week_9/samples_09/breakin/test.in", "r", stdin);





    int test_cases;
    cin >> test_cases;


    for (int t = 1; t <= test_cases; ++t) {
        ll n;
        cin>>n;
        vector<ll> friends;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            friends.push_back(temp);
        }
        set<ll> possib;


        // generate all combinations
        for(int i=0;i< (1 << n); i++)
        {
            ll candies = 1;
            for(int j=0; j<n ; j++)
            {
                if(i & (1<<j))
                    candies+=friends[j];
            }
            possib.insert(candies);
        }

        vector<ll> get(possib.size());
        int x=0;
        for(set<ll>::iterator i=possib.begin();i!=possib.end();++i) {
            get[x] = *i;
            x++;
        }


        cout<<"Case #"<<t<<": "<<lcm(get, possib.size())<<endl;
    }
}