////
//// Created by abahnasy on 06.06.20.
////
//
//
//#include <bits/stdc++.h>
//
//
//
//using namespace std;
//
//
//int get_numeric(char c) {
//    int res = -1;
//    switch(c) {
//        case 'A':
//            res = 0;
//            break;
//        case 'C':
//            res = 1;
//            break;
//        case 'T':
//            res = 2;
//            break;
//        case 'G':
//            res = 3;
//            break;
//        default:
//            res =  0;
//    }
//
//    return res;
//
//
//}
//
//double compute_score (vector<int>& freq, vector<int>& approx) {
//    double total = 0;
//    for (int i = 0; i < 10; ++i) {
//        total += (freq[i] * approx[i]);
//    }
//    return total;
//}
//
//
//int main() {
//
////    ios_base::sync_with_stdio(false);
////    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../../week_7/samples_07/dolphins/1.in", "r", stdin);
////    freopen("../../week_7/samples_07/dolphins/2.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//
//
//    for (int t = 1; t <= test_cases; ++t) {
//
//        int n, m;
//        cin>>n>>m;
//        vector<string> humans_dna;
//        vector<string> mice_dna;
//        string line;
//        for (int i = 0; i < n; ++i) {
//            cin >> line;
//            humans_dna.push_back(line);
//        }
//        for (int j = 0; j < m; ++j) {
//            cin>> line;
//            mice_dna.push_back(line);
//        }
//
//        vector<vector<int>> freq (4, vector<int>(4, 0));
//        // get the frequency of every pair of letters in all input combinations
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                for (int k = 0; k < humans_dna[i].size(); ++k) {
////                    cout << get_numeric(humans_dna[i][k]) << "\n";
////                    cout << get_numeric(mice_dna[j][k]) << "\n";
//                    ++freq[get_numeric(humans_dna[i][k])][get_numeric(mice_dna[j][k])];
//                }
//            }
//        }
//
//        // freq as mentioned in the form of the tutorial
//        vector<int> freq_vec(10, 0);
//        freq_vec[0] = freq[get_numeric('A')][get_numeric('A')];
//        freq_vec[1] = freq[get_numeric('C')][get_numeric('C')];
//        freq_vec[2] = freq[get_numeric('T')][get_numeric('T')];
//        freq_vec[3] = freq[get_numeric('G')][get_numeric('G')];
//        freq_vec[4] = freq[get_numeric('A')][get_numeric('C')]  + freq[get_numeric('C')][get_numeric('A')];
//        freq_vec[5] = freq[get_numeric('A')][get_numeric('T')]  + freq[get_numeric('T')][get_numeric('A')];
//        freq_vec[6] = freq[get_numeric('A')][get_numeric('G')]  + freq[get_numeric('G')][get_numeric('A')];
//        freq_vec[7] = freq[get_numeric('C')][get_numeric('T')]  + freq[get_numeric('T')][get_numeric('C')];
//        freq_vec[8] = freq[get_numeric('C')][get_numeric('G')]  + freq[get_numeric('G')][get_numeric('C')];
//        freq_vec[9] = freq[get_numeric('G')][get_numeric('T')]  + freq[get_numeric('T')][get_numeric('G')];
//
//        std::sort(std::next(freq_vec.begin(), 4), freq_vec.end(), [](const int a, const int b) {return a > b; });
//
//        double optim = -INFINITY;
//        vector<int> approx (10, 0);
//        for (int i = 0; i <= 10; ++i) {
//            for (int j = 0; j <= 10; ++j) {
//                for (int k = 0; k <= 10; ++k) {
//                    for (int l = 0; l <= 10; ++l) {
//                        if(((i+j+k+l)%2) == 0) {
//                            approx[0] = i;
//                            approx[1] = j;
//                            approx[2] = k;
//                            approx[3] = l;
//                            approx[4] = 10;
//                            approx[5] = 10;
//                            approx[6] = 10 -((approx[0] +approx[1] + approx[2] + approx[3]) / 2);
//                            approx[7] = -10;
//                            approx[8] = -10;
//                            approx[9] = -10;
//
//
//                            double score = compute_score(freq_vec, approx);
//
//                            if(score > optim) {
//                                optim = score;
//                            }
//
//
//
//
//
//                        }
//                    }
//                }
//            }
//        }
//
//
//
//
//
//
//        cout << "Case #"<<t<<": ";
//        cout << optim << "\n";
//
//
//
//
//
//
//
//
//
//    }
//
//
//
//    return 0;
//}
//
