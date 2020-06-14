////
//// Created by abahnasy on 21.05.20.
////
//// implementation based on https://www.geeksforgeeks.org/dinics-algorithm-maximum-flow/
//
//
//#include <bits/stdc++.h>
//#define REP(i,a,b) for (int i = a; i <= b; ++i)
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
//int main () {
//
//    // redirect input stream to samples files
////    freopen("../../../../week_5/samples_05/finedining/1.in", "r", stdin);
////    freopen("../../week_5/samples_05/finedining/2.in", "r", stdin);
////    freopen("../../week_5/samples_05/finedining/unitTest.in", "r", stdin);
//
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; t++) {
//        cout << "Case #" << t << ": ";
//
//        int n, m, b;
//        cin >> n >> m >> b;
//
//        PushRelabel<int> g(m+b+2);
//
//
//        // scan for edges
//        int main, drink;
//        for (int i = 1; i <= n ; ++i) {
//            cin >> main >> drink;
//            g.AddEdge(main, m+drink,1);
////            g[main][m+drink] = 1;
//
//
//        }
//
//        // establish the main source
//        REP(i,1,m) {
//            g.AddEdge(0, i,1);
////            g[0][i] = 1;
//        }
//
//        //establish the main sink
//
//        REP(i,1,b) {
//            g.AddEdge(m+i, b+m+1, 1);
////            g[m+i][b+m+1] = 1;
//        }
//
//
//
//
//
//        cout << g.GetMaxFlow(0,b+m+1) << "\n";
//
//
//
//
//
//    }
//}
//
