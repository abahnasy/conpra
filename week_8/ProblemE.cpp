//
// Created by abahnasy on 13.06.20.
//

#include <bits/stdc++.h>

using namespace std;
# define INF 0x3f3f3f3f
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pi;


vi num_objects;
vi fut_lea_dist;
int reached_safely = false;
int global_max_objects = 0;

void dijkstra(const vii& fut_lea,const int g, const int n, vi& dist) {
    // pairs(cost, node)
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    dist.clear();
    dist.resize(n+1, INF);
    pq.push(make_pair(0, g));
    dist[g] = 0;
    while (!pq.empty())  {
        int u = pq.top().second;
        pq.pop();
        // loop to get all vertices
        for (int i = 0; i <= n; ++i) {
            if (fut_lea[u][i] > 0) {
                // get vertex and weight
                int weight = fut_lea[u][i];
                if(dist[i] > dist[u] + weight) {
                    dist[i] = dist[u] + weight;
                    pq.push(make_pair(dist[i], i));
                }
            }
        }
    }
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../week_8/samples_08/escapingtheparadox/1.in", "r", stdin);
//    freopen("../week_8/samples_08/escapingtheparadox/2.in", "r", stdin);
//    freopen("../week_8/samples_08/escapingtheparadox/test.in", "r", stdin);

    int test_cases;
    cin>> test_cases;

    int n, m, g; // graves, tunnels and position of future lea
    // future lea's grave -> g
    // lea's grave -> n
    for (int t = 1; t <= test_cases; ++t) {
        reached_safely = false;
        global_max_objects = 0;
        cout << "Case #"<<t<<": ";
        cin >> n >> m>> g;
        // read number of objects
        num_objects.clear();
        num_objects.resize(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            int temp;
            cin >> temp;
            num_objects[i] = temp;
        }

        vii fut_lea(n+1, vi(n+1, 0));
        vii lea(n+1, vi(n+1, 0));

        for (int i = 0; i < m; ++i) {
            int n1, n2, c;
            cin >> n1 >> n2 >> c;
            if(n1 == n2)
                continue;
            //update undirected graph
            if (fut_lea[n1][n2] == 0 || fut_lea[n1][n2] > c) {
                fut_lea[n1][n2] = c;
                fut_lea[n2][n1] = c;
                //update lea graph
                lea[max(n1, n2)][min(n1, n2)] = c;
            }
        }

        dijkstra(fut_lea, g, n, fut_lea_dist);
        vector<set<pair<int, int>> > path_options(n+1);

        if (fut_lea_dist[n] != 0)
            path_options[n].insert(make_pair(0, num_objects[n]));

        for (int i = n-1; i >= 0 ; --i) {
            // loop over incoming edges from nodes with idx greater than self
            for (int j = n; j > i; --j) {
                if(lea[j][i] > 0) {
                    // loop over neighbour options
                    // if neighbour time + self time < futture lea to self, add
                    for(auto x: path_options[j]) {
                        if(fut_lea_dist[i] > (x.first + lea[j][i])) {
                            path_options[i].insert(make_pair(x.first + lea[j][i], x.second + num_objects[i]));
                        }
                    }
                }
            }
        }

        int max = -1;
        for( auto x: path_options[0]) {
            if(x.second> max)
                max = x.second;
        }

        if(max == -1)
            cout  << "impossible\n";
        else
            cout << max << "\n";




        dijkstra(fut_lea, g, n, fut_lea_dist);









    }




}

//vii test(10, vi(10, 0));
//test[1][2] = 4;test[2][1] = 4;
//test[1][8] = 8; test[8][1] = 8;
//test[2][3] = 8; test[3][2] = 8;
//test[2][8] = 11; test[8][2] = 11;
//test[3][4] = 7; test[4][3] = 7;
//test[3][9] = 2; test[9][3] = 2;
//test[3][6] = 4; test[6][3] = 4;
//test[4][5] = 9; test[5][4] = 9;
//test[4][6] = 14; test[6][4] = 14;
//test[5][6] = 10; test[6][5] = 10;
//test[6][7] = 2; test[7][6] = 2;
//test[7][8] = 1; test[8][7] = 1;
//test[7][9] = 6; test[9][7] = 6;
//test[8][9] = 7; test[9][8] = 7;
//
//dijkstra(test, 1, 9, dist);
//for (auto x: dist) {
//cout << x << "\n";
//}