////
//// Created by abahnasy on 02.05.20.
////
//
//#include <iostream>
//
//
//using namespace std;
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
//int main () {
//    int t;
//    cin >> t;
//
//    //loop over the test cases
//    for (int i = 0; i < t; ++i) {
//        cout << "Case #" << i+1 <<": ";
//        // get no. of people relations marriages
//        int n, r, m;
//        // get number of people
//        cin >> n >> r >> m;
//
//
//        int parent[n+1];
//        for (int j = 0; j <=n; ++j) {
//           parent[j] = -1;
//        }
//        long long int size[n+1];
//        for (int j = 1; j < n; ++j) {
//            cin >> size[j];
//        }
//
//        bool marr [n+1];
//        for (int j = 0; j <= n; ++j) {
//            marr[j] = false;
//        }
//
//        // loop over relations
//        for (int j = 0; j <r; ++j) {
//            int r1 ,r2;
//            cin >> r1 >> r2;
//
//            Union(parent, r1,r2);
//        }
//        // loop over married people
//        for (int j = 0; j < m; ++j) {
//            int m1, m2;
//            cin >> m1 >> m2;
//            Union(parent, m1, m2);
//            marr[m1] = true;
//            marr[m2] = true;
//        }
//
//        int maxIdx = -1;
//        int maxMoney = -1;
//        for (int j =1; j < n; ++j) {
//            int lea_parent = find(parent,n);
//            int candid = find(parent, j);
//            if (candid != lea_parent && marr[j] == false) {
//                if (size[j] > maxMoney) {
//                    maxMoney = size[j];
//                    maxIdx = j;
//                }
//            }
//        }
//
//        if (maxMoney == -1)
//            cout << "impossible" << "\n";
//        else
//            cout << maxMoney << "\n";
//
//
//
//
//    }
//    return 0;
//}
