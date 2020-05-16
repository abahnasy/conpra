////
//// Created by abahnasy on 10.05.20.
////
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <utility>
//
//using namespace std;
//
//// http://stackoverflow.com/questions/8300125/union-find-data-structure
//
//class UF {
//    int *id, cnt, *sz;
//public:
//    // Create an empty union find data structure with N isolated sets.
//    UF(int N) {
//        cnt = N; id = new int[N]; sz = new int[N];
//        for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
//    ~UF() { delete[] id; delete[] sz; }
//
//    // Return the id of component corresponding to object p.
//    int find(int p) {
//        int root = p;
//        while (root != id[root])    root = id[root];
//        while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
//        return root;
//    }
//    // Replace sets containing x and y with their union.
//    void merge(int x, int y) {
//        int i = find(x); int j = find(y); if (i == j) return;
//        // make smaller root point to larger one
//        if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
//        else { id[j] = i, sz[i] += sz[j]; }
//        cnt--;
//    }
//    // Are objects x and y in the same set?
//    bool connected(int x, int y) { return find(x) == find(y); }
//    // Return the number of disjoint sets.
//    int count() { return cnt; }
//};
//
//
//
//struct Graph {
//    int V;
//    int E;
//    vector<pair<int, pair<int, int>> > edges;
//
//    // Constructor
//    Graph(int V, int E)
//    {
//        this->V = V;
//        this->E = E;
//    }
//
//    // Utility function to add an edge
//    void addEdge(int u, int v, int w)
//    {
//        edges.push_back({w, {u, v}});
//    }
//
//};
//
////struct subset {
////    int parent;
////    int rank;
////};
//
////int find (subset* subsets, int n) {
////    if (subsets[n].parent == n) {
////        return n;
////    }
////    subsets[n].parent = subsets[subsets[n].parent].parent;
////}
////
////void Union (subset* subsets, int u, int v) {
////    int u_root = find(subsets, u);
////    int v_root = find(subsets, v);
////
////    if(u_root != v_root) {
////        if(subsets[u_root].rank > subsets[v_root].rank) {
////            subsets[v_root].parent = u_root;
////        } else if (subsets[v_root].rank > subsets[u_root].rank) {
////            subsets[u_root].parent = v_root;
////        } else {
////            subsets[u_root].parent = v_root;
////            subsets[v_root].rank++;
////        }
////
////    }
////}
//
//int main () {
//
//    std::ios_base::sync_with_stdio(false);
//    int test_cases;
//    cin >> test_cases;
//    for(int t = 1; t  <= test_cases; t++) {
//
//        int n;
//        cin >> n;
//
//        // create a graph struc based on the input number of vertices
//        Graph* graph = new Graph(n, n*n);
//        int scanned_w;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                cin >> scanned_w;
//                if(i != j) {
//                    graph->addEdge(i,j,scanned_w);
//                }
//            }
//        }
//
//        cout  << "Case #" << t << ": \n" ;
//
////        subset* subsets = new subset[sizeof((graph->V+1) * sizeof(subset))];
////        for (int i = 1 ; i<= graph->V;++i) {
////            subsets[i].parent = i;
////            subsets[i].rank = 0;
////        }
//        UF connectedNodes(n+1); // don't use 0 element
//
//        // Sort edges in increasing order on basis of cost
//        sort(graph->edges.begin(), graph->edges.end());
//
//        vector<pair<int, int> > result;
//        vector<pair<int, pair<int, int>>>::iterator it;
//        for (it=graph->edges.begin(); it!=graph->edges.end(); it++)
//        {
//            int src_root = connectedNodes.find(it->second.first);
//            int des_root = connectedNodes.find(it->second.second);
//
//            if (src_root != des_root) {
//                connectedNodes.merge(src_root, des_root);
//                result.push_back({it->second.first, it->second.second});
//               // cout << it->second.first << " " << it->second.second << "\n";
//            }
//        }
//
//        sort(result.begin(), result.end());
//        for (auto it = result.begin(); it != result.end(); ++it) {
//            cout << it->first << " " << it->second << "\n";
//        }
//    }
//    return 0;
//}
//
//
