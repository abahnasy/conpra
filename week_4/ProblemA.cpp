////
//// Created by abahnasy on 18.05.20.
////
//
//#include <bits/stdc++.h>
//
//
//
//using namespace std;
//
//typedef pair<int, int> pi ;
//
//
//
//void dijkstra(vector<pi> adjList[], int n, int src, int des) {
//
//    vector<bool> visited(n+1, false);
//    vector<int> dist(n+1, INT_MAX);
//    dist[src] = 0;
//    visited[src] = true;
//   // use vector as priority queue, search for min score, remove it from the vector
//    auto cmp = [](pi left, pi right) { return (left.second > right.second); };
//
//    std::priority_queue<pi, std::vector<pi>, decltype(cmp)> pq(cmp);
//
//    cout << "I'm pushing now:  ";
//    for (auto it = adjList[src].begin(); it != adjList[src].end(); ++it) {
//        cout << it->first << " with weight " << it->second << "\n";
//        pq.push(*it);
//    }
//    cout << "finished pushing" << "\n";
//
//    while(!pq.empty()) {
//        pi curr = pq.top();
//        cout << "popping " << curr.first << " with wieght " << curr.second << "\n";
//        pq.pop();
//        // look over the neighbours of the popped node and update the distance
//        if(!visited[curr.first]) {
//            visited[curr.first] = true;
//            dist[curr.first] = curr.second;
//            for (auto it = adjList[curr.first].begin(); it != adjList[curr.first].end(); ++it) {
//                cout << "pushing " << it->first << " with weights " << dist[curr.first] + it->second << "\n";
//                pq.push({it->first, dist[curr.first] + it->second});
//            }
//        } else {
//            cout << "visited before \n";
//        }
//    }
//
//
//    cout << dist[des] << "\n";
//
//}
//
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for(int t = 1; t  <= test_cases; t++) {
//        cout  << "Case #" << t << ": ";
//        int n, m;
//        cin >> n >> m;
//        // construct graph
//        vector<pi> adjList[n+1]; // don't use zero
//        // scan for edges
//        int v, w, c;
//        for (int i = 0; i < m; ++i) {
//            cin >> v >> w >> c;
//            adjList[v].push_back(make_pair(w,c));
//            adjList[w].push_back(make_pair(v,c));
//        }
//
//        dijkstra(adjList, n, 1, n);
//
//
//    }
//}
//
//
////Ideas: my remove the duplicates connections between node by keeping the shortest only.