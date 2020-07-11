//
// Created by abahnasy on 04.07.20.
//
//https://www.geeksforgeeks.org/adjoint-inverse-matrix/
// disable / enable assertions
//# define NDEBUG

#include <bits/stdc++.h>
using namespace std;
typedef vector<long double> vd;
typedef vector<vector<long double>> vdd;

// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void getCofactor(vdd& A, vdd& temp, int p, int q, int n)
{
    int i = 0, j = 0;
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
long double determinant(vdd& A, int n)
{
    int N = A.size();
    long double D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];

    vdd temp(N, vd(N,0)); // To store cofactors

    int sign = 1;  // To store sign multiplier

    // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}
// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(vdd& A,vdd& adj)
{
    int N = A.size();
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }

    // temp is used to store cofactors of A[][]
    int sign = 1;
    vdd temp(N, vd(N, 0));

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(vdd& A, vdd& inverse)
{
    int N = A.size();
    // Find determinant of A[][]
    long double det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }

    // Find adjoint
    vdd adj(N, vd(N, 0));
    adjoint(A, adj);

    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = adj[i][j]/float(det);

    return true;
}


void matrix_vector_mul(vdd& m, vd& v, vd&res) {
    assert(m.size() == v.size());
    for (int i = 0; i < m.size(); ++i) {
        res[i] = 0;
        for (int j = 0; j < m[i].size(); ++j) {
            res[i] += m[i][j] * v[j];
        }
    }
}

void scale_mat_vec(vdd& m, vd& scale) {
    assert(m.size() == scale.size());
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
            m[j][i] = m[j][i] * scale[i];
        }
    }

}

void mat_mat_mult(vdd& m1, vdd& m2, vdd& res) {
    assert(m1.size() == m2.size());
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m1.size(); ++j) {
            res[i][j] = 0;
            for (int k = 0; k < m1.size(); ++k) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    // redirect input stream to samples files
//    freopen("../../week_12/samples_12/familypictures/1.in", "r", stdin);
//    freopen("../../week_12/samples_12/familypictures/2.in", "r", stdin);
//    freopen("../../week_11/samples_11//test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;

    // getting the M for original image
    vdd M1;
    M1.push_back(vd{0,1,1});
    M1.push_back(vd{0,0,1});
    M1.push_back(vd{1,1,1});
    vd lambda1(3,0);
    vd D1 {0,1,1};
    vdd M1_inv(M1.size(), vd(M1.size(), 0));
    inverse(M1, M1_inv);
    matrix_vector_mul(M1_inv, D1,lambda1);
    // scale M1 by the coefficients of lambda1
    scale_mat_vec(M1, lambda1);


    for (int test_case = 1; test_case <= test_cases; ++test_case) {
        cout << "Case #" << test_case << ": ";
        double x, y;
        vdd M2 (3, vd(3, 0));
        vd D2(3, 0);
        vd E2(3, 0);
        vd F2(3, 0);
        vd lambda2 (3, 0);
        for (int i = 0; i < 3; ++i) {
            cin >> x >> y;
            M2[0][i] = x;
            M2[1][i] = y;
            M2[2][i] = 1;
        }
        // scan D2
        cin >> x >> y;
        D2[0] = x; D2[1] = y; D2[2] = 1;
        cin >> x >> y;
        E2[0] = x; E2[1] = y; E2[2] = 1;
        cin >> x >> y;
        F2[0] = x; F2[1] = y; F2[2] = 1;

        vdd M2_inv(M2.size(), vd(M2.size(),0));
        inverse(M2, M2_inv);
        matrix_vector_mul(M2_inv, D2, lambda2);
        scale_mat_vec(M2, lambda2);

        // get the combined matrix
        M2_inv.clear();
        M2_inv.resize(3, vd(3,0));
        inverse(M2, M2_inv);
        vdd C (3, vd(3,0));
        mat_mat_mult(M1, M2_inv, C);

        // map the clock and head to prjected coordinates
        vd E2_proj(E2.size(),0);
        matrix_vector_mul(C, E2, E2_proj);
        vd F2_proj (F2.size(), 0);
        matrix_vector_mul(C, F2, F2_proj);
        cout << fixed <<(E2_proj[1] * F2_proj[2]) / (E2_proj[2]*F2_proj[1]) << "\n";




    }
}