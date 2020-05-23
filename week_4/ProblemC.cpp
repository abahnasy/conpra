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
//// A utility function to print the constructed distance array
//void print_dijkstra(int dist[], int size)
//{
//    printf("Vertex \t\t Distance from Source\n");
//    for (int i = 1; i <= size; i++)
//        printf("%d \t\t %d\n", i, dist[i]);
//}
//
//int min_distance(int dist[], bool spt_set[], int size)
//{
//    // Initialize min value
//    int min = INT_MAX, min_index;
//    for (int v = 0; v <= size; v++)
//        if (spt_set[v] == false && dist[v] <= min)
//            min = dist[v], min_index = v;
//    return min_index;
//}
//
//void print_time(int mins)
//{
//
//    int minutes = mins / 60;
//    cout << minutes;
//    cout << ":";
//
//    int seconds = mins % 60;
//    if (seconds < 10)
//        std::cout << "0";
//    cout << seconds;
//
//    cout << "\n";
//}
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for(int t = 1; t  <= test_cases; t++) {
//        cout  << "Case #" << t << ": ";
//
//        int n, m, s, a, b;
//
//        cin >> n >> m >> s >> a >> b;
//
//        int g[n+1][n+1];
//
//        for (int i = 0; i <= n; ++i) {
//            for (int j = 0; j <= n; ++j) {
//                g[i][j] = 0;
//            }
//        }
//
//        int src, des, cost;
//        for (int i = 0; i < m; ++i) {
//            cin >> src >> des >> cost;
//            // skip if the cost is above current one
//            if (g[src][des] == 0 || (cost < g[src][des])) {
//                g[src][des] = cost;
//                g[des][src] = cost;
//            }
//
//        }
//
//
//
//        int market, time;
//
//        vector<int> markets(n+1, 0);
//        for (int i = 0; i < s; ++i) {
//            cin >> market >> time;
//            markets[market] = time;
//        }
//
//        // handle corner case, no supermarks
//        if(s == 0){
//            cout << "impossible\n";
//            continue; // skip to the next test case
//        }
//
//        // dijkstra over a
//        int dist_a[n+1];
//        bool spt_set_a[n+1];
//        for (int i = 0; i <= n; i++)
//            dist_a[i] = INT_MAX, spt_set_a[i] = false;
//        dist_a[a] = 0;
//        // Find shortest path for all vertices
//        for (int count = 1; count < n; count++) {
//            // Pick the minimum distance vertex from the set of vertices not
//            // yet processed. u is always equal to src in the first iteration.
//            int u = min_distance(dist_a, spt_set_a, n);
//
//            // Mark the picked vertex as processed
//            spt_set_a[u] = true;
//
//            // Update dist value of the adjacent vertices of the picked vertex.
//            for (int v = 1; v <= n; v++)
//
//                // Update dist[v] only if is not in sptSet, there is an edge from
//                // u to v, and total weight of path from src to  v through u is
//                // smaller than current value of dist[v]
//                if (!spt_set_a[v] && g[u][v] && dist_a[u] != INT_MAX
//                    && dist_a[u] + g[u][v] < dist_a[v])
//                    dist_a[v] = dist_a[u] + g[u][v];
//        }
//
////        print_dijkstra(dist_a, n);
//
//        // dijkstra over b
//        int dist_b[n+1];
//        bool spt_set_b[n+1];
//        for (int i = 0; i <= n; i++)
//            dist_b[i] = INT_MAX, spt_set_b[i] = false;
//        dist_b[b] = 0;
//        // Find shortest path for all vertices
//        for (int count = 1; count < n; count++) {
//            // Pick the minimum distance vertex from the set of vertices not
//            // yet processed. u is always equal to src in the first iteration.
//            int u = min_distance(dist_b, spt_set_b, n);
//
//            // Mark the picked vertex as processed
//            spt_set_b[u] = true;
//
//            // Update dist value of the adjacent vertices of the picked vertex.
//            for (int v = 1; v <= n; v++)
//
//                // Update dist[v] only if is not in sptSet, there is an edge from
//                // u to v, and total weight of path from src to  v through u is
//                // smaller than current value of dist[v]
//                if (!spt_set_b[v] && g[u][v] && dist_b[u] != INT_MAX
//                    && dist_b[u] + g[u][v] < dist_b[v])
//                    dist_b[v] = dist_b[u] + g[u][v];
//        }
//
////        print_dijkstra(dist_b, n);
//
//        // minimize over supermarks
//        int min_time  = INT_MAX;
//        for (int i = 0; i <markets.size(); ++i) {
//            if(markets[i] != 0 && (dist_a[i] != INT_MAX) && (dist_b[i] != INT_MAX) && (dist_b[a] != INT_MAX) && (dist_a[b] != INT_MAX)) {
//                if ((dist_a[i] + markets[i] + dist_a[i] < min_time))
//                    min_time = dist_a[i] + markets[i] + dist_b[i];
//            }
//        }
//
//        if(min_time == INT_MAX) {
//            cout << "impossible\n";
//            continue; // skip to the next test case
//        }
//        print_time(min_time);
//
//
//
//    }
//}
//
//
//
