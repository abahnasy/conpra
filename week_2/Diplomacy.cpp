////
//// Created by abahnasy on 02.05.20.
////
//
//
//
//#include  <iostream>
//
//#include <vector>
//
//
//// http://stackoverflow.com/questions/8300125/union-find-data-structure
////class UF {
////    int *id, cnt, *sz;
////public:
////    // Create an empty union find data structure with N isolated sets.
////    UF(int N) {
////        cnt = N; id = new int[N]; sz = new int[N];
////        for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
////    ~UF() { delete[] id; delete[] sz; }
////
////    // Return the id of component corresponding to object p.
////    int find(int p) {
////        int root = p;
////        while (root != id[root])    root = id[root];
////        while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
////        return root;
////    }
////    // Replace sets containing x and y with their union.
////    void merge(int x, int y) {
////        int i = find(x); int j = find(y); if (i == j) return;
////        // make smaller root point to larger one
////        if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
////        else { id[j] = i, sz[i] += sz[j]; }
////        cnt--;
////    }
////    // Are objects x and y in the same set?
////    bool connected(int x, int y) { return find(x) == find(y); }
////    // Return the number of disjoint sets.
////    int count() { return cnt; }
////};
//
//
//using namespace std;
//
//
//
//// A utility function to find the subset of an element i
//int find(int parent[], int i)
//{
//    if (parent[i] == -1)
//        return i;
//    return find(parent, parent[i]);
//}
//
//// A utility function to do union of two subsets
//void Union(int parent[], int x, int y)
//{
//    int xset = find(parent, x);
//    int yset = find(parent, y);
//    if(xset != yset)
//    {
//        parent[xset] = yset;
//    }
//}
//
//
//int  main() {
//
//
//    std::ios_base::sync_with_stdio(false);
//    //  loop  over  all  test  cases
//    int t;
//    cin >> t;
//    for(int i = 1; i  <= t; i++) {
//        cout  << "Case #" << i << ": " ;
//
//        int n, m;
//        cin >> n >> m;
//     //   UF countries(n+1); //remove
//        // initialize the parents with -1
//        int parent[n+1];
//        for (int j = 0; j <=n; ++j) {
//           parent[j] = -1;
//        }
//        vector<int> hates(n+1);
//        char rel; int c1, c2;
//        // loop over the relations
//        for (int j =0; j < m; ++j) {
//
//            cin >> rel >> c1 >> c2;
//
//            if(rel == 'F') {
//                int c1_rep = find(parent, c1);
//                int c2_rep = find(parent, c2);
////                int c1_rep = countries.find(c1);
////                int c2_rep = countries.find(c2);
//
//                if(hates[c1_rep] == 0 && hates[c2_rep] == 0) {
////                    countries.merge(c1_rep, c2_rep); //remove
//                    Union(parent, c1_rep, c2_rep);
//                } else if (hates[c1_rep] != 0 && hates[c2_rep] == 0) {
////                    countries.merge(c1_rep, c2_rep);
//                    Union(parent, c1_rep, c2_rep);
//                    hates[c2_rep] = hates[c1_rep];
//                } else if (hates[c1_rep] == 0 && hates[c2_rep] != 0) {
////                    countries.merge(c1_rep, c2_rep);
//                    Union(parent, c1_rep, c2_rep);
//                    hates[c1_rep] = hates[c2_rep];
//                }else {
////                    countries.merge(c1_rep, c2_rep);
//                    Union(parent, c1_rep, c2_rep);
////                    countries.merge(hates[c1_rep], hates[c2_rep]);
//
//                    Union(parent, hates[c1_rep], hates[c2_rep]);
//                }
//
//
//
//            } else {
//
//                int c1_rep = find(parent, c1);
//                int c2_rep = find(parent, c2);
////                int c1_rep = countries.find(c1);
////                int c2_rep = countries.find(c2);
//                if(hates[c1_rep] == 0 && hates[c2_rep] == 0) {
//                    hates[c1_rep] = c2_rep;
//                    hates[c2_rep] = c1_rep;
//                } else if (hates[c1_rep] != 0 && hates[c2_rep] == 0) {
//                    Union(parent, c2_rep, hates[c1_rep]);
////                    countries.merge(c2_rep, hates[c1_rep]);
//                    hates[c2_rep] = c1_rep;
//                } else if (hates[c1_rep] == 0 && hates[c2_rep] != 0) {
//                    Union(parent, c1_rep, hates[c2_rep]);
////                    countries.merge(c1_rep, hates[c2_rep]);
//                    hates[c1_rep] = c2_rep;
//                } else {
//                    Union(parent, c2_rep, hates[c1_rep]);
//                    Union(parent, c1_rep, hates[c2_rep]);
////                    countries.merge(c2_rep, hates[c1_rep]);
////                    countries.merge(c1_rep, hates[c2_rep]);
//                }
//            }
//
//
//        }
//        int counter=0;
//        for(int i=1; i<n+1; ++i)
////            if (countries.connected(1, i))
//            if (find(parent, i) == find(parent, 1))
//                ++counter;
//
//        if (counter > (n/2)) {
//            cout << "yes\n";
//        } else {
//            cout << "no\n";
//        }
//
//    }
//
//
//    return  0;
//}