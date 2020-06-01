////
//// Created by abahnasy on 23.05.20.
////
//
//
//// implementation based on https://codeforces.com/blog/entry/14378
//
//#include <bits/stdc++.h>
//
//#define REP(i,a,b) for (int i = a; i <= b; ++i)
//
//using namespace std;
//
//typedef vector<pair<int, int>> pi ;
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
//
//    vector <T> GetExcess()
//    {
//        return excess;
//    }
//};
//
//// idea: loop over teams, for each team calculate the max points, construct a graph with all teams and matches except for the current team, calculate the max flow
//// the capacity of each team is upper bounded by max points of the current team, if there is excess points at any of the other teams, this means it can earn points more than
//// our current team, so current team cannot win, otherwise it could be qualified to win or playoffs
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
////    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../week_5/samples_05/footballchampion/1.in", "r", stdin);
////    freopen("../week_5/samples_05/footballchampion/2.in", "r", stdin);
////    freopen("../week_5/samples_05/footballchampion/unitTest.in", "r", stdin);
//
//
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; t++) {
//        cout << "Case #" << t << ": ";
//        // scan number of teams and number of matches
//        int n, m;
//        cin >> n >> m;
//
//
//        vector<int> wins (n+1);
//        REP(i,1,n) {
//            cin >> wins[i];
//        }
//
//
//
//        pi possible_matches;
//
//        REP(i,1,m) {
//            int a, b;
//            cin >> a >> b;
//            if( a<= b)
//                possible_matches.push_back({a,b});
//            else
//                possible_matches.push_back({b,a});
//        }
//
//        REP(current,1,n) {
//
//            int curr_max_points = wins[current];
//            for (auto match : possible_matches) {
//                if (match.first == current || match.second == current) {
//                    curr_max_points++;
//                }
//            }
//
//            PushRelabel<int> g (n + 2);
//            vector<int> possible_wins (n + 1);
//            for (auto match : possible_matches) {
//                if (match.first == current || match.second == current)
//                    continue;
//                possible_wins[match.first]++;
//                g.AddEdge(match.first, match.second, 1);
//            }
//
//
//            REP(i,1,n) {
//                if (i == current)
//                    continue;
//                g.AddEdge(0, i, wins[i] + possible_wins[i]);
//            }
//
//
//            REP(i,1,n) {
//                if (i == current)
//                    continue;
//
//                g.AddEdge(i, n + 1, curr_max_points);
//            }
//
//            g.GetMaxFlow(0, n + 1);
//            vector<int> excess = g.GetExcess();
//            bool yes = true;
//            REP(i,0,n) {
//                if (excess[i] != 0) {
//                    yes = false;
//                    break;
//                }
//            }
//
//            if (yes)
//                std::cout << "yes ";
//            else
//                std::cout << "no ";
//
//
//        }
//
//        std::cout << "\n";
//
//
//
//
//    }
//    return 0;
//}