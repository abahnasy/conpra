////
//// Created by abahnasy on 06.06.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//
//
//
//int main() {
//
////    ios_base::sync_with_stdio(false);
////    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../week_7/samples_07/woodchucking/1.in", "r", stdin);
////    freopen("../week_7/samples_07/woodchucking/2.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//    int64_t n, m;
//
//    for (int t = 1; t <= test_cases; ++t) {
//        cin >> n >> m;
//        vector<int64_t> time;
//        int temp;
//        for (int i = 0; i < n; ++i) {
//            cin >> temp;
//            time.push_back(temp);
//        }
//        sort(time.begin(), time.end());
//
//        priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t> > pq;
//        for (int64_t i = 0; i < m; ++i) {
//            pq.push(0);
//        }
//
//        while(!time.empty()) {
//            int64_t largest = time.back();
//            time.pop_back();
//
//            int64_t small = pq.top();
//            pq.pop();
//            small += largest;
//            pq.push(small);
//        }
//
//        int64_t print64_t_value;
//        while(!pq.empty()) {
//            print64_t_value = pq.top();
//            pq.pop();
//        }
//        cout << "Case #"<<t<<": ";
//        cout << print64_t_value <<"\n";
//
//
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
