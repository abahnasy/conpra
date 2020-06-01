////
//// Created by abahnasy on 31.05.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//// right, down, left, up
//
//vector<int> y_move {0, 1, 0, -1};
//vector<int> x_move {1, 0, -1, 0};
//
//int w, h;
//
//void print_map(vector<vector<char>>&map, int h, int w) {
//    for (int i = 0; i < h; ++i) {
//        for (int j = 0; j < w; ++j) {
//            cout << map[i][j];
//        }
//        cout << "\n";
//    }
//}
//
//bool is_safe(vector<vector<char>>& map,  int pos_y, int pos_x) {
//    if (pos_x >= 0 && pos_x < w && pos_y >= 0 && pos_y < h) {
//        if(map[pos_y][pos_x] != '#' && map[pos_y][pos_x] != 'V') {
//            return true;
//        }
//    }
//    return false;
//}
//
//bool back_track(vector<vector<char>>& map, int pos_y , int pos_x , int& num_tools, const int& total_tools) {
//
//    if (num_tools == total_tools) {
//        return true;
//    } else {
//
//        // loop over the possible directions -> right, down, left, up
//        for (int i = 0; i < 4; ++i) {
//            int next_y = pos_y + y_move[i];
//            int next_x = pos_x + x_move[i];
//
//            if(is_safe(map, next_y,next_x)) {
//                int prev_sign = map[next_y][next_x];
//                if(map[next_y][next_x] == 'T')
//                    num_tools++;
//                // mark the new position as visited
//                map[next_y][next_x] = 'V';
//                if(back_track(map, next_y,next_x, num_tools, total_tools)) {
//                    return true;
//                } else {
//                map[next_y][next_x] = prev_sign;
//                if(map[next_y][next_x] == 'T')
//                    num_tools--;
//                  //  return false;
//                }
//            }
//
//        }
//        // back_track and release tool in this position
////        num_tools--;
//        return false;
//
//    }
//}
//
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
////    freopen("../week_6/samples_06/trapped/1.in", "r", stdin);
////    freopen("../week_6/samples_06/trapped/2.in", "r", stdin);
////    freopen("../week_6/samples_06/trapped/unit_test.in", "r", stdin);
//
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; ++t) {
//
//        cin >> w >> h;
//        vector<vector<char >> map (h, vector<char>(w));
//
//        int total_tools = 0;
//        int  lea_y,lea_x;
//        for (int i = 0; i < h; ++i) {
//            for (int j = 0; j < w; ++j) {
//                char c;
//                cin >> c;
//                map[i][j] = c;
//                if(c == 'T')
//                    total_tools++;
//                else if (c == 'L') {
//                    lea_x = j; lea_y = i;
//                }
//            }
//        }
//        string line;
//        getline(cin, line);
//        cout << "Case #" << t << ": ";
////        print_map(map, h,w);
//
//        int num_tools = 0;
//        map[lea_y][lea_x] = 'V';
//        back_track(map, lea_y, lea_x, num_tools, total_tools);
//        if(total_tools == num_tools) {
//            cout << "yes\n";
//        } else {
//            cout << "no\n";
//        }
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
