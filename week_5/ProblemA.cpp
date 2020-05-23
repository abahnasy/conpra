////
//// Created by abahnasy on 21.05.20.
////
//
//#include <bits/stdc++.h>
//
//#define DEBUG(X) cout << X << endl;
//
//using namespace std;
//
//
//bool bfs(vector<vector<int>>& r_g, int s, int t, vector<int>& parent) {
//    // Create a visited array and mark all vertices as not visited
//    int size = t+1;
//
//    vector<int> visited(size, false);
//
//    // Create a queue, enqueue source vertex and mark source vertex
//    // as visited
//    queue <int> q;
//    q.push(s);
//    visited[s] = true;
//    parent[s] = -1;
//
//    // Standard BFS Loop
//    while (!q.empty())
//    {
//        int u = q.front();
//        q.pop();
//
//
//        for (int v=1; v<size; v++)
//        {
//            if (visited[v]==false && r_g[u][v] > 0)
//            {
//                q.push(v);
//                parent[v] = u;
//                visited[v] = true;
//            }
//        }
//    }
//
//    // If we reached sink in BFS starting from source, then return
//    // true, else false
//    return (visited[t] == true);
//}
//
//
//// Returns the maximum flow from s to t in the given graph
//void fordFulkerson(vector<vector<int>>& g, int s, int t)
//{
//    int size = t+1;
//    // create residual graph
//    vector<vector<int>> r_g(size, vector<int>(size,0));
//    // copy graph to residual graph
//    for (int u = 0; u < size; u++)
//        for (int v = 0; v < size; v++)
//            r_g[u][v] = g[u][v];
//
//
//    // This array is filled by BFS and to store path
//    vector<int> parent(size);
//
//    int max_flow = 0;  // There is no flow initially
//
//    // Augment the flow while tere is path from source to sink
//    while (bfs(r_g, s, t, parent))
//    {
//        // Find minimum residual capacity of the edges along the
//        // path filled by BFS. Or we can say find the maximum flow
//        // through the path found.
//        int path_flow = INT_MAX;
//        for (int v=t; v!=s; v=parent[v])
//        {
//            int u = parent[v];
//            path_flow = min(path_flow, r_g[u][v]);
//        }
//
//        // update residual capacities of the edges and reverse edges
//        // along the path
//        for (int v=t; v != s; v=parent[v])
//        {
//            int u = parent[v];
//
//            r_g[u][v] -= path_flow;
//            r_g[v][u] += path_flow;
//        }
//
//        // Add path flow to overall flow
//        max_flow += path_flow;
//    }
//
//    if (max_flow == 0)
//        cout << "impossible" << endl;
//    else
//        // Return the overall flow
//        cout << max_flow << endl;
//}
//
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; t++) {
//        cout << "Case #" << t << ": ";
//
//        int n, m;
//        cin >> n >> m;
//
////        list<Edge> g[n+1];
//        vector<vector<int>> g(n+1, vector<int>(n+1, 0));
//        // scan for edges
//        int a, b, w;
//        for (int i = 0; i < m ; ++i) {
//            cin >> a >> b >> w;
////            add_edge(g,a,b,w);
//            g[a][b] += w;
//            g[b][a] += w;
//        }
//
//
//
//        fordFulkerson(g, 1,n);
//
//
//
//
//
//
//
//
//    }
//}
//
