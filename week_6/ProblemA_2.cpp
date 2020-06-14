////
//// Created by abahnasy on 01.06.20.
////
//// !!! DISCLAIMER: the part for checking the validity of the segments has been explained to me into details
//// with pseudo code from one of my friends who took this course before. it was not originally my idea. Ahmed Bahnasy
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//
//int observs[6][100];
//char c;
//
//
//
//
//
//bool check(vector<int> ill_posed_repr[], int st1, int st2, int dq1, int dq2, int sttt1, int sttt2, int dqqq1, int dqqq2){
//    if(find(ill_posed_repr[st1].begin(), ill_posed_repr[st1].end(), sttt1) == ill_posed_repr[st1].end())
//        return false;
//    if(find(ill_posed_repr[st2].begin(), ill_posed_repr[st2].end(), sttt2) == ill_posed_repr[st2].end())
//        return false;
//    if(find(ill_posed_repr[dq1].begin(), ill_posed_repr[dq1].end(), dqqq1) == ill_posed_repr[dq1].end())
//        return false;
//    if(find(ill_posed_repr[dq2].begin(), ill_posed_repr[dq2].end(), dqqq2) == ill_posed_repr[dq2].end())
//        return false;
//    return true;
//}
//
//bool check_pos(int n, vector<int> seg_repr[], vector<int> ill_posed_repr[], int saat, int deq) {
//    vector<vector<int>> working_segments(10, vector<int>(10));
//    // input: candidate time from search space
//    for(int i = 0; i < 5; ++i)
//        for(int j = 0; j < 8; ++j)
//            working_segments[i][j] = 0;
//    int sss[4];
//
//
//    for(int i = 0; i < n; ++i){
//
//        sss[0] = saat / 10;
//        sss[1] = saat % 10;
//        sss[2] = deq / 10;
//        sss[3] = deq % 10;
//
//        // check if the candidate time is present in shape of one of its ill posed representations
//        if(check(ill_posed_repr, sss[0], sss[1], sss[2], sss[3], observs[0][i], observs[1][i], observs[2][i], observs[3][i]) == true){
//            // check the working segments per segment
//            for(int j = 0; j < 4; ++j){
//
//                for(int k : seg_repr[observs[j][i]]){
//                    if(working_segments[j][k] == 2) // malfunction segment is lit up, not possible time candidate
//                        return false;
//                    working_segments[j][k] = 1;
//                }
//                for(int k : seg_repr[sss[j]]){
//                    // check if there is a segment for the candidate not found in the observation but functional, so it should be lit up, so this observation is not consistent.
//                    if(find(seg_repr[observs[j][i]].begin(), seg_repr[observs[j][i]].end(), k) == seg_repr[observs[j][i]].end()){
//                        if(working_segments[j][k] == 1)
//                            return false;
//                        working_segments[j][k] = 2; // I need to light this, malfunction segment
//                    }
//                }
//            }
//        }
//        else
//            return false;
//
//        ++deq;
//        if(deq == 60)
//            deq = 0, ++saat;
//        if(saat == 24)
//            saat = 0;
//    }
//
//
//    return true;
//}
//
//
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../../week_6/samples_06/alarmclock/1.in", "r", stdin);
////    freopen("../../week_6/samples_06/alarmclock/unit_test.in", "r", stdin);
//
//    vector<int> seg_repr[10];
//    vector<int> ill_posed_repr[10];
//
//    seg_repr[1].push_back(1);
//    seg_repr[1].push_back(2);
//
//    seg_repr[2].push_back(1);
//    seg_repr[2].push_back(7);
//    seg_repr[2].push_back(4);
//    seg_repr[2].push_back(3);
//    seg_repr[2].push_back(6);
//
//    seg_repr[3].push_back(1);
//    seg_repr[3].push_back(2);
//    seg_repr[3].push_back(7);
//    seg_repr[3].push_back(3);
//    seg_repr[3].push_back(6);
//
//    seg_repr[4].push_back(1);
//    seg_repr[4].push_back(7);
//    seg_repr[4].push_back(2);
//    seg_repr[4].push_back(5);
//
//    seg_repr[5].push_back(2);
//    seg_repr[5].push_back(7);
//    seg_repr[5].push_back(3);
//    seg_repr[5].push_back(5);
//    seg_repr[5].push_back(6);
//
//    seg_repr[6].push_back(2);
//    seg_repr[6].push_back(7);
//    seg_repr[6].push_back(4);
//    seg_repr[6].push_back(3);
//    seg_repr[6].push_back(5);
//    seg_repr[6].push_back(6);
//
//    seg_repr[7].push_back(6);
//    seg_repr[7].push_back(1);
//    seg_repr[7].push_back(2);
//
//    seg_repr[8].push_back(1);
//    seg_repr[8].push_back(2);
//    seg_repr[8].push_back(3);
//    seg_repr[8].push_back(4);
//    seg_repr[8].push_back(5);
//    seg_repr[8].push_back(6);
//    seg_repr[8].push_back(7);
//
//    seg_repr[9].push_back(1);
//    seg_repr[9].push_back(2);
//    seg_repr[9].push_back(3);
//    seg_repr[9].push_back(5);
//    seg_repr[9].push_back(6);
//    seg_repr[9].push_back(7);
//
//    seg_repr[0].push_back(1);
//    seg_repr[0].push_back(2);
//    seg_repr[0].push_back(3);
//    seg_repr[0].push_back(4);
//    seg_repr[0].push_back(5);
//    seg_repr[0].push_back(6);
//
//    // figure out the ill-posed representations for every number
//    for(int i = 0; i < 10; ++i) {
//        for(int j = 0; j < 10; ++j) {
//            bool flag = true;
//            for(int k : seg_repr[i]){
//                if(find(seg_repr[j].begin(), seg_repr[j].end(), k) == seg_repr[j].end()){
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag == true)
//                ill_posed_repr[j].push_back(i);
//        }
//    }
//
////    for (int i = 0; i < 10; ++i) {
////        for(auto it = ill_posed_repr[i].begin(); it != ill_posed_repr[i].end(); ++it) {
////            cout << *it << ", ";
////        }
////        cout << "\n";
////    }
//
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; ++t) {
//        vector<int> final_hours, final_mins;
//        int n;
//        cin>>n;
////        final_hours.clear();
////        final_mins.clear();
//
//        for(int i = 0; i < n; ++i){
//            cin >> c;
//            observs[0][i] = c - '0';
//            cin >> c;
//            observs[1][i] = c - '0';
//            cin >> c;
//            cin >> c;
//            observs[2][i] = c - '0';
//            cin >> c;
//            observs[3][i] = c - '0';
//        }
//
//        for(int i = 0; i < 24; ++i)
//            for(int j = 0; j < 60; ++j){
//                if(check_pos(n, seg_repr, ill_posed_repr, i, j) == true){
//                    final_hours.push_back(i);
//                    final_mins.push_back(j);
//                }
//            }
//
//        cout<<"Case #"<<t<<":\n";
//        for(int i = 0; i < final_hours.size(); ++i)
//            cout << final_hours[i] / 10 << final_hours[i] % 10 << ":" << final_mins[i] / 10 << final_mins[i] % 10 << endl;
//        if(final_hours.size() == 0)
//            cout<<"none"<<endl;
//    }
//
//    return 0;
//}
//
