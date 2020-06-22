//
// Created by abahnasy on 12.06.20.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi ;
typedef vector<vector<int>> vii ;
typedef vector<bool> vb;
typedef vector<vector<bool>> vbb ;

void minChange(vi& result, vi& denom, int changeAmount)
{
    int n = denom.size();
    vi count(changeAmount + 1);
    vi from (changeAmount + 1);

    count[0] = 1;
    for (int i = 0 ; i < changeAmount; i++)
        if (count[i] > 0)
            for (int j = 0; j < n; j++)
            {
                int p = i + denom[j];
                if (p <= changeAmount)
                {
                    if (count[p] == 0 || count[p] > count[i] + 1)
                    {
                        count[p] = count[i] + 1;
                        from[p] = j;
                    }
                }
            }

    // No solutions:
    if (count[changeAmount] != 0) {
        result.resize(count[changeAmount] - 1);
        int k = changeAmount;
        while (k > 0)
        {
            result[count[k] - 2] = denom[from[k]];
            k = k - denom[from[k]];
        }

    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // redirect input stream to samples files
    freopen("../../week_8/samples_08/makingchange/1.in", "r", stdin);
//    freopen("../../week_8/samples_08/makingchange/2.in", "r", stdin);

    int test_cases;
    cin>> test_cases;



    for (int t = 1; t <= test_cases; ++t) {
        int n, c;
        cin >> n >> c;
        vi coin_vals; // reserve place for coin with value 1
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            coin_vals.push_back(temp);
            m[temp] = 0;
        }
        vi res(n, 0);
        minChange(res, coin_vals, c);
        for(auto x: res) {
            m[x]++;
        }


        cout << "Case #"<<t<<": ";

        for(auto i = m.begin(); i != m.end(); i++) {
            cout << i->second << " ";
        }
        cout << "\n";


    }



    return 0;
}



