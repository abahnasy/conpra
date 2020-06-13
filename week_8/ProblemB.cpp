////
//// Created by abahnasy on 12.06.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef vector<int> vi ;
//typedef vector<vector<int>> vii ;
//typedef vector<bool> vb;
//typedef vector<vector<bool>> vbb ;
//
//
//int length_lcs(const string s1, const string s2) {
//    int len_s1 = s1.length();
//    int len_s2 = s2.length();
//    vii dp (len_s1+1, vi(len_s2+1, 0));
//    for (int i = 1; i <= len_s1 ; ++i) {
//        for (int j = 1; j <= len_s2; ++j) {
//            if(s1[i-1] == s2[j-1]) {
//                dp[i][j] = 1 + dp[i-1][j-1];
//            } else {
//                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//            }
//        }
//    }
//    return dp[len_s1][len_s2];
//}
//
//int main() {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../week_8/samples_08/bracelets/1.in", "r", stdin);
////    freopen("../week_8/samples_08/bracelets/2.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//    string s1, s2;
//    for (int t = 1; t <= test_cases; ++t) {
//        cin >> s1 >> s2;
//
////        cout << "print scanned strings " << s1 << " " << s2 << "\n";
//
//        int max_match = 0;
//        for(int i =0; i < s1.length();++i) {
//            rotate(s1.begin(), s1.begin()+1, s1.end());
//            max_match = max(max_match, length_lcs(s1, s2));
////            cout << "comparison: " << s1 <<", " << s2 << " is "<< max_match<< "\n";
//
//
//            // reverse the current rotated version
//            string s1_rev = s1;
//            reverse(s1_rev.begin(), s1_rev.end());
//            max_match = max(max_match, length_lcs(s1_rev, s2));
////            cout << "comparison: " << s1_rev <<", " << s2 << " is "<< max_match<< "\n";
//
//
//        }
//
//
//        cout << "Case #"<<t<<": ";
//        cout << max_match << "\n";
//
//
//
//    }
//
//
//
//    return 0;
//}
//
//
//
//
//
