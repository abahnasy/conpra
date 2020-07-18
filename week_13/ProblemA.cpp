

#include <bits/stdc++.h>


using namespace std;

struct Edge{
    int dir, w;
};
void addEdge(vector<Edge> adj[], int s, int d, int w) {
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}

void find_paths(vector<vector<int>>& parent, vector<vector<int>>& paths,
        vector<int>& curr_path,int node) {
    if(node == -1) {
        // base case
        paths.push_back(curr_path);
        return;
    }
    for (auto x : parent[node]) {
        curr_path.push_back(node);
        find_paths(parent, paths, curr_path, x);
        curr_path.pop_back();
    }
}

void find_shortest_paths (vector<vector<int>>& g, int s, int d, vector<vector<int>>& parent, int V) {

    vector<int> dist(V, INT_MAX);
    queue<int> q;

    parent[s].push_back(-1);
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < V; ++i) {
            if (g[curr][i] != -1) { // is neighbour
                if (dist[i] > dist[curr] + g[curr][i]) {
                    dist[i] = dist[curr] + g[curr][i];
                    parent[i].clear();
                    parent[i].push_back(curr);
                    q.push(i);
                } else if (dist[i] == dist[curr] + g[curr][i]) {
                    parent[i].push_back(curr);
                }
            }
        }
//
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_13/samples_13/flowerytrails/1.in", "r", stdin);
//    freopen("../../week_13/samples_13//2.in", "r", stdin);
//    freopen("../../week_13/samples_13/flowerytrails/test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;

    int V, P;
    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        cin >> V >> P;
//        vector<Edge> adj[V];
        vector<vector<int>> g(V, vector<int>(V, -1));
        vector<vector<int>> g_duplicate(V, vector<int>(V, 1));
        vector<vector<int>> parent(V);

        int s, d, w;
        for (int i = 0; i < P; ++i) {
            cin >> s>> d >> w;
            if(g[s][d] == -1 || g[s][d] > w) {
                g[s][d] = w;
                g[d][s] = w;
            } else if (g[s][d] == w){
                g_duplicate[s][d] += 1;
                g_duplicate[d][s] += 1;
            }
        }

        vector<vector<int>> paths;
        vector<int> path;
        find_shortest_paths(g, 0, V-1, parent, V);
        find_paths(parent, paths, path, V-1);
        vector<vector<bool>> g_taken(V, vector<bool>(V, false));
        int sum = 0;
        for (auto v : paths) {
            reverse(v.begin(), v.end());
            // Print node for the current path
            for(int i = 1; i < v.size(); ++i) {
                   if(g_taken[v[i-1]][v[i]] == false && g_taken[v[i]][v[i-1]] == false) {
                       for(int j = 0; j < g_duplicate[v[i-1]][v[i]]; ++j) {
                           sum += g[v[i-1]][v[i]];
//                           cout << "adding " << i-1 << " to " << i << "\n";
                       }
                       g_taken[v[i-1]][v[i]] = true;
                       g_taken[v[i]][v[i-1]] = true;
                   }
            }
        }
        cout << sum*2 << "\n";





    }
}