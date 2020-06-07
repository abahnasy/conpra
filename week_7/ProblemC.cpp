////
//// Created by abahnasy on 06.06.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef vector<int> vi ;
//typedef vector<vector<int>> vii ;
//
//int n; //number of nodes
//
//int compute_max_cut(vii& g, vi& set_a) {
//    int max_connections = 0;
//    for (auto node_a: set_a) {
//        for(int i = 1; i <= n; ++i ) {
//            if(find(set_a.begin(), set_a.end(), i) == set_a.end()) {
//                max_connections += g[node_a][i];
//            }
//        }
//
//    }
//
//    return max_connections;
//}
//
//int main() {
//
////    ios_base::sync_with_stdio(false);
////    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../week_7/samples_07/customs/1.in", "r", stdin);
////    freopen("../week_7/samples_07/customs/2.in", "r", stdin);
////    freopen("../week_7/samples_07/customs/unit_test.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//
//    for (int t = 1; t <= test_cases; ++t) {
//        cout << "Case #"<<t<<": \n";
//        cin >> n;
//        vii g(n+1, vi(n+1, 0));
//        int edges;
//        for (int i = 1; i <= n; ++i) {
//            cin >> edges;
//            int neighbour;
//            for (int j = 0; j < edges; ++j) {
//                cin >> neighbour;
//                // undirected
//                g[i][neighbour] += 1;
//                g[neighbour][i] += 1;
//
//            }
//        }
//
//
//        // value vector with degrees of the nodes
//
//        vector<pair<int, int>> values;
//        for (int i = 1; i <= n; ++i) {
//            int connections = 0;
//            for (int j = 1; j <= n; ++j) {
//                connections += g[i][j];
//            }
//            values.push_back(make_pair(connections, i));
//        }
//
//        // get node with max degree
//        sort(values.begin(), values.end());
//        vi set_a;
//
//        int optim_connections = 0;
//
//
//        do {
//            // get the node with highest degree
//            pair<int, int> node = values.back();
//            int node_id = node.second;
//            values.pop_back();
//            // add it to the selected set
//            set_a.push_back(node_id);
//            // compute connections
//            int curr_connections = compute_max_cut(g, set_a);
//            if (curr_connections > optim_connections) {
//                // keep it and update the new connection value
//                optim_connections = curr_connections;
//            } else {
//                // remove it
//                set_a.pop_back();
//            }
//
//
//        } while (!values.empty());
//
//        for (auto x: set_a) {
//            cout << x << " ";
//        }
//        cout << "\n";
//    }
//
//
//
//    return 0;
//}
//
