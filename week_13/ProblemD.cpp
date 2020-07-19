

#include <bits/stdc++.h>


using namespace std;

typedef long long ll;


char a[20], b[20];
bool check(int x,int len)
{
    for(int i=x;i<len;i++)
        if(a[i]!='0') return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_13/samples_13/absurdprices/1.in", "r", stdin);
//    freopen("../../week_13/samples_13//2.in", "r", stdin);
//    freopen("../../week_13/samples_13/absurdprices/test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;
    ll n;

    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        cin >> n;

        ll c;
        sprintf(a, "%lld", n);
        int len = strlen(a);
        for (int i = len - 1; i >= 0 ; --i) {
            if(a[i] != '0') {
                if(a[i] == '5') {
                    c = (i+1)*2 - 1;
                } else {
                    c = (i+1)*2;
                }
                break;
            }
        }

        ll l,r;
        //TODO: check what was wrong with calculation
        r = n*105/100;
        l = (n*95-1)/100+1;
        sprintf(a, "%lld", l);
        sprintf(b, "%lld", r);

        int lena = strlen(a);
        int lenb = strlen(b);

        if(lena != lenb) {
            if (c>2) {
                cout << "absurd\n";
            } else {
                cout << "not absurd\n";
            }
        } else {
            int i, ret;
            for(i=0; i < lena; ++i) {
                if(a[i] != b[i])
                    break;
            }
            if(i==lena||(a[i]=='0'&&check(i+1,lena))){
                while(a[i]=='0') i--;
                if(a[i]=='5') ret = (i+1)*2 - 1;
                else ret = (i+1)*2;
            }else{
                int l,r;
                if(check(i+1,lena)) l = a[i]-'0',r = b[i]-'0';
                else l = a[i]-'0'+1,r = b[i]-'0';
                if(l<=5&&r>=5) ret = (i+1)*2 - 1;
                else ret = (i+1)*2;
            }

            if(c>ret) {
                cout << "absurd\n";
            } else {
                cout << "not absurd\n";
            }

        }
    }

    return 0;
}