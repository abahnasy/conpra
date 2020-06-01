////
//// Created by abahnasy on 30.05.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//vector<int> subset;
//void print_vector(vector<int>& vector) {
//    if(vector.empty())
//        cout << "empty set";
//    for (int i = 0; i < vector.size(); ++i) {
//        cout << vector.at(i) << " ";
//    }
//    cout << endl;
//}
//
//void generate_subsets_rec (int size, int k) {
//    if (k == size) {
//         print_vector(subset);
//    } else {
//        generate_subsets_rec(size, k+1);
//        subset.push_back(k);
//        generate_subsets_rec(size, k+1);
//        subset.pop_back();
//    }
//}
//
//// represent subsets based on bit representation, we can imagine the subsets as a
//// sequence of n bits, each sequence correspondes to a number between 0... 2^(n)-1
//// the one bits in the sequence represent the elements included in the subset
//void generate_subsets_loop (int size) {
//    // for loop goes through the subsets of n elements
//    for (int i = 0; i < (1 << size); ++i) {
//        cout << "{";
//        for (int j = 0; j<size; ++j) {
//            if(i&(1<<j)) {
//                // add the element to the subset
//                cout << j << ", ";
//            }
//        }
//        cout << "}" << endl;
//    }
//}
//
//void back_track(int& total, const int& board_size, vector<int>& col , vector<int>& diag_r, vector<int>& diag_l, int y) {
//    if (y == board_size) {
//        total++;
//        return;
//    }
//    //loop over all columns
//    for (int x = 0; x < board_size; x++) {
//        // if there is another queen in the same column or diagonals skip this column
//        if (col[x] || diag_l[x-y+board_size-1] || diag_r[x+y]) {
//            continue;
//        }
//        // assign a new queen in this position
//        col[x] = diag_l[x-y+board_size-1] = diag_r[x+y] =1;
//        // go one step deeper and launch a new search given the current positions
//        back_track(total, board_size, col, diag_r, diag_l, y+1);
//        // remove this assignation and explore other options
//        col[x] = diag_l[x-y+board_size-1] = diag_r[x+y] =0;
//    }
//}
//
//int back_track_helper (int size_board) {
//    int total = 0;
//    vector<int> col(size_board,0);
//    vector<int> diag_r(2*size_board - 1,0);
//    vector<int> diag_l(2*size_board - 1,0);
//    back_track(total, size_board, col, diag_r, diag_l, 0);
//    return total;
//
//}
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//
////    generate_subsets_rec(3, 0);
////    generate_subsets_loop(3);
//
//    for (int i = 1; i <= 16; ++i) {
//        cout << "Board size "<< i << ": " << back_track_helper(i) << "\n";
//    }
//
//
//
//    //generate subsets loop
//    // generate permutations recursive way
//    // generate permutations loop way
//}
