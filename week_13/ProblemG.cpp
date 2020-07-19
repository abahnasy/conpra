

#include <bits/stdc++.h>


using namespace std;


bool prime(int n) {
    if (n < 2) return false;
    for (int x = 2; x*x <= n; x++) {
        if (n%x == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_13/samples_13/anindustrialspy/1.in", "r", stdin);
//    freopen("../../week_13/samples_13//2.in", "r", stdin);
//    freopen("../../week_13/samples_13/anindustrialspy/test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;
    int n;
    string str;

    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        cin >> n >> str;
        int count = 0;
        set<int> visited;
        for (int i = 0; i < (1 << n); ++i) {
            string tmp = "";
            for (int j = 0; j < n; ++j) {
                if(i&(1<<j)) {
                    tmp+= str[j];
                }
            }
            // convert to characters and sort for permutations
            char c_tmp[tmp.length()+1];
            strcpy(c_tmp, tmp.c_str());
            sort(c_tmp, c_tmp+tmp.length());
            do {
//                cout<< "Permutation: " << c_tmp << " extracted no. is " << atoi(c_tmp) << "\n";
                auto p = visited.find(atoi(c_tmp));
                if(p != visited.end()) {
                    continue;
                }
                visited.insert(atoi(c_tmp));
                if(prime(atoi(c_tmp))) {
                    count++;
                }
            } while (next_permutation(c_tmp, c_tmp + tmp.length()));

        }
        cout << count << "\n";
    }

}