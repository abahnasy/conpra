////
//// Created by abahnasy on 31.05.20.
////
//
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void print_vector(vector<int>& vec) {
//    for (auto x: vec) {
//        cout << x <<", ";
//    }
//    cout  << "\n";
//}
//
//
//int main () {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../../week_6/samples_06/muffinqueen/1.in", "r", stdin);
////    freopen("../../week_6/samples_06/muffinqueen/2.in", "r", stdin);
//    freopen("../../week_6/samples_06/muffinqueen/unit_test.in", "r", stdin);
//
//
//
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; ++t) {
//
//        int b, j;
//        cin >> b >> j;
////        vector<int> bakers_options;
////        for(int i = 1; i <= b; ++i) {
////            bakers_options.push_back(i);
////            bakers_options.push_back((-1)*i);
////        }
//        vector<int> judge_lists[j];
//        int pref;
//        for (int i = 0; i < j; ++i) {
//            cin >> pref;
//            while(pref != 0) {
//                judge_lists[i].push_back(pref);
//                cin >> pref;
//            }
//        }
//
//        // loop over search space
//        int options = pow(2,b);
//        int flag = true;
//        for (int i = 0; i < options; ++i) {
//            cout << "trying option " << i << "\n";
//            vector<int> curr_option;
//
//            int curr_rep = i;
//            for (int k = 1; k <= b; ++k) {
//                int baker_option = curr_rep & 0x1;
//                if(baker_option == 0)
//                    curr_option.push_back(k);
//                else
//                    curr_option.push_back(-1*k);
//                curr_rep = curr_rep >> 1;
//            }
//            print_vector(curr_option);
//
////            print_vector(curr_option);
//            // loop over judges to see if they are satisfied?
//            for(int k = 0; k <j;++k) {
//                cout << "satisfying judge " << k << "\n";
//                // loop over judge j preferences
//                int flag_per_judge = false;
//                for (auto x: judge_lists[k]) {
//                    if(find(curr_option.begin(), curr_option.end(), x) != curr_option.end()) {
//                        flag_per_judge = true;
//                        break;
//                    }
//                }
//                if(flag_per_judge == false) {
//                    cout << "judge " << k << "is not satisfied" << "\n";
//                    flag = false;
//                    break;
//                }
//            }
//
//            if(flag == true) {
//                break;
//            }
//        }
//
//        if(flag)
//            cout << "Case #" << t << ": " << "yes\n";
//        else
//            cout << "Case #" << t << ": " << "no\n";
//
//
//    }
//}
