////
//// Created by abahnasy on 11.05.20.
////
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <list>
//#include <stack>
//#include <utility>
//
//#define DEBUG(X) cout << X << "\n"
//
//
//using namespace std;
//
//void print_vector(vector<int>& vec) {
//    for(auto it = vec.begin(); it != vec.end(); ++it) {
//        cout << *it << " " ;
//    }
//    cout << "\n";
//}
//
//struct Graph {
//    int V;
////    int E;
//    list<int>* adjList;
//    void topological_sort_util(int node, vector<int>& visited, stack<int>& top_stack) {
//        visited[node] = true;
//        list<int>::iterator it;
//        for (it = adjList[node].begin(); it != adjList[node].end(); ++it) {
//            if (!visited[*it])
//                topological_sort_util(*it, visited, top_stack);
//        }
//        top_stack.push(node);
//    }
//    // This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
//    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack)
//    {
//        if(visited[v] == false)
//        {
//            // Mark the current node as visited and part of recursion stack
//            visited[v] = true;
//            recStack[v] = true;
//
//            // Recur for all the vertices adjacent to this vertex
//            list<int>::iterator i;
//            for(i = adjList[v].begin(); i != adjList[v].end(); ++i)
//            {
//                if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
//                    return true;
//                else if (recStack[*i])
//                    return true;
//            }
//
//        }
//        recStack[v] = false;  // remove the vertex from recursion stack
//        return false;
//    }
//public:
//    // Constructor
//    Graph(int V)
//    {
//        this->V = V;
//        this->adjList = new list<int>[V+1];
//    }
//
//    void print_graph() {
//        for (auto it = this->adjList->begin(); it != adjList->end(); ++it) {
//            cout << *it << " " << "\n";
//        }
//    }
//
//    // Utility function to add an edge
//    void addEdge(int u, int v)
//    {
//        adjList[u].push_back(v);
//    }
//
//
//    void topologicalSort(vector<int>& topological_sorted_nodes) {
//
//        vector<int> visited(V+1, false);
//
//        stack<int> top_stack;
//        for (int node = 1; node < V+1; ++node) {
//            if (!visited[node]) {
//                topological_sort_util(node, visited, top_stack);
//            }
//
//
//        }
//
//        // add stack to vector
//        while(!top_stack.empty()) {
//            topological_sorted_nodes.push_back(top_stack.top());
//            top_stack.pop();
//        }
//    }
//
//    // Returns true if the graph contains a cycle, else false.
//    // This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
//    bool isCyclic()
//    {
//        // Mark all the vertices as not visited and not part of recursion
//        // stack
//        vector<bool> visited(V+1, false);
//        vector<bool> recStack(V+1, false);
////        for(int i = 1; i <= V; i++)
////        {
////            visited[i] = false;
////            recStack[i] = false;
////        }
//
//        // Call the recursive helper function to detect cycle in different
//        // DFS trees
//        for(int i = 1; i <= V; i++)
//            if (isCyclicUtil(i, visited, recStack))
//                return true;
//
//        return false;
//    }
//
//};
//
//int main () {
//
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for(int t = 1; t  <= test_cases; t++) {
//
//        //scan the number of intersections, no of one way and two way roads
//        int n, m, l;
//        cin >>n >>m >> l;
//
//        Graph* graph = new Graph(n);
//        // scan one way roads and construct graph
//        int src, des;
//        for (int i = 0; i < m; ++i) {
//            cin >> src >> des;
//            graph->addEdge(src, des);
//        }
//
//
//        // save for later
//        std::vector<std::pair<int, int>> two_way_roads;
//        for (int i=0; i<l; ++i)
//        {
//            cin >> src >> des;
//            two_way_roads.push_back(std::make_pair(src, des));
//        }
//
//
//        // check for cycle
//        bool cycle_found = graph->isCyclic();
//
//        vector<pair<int, int>> result;
//
//
//        if (!cycle_found) {
//            vector<int >topological_sorted_nodes;
//            graph->topologicalSort(topological_sorted_nodes);
////            print_vector(topological_sorted_nodes);
//            vector<pair<int, int>>::iterator it;
//
//            for(it = two_way_roads.begin(); it!= two_way_roads.end();++it) {
//                vector<int>::iterator src_it = std::find(topological_sorted_nodes.begin(), topological_sorted_nodes.end(), it->first);
//                vector<int>::iterator des_it = std::find(topological_sorted_nodes.begin(), topological_sorted_nodes.end(), it->second);
//                if (src_it < des_it) {
//                    graph->addEdge(*src_it, *des_it);
//                    result.push_back({*src_it, *des_it});
//                } else {
//                    graph->addEdge(*des_it,*src_it);
//                    result.push_back({*des_it, *src_it});
//                }
//            }
//        }
//
//        cout  << "Case #" << t << ": ";
//        if (cycle_found) {
//            cout << "no " << "\n";
//        } else {
//            cout << "yes " << "\n";
//            for(auto it = result.begin(); it!= result.end(); ++it) {
//                cout << (it->first) << " " << (it->second) << "\n";
//            }
//
//        }
//
//    }
//}