////
//// Created by abahnasy on 31.05.20.
////
//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//void print_board(const vector<vector<bool>> &solution, int n)
//{
//    for (int i=1; i<=n; ++i)
//    {
//        for (int j=1; j<=n; ++j)
//        {
//            if (solution[i][j])
//                cout << 'x';
//            else
//                cout << '.';
//        }
//        cout << "\n";
//    }
//}
//
////bool back_track(vector<vector<bool>>& board, const int& board_size, vector<bool>& row, vector<bool>& col , vector<bool>& diag_r, vector<bool>& diag_l, int y) {
//////    cout << "board_state when calling back_track\n";
//////    print_board(board);
////    if (y == board_size) {
////        return true;
////    }
////    if(row[y] == true) {
////
////        if (back_track(board, board_size, row, col, diag_r, diag_l, y+1)) {
////            return true;
////        } else {
////            return false;
////        }
////    }
////    //loop over all columns
////    for (int x = 1; x <= board_size; x++) {
////        // if there is another queen in the same column or diagonals skip this column
////        if (col[x] || diag_l[x-y+board_size-1] || diag_r[x+y]) {
////            continue;
////        }
////        // assign a new queen in this position
////        col[x] = diag_l[x-y+board_size-1] = diag_r[x+y] =1;
////        //update board
////        board[y][x] = true;
////        // go one step deeper and launch a new search given the current positions
////        if (back_track(board, board_size, row, col, diag_r, diag_l, y+1)) {
////            return true;
////        }
////        // remove this assignation and explore other options
////        col[x] = diag_l[x-y+board_size-1] = diag_r[x+y] =0;
////        //update board
////        board[y][x] = false;
////    }
////    return false;
////}
//
//
//bool is_valid_input(vector<vector<bool>>& board, int n, int row, int col)
//{
//    int i, j;
//
//    /* Check this row on left side */
//    for (i = 0; i < col; i++)
//        if (board[row][i])
//            return false;
//
//    /* Check this col above */
//    for (i = 0; i < row; i++)
//        if (board[i][col])
//            return false;
//
//
//    /* Check upper diagonal on left side */
//    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
//        if (board[i][j])
//            return false;
//
//    /* Check upper on the right side */
//    for (i = row -1, j= col +1; i>= 0 && j < n;i--,j++)
//        if (board[i][j])
//            return false;
//
//    return true;
//}
//
//bool is_valid(const vector<vector<bool>> &solution, int i, int j, int n)
//{
//
//// rows are checked from within the calling function
//
//// vertical up
//    for (int k=1; k<i; ++k){
//        if (solution[k][j]){
//            return false;
//        }
//    }
//
//// vertical down
//    for (int k=i+1; k<=n; ++k){
//        if (solution[k][j]){
//            return false;
//        }
//    }
//
//
//
//    // diag left-up
//    for (int k=1; k<=min(i-1, j-1); ++k) {
//        if (solution[i-k][j-k]) {
//            return false;
//        }
//    }
//
//
//
//    // diag right-up
//    for (int k=1; k<=min(i-1, n-j); ++k) {
//        if (solution[i-k][j+k]) {
//            return false;
//        }
//    }
//
//
//
//    // diag right-down
//    for (int k=1; k<=min(n-i, j-1); ++k) {
//        if (solution[i+k][j-k]){
//            return false;
//        }
//    }
//
//    // diag left-down
//    for (int k=1; k<=min(n-i, n-j); ++k) {
//        if (solution[i+k][j+k]) {
//            return false;
//        }
//    }
//
//
//    return true;
//}
//
//bool check_board(vector<vector<bool>> board, int n)
//{
//    for (int row=1; row<=n; ++row)
//    {
//        // check that there is at most one queen
//        int queens = 0;
//        for (int column=1; column<=n; ++column)
//        {
//            if (board[row][column])
//            {
//                bool res = is_valid(board, row, column, n);
//                if (!res)
//                {
//                    return false;
//                }
//                ++queens;
//            }
//        }
//        if (queens > 1)
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//
//
//// assume that in our row no other queen is placed
//void findSolutionsForRow(const vector<vector<bool> > &currentSolution, int row, int n, vector<vector<vector<bool> >> &allSolutions)
//{
//    for (int column=1; column<=n; ++column)
//    {
//        vector<vector<bool> > possibleSolution (currentSolution);
//        possibleSolution[row][column] = true;
//        bool works = is_valid(possibleSolution, row, column, n);
//        if (works)
//        {
//            allSolutions.push_back(possibleSolution);
//        }
//    }
//}
//
//bool back_track(const vector<vector<bool> > &currentSolution, int n, priority_queue<int, vector<int>, greater<int> > pqRows)
//{
//    // we were able to place a queen in every row
//    if (pqRows.empty())
//    {
//        print_board(currentSolution, n);
//        return true;
//    }
//
//    int nextRow = pqRows.top();
//    pqRows.pop();
//
//    vector<vector<vector<bool> >> nextSolutions;
//    findSolutionsForRow(currentSolution, nextRow, n, nextSolutions);
//
//    for (const auto &nextSolution : nextSolutions)
//    {
//        bool result = back_track(nextSolution, n, pqRows);
//        if (result)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
////    freopen("../week_6/samples_06/queensproblem/1.in", "r", stdin);
////    freopen("../week_6/samples_06/queensproblem/unitTest.in", "r", stdin);
//    int test_cases;
//    cin >> test_cases;
//    for (int t = 1; t <= test_cases; ++t) {
//        int n;
//        cin >> n;
//        vector<vector<bool> > board(n+1, vector<bool>(n+1));
//        vector<bool> missing_rows (n + 1, true);
//
////        vector<bool> row(n, false);
////        vector<bool> col(n,false);
////        vector<bool> diag_r(2*n - 1,false);
////        vector<bool> diag_l(2*n - 1,false);
//
//
////        int flag = true;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                char c;
//                cin >> c;
//                if (c == 'x') {
//                    board[i][j] = true;
//                    missing_rows[i] = false;
//
//
////                    // fill the given constraints
////                    row[i] = true;
////                    col[j] = true;
////                    diag_r[i+j] = true;
////                    diag_l[j-i+n-1] = true;
//                }
//
//            }
//        }
//
//        cout << "Case #" << t << ":\n";
//
//        // check if the initial configuration is valid
//
//        if (!check_board(board, n)) {
//            cout << "impossible\n";
//            continue;
//        }
//
//        // create pq for rows
//        priority_queue<int, vector<int>, greater<int> > pq;
//        for (int i=1; i<=n; ++i) {
//            if (missing_rows[i])
//            {
//                pq.push(i);
//            }
//        }
//
//
//        if (!back_track(board, n, pq)) {
//            cout << "impossible\n";
//        }
//
//
//
////        if(back_track(board, n, row, col, diag_r, diag_l, 0)) {
////
////            print_board(board);
////        } else {
////            cout << "impossible\n";
////        }
//
//    }
//
//
//
//
//
//
//
//
//
//}
//
