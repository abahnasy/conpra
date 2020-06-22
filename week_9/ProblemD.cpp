//
// Created by abahnasy on 20.06.20.
//
// This solution is done with help of one of my friends that took the course before !
// he provided few hints about the data types that should be used

// solution is based on this implementation https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/

#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;



// fix for printing __int128
// https://stackoverflow.com/questions/25114597/how-to-print-int128-in-g
std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}


// Returns modulo inverse of a with respect to m using extended
// Euclid Algorithm. Refer below post for details:
// http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}
// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0],
//  x % num[1] = rem[1],
//  x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
ll findMinX(vector<ll> num, vector<ll> rem, ll k)
{
    // Compute product of all numbers
    ll prod = 1;
    for (ll i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    ll result = 0;

    // Apply above formula
    for (ll i = 0; i < k; i++)
    {
        ll pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }

    return result % prod;
}



int main()
{

    freopen("../../week_9/samples_09/nathlon/1.in", "r", stdin);
//    freopen("../../week_9/samples_09/nathlon/2.in", "r", stdin);
    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; ++t) {

        long long n,k,x,y;
        unsigned long long r = 1;
        cin>>n>>k;
        bool f = 1;
        vector<ll> num, rem;
        for(ll i=0;i<n;i++)
        {
            cin>>x>>y;
            ll xx,yy;
            xx = static_cast<__int128>(x);
            yy = static_cast<__int128>(y);
            bool f2 = 1;
            for(int i=0;i<num.size();i++)
            {
                // make sure the numbers are coprime
                if((num[i] != xx && __gcd(xx,num[i])!=1) || (num[i] == xx && rem[i] != yy))
                {
                    f = 0;
                    break;
                }
                // no duplicates
                else if(num[i] == xx && rem[i] == yy)
                {
                    f2 = 0;
                }
            }
            if(f2)
            {
                num.push_back(xx);
                rem.push_back(yy);
                r*=xx;
            }
        }
        ll ans;
        cout<<"Case #"<<t<<": ";
        if(f)
        {
            ans = findMinX(num,rem,num.size());
        }
        if(!f || ans>k)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        ll KT = ans;
        if(r>k-ans)
        {
            cout<<ans<<endl;
            continue;
        }
        else
        {
            ans = (k - KT)/r * r + KT;
        }

        cout<<ans<<endl;

    }
}