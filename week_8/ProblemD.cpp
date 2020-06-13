////
//// Created by abahnasy on 13.06.20.
////

////TODO: You can do DP with 1D array and it is only O(n). Keeping track of the maximum money that can be earned till day n.
//
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
//int cmp (pair<pair<int, int>,int>& a, pair<pair<int, int>,int>& b) {
//    if (a.first.second < b.first.second) {
//        return 1;
//    } else {
//        return 0;
//    }
//}
//
//int main() {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../week_8/samples_08/poker/1.in", "r", stdin);
////    freopen("../week_8/samples_08/poker/2.in", "r", stdin);
////    freopen("../week_8/samples_08/poker/test.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//    int n;
//    int s, e, p;
//
//
//    for (int t = 1; t <= test_cases; ++t) {
//        cin >> n;
//        vector <pair<pair<int,int>, int > > tour;
//        tour.push_back(make_pair(make_pair(0,0),0)); // empty pai for index 0
//        for (int i = 0; i < n; ++i) {
//            cin >> s >> e >> p;
//            // format ((start, end), reward)
//            tour.push_back(make_pair(make_pair(s,e), p));
//        }
//        // sort according to end time
//        sort(tour.begin(), tour.end(), cmp);
//
//        // get the last max time
//        int max_time = tour.back().first.second;
//
//        vii dp (tour.size(), vi(max_time+1, 0));
//
//        for (int i = 0; i <= tour.size()-1; ++i) {
//            for (int j = 0; j <= max_time; ++j) {
//                if (i == 0 || j ==0 ) {
//                    dp[i][j] = 0;
//                } else if(j >= tour[i].first.second) {
//                    dp[i][j] = max (dp[i-1][j], dp[i-1][tour[i].first.first - 1] + tour[i].second);
//                } else {
//                    dp[i][j] = dp[i-1][j];
//                }
//            }
//        }
//
//
//
//
//
//
//        cout << "Case #"<<t<<": " << dp[tour.size()-1][max_time] << "\n";
//
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
