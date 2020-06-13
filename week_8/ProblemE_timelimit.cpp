////
//// Created by abahnasy on 13.06.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//# define INF 0x3f3f3f3f
//typedef vector<int> vi;
//typedef vector<vector<int> > vii;
//typedef pair<int, int> pi;
//
//
//vi num_objects;
//vi fut_lea_dist;
//int reached_safely = false;
//int global_max_objects = 0;
//
//void dijkstra(const vii& fut_lea,const int g, const int n, vi& dist) {
//    // pairs(cost, node)
//    priority_queue<pi, vector<pi>, greater<pi> > pq;
//    dist.clear();
//    dist.resize(n+1, INF);
//    pq.push(make_pair(0, g));
//    dist[g] = 0;
//    while (!pq.empty())  {
//        int u = pq.top().second;
//        pq.pop();
//        // loop to get all vertices
//        for (int i = 0; i <= n; ++i) {
//            if (fut_lea[u][i] > 0) {
//                // get vertex and weight
//                int weight = fut_lea[u][i];
//                if(dist[i] > dist[u] + weight) {
//                    dist[i] = dist[u] + weight;
//                    pq.push(make_pair(dist[i], i));
//                }
//            }
//        }
//    }
//}
//
//void check_all_paths_util(vii& lea, int s, int d, vector<bool>& visited, vector<int> path_track, int path_idx, int n) {
//    visited[s] = true;
//    path_track[path_idx] = s;
//    path_idx++;
//    bool res = false;
//
//    if(s == d) {
//        int max_objects = 0;
//        int time_to_surface = 0;
//        bool invalid = false;
//        // check if the path is valid or not
//        // calculate time to surface, must be faster than future lea
//        // for every node lea must be faster than future lea
//        for (int i = 0; i < path_idx; ++i) {
////            cout << path_track[i] << " ";
//            if (i>0) {
//                time_to_surface += lea[path_track[i-1]][path_track[i]];
//            }
//            // invalid path
//            if(time_to_surface>= fut_lea_dist[path_track[i]]) {
//                invalid = true;
//                continue;
//            }
//            max_objects += num_objects[path_track[i]];
//        }
//
//        if(!invalid) {
////            cout << "objects could be taken " << max_objects << "\n";
//            global_max_objects = max(global_max_objects, max_objects);
//            res = true;
//            reached_safely = true;
//        }
//
////        cout << "\n";
////        cout << "time to surface "<< time_to_surface << "\n";
////        cout << "future lea time to surface " << fut_lea_dist[0] << "\n";
//
//    } else {
//        for (int i = 0; i <= n; ++i) {
//            if(lea[s][i] > 0 && visited[i] == false) {
//                check_all_paths_util(lea, i, d, visited, path_track, path_idx, n);
//            }
//        }
//    }
//    path_idx--;
//    visited[s] = false;
//}
//void check_all_paths (vii& lea, int s, int d, int n) {
//    vector<bool> visited(n+1, false);
//    vector<int> path_track(n+1, 0);
//    int path_idx = 0;
//
//    int max_objects = 0;
//
//    check_all_paths_util(lea, s,d,visited, path_track, path_idx, n);
//
//
//
//
//}
//
//int main() {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    // redirect input stream to samples files
////    freopen("../week_8/samples_08/escapingtheparadox/1.in", "r", stdin);
////    freopen("../week_8/samples_08/escapingtheparadox/2.in", "r", stdin);
////    freopen("../week_8/samples_08/escapingtheparadox/test.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//
//    int n, m, g; // graves, tunnels and position of future lea
//    // future lea's grave -> g
//    // lea's grave -> n
//    for (int t = 1; t <= test_cases; ++t) {
//        reached_safely = false;
//        global_max_objects = 0;
//        cout << "Case #"<<t<<": ";
//        cin >> n >> m>> g;
//        // read number of objects
//        num_objects.clear();
//        num_objects.resize(n+1, 0);
//        for (int i = 1; i <= n; ++i) {
//            int temp;
//            cin >> temp;
//            num_objects[i] = temp;
//        }
//
//        vii fut_lea(n+1, vi(n+1, 0));
//        vii lea(n+1, vi(n+1, 0));
//
//        for (int i = 0; i < m; ++i) {
//            int n1, n2, c;
//            cin >> n1 >> n2 >> c;
//            if(n1 == n2)
//                continue;
//            //update undirected graph
//            if (fut_lea[n1][n2] == 0 || fut_lea[n1][n2] > c) {
//                fut_lea[n1][n2] = c;
//                fut_lea[n2][n1] = c;
//                //update lea graph
//                lea[max(n1, n2)][min(n1, n2)] = c;
//            }
//        }
//
//
//
//
//        dijkstra(fut_lea, g, n, fut_lea_dist);
//        check_all_paths(lea, n, 0, n);
//
//        if (reached_safely) {
//            cout << global_max_objects << "\n";
//        } else {
//            cout << "impossible" << "\n";
//        }
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
//
//}
//
////vii test(10, vi(10, 0));
////test[1][2] = 4;test[2][1] = 4;
////test[1][8] = 8; test[8][1] = 8;
////test[2][3] = 8; test[3][2] = 8;
////test[2][8] = 11; test[8][2] = 11;
////test[3][4] = 7; test[4][3] = 7;
////test[3][9] = 2; test[9][3] = 2;
////test[3][6] = 4; test[6][3] = 4;
////test[4][5] = 9; test[5][4] = 9;
////test[4][6] = 14; test[6][4] = 14;
////test[5][6] = 10; test[6][5] = 10;
////test[6][7] = 2; test[7][6] = 2;
////test[7][8] = 1; test[8][7] = 1;
////test[7][9] = 6; test[9][7] = 6;
////test[8][9] = 7; test[9][8] = 7;
////
////dijkstra(test, 1, 9, dist);
////for (auto x: dist) {
////cout << x << "\n";
////}