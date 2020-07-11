//
// Created by abahnasy on 04.07.20.
//

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;


void add(vii& link, string s, int& cnt)
{
    int len = s.size();
    int cur = 0;
    int pos;
    for(int i = 0; i < len; ++i)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            pos = s[i] - 'A';
        else
            pos = s[i] - 'a';

        if(link[cur][pos] == 0)
        {
            link[cur][pos] = ++cnt;
            cur = cnt;
        }
        else
            cur = link[cur][pos];
        //cout<<s[i]<<" "<<cur<<" "<<"indiki"<<endl;
    }

    link[cur][26] = ++cnt;
    //cout<<"$ "<<cnt<<" indiki\n";
    //cout<<cur<<" "<<cnt<<endl;

    //recur(s, len, 0, 0);

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
    freopen("../../week_11/samples_11/ghost/1.in", "r", stdin);
//    freopen("../../week_11/samples_11//2.in", "r", stdin);
//    freopen("../../week_11/samples_11//test.in", "r", stdin);

    int test_cases;
    cin >> test_cases;

    for (int t = 1; t <= test_cases; ++t) {
        cout<<"Case #"<<t<<": \n";
        int n, w;
        cin >> n >>w;
        int cnt = 0;
        vii link (1000000, vi(27, 0));
        string s;
        for (int i = 0; i < w; ++i) {
            cin >> s;
            add(link, s, cnt);
            cout << s << "\n";
        }

    }
}