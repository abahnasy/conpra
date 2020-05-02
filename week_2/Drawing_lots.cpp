////
//// Created by abahnasy on 02.05.20.
////
//
//#include  <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//
//double calc_cost(vector<int> values, double prob) {
//    double res = 0;
//    for (int j = 0; j < values.size(); ++j) {
//        res += values.at(j)*pow(prob, j+1);
//    }
//    return res;
//}
//
//int  main() {
//
//    std::ios_base::sync_with_stdio(false);
//    //  loop  over  all  test  cases
//    int t;
//    cin >> t;
//    for(int i = 1; i  <= t; i++) {
//        //  read  testcase input
//        int n, b;
//        cin >> n >> b;
//        vector<int> values;
//        for (int j = 0; j < n; ++j) {
//            int temp;
//            cin >> temp;
//            values.push_back(temp);
//        }
//
//        double err = 0.000001;
//
//        // binary search over range [0,1]
//        double l = 0;
//        double r = 1;
//        double mid = l + (r-l)/2;
//        double cost = calc_cost(values, mid);
//
//        while ( r - l > err && abs(cost - b) > err) {
//            if (cost - b > 0) {
//                r=mid-err;
//            } else {
//                l = mid+err;
//            }
//            mid = l + (r-l)/2;
//            cost = calc_cost(values, mid);
//        }
//
//        std::cout  << "Case #" << i << ": " << mid << std::endl;
//
//    }
//    return  0;
//}