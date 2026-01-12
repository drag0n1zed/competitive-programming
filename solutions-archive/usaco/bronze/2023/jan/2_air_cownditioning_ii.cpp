// C++17
#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> cow_temps(101);

vector<int> ac_start;
vector<int> ac_end;
vector<int> ac_temp;
vector<int> ac_cost;

int recurse_total_ac_cost(int ac_index, int (&temp)[101]) {
    if (ac_index == m) {
        for (int stall_index = 1; stall_index <= 100; stall_index++) {
            if (temp[stall_index] < cow_temps[stall_index]) {
                return 1e9;
            }
        }
        return 0;
    }
    int disable_cost = recurse_total_ac_cost(ac_index + 1, temp);
    for (int stall_index = ac_start[ac_index]; stall_index <= ac_end[ac_index]; stall_index++) {
        temp[stall_index] += ac_temp[ac_index];
    }
    int enable_cost = recurse_total_ac_cost(ac_index + 1, temp) + ac_cost[ac_index];
    // backtrack
    for (int stall_index = ac_start[ac_index]; stall_index <= ac_end[ac_index]; stall_index++) {
        temp[stall_index] -= ac_temp[ac_index];
    }
    return min(disable_cost, enable_cost);
}

void solve() {
    cin >> n >> m;

    ac_start.resize(m);
    ac_end.resize(m);
    ac_temp.resize(m);
    ac_cost.resize(m);

    for (int i = 0; i < n; i++) {
        int cow_start, cow_end, cow_temp;
        cin >> cow_start >> cow_end >> cow_temp;
        for (int stall_index = cow_start; stall_index <= cow_end; stall_index++) {
            cow_temps[stall_index] = cow_temp;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> ac_start[i] >> ac_end[i] >> ac_temp[i] >> ac_cost[i];
    }
    int temp[101] = {0};
    int mincost = recurse_total_ac_cost(0, temp);
    cout << mincost << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen(("NAME.in"), "r", stdin);
    // freopen(("NAME.out"), "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
