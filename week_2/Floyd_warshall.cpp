//
// Created by abahnasy on 02.05.20.
//

#include <bits/stdc++.h>

using namespace std;
#define V 4
#define INF 99999

// all-pairs shortest path

void print (int graph [][V]) {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if(graph[i][j] == INF) {
                cout << "INF" << "    ";
            } else {
                cout << graph[i][j] << "    ";
            }
        }
        cout << "\n";

    }
}

void floyd_warshall(int graph[][V]) {
    int dist[V][V];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++i) {
            // copy the input adjancy matrix to the output adj matrix
            dist[i][j] = graph[i][j];

            // loop over all intermediate vertices
            for (int k =0; k < V; ++k) {
                for (int i = 0; i < V; ++i) {
                    for (int j = 0; j < V; ++i) {

                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }


            }
        }
    }
}

//int main () {
//
//
//    int graph[V][V] = { {0, 5, INF, 10},
//                        {INF, 0, 3, INF},
//                        {INF, INF, 0, 1},
//                        {INF, INF, INF, 0}
//    };
//
//
//
//    return 0;
//}

