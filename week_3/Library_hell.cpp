////
//// Created by abahnasy on 10.05.20.
////
//#include <iostream>
//#include <vector>
//#include <list>
//#include <set>
//using namespace std;
//
//struct Graph {
//    int V;
//    list<int>*adjList;
//public:
//    Graph(int v);
//    void add_edge(int src, int des);
//    bool BFS(int src, int des);
//};
//
//Graph::Graph(int v) {
//    this->V = v;
//    this->adjList = new list<int>[V];
//}
//void Graph::add_edge(int src, int des) {
//    this->adjList[src].push_back(des);
//}
//bool Graph::BFS(int src, int des) {
//
//    if (src == des)
//        return true;
//
//    vector<bool> visited(V, false);
//    for (int i = 0; i < this->V; ++i) {
//        visited[i] = false;
//    }
//
//    list<int> queue;
//    visited[src] = true;
//    queue.push_back(src);
//
//
//    while (!queue.empty()) {
//        int curr = queue.front();
//        //cout  << curr << " ";
//        queue.pop_front();
//
//        list<int>::iterator it;
//
//        for (it = adjList[curr].begin(); it != adjList[curr].end(); ++it) {
//            if (*it == des) {
//                return true;
//            }
//
//            if (!visited[(*it)]) {
//                visited[(*it)] = true;
//                queue.push_back(*it);
//            }
//
//
//        }
//
//    }
//    return false;
//
//}
//
//
//int main () {
//
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for(int t = 1; t  <= test_cases; t++) {
//        cout  << "Case #" << t << ": ";
//
//        int n, k, r, d;
//        cin >> n >> k >> r >> d;
//
//        vector<int> keep;
//        int scan_var;
//        for (int i = 0; i < k; ++i) {
//            cin >> scan_var;
//            keep.push_back(scan_var);
//        }
//
//        vector<int> remove;
//        for (int i = 0; i < r; ++i) {
//            cin >> scan_var;
//            remove.push_back(scan_var);
//        }
//
//        // create graph
//        Graph graph(n+1);
//        //graph[3] = new list<int> ();
//        // scan dependencies
//        int from, to;
//        for (int i =0; i < d; ++i) {
//            cin >> from >> to;
//            graph.add_edge(from, to);
//        }
//
//        // brute force search for every path between every remove and keep software
//        bool flag = false;
//        for (int i = 0; i < keep.size(); ++i) {
//            for (int j = 0; j < remove.size(); ++j) {
////                cout << keep.at(i) << " " << remove.at(j);
//                if (graph.BFS(keep.at(i), remove.at(j))) {
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag == true)
//                break;
//        }
//
//        if (flag == true)
//            cout << "conflict\n";
//        else
//            cout << "ok\n";
//
//    }
//}