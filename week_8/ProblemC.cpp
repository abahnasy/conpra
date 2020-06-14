////
//// Created by abahnasy on 13.06.20.
////
//
//// Solution built based on https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
//
////TODO: investigate why tuple sorting is not correct?!
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct Box {
//    int w,d,h;
//};
//// A utility function to get minimum of two intgers
//int min (int x, int y)
//{ return (x < y)? x : y; }
//
//// A utility function to get maximum of two intgers
//int max (int x, int y)
//{ return (x > y)? x : y; }
//
//int compare (const void *a, const void * b)
//{
//    return ( (*(Box *)b).d * (*(Box *)b).w ) -
//           ( (*(Box *)a).d * (*(Box *)a).w );
//}
//int maxStackHeight( Box arr[], int n )
//{
//    /* Create an array of all rotations of given boxes
//       For example, for a box {1, 2, 3}, we consider three
//       instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
//    Box rot[3*n];
//    int index = 0;
//    for (int i = 0; i < n; i++)
//    {
//        // Copy the original box
//        rot[index].h = arr[i].h;
//        rot[index].d = max(arr[i].d, arr[i].w);
//        rot[index].w = min(arr[i].d, arr[i].w);
//        index++;
//
//        // First rotation of box
//        rot[index].h = arr[i].w;
//        rot[index].d = max(arr[i].h, arr[i].d);
//        rot[index].w = min(arr[i].h, arr[i].d);
//        index++;
//
//        // Second rotation of box
//        rot[index].h = arr[i].d;
//        rot[index].d = max(arr[i].h, arr[i].w);
//        rot[index].w = min(arr[i].h, arr[i].w);
//        index++;
//    }
//
//    // Now the number of boxes is 3n
//    n = 3*n;
//
//    /* Sort the array 'rot[]' in non-increasing order
//       of base area */
//    qsort (rot, n, sizeof(rot[0]), compare);
//
//    // Uncomment following two lines to print all rotations
//    // for (int i = 0; i < n; i++ )
//    //    printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d);
//
//    /* Initialize msh values for all indexes
//       msh[i] --> Maximum possible Stack Height with box i on top */
//    int msh[n];
//    for (int i = 0; i < n; i++ )
//        msh[i] = rot[i].h;
//
//    /* Compute optimized msh values in bottom up manner */
//    for (int i = 1; i < n; i++ )
//        for (int j = 0; j < i; j++ )
//            if ( rot[i].w < rot[j].w &&
//                 rot[i].d < rot[j].d &&
//                 msh[i] < msh[j] + rot[i].h
//                    )
//            {
//                msh[i] = msh[j] + rot[i].h;
//            }
//
//
//    /* Pick maximum of all msh values */
//    int max = -1;
//    for ( int i = 0; i < n; i++ )
//        if ( max < msh[i] )
//            max = msh[i];
//
//    return max;
//}
//
////bool myComp (tuple<int, int, int>& a, tuple<int, int, int>& b) {
////    // compare based on base area
////    int area_b = get<0>(b) * get<1>(b);
////    int area_a = get<0>(a) * get<1>(a);
////    if(area_a < area_b) {
////        return 1;
////    } else if(area_b == area_a) {
////        return 0;
////    } else {
////        return -1;
////    }
////}
//
////bool fit_on_top(tuple<int, int, int>& a, tuple<int, int, int>& b) {
////    // check if the width and height of the upper box are strictly less than the lower box
////    if((get<0>(a) < get<0>(b)) && (get<1>(a) < get<1>(b)))
////        return true;
////    return false;
////}
//
//
//int main() {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../../week_8/samples_08/packingcases/1.in", "r", stdin);
////    freopen("../../week_8/samples_08/packingcases/test.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//
//    int h, n;
//    for (int t = 1; t <= test_cases; ++t) {
//        cout << "Case #"<<t<<": ";
//        cin >> h >> n;
////        vector<tuple<int, int , int>> boxes;
//        Box arr[n];
//        for (int i = 0; i < (n); ++i){
//            int x,y,z;
//            cin >> x >> y>> z;
//            arr[i] = {x,y,z};
////            boxes.push_back(make_tuple(x,y,z));
////            //push other orientations
////            boxes.push_back(make_tuple(z, x,y));
////            boxes.push_back(make_tuple(y,z,x));
//        }
//
//        if(maxStackHeight (arr, n) >= h) {
//            cout << "yes\n";
//        } else {
//            cout << "no\n";
//        }
//
////        sort(boxes.begin(), boxes.end(), myComp);
////        vector<int> max_h(boxes.size(), 0);
////        // assign the max height for each box
////        for (int i = 0; i < boxes.size(); ++i) {
////            max_h[i] = get<2>(boxes.at(i));
////        }
////        for (int i = 1; i < boxes.size(); ++i) {
////            for (int j = 0; j < i; ++j) {
////                if (fit_on_top(boxes.at(i), boxes.at(j))) {
////                    max_h[i] = max_h[i] + get<2>(boxes.at(j));
////                }
////            }
////        }
////
////        auto it = max_element(max_h.begin(), max_h.end());
////        if(*it >= h) {
////            cout << "yes\n";
////        } else {
////            cout << "no\n";
////        }
//
//    }
//
//
//
//}