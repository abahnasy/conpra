////
//// Created by abahnasy on 06.06.20.
////
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef vector<int> vi ;
//typedef vector<vector<int>> vii ;
//typedef vector<bool> vb;
//typedef vector<vector<bool>> vbb ;
//
//int n, m;
//
//void print_sol(vbb& curr_sol, vb& curr_active_f){
//    for (int i = 1; i <= n; ++i) {
//        bool print_f = true;
//            for (int j = 1; j <= m; ++j) {
//                if(curr_sol[i][j] == true) {
//                    if(print_f) {
//                        cout << i << " ";
//                        print_f = false;
//                    }
//                    cout << j << " ";
//                }
//            }
//            if(!print_f)
//                cout << "\n";
//    }
//}
//
//int compute_cost(const vbb& curr_solution, vb& active_f, vii& d_costs, vi& f_costs) {
//    int total_cost = 0;
////    for (int i = 1; i <= n; ++i) {
////        if(active_f[i] == true) {
////            total_cost += f_costs[i];
////        }
////    }
//    for (int i = 1; i <= n; ++i) {
//        bool f_used = false;
//        for (int j = 1; j <= m; ++j) {
//            if(curr_solution[i][j] == true) {
//                if(!f_used) {
//                    total_cost += f_costs[i];
//                    f_used = true;
//                }
//
//                total_cost+= d_costs[i][j];
//            }
//        }
//    }
//    return total_cost;
//}
//
//void generate_sol(vbb& curr_solution, vb& active_f, vii& d_costs, vi& f_costs) {
//  //  vbb sol(n+1, vb(m+1, false) );
//    for (int i = 1; i <= m; ++i) {
//        int d_cost = INT_MAX;
//        int idx = -1;
//        for (int j = 1; j <= n; ++j) {
//            if(active_f[j] == true) {
//                if(d_costs[j][i] < d_cost) {
//                    d_cost = d_costs[j][i];
//                    idx = j;
//                }
//            }
//
//        }
//        curr_solution[idx][i] = true;
//
//    }
//}
//
//// random add
//bool add_trial(vb&temp_active_f) {
//    int active_counts = 0;
//    for (int i = 1; i <= n; ++i) {
//        if(temp_active_f[i] == true) {
//            active_counts++;
//        }
//    }
//    if(active_counts == n) {
//        return false;
//    } else {
//        for (int i = 0; i < 150; ++i) {
//            //generate number between 1 and n
//            int rand_num = (rand() % n) + 1;
//            if (temp_active_f[rand_num] == false) {
//                temp_active_f[rand_num] = true;
//                return true;
//            }
//        }
//
//    }
//    return false; // redundant
//}
//// random remove
//bool remove_trial(vb&temp_active_f) {
//    int active_counts = 0;
//    for (int i = 1; i <= n; ++i) {
//        if(temp_active_f[i] == false) {
//            active_counts++;
//        }
//    }
//    if(active_counts >= n-1) {
//        return false;
//    } else {
//        for (int i = 0; i < 150; ++i) {
//            //generate number between 1 and n
//            int rand_num = (rand() % n) + 1;
//            if (temp_active_f[rand_num] == true) {
//                temp_active_f[rand_num] = false;
//                return true;
//            }
//        }
//
//    }
//    return false; // redundant
//}
//
//// random swap
//bool swap_trial(vb&temp_active_f) {
//    for (int i = 0; i < (n * 1000); ++i) {
//        for (int j = 0; j < (n * 1000); ++j) {
//            int rand_num_1 = (rand() % n) + 1;
//            int rand_num_2 = (rand() % n) + 1;
//            if (temp_active_f[rand_num_1] != temp_active_f[rand_num_2]) {
//                bool temp = temp_active_f[rand_num_1];
//                temp_active_f[rand_num_1] = temp_active_f[rand_num_2];
//                temp_active_f[rand_num_2] = temp;
//                return true;
//            }
//            return false;
//        }
//    }
//}
//
//int main() {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    // redirect input stream to samples files
////    freopen("../week_7/samples_07/soupdelivery/1.in", "r", stdin);
////    freopen("../week_7/samples_07/soupdelivery/2.in", "r", stdin);
//
//    int test_cases;
//    cin>> test_cases;
//
//    for (int t = 1; t <= test_cases; ++t) {
//        cin >> n >> m;
//        vi f_costs(n+1, 0);
//        int temp;
//        for (int i = 1; i <= n; ++i) {
//            cin>>temp;
//            f_costs[i] = temp;
//        }
//        vii d_costs(n+1, vi(m+1, 0));
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j) {
//                cin >> temp;
//                d_costs[i][j] = temp;
//            }
//        }
//        int max_evals = 2 * pow((n+m),2);
//        vb curr_active_f(n+1, false);
//        // initial solution, set first facility active
//        curr_active_f[1] = true;
//        int curr_num_active = 1;
//
//        vbb curr_sol(n+1, vb(m+1, false));
//        generate_sol(curr_sol, curr_active_f, d_costs, f_costs);
//        int curr_cost = compute_cost(curr_sol, curr_active_f, d_costs,f_costs);
//        int evals = 0;
//
//
//
//
//
//        int temp_cost = 0;
//
//        int i = 1;
//        while (i <= n) {
//            bool improve_flag = false;
//            if(curr_active_f[i] == false) {
//                vb temp_active_f(curr_active_f);
//                temp_active_f[i] = true;
//                vbb temp_sol(n+1, vb(m+1, false));
//                generate_sol(temp_sol, temp_active_f, d_costs, f_costs);
//                temp_cost = compute_cost(temp_sol, temp_active_f, d_costs, f_costs);
//                if(temp_cost < curr_cost) {
//                    curr_active_f = temp_active_f;
//                    curr_sol = temp_sol;
//                    curr_cost = temp_cost;
//                    if (curr_active_f[i] == false)
//                        curr_num_active++;
//                    else
//                        curr_num_active--;
//                    // re-run again using the new configuration
//                    i = 1;
//                    improve_flag = true;
//                    continue;
//                }
//            }else {
//                if(curr_num_active > 1) {
//                    vb temp_active_f(curr_active_f);
//                    temp_active_f[i] = false;
//                    vbb temp_sol(n+1, vb(m+1, false));
//                    generate_sol(temp_sol, temp_active_f, d_costs, f_costs);
//                    temp_cost = compute_cost(temp_sol, temp_active_f, d_costs, f_costs);
//                    if(temp_cost < curr_cost) {
//                        curr_active_f = temp_active_f;
//                        curr_sol = temp_sol;
//                        curr_cost = temp_cost;
//                        if (curr_active_f[i] == false)
//                            curr_num_active++;
//                        else
//                            curr_num_active--;
//                        // re-run again using the new configuration
//                        i = 1;
//                        improve_flag = true;
//                        continue;
//                    }
//                }
//
//            }
//
//
//
//            for (int j = 1; j <= n; ++j) {
//                if((i != j) && curr_active_f[i] == true && curr_active_f[j] == false) {
//                    vb temp_active_f(curr_active_f);
//                    temp_active_f.clear();
//                    temp_active_f = curr_active_f;
//                    temp_active_f[i] = false;
//                    temp_active_f[j] = true;
//
//                    vbb temp_sol(n+1, vb(m+1, false));
//                    generate_sol(temp_sol, temp_active_f, d_costs, f_costs);
//                    temp_cost = compute_cost(temp_sol, temp_active_f, d_costs, f_costs);
//                    if(temp_cost < curr_cost) {
//                        curr_active_f = temp_active_f;
//                        curr_sol = temp_sol;
//                        curr_cost = temp_cost;
//
//
//                        // re-run again using the new configuration
//                        i = 1;
//                        improve_flag = true;
//                        break;
//                    }
//                }
//
//            }
//
//            if(!improve_flag)
//                i++;
//
//        }
//
//
//
//
//
////        for (int i = 1; i <= n; ++i) {
////            vb best_so_far = curr_active_f;
////            // add if possible
////            if(curr_active_f[i] == false) {
////                vb temp_active_f(curr_active_f);
////                temp_active_f[i] = true;
////                vbb temp_sol(n+1, vb(m+1, false));
////                generate_sol(temp_sol,temp_active_f, d_costs, f_costs);
////                int temp_cost = compute_cost(temp_sol, curr_active_f, d_costs, f_costs);
////                if(temp_cost < curr_cost) {
////                    best_so_far = temp_active_f;
////                }
////            }
////            // remove if possible
////            // swap
////            for (int j = 1; j <= n; ++j) {
////                if(curr_active_f[j] == true && (j != i)) {
////                    vb temp_active_f(curr_active_f);
////                    temp_active_f[j] = false;
////                    temp_active_f[i] = true;
////                    vbb temp_sol(n+1, vb(m+1, false));
////                    generate_sol(temp_sol,temp_active_f, d_costs, f_costs);
////                    int temp_cost = compute_cost(temp_sol, curr_active_f, d_costs, f_costs);
////                    if(temp_cost < curr_cost) {
////                        best_so_far = temp_active_f;
////                    }
////                }
////            }
////            curr_active_f = best_so_far;
////            //update curr sil and current cost
////            vbb updated_Curr_sol(n+1, vb(m+1, false));
////            generate_sol(updated_Curr_sol, curr_active_f, d_costs, f_costs);
////            curr_cost = compute_cost(curr_sol,curr_active_f, d_costs,f_costs);
////            curr_sol = updated_Curr_sol;
////        }
//
//
////        do {
////            /* loop over every facility
////             * add it if possible
////             * remove it possible
////             * swap with every current
////             * */
////
////            // based on the current active set, generate possible additions
////            vi possible_adds;
////            vi possible_removals;
////            //vi possible_swaps[n+1];
////            for (int i = 1; i <= n; ++i) {
////                if(curr_active_f[i] == false) {
////                    possible_adds.push_back(i);
////                } else {
////                    // generate possible removals
////                    possible_removals.push_back(i);
////                }
////            }
////
////            vb temp_active_f(curr_active_f);
////            vbb temp_sol(n+1, vb(m+1, false));
////
////            bool need_update = false;
////            //try all possible adds
////            for (auto x: possible_adds) {
////                temp_active_f[x] = true;
////                generate_sol(temp_sol, temp_active_f, d_costs, f_costs);
////                int cost = compute_cost(temp_sol,temp_active_f, d_costs, f_costs);
//////
////                if(cost < curr_cost) {
////                    curr_cost = cost;
////                    curr_active_f = temp_active_f;
////                    curr_sol = temp_sol;
////                    need_update = true;
////                    break;
////                }
////                // undo the change
////                temp_active_f[x] = false;
////                evals++;
////            }
////
////            if(need_update)
////                continue;
////
////            if(possible_removals.size() != 1) {
////                for(auto x: possible_removals) {
////                    temp_active_f[x] = false;
////                    generate_sol(temp_sol, temp_active_f, d_costs, f_costs);
////                    int cost = compute_cost(temp_sol,temp_active_f, d_costs, f_costs);
//////
////                    if(cost < curr_cost) {
////                        curr_cost = cost;
////                        curr_active_f = temp_active_f;
////                        curr_sol = temp_sol;
////                        need_update = true;
////                        break;
////                    }
////                    // undo the change
////                    temp_active_f[x] = true;
////                    evals++;
////
////                }
////                if(need_update)
////                    continue;
////            }
////
////
////
////
////        } while (evals<max_evals);
//
//
//
//
//        generate_sol(curr_sol, curr_active_f, d_costs,f_costs);
//        cout << "Case #"<<t<<": ";
//        cout << curr_cost << "\n";
//        print_sol(curr_sol, curr_active_f);
//
//    }
//
//
//
//    return 0;
//}
//
