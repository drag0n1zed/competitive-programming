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

// Set to true for old USACO (file I/O), false for modern problems (stdin/stdout)
constexpr bool USE_FILE_IO = false;
constexpr auto FILENAME = "CHANGE_THIS";

void setup_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef LOCAL
    if (USE_FILE_IO) {
        freopen((string(FILENAME) + ".in").c_str(), "r", stdin);
        freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
    }
#endif
}

struct Cow {
    int index;
    int constant_coord;
    int initial_dynamic_coord;
    int grass_to_eat;

    bool operator<(const Cow &other) const {
        if (constant_coord == other.constant_coord) {
            return initial_dynamic_coord < other.initial_dynamic_coord; // Secondary sort by the other coordinate
        }
        return constant_coord < other.constant_coord; // Primary sort by constant coordinate
    }
};

void solve() {
    int n;
    cin >> n;

    // Input
    vector<Cow> north_moving_cows, east_moving_cows;
    for (int i = 0; i < n; i++) {
        char direction;
        int x, y;
        cin >> direction >> x >> y;
        if (direction == 'N') {
            north_moving_cows.push_back({i, x, y, INF});
        } else {
            east_moving_cows.push_back({i, y, x, INF});
        }
    }

    sort(east_moving_cows.begin(), east_moving_cows.end()); // Sort by y coordinate then initial x coordinate
    sort(north_moving_cows.begin(), north_moving_cows.end()); // Sort by x coordinate then initial y coordinate

    for (auto& north_cow: north_moving_cows) {
        for (auto& east_cow: east_moving_cows) {
            pii collision_coord = make_pair(north_cow.constant_coord, east_cow.constant_coord);
            if (collision_coord.first < east_cow.initial_dynamic_coord
                || collision_coord.second < north_cow.initial_dynamic_coord
                || collision_coord.first >= east_cow.initial_dynamic_coord + east_cow.grass_to_eat
                || collision_coord.second >= north_cow.initial_dynamic_coord + north_cow.grass_to_eat) {
                continue; // Skip if collision point unattainable
            }
            // If collision point closer to north cow than east cow (east cow gets blocked)
            if (collision_coord.second - north_cow.initial_dynamic_coord
                < collision_coord.first - east_cow.initial_dynamic_coord) {
                east_cow.grass_to_eat = collision_coord.first - east_cow.initial_dynamic_coord;
            }
            // Vice versa
            if (collision_coord.second - north_cow.initial_dynamic_coord
                > collision_coord.first - east_cow.initial_dynamic_coord) {
                north_cow.grass_to_eat = collision_coord.second - north_cow.initial_dynamic_coord;
            }
        }
    }

    vector<string> final_solution(n);
    for (auto north_cow: north_moving_cows) {
        final_solution[north_cow.index] = north_cow.grass_to_eat == INF
                                              ? string("Infinity")
                                              : to_string(north_cow.grass_to_eat);
    }
    for (auto east_cow: east_moving_cows) {
        final_solution[east_cow.index] = east_cow.grass_to_eat == INF
                                             ? string("Infinity")
                                             : to_string(east_cow.grass_to_eat);
    }

    for (int i = 0; i < n; i++) {
        cout << final_solution[i] << '\n';
    }
}

int main() {
    setup_io();

    if (USE_FILE_IO && FILENAME == "CHANGE_THIS") {
        cerr << "Error: you are in USE_FILE_IO mode but forgot to set the FILENAME variable!" << '\n';
        exit(1);
    }

    int t = 1;
    // cin >> t; // Multiple test cases
    while (t--) { solve(); }

    return 0;
}
