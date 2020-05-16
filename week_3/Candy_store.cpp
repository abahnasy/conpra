//
// Created by abahnasy on 11.05.20.
//

#include <bits/stdc++.h>
using namespace std;

// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int32_t> adj[], int32_t src, int32_t dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}


int main() {

    std::ios_base::sync_with_stdio(false);
    int test_cases;
    cin >> test_cases;
    for(int t = 1; t  <= test_cases; t++) {
        cout  << "Case #" << t << ": " ;
        // scan number of nodes
        int32_t n;
        cin >>n;

        vector<int32_t> degree (n,0);
        vector<int32_t> adj[n];

        // scan for edges
        int32_t e1, e2;
        for (int i = 0; i < n-1; ++i) {
            cin >> e1 >> e2;
            adj[e1].push_back(e2);
            adj[e2].push_back(e1);
            degree[e1]++;
            degree[e2]++;
        }


        bool star =  false;
        int node_count = n;
        while (node_count > 2) {
            queue<int32_t> q;
            // remove nodes with degree = 1 (leaf nodes)
            for (int i = 0; i < n; ++i) {
                if(degree[i] == 1){
                    q.push(i);
                    degree[i]= -1;
                    node_count--;
                }
            }


            // update the degree of the nodes adjacent to the removed ones
            while(!q.empty()) {
                int32_t node = q.front();
                q.pop();
                for(auto x: adj[node]){
                    degree[x]--;
                }
            }
        }


        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0 || degree[i] == 1) {

                cout << i << "\n";
                break;
            }
        }






    }
    return 0;
}