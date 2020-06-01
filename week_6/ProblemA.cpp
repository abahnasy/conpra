////
//// Created by abahnasy on 31.05.20.
////
//
//// High level understanding for the problem
//// search space every single min in the 24-hour day
//// check if that time is possible given the following reading
//#include <bits/stdc++.h>
//
//using namespace std;
//
//// make sure to be sorted vectors so that can be used in intersection and union operations
//vector<vector<int>> possibles {
//        {8}, // possibles if the visible digit is 0 -> {0,8}
//        {0,3,4,7,8,9}, // possibles if the visible digit is 1 -> {0,1,2,3,4,7,8,9}
//        {8}, // possibles if the visible digit is 2 -> {2,8}
//        {8,9}, // possibles if the visible digit is 3 -> {3,8,9}
//        {8,9}, // possibles if the visible digit is 4 -> {4,8,9}
//        {6,8,9}, // possibles if the visible digit is 5 -> {5,6,8,9}
//        {8}, // possibles if the visible digit is 6 -> {6,8}
//        {0,3,8,9}, // possibles if the visible digit is 7 -> {0,3,7,8,9}
//        {}, // possibles if the visible digit is 8 -> {8}
//        {8}, // possibles if the visible digit is 9 -> {8,9}
//};
//
//
//
//int main () {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../week_6/samples_06/alarmclock/1.in", "r", stdin);
////    freopen("../week_6/samples_06/alarmclock/unit_test.in", "r", stdin);
//
//
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; ++t) {
//        cout << "Case #" << t << ": \n";
//        int n;
//        cin >> n;
//        // observation per every position
//        vector<vector<int>> obs (4, vector<int>(n));
//        char obs_digit;
//
//        vector<int> final_hour_tenth;
//        vector<int> final_hour_unit;
//        vector<int> final_min_tenth;
//        vector<int> final_min_unit;
//
//        // read the actual time appeared
//        cin >> obs_digit;
//        obs[0][0] = obs_digit - '0'; // hours tenth
//        final_hour_tenth = possibles[obs[0][0]]; // copy intial possible values
//        cin >> obs_digit;
//        obs[1][0] = obs_digit - '0'; // hours units
//        final_hour_unit = possibles[obs[1][0]]; // copy intial possible values
//        cin >> obs_digit; // skip delimiter ":"
//        cin >> obs_digit;
//        obs[2][0] = obs_digit - '0'; // min tenth
//        final_min_tenth = possibles[obs[2][0]]; // copy intial possible values
//        cin >> obs_digit;
//        obs[3][0] = obs_digit - '0'; // min units
//        final_min_unit = possibles[obs[3][0]]; // copy intial possible values
//
//        // reading consequenet minutes and eliminitate the prelimenary set based on the reading
//        vector<int> temp_vector;
//        for (int i = 1; i < n; ++i) {
//            cin >> obs_digit;
//            obs[0][i] = obs_digit - '0'; // hours tenth
//            temp_vector.clear();
//            set_intersection(possibles[obs[0][i]].begin(), possibles[obs[0][i]].end(),
//                    final_hour_tenth.begin(),final_hour_tenth.end(), back_inserter(temp_vector));
//            final_hour_tenth = temp_vector;
//
//            cin >> obs_digit;
//            obs[1][i] = obs_digit - '0'; // hours units
//            temp_vector.clear();
//            set_intersection(possibles[obs[1][i]].begin(), possibles[obs[1][i]].end(),
//                             final_hour_unit.begin(),final_hour_unit.end(), back_inserter(temp_vector));
//            final_hour_unit = temp_vector;
//            cin >> obs_digit; // skip delimiter ":"
//            cin >> obs_digit;
//            obs[2][i] = obs_digit - '0'; // min tenth
//            temp_vector.clear();
//            set_intersection(possibles[obs[2][i]].begin(), possibles[obs[2][i]].end(),
//                             final_min_tenth.begin(),final_min_tenth.end(), back_inserter(temp_vector));
//            final_min_tenth = temp_vector;
//            cin >> obs_digit;
//            obs[3][i] = obs_digit - '0'; // min units
//            temp_vector.clear();
//            set_intersection(possibles[obs[3][i]].begin(), possibles[obs[3][i]].end(),
//                             final_min_unit.begin(),final_min_unit.end(), back_inserter(temp_vector));
//            final_min_unit = temp_vector;
//        }
//
//        final_hour_tenth.push_back(obs[0][0]); // push_back the original time to be considered when searchin over search space
//        final_hour_unit.push_back(obs[1][0]);
//        final_min_tenth.push_back(obs[2][0]);
//        final_min_unit.push_back(obs[3][0]);
//        // skip the line
//        string line;
//        getline(cin, line);
//
//        bool none = true;
//        // loop over all the feasible options for time
//        for (int i = 0; i < 24; ++i) {
//            for (int j = 0; j < 60; ++j) {
//                // check if the hour is feasible
//                int hour_unit = i%10;
//                int hour_tenth = i/10;
//                int min_unit = j%10;
//                int min_tenth = j / 10;
//
////                cout << "print search space "<< hour_tenth << hour_unit << ":" << min_tenth << min_unit << "\n";
//
//                bool flag = true;
//
//
//                if(find(final_hour_tenth.begin(), final_hour_tenth.end(), hour_tenth) == final_hour_tenth.end()) {
//                    flag = false;
////                    break;
//                }
//                // check over position 1
//                if(find(final_hour_unit.begin(), final_hour_unit.end(), hour_unit) == final_hour_unit.end()) {
//                    flag = false;
////                    break;
//                }
//                // check over position 2
//                if(find(final_min_tenth.begin(), final_min_tenth.end(), min_tenth) == final_min_tenth.end()) {
//                    flag = false;
////                    break;
//                }
//                // check over position 3
//                if(find(final_min_unit.begin(), final_min_unit.end(), min_unit) == final_min_unit.end()) {
//                    flag = false;
////                    break;
//                }
//
//
//                if (flag) {
//                    // candidate is possible, print it
//                    cout << hour_tenth << hour_unit << ":" << min_tenth << min_unit << "\n";
//                    none = false;
//                }
//
//            }
//        }
//
//        if(none) {
//            cout << "none\n";
//        }
//
//
//
//    }
//}
