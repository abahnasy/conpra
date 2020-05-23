////
//// Created by abahnasy on 22.05.20.
////
//
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
///*
//    Implementation of highest-label push-relabel maximum flow
//    with gap relabeling heuristic.
//
//    Running time:
//        O(|V|^2|E|^{1/2})
//
//    Usage:
//        - add edges by AddEdge()
//        - GetMaxFlow(s, t) returns the maximum flow from s to t
//
//    Input:
//        - graph, constructed using AddEdge()
//        - (s, t), (source, sink)
//
//    Output:
//        - maximum flow value
//
//    Todo:
//        - implement Phase II (flow network from preflow network)
//        - implement GetMinCut()
//*/
//
//template <class T> struct Edge {
//    int from, to, index;
//    T cap, flow;
//
//    Edge(int from, int to, T cap, T flow, int index): from(from), to(to), cap(cap), flow(flow), index(index) {}
//};
//
//template <class T> struct PushRelabel {
//    int n;
//    vector <vector <Edge <T>>> adj;
//    vector <T> excess;
//    vector <int> dist, count;
//    vector <bool> active;
//    vector <vector <int>> B;
//    int b;
//    queue <int> Q;
//
//    PushRelabel (int n): n(n), adj(n) {}
//
//    void AddEdge (int from, int to, int cap) {
//        adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
//        if (from == to) {
//            adj[from].back().index++;
//        }
//        adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));
//
//    }
//
//    void Enqueue (int v) {
//        if (!active[v] && excess[v] > 0 && dist[v] < n) {
//            active[v] = true;
//            B[dist[v]].push_back(v);
//            b = max(b, dist[v]);
//        }
//    }
//
//    void Push (Edge <T> &e) {
//        T amt = min(excess[e.from], e.cap - e.flow);
//        if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
//            e.flow += amt;
//            adj[e.to][e.index].flow -= amt;
//            excess[e.to] += amt;
//            excess[e.from] -= amt;
//            Enqueue(e.to);
//        }
//    }
//
//    void Gap (int k) {
//        for (int v = 0; v < n; v++) if (dist[v] >= k) {
//                count[dist[v]]--;
//                dist[v] = max(dist[v], n);
//                count[dist[v]]++;
//                Enqueue(v);
//            }
//    }
//
//    void Relabel (int v) {
//        count[dist[v]]--;
//        dist[v] = n;
//        for (auto e: adj[v]) if (e.cap - e.flow > 0) {
//                dist[v] = min(dist[v], dist[e.to] + 1);
//            }
//        count[dist[v]]++;
//        Enqueue(v);
//    }
//
//    void Discharge(int v) {
//        for (auto &e: adj[v]) {
//            if (excess[v] > 0) {
//                Push(e);
//            } else {
//                break;
//            }
//        }
//
//        if (excess[v] > 0) {
//            if (count[dist[v]] == 1) {
//                Gap(dist[v]);
//            } else {
//                Relabel(v);
//            }
//        }
//    }
//
//    T GetMaxFlow (int s, int t) {
//        dist = vector <int>(n, 0), excess = vector<T>(n, 0), count = vector <int>(n + 1, 0), active = vector <bool>(n, false), B = vector <vector <int>>(n), b = 0;
//
//        for (auto &e: adj[s]) {
//            excess[s] += e.cap;
//        }
//
//        count[0] = n;
//        Enqueue(s);
//        active[t] = true;
//
//        while (b >= 0) {
//            if (!B[b].empty()) {
//                int v = B[b].back();
//                B[b].pop_back();
//                active[v] = false;
//                Discharge(v);
//            } else {
//                b--;
//            }
//        }
//        return excess[t];
//    }
//
//    T GetMinCut (int s, int t, vector <int> &cut);
//};
//
//
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
////    freopen("../week_5/samples_05/connectivity/1.in", "r", stdin);
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; t++) {
//        cout << "Case #" << t << ": ";
//
//        int n, m;
//        cin >> n >> m;
//
//        // split the vertices with capacity
//        // get V_in by multiply by two
//        // get V_out by mulltiply by 2 and add 1
//
//        PushRelabel<int> g((n+1)*2);
////        PushRelabel<int> g((n+1));
//
//        // scan for edges
//        int a, b;
//        for (int i = 0; i < m ; ++i) {
//            cin >> a >> b;
//
//            int a_in = a*2;
//            int a_out = a*2+1;
//            int b_in = b*2;
//            int b_out = b*2 +1;
//
//            g.AddEdge(a_out, b_in, 1);
//            g.AddEdge(b_out, a_in, 1);
////
////            g.AddEdge(a, b, 1);
////            g.AddEdge(b, a, 1);
//
//        }
//
//        // split vertices
//        for (int i = 0;i < n+1; ++i) {
//            int i_in = i*2;
//            int i_out = i*2 +1;
//
//            g.AddEdge(i_in,i_out,1);
//            g.AddEdge(i_out,i_in,1);
//        }
//
//
//        int source = 1*2 + 1; //source out
//        int sink = n*2; // sink In
//
//        cout << g.GetMaxFlow(source,sink) << "\n";
//
//
//
//
//
//
//
//
//    }
//
//    return 0;
//}