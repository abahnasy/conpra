//
// Created by abahnasy on 06.06.20.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi ;
typedef vector<vector<int>> vii ;
typedef vector<bool> vb;
typedef vector<vector<bool>> vbb ;

int n, m;

void print_sol(vbb& curr_sol, vb& curr_active_f){
    for (int i = 1; i <= n; ++i) {
        bool print_f = true;
            for (int j = 1; j <= m; ++j) {
                if(curr_sol[i][j] == true) {
                    if(print_f) {
                        cout << i << " ";
                        print_f = false;
                    }
                    cout << j << " ";
                }
            }
            if(!print_f)
                cout << "\n";
    }
}

int compute_cost(const vbb& curr_solution, vb& active_f, vii& d_costs, vi& f_costs) {
    int total_cost = 0;
//    for (int i = 1; i <= n; ++i) {
//        if(active_f[i] == true) {
//            total_cost += f_costs[i];
//        }
//    }
    for (int i = 1; i <= n; ++i) {
        bool f_used = false;
        for (int j = 1; j <= m; ++j) {
            if(curr_solution[i][j] == true) {
                if(!f_used) {
                    total_cost += f_costs[i];
                    f_used = true;
                }

                total_cost+= d_costs[i][j];
            }
        }
    }
    return total_cost;
}

void generate_sol(vbb& curr_solution, vb& active_f, vii& d_costs, vi& f_costs) {
  //  vbb sol(n+1, vb(m+1, false) );
    for (int i = 1; i <= m; ++i) {
        int d_cost = INT_MAX;
        int idx = -1;
        for (int j = 1; j <= n; ++j) {
            if(active_f[j] == true) {
                if(d_costs[j][i] < d_cost) {
                    d_cost = d_costs[j][i];
                    idx = j;
                }
            }

        }
        curr_solution[idx][i] = true;

    }
}

// random add
bool add_trial(vb&temp_active_f) {
    int active_counts = 0;
    for (int i = 1; i <= n; ++i) {
        if(temp_active_f[i] == true) {
            active_counts++;
        }
    }
    if(active_counts == n) {
        return false;
    } else {
        for (int i = 0; i < 150; ++i) {
            //generate number between 1 and n
            int rand_num = (rand() % n) + 1;
            if (temp_active_f[rand_num] == false) {
                temp_active_f[rand_num] = true;
                return true;
            }
        }

    }
    return false; // redundant
}
// random remove
bool remove_trial(vb&temp_active_f) {
    int active_counts = 0;
    for (int i = 1; i <= n; ++i) {
        if(temp_active_f[i] == false) {
            active_counts++;
        }
    }
    if(active_counts == n) {
        return false;
    } else {
        for (int i = 0; i < 150; ++i) {
            //generate number between 1 and n
            int rand_num = (rand() % n) + 1;
            if (temp_active_f[rand_num] == true) {
                temp_active_f[rand_num] = false;
                return true;
            }
        }

    }
    return false; // redundant
}

// random swap
bool swap_trial(vb&temp_active_f) {
    for (int i = 0; i < (n * 1000); ++i) {
        for (int j = 0; j < (n * 1000); ++j) {
            int rand_num_1 = (rand() % n) + 1;
            int rand_num_2 = (rand() % n) + 1;
            if (temp_active_f[rand_num_1] != temp_active_f[rand_num_2]) {
                bool temp = temp_active_f[rand_num_1];
                temp_active_f[rand_num_1] = temp_active_f[rand_num_2];
                temp_active_f[rand_num_2] = temp;
                return true;
            }
            return false;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // redirect input stream to samples files
//    freopen("../week_7/samples_07/soupdelivery/1.in", "r", stdin);
//    freopen("../week_7/samples_07/soupdelivery/2.in", "r", stdin);

    int test_cases;
    cin>> test_cases;

    for (int t = 1; t <= test_cases; ++t) {
        cin >> n >> m;
        vi f_costs(n+1, 0);
        int temp;
        for (int i = 1; i <= n; ++i) {
            cin>>temp;
            f_costs[i] = temp;
        }
        vii d_costs(n+1, vi(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> temp;
                d_costs[i][j] = temp;
            }
        }
        int max_evals = 2* pow((n+m),2);
        vb curr_active_f(n+1, false);
        // initial solution, set first facility active
        curr_active_f[1] = true;

        vbb curr_sol(n+1, vb(m+1, false));
        generate_sol(curr_sol, curr_active_f, d_costs, f_costs);
        int curr_cost = compute_cost(curr_sol, curr_active_f, d_costs,f_costs);
        int evals = 0;


        do {

            vb temp_active_f(curr_active_f);
            vbb temp_sol(n+1, vb(m+1, false));
            // add
            if(add_trial(temp_active_f)) {
                generate_sol(temp_sol, temp_active_f, d_costs, f_costs);
                int cost = compute_cost(temp_sol,temp_active_f, d_costs, f_costs);

                if(cost < curr_cost) {
                    curr_cost = cost;
                    curr_active_f = temp_active_f;
                    curr_sol = temp_sol;
                    evals++;

                    continue;
                }
            }
            // remove
            if(remove_trial(temp_active_f)) {
                generate_sol(temp_sol, temp_active_f, d_costs, f_costs);
                int cost = compute_cost(temp_sol,temp_active_f, d_costs, f_costs);
                if(cost < curr_cost) {
                    curr_cost = cost;
                    curr_active_f = temp_active_f;
                    curr_sol = temp_sol;
                    evals++;
                    continue;
                }
            }
            // swap
            if(swap_trial(temp_active_f)) {
                generate_sol(temp_sol, temp_active_f, d_costs, f_costs);
                int cost = compute_cost(temp_sol,temp_active_f, d_costs, f_costs);
                if(cost < curr_cost) {
                    curr_cost = cost;
                    curr_active_f = temp_active_f;
                    curr_sol = temp_sol;
                    evals++;
                    continue;
                }
            }

            evals++;
        } while (evals<max_evals);



        cout << "Case #"<<t<<": ";
        cout << curr_cost << "\n";
        print_sol(curr_sol, curr_active_f);

    }



    return 0;
}

