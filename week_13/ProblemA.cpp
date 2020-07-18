

#include <bits/stdc++.h>


using namespace std;



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

        vector<vector<pair<int, int>>> adj(V);
        vector<vector<int>> parent(V);
        vector<int> dist (V, INT_MAX);
        vector<bool> vis(V, false);
        vector<vector<int>> g_w(V, vector<int>(V, -1));


        int s, d, w;
        for (int i = 0; i < P; ++i) {
            cin >> s>> d >> w;
            if (s == d) // skip self loops
                continue;
            adj[s].push_back({w,d});
            adj[d].push_back({w,s}); // undirected

            if(g_w[s][d] == -1 || g_w[s][d] > w) {
                g_w[s][d] = w;
                g_w[d][s] = w;
            }

        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        dist[0] = 0;

        while (!pq.empty()) {
            int curr = pq.top().second; // get node index
            pq.pop();
            if(!vis[curr]) {
                vis[curr] = true;
                for (auto i: adj[curr]) {
                    int next = i.second;
                    int w = i.first;

                    if (dist[next] > dist[curr] + w) {
                        dist[next] = dist[curr] + w;
                        parent[next].clear();
                        parent[next].push_back(curr);
                        pq.push({dist[curr]+w, next});
                    } else if (dist[next] == dist[curr] + w) {
                        parent[next].push_back(curr);
                    }

                }
            }
        }

        vis.clear();
        vis.resize(V, false);
        queue<int> q;
        q.push(V-1);
        int sum = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if(!vis[curr]) {
                vis[curr] = true;
                for (auto i: parent[curr]) {
                    sum += g_w[curr][i];
                    q.push(i);
                }
            }
        }

        cout << sum*2 << "\n";





    }
}