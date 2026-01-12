// C++17
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int> >;
using pii = pair<int, int>;
using vpii = vector<pair<int, int> >;
using pll = pair<long long, long long>;
using vpll = vector<pair<long long, long long> >;

constexpr int INF = 1e9;
constexpr ll INF64 = 1e18;
constexpr int MOD = 1e9 + 7;

vector<bool> check_state(int cow_num, int k, int patient_zero, map<int, pair<int, int>> interactions) {
    vector<bool> is_infected(cow_num + 1, 0);
    is_infected[patient_zero] = 1;
    vector<int> shakes_left(cow_num + 1, 0);
    shakes_left[patient_zero] = k;
    for(auto const& [time, cows] : interactions) {
        int cow1 = cows.first;
        int cow2 = cows.second;
        bool cow1_infects = is_infected[cow1] && shakes_left[cow1] > 0;
        bool cow2_infects = is_infected[cow2] && shakes_left[cow2] > 0;
        if(cow1_infects) {
            shakes_left[cow1]--;
            if(!is_infected[cow2]) {
                is_infected[cow2] = true;
                shakes_left[cow2] = k;
            }
        }
        if(cow2_infects) {
            shakes_left[cow2]--;
            if(!is_infected[cow1]) {
                is_infected[cow1] = true;
                shakes_left[cow1] = k;
            }
        }
    }
    return is_infected;
}

void solve() {
    int n, t;
    cin >> n >> t;
    string state;
    cin >> state;
    vector<bool> final_state(n + 1);
    for (int i = 1; i <= n; i++) {
        final_state[i] = (state[i - 1] == '1');
    }
    map<int, pair<int, int>> interactions; // Time, <Cow 1, Cow 2>
    for (int i = 0; i < t; i++) {
        int time, cow1, cow2;
        cin >> time >> cow1 >> cow2;
        interactions.emplace(time, make_pair(cow1, cow2));
    }

    // PLAN:
    // If cow i is patient zero and K = some number, is it possible to reach this scenario?
    set<int> possible_zeros;
    int min_k = INF, max_k = -1;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= t; k++) { // Test every possible time the virus would stay for
            if (final_state == check_state(n, k, i, interactions)) {
                min_k = min(k, min_k);
                max_k = max(k, max_k);
                possible_zeros.insert(i);
            }
        }
    }
    string str_max_k = max_k == t ? "Infinity" : to_string(max_k);
    cout << possible_zeros.size() << " " << min_k << " " << str_max_k << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(("tracing.in"), "r", stdin);
    freopen(("tracing.out"), "w", stdout);

    int t = 1;
    // cin >> t; // Multiple test cases
    while (t--) { solve(); }

    return 0;
}
