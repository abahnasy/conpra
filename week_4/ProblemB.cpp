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
//
//
//struct Edge {
//    int into;
//    double rate;
//};
//
//double get_rate(list<Edge> adjList[], int src, int des) {
//    for (auto it = adjList[src].begin(); it != adjList[des].end(); ++it) {
//        if (it->into == des)
//            return it->rate;
//    }
//}
//
//void print_all_paths_util(vector<double> possible_rates, list<Edge> adjList [], int u, int d, vector<bool> visited,
//                          vector<int> path, int &path_index)
//{
//    // Mark the current node and store it in path[]
//    visited[u] = true;
//    path[path_index] = u;
//    path_index++;
//
//    // If current vertex is same as destination, then print
//    // current path[]
//    if (u == d)
//    {
//        double calculate_rate = 1;
//        for (int i = 0; i<path_index; i++) {
//            cout << path[i] << " ";
//            if (i>0) {
//       //         calculate_rate *= get_rate(adjList, i,i-1);
//            }
//        }
//        possible_rates.push_back(calculate_rate);
//
//        cout << endl;
//
//    }
//    else // If current vertex is not destination
//    {
//        // Recur for all the vertices adjacent to current vertex
//
//        for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i)
//            if (!visited[i->into])
//                print_all_paths_util(possible_rates, adjList, i->into, d, visited, path, path_index);
//    }
//
//    // Remove current vertex from path[] and mark it as unvisited
//    path_index--;
//    visited[u] = false;
//}
//
//
//void print_all_paths(vector<double> possible_rates, list<Edge> adjList [], int n, int s, int d)
//{
//    // Mark all the vertices as not visited
//    vector<bool> visited(n+1, false);
//
//    // Create an array to store paths
//    vector<int> path(n+1, 0);
//    int path_index = 0;
//
//    // Call the recursive helper function to print all paths
//    print_all_paths_util(possible_rates, adjList, s, d, visited, path, path_index);
//}
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for(int t = 1; t  <= test_cases; t++) {
//        cout  << "Case #" << t << ": ";
//        int n, m;
//        cin >> n >> m;
//
//        // create graph
//        list<Edge> adjList[n+1];
//
//        // scan for edges
//        int src, des;
//        double rate;
//        for (int i = 0; i < m; ++i) {
//            cin >> src >> des >> rate;
//
//            adjList[src].push_back({des, rate});
//
//        }
//        vector<double> possible_rates;
//        print_all_paths(possible_rates, adjList,n,src,des);
//
//
//
//    }
//}
//
//
