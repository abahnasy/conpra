//
// Created by abahnasy on 20.06.20.
//

// refer to python implementation
//TODO: re-implement the python solution using c++, fix this implementation

// A Dynamic Programming based solution to compute nCr % p
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

//vector<vector<ulli>> arr;
//vector<ulli> row;
//lli m = 223092870;
vector<lli> mod_facts = {2, 3, 5, 7, 11, 13, 17, 19, 23};

void print_vector(vector<lli> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ", ";
    }
    cout  << "\n";
}

//void 2dPascal(ulli n)
//{
//
//
//    for (ulli line = 0; line < n; line++)
//    {
//        // Every line has number of integers
//        // equal to line number
//        for (ulli i = 0; i <= line; i++)
//        {
//            // First and last values in every row are 1
//            if (line == i || i == 0)
//                arr[line][i] = 1;
//                // Other values are sum of values just
//                // above and left of above
//            else
//                arr[line][i] = (arr[line - 1][i - 1] +
//                               arr[line - 1][i]) % p;
////            cout << arr[line][i] << " ";
//        }
////        cout << "\n";
//    }
//}

//void rowPascal(ulli n)
//{
//    row.clear();
//    row.resize(n+1, 0);
//    row[0] = 1;
////    print_vector(row);
//
//    for (int i = 1; i <= n; ++i) {
//        vector<ulli> temp(n+1,0);
//        temp[0] = 1;
//
//        for (int j = 1; j <= n; ++j) {
//            temp[j] = (row[j] + row[j-1])%p;
//        }
//        row = temp;
////        print_vector(row);
//    }
//}





// A Lucas Theorem based solution to compute nCr % p


// Returns nCr % p. In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
//int nCrModpDP(int n, int r, int p)
//{
//    // The array C is going to store last row of
//    // pascal triangle at the end. And last entry
//    // of last row is nCr
//    int C[r+1];
//    memset(C, 0, sizeof(C));
//
//    C[0] = 1; // Top row of Pascal Triangle
//
//    // One by constructs remaining rows of Pascal
//    // Triangle from top to bottom
//    for (int i = 1; i <= n; i++)
//    {
//        // Fill entries of current row using previous
//        // row values
//        for (int j = min(i, r); j > 0; j--)
//
//            // nCj = (n-1)Cj + (n-1)C(j-1);
//            C[j] = (C[j] + C[j-1])%p;
//    }
//    return C[r];
//}


lli mod_exp(lli b, lli e, lli mod) {
    lli r= 1;
    while(e>0) {
        if((e&1) == 1){
            r = (r*b)%mod;
        }
        b = (b*b)%mod;
        e >>= 1;
    }
    return r;
}

lli fact_exp(lli n, lli p) {
    lli e = 0;
    lli u = p;
    lli t = n;
    while (u <= t) {
        e += t/u;
         u *= p;
    }
    return e;
}

void get_base_digits(vector<lli>& vec, lli n,lli b) {
    // get vector and fill it
    while(n>0) {
        vec.push_back(n%b);
        n/=b;
    }
}

// Extended Euclidean GCD
// compute x,y for ax + by = gcd(a,b)
// here, a,b are coprime, meaning gcd(a,b) = 1

pair<lli, lli> egcd(lli a, lli b) {
  lli x, y, u, v;
  x = 0; y = 1; u = 1; v = 0;
  while(a != 0) {
      lli q = b/a; lli r = b%a;
      lli m = x-u*q; lli n = y-v*q;
      b = a;
      a = r;
      x = u;
      y = v;
      u = m;
      v = n;
  }
  lli gcd = b;
  return make_pair(x,y);
}

lli crt(vector<pair<lli, lli>> congruences) {
    lli m = 1;
    for(auto congruence: congruences) {
        m *= congruence.second;
    }

    lli result = 0;
    for(auto congruence: congruences) {
        pair<lli, lli> temp = egcd(m/congruence.second, congruence.second);
        lli s = temp.first;
        lli t = temp.second;
        result += (congruence.first*s*m)/congruence.second;
    }
    return result%m;


}




lli fermat_binom_advanced(lli n, lli k, lli p) {
    lli num_degree = fact_exp(n,p) - fact_exp(n-k, p);
    lli den_degree = fact_exp(k,p);
    if(num_degree > den_degree) {
        return 0;
    }
    if(k > n) {
        return 0;
    }
    // calculate numerator and cancel out occurrences of p
    lli num  = 1;
    for (int i = n; i > n-k ; --i) {
        lli cur = i;
        while (cur%p == 0) {
            cur/=p;
        }
        num = (num*cur)%p;
    }
    // calculate denomenator and cancel out occurrences of p

    lli denom = 1;
    for (int i = 1; i <k+1 ; ++i) {
        lli cur = i;
        while(cur%p == 0) {
            cur/=p;
        }
        denom = (denom*cur)%p;
    }

    // numerator * denomentaor^(p-2) (mod p)
    return (num * mod_exp(denom, p-2,p))%p;
}

lli lucas_binom(lli n,lli k,lli p) {
    vector<lli> np;
    get_base_digits(np, n, p);
    vector<lli> kp;
    get_base_digits(kp, k, p);
    
    lli binom = 1;
    for (lli i = np.size()-1; i>=0  ; --i) {
        lli ni = np[i];
        lli ki = 0;
        if (i < kp.size()) {
            ki = kp[i];
        }
        binom = (binom * fermat_binom_advanced(ni,ki,p))%p;
    }

    return binom;
    
}


lli binom (lli n, lli k, vector<lli>& mod_facts) {
    vector<pair<lli, lli>> congruences;
    for (auto p: mod_facts) {
        congruences.push_back(make_pair(lucas_binom(n,k,p), p));
    }

    return crt(congruences);
}



// Driver program
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_9/samples_09/softskills/1.in", "r", stdin);
//    freopen("../../week_9/samples_09/softskills/2.in", "r", stdin);
    freopen("../../week_9/samples_09/softskills/test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;
    
    lli n, k;
    for (int t = 1; t <= test_cases; ++t) {
        cin >> n >> k;
        cout << binom(n,k,mod_facts);
    }




    return 0;
}








// hard coded snippet to get prime factors of m
//    vector<ulli> res;
//    for(ulli i = 2; (i*i) < p; ++i) {
//        if(p%i == 0) {
//            while(p%i == 0) {
//                p/=i;
//                res.push_back(i);
//            }
//        }
//    }
//    if(p>1)
//        res.push_back(p);
//    print_vector(res);
//        int test_cases;
//        cin >> test_cases;
//
//
//        ulli n, r;
//        for (int t = 1; t <= test_cases; ++t) {
//            cin >> n >> r;
//            // resize according to new input
//
////            arr.resize(n+1, vector<ulli>(n+1));
//
////            rowPascal(n);
//
//
////            cout << "Case #" <<t << ": " << row[r] << "\n";
//
//
//
//
//        }
//    ulli n = 100, r = 12, p = 223092870;

