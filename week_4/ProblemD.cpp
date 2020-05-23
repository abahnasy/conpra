////
//// Created by abahnasy on 18.05.20.
////
//
//#include <bits/stdc++.h>
//using namespace std;
//
//// A utility function to print the constructed distance array
//struct Edge {
//    int dir;
//    int weight;
//};
//
//
//void topologicalSortUtil(list<Edge> adjList[], int v, bool visited[], stack<int>& Stack) {
//    // Mark the current node as visited
//    visited[v] = true;
//    // Recur for all the vertices adjacent to this vertex
//    for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
//        if (!visited[it->dir])
//            topologicalSortUtil(adjList, it->dir, visited, Stack);
//    }
//    Stack.push(v);
//}
//
//void longestPath(list<Edge> adjList[], vector<int>& critical_paths, int n, int s)
//{
//    stack<int> Stack;
//    int dist[n+1];
//
//    // Mark all the vertices as not visited
//    bool* visited = new bool[n+1];
//    for (int i = 0; i < n+1; i++)
//        visited[i] = false;
//
//    // Call the recursive helper function to store Topological
//    // Sort starting from all vertices one by one
//    for (int i = 1; i < n+1; i++)
//        if (visited[i] == false)
//            topologicalSortUtil(adjList, i, visited, Stack);
//
//    // Initialize distances to all vertices as infinite and
//    // distance to source as 0
//    for (int i = 0; i < n+1; i++)
//        dist[i] = INT_MIN;
//    dist[s] = 0;
//
//    // Process vertices in topological order
//    while (Stack.empty() == false) {
//        // Get the next vertex from topological order
//        int u = Stack.top();
//        Stack.pop();
//
//        // Update distances of all adjacent vertices
////        list<AdjListNode>::iterator i;
//        if (dist[u] != INT_MIN) {
//            for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it)
//                if (dist[it->dir] < dist[u] + it->weight)
//                    dist[it->dir] = dist[u] + it->weight;
//        }
//    }
//
//    // Print the calculated longest distances
//    for (int i = 0; i < n+1; i++){
//        critical_paths.push_back(dist[i]);
//    }
////        (dist[i] == INT_MIN) ? cout << "INF " : cout << dist[i] << " ";
//
//    delete [] visited;
//}
//
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for(int t = 1; t  <= test_cases; t++) {
//        cout  << "Case #" << t << ": ";
//        int n;
//        cin >> n; // number of tasks
//        list<Edge> adjList [n+1];
//        int time, successors;
//        for (int i = 1; i <= n ;++i) {
//
//            cin >> time >> successors;
//
//            int succ_node;
//            for (int j = 0 ; j < successors; ++j) {
//                cin >> succ_node;
//                adjList[i].push_back({succ_node, time});
//            }
//
//
//        }
//
//
//        vector<int> critical_paths;
//        longestPath(adjList, critical_paths,n, 1);
//        int max = INT_MIN;
//        for(int i = 0 ; i < critical_paths.size(); ++i ) {
//            if(critical_paths[i] > max)
//                max = critical_paths[i];
//        }
//        cout << max+time << "\n";
//
//    }
//
//    return 0;
//}
//
//
//
//
