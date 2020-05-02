////
//// Created by abahnasy on 02.05.20.
////
//
//#include  <iostream>
//#include <iomanip>
//# define ERR double(0.000001)
//using namespace std;
//bool greaterThan(double a, double b)
//{
//    double err = 0.000000001;
//    return (a - b) > err;
//}
//
//bool check_dist(double mid, int d, int p, int u, int v)
//{
//    // find out how many post I can place until I reach u
//    int poss_before = ((u/mid) + 1);
//
//
//    double pos_before = (poss_before - 1) * mid;
//    double pos_after = v;
//    if (greaterThan(pos_before + mid, v))
//        pos_after = pos_before + mid;
//
//    // how many to be placed from v till end
//    int poss_after = ((d - pos_after) / mid + 1);
//
//    return poss_before + poss_after >= p;
//}
//int  main() {
//
//
//    std::ios_base::sync_with_stdio(false);
//    //  loop  over  all  test  cases
//    int t;
//    cin >> t;
//    for(int i = 1; i  <= t; i++) {
//        //  read  several  types  of  input
//        int d, p , u, v;
//        cin >> d >> p >> u >> v;
//
//        double err = 0.000000001;
//        double l = 0;
//        double r = d;
//
//        double mid;
//
//
//        while (r-l > err) {
//            mid = l + (r-l)/2;
//            if(check_dist(mid, d, p, u, v)) {
//                //increase possible distance
//                l = mid;
//            } else {
//                // decrease possible distance
//                r = mid;
//            }
//
//        }
//
//        cout  << "Case #" << i << ": " << setprecision(11) << mid << std::endl;
//    }
//    return  0;
//}