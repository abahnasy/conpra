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
//int get_edge_cost(list<Edge> adjList[], int src, int des) {
//    for (auto it = adjList[src].begin(); it != adjList[des].end(); ++it) {
//        if (it->dir == des)
//            return it->weight;
//    }
//}
//
//int get_path_cost(list<Edge> adjList[], vector<int> path) {
//    int total_cost = 0;
//    for (int i = 1; i < path.size(); ++i) {
//        total_cost += get_edge_cost(adjList, path[i-1], path[i]);
//    }
//    return total_cost;
//}
//
//// Prints all paths from 's' to 'd'
//
//
//
//void printAllPathsUtil(list<Edge> adjList[], int u, int d, vector<bool> visited,
//                              vector<int> path, int &path_index, int lea_path_cost, vector<vector<int>>& returned_paths)
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
//        vector<int> path_seq;
//        for (int i = 0; i<path_index; i++) {
////            cout << path[i] << " ";
//            path_seq.push_back(path[i]);
//
//        }
////        cout << endl;
//        int curr_path_cost =  get_path_cost(adjList, path_seq);
//        //TODO comapre with lea path cost
//        if (curr_path_cost <= lea_path_cost) {
////            cout << "curr_path_cost = " << curr_path_cost << " and lea path cost is " << lea_path_cost << "equal\n";
//            returned_paths.push_back(path_seq);
//        }
//
//
//    }
//    else // If current vertex is not destination
//    {
//        // Recur for all the vertices adjacent to current vertex
////        list<int>::iterator i;
//        for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i)
//            if (!visited[i->dir])
//                printAllPathsUtil(adjList, i->dir, d, visited, path, path_index, lea_path_cost, returned_paths);
//    }
//
//    // Remove current vertex from path[] and mark it as unvisited
//    path_index--;
//    visited[u] = false;
//}
//
//void printAllPaths(list<Edge> adjList[], int s, int d, int n, int lea_path_cost, vector<vector<int>>& returned_paths)
//{
//    int path_index = 0;
//    vector<bool> visited(n+1, false);
//    vector<int> path(n+1, 0);
//
//    // Initialize all vertices as not visited
//    for (int i = 0; i < n+1; i++)
//        visited[i] = false;
//
//    // Call the recursive helper function to print all paths
//    printAllPathsUtil(adjList, s, d, visited, path, path_index,  lea_path_cost, returned_paths);
//}
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for(int t = 1; t  <= test_cases; t++) {
//        cout  << "Case #" << t << ": ";
//        int n, m, k;
//        cin >> n >> m >> k;
//        list<Edge> adjList [n+1];
//
//        // scan Lea Path
//        vector<int> lea_path;
//        int temp;
//        for (int i = 0; i < k ;++i) {
//            cin >> temp;
//            lea_path.push_back(temp);
//        }
//        // scan edges and costs
//        int src, des, cost;
//        for (int i = 0; i < m; ++i) {
//            cin >> src >> des >> cost;
//            adjList[src].push_back({des, cost});
//            adjList[des].push_back({src, cost});
//        }
//
//        // compute lea path cost
//        int lea_path_cost = 0;
//        lea_path_cost = get_path_cost(adjList,lea_path);
//
//        // get all possible root costs between 1 and N
//
//        // return found paths if equal to lea path cost
//        vector<vector<int>> returned_paths;
//
//        printAllPaths(adjList, 1,n, n, lea_path_cost, returned_paths);
//
//        if (returned_paths.size()>1) {
//            cout << "yes\n";
//        } else {
//            cout << "no\n";
//        }
//
//
//
//
//    }
//
//    return 0;
//}
//
//
//
//
