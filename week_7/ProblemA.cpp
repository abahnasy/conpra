////
//// Created by abahnasy on 06.06.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef vector<int> vi ;
//
//int main() {
//
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../week_7/samples_07/streetlights/1.in", "r", stdin);
////    freopen("../week_7/samples_07/streetlights/2.in", "r", stdin);
////    freopen("../week_7/samples_07/streetlights/unit_test.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//    int l,n,d;
//
//    for (int t = 1; t <= test_cases; ++t) {
//        cin >> l >> n >> d;
//
//        // represents the light coverage starting from pos i
//        vi range (l+1, 0);
//        int temp;
//        for (int i = 0; i < n; ++i) {
//            cin >> temp;
//            int start = max(0,temp - d);
//            int end = min (temp+d, l);
//            int pole_range = start+(end-start);
//            if(range[start] < pole_range) {
//                range[start] = pole_range;
//            }
//        }
//
//        int coverage = 0;
//        int count = 0;
//        int idx = 0;
//        int last_idx = -1;
//        while (coverage < l && idx!=last_idx) {
//            if (range[idx] != 0) {
//                coverage = range[idx];
//                count++;
//                last_idx = idx;
//                idx = coverage;
//            } else {
//                idx--;
//            }
//        }
//
//
//        cout << "Case #"<<t<<": ";
//        if (coverage >= l)
//            cout << count <<"\n";
//        else
//            cout << "impossible\n";
//    }
//
//
//
//    return 0;
//}
//
