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

void solve() {
    int n, side_length;
    cin >> n >> side_length; // N is number of cows, <= 100; B is the side length of the square farm, <= 1e6.

    // Input coordinate pairs into location vector<pair>
    vpii locations;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        locations.emplace_back(x, y);
    }

    // Create a list of *possible* fence coordinates.
    vi fence_x, fence_y;
    for (auto [x,y]: locations) {
        fence_x.push_back(x + 1);
        fence_y.push_back(y + 1);
    }

    // Iterate through every possible fence placement. 2 <= a, b <= side_length
    int min_m = INF;
    for (const auto &a: fence_x) {
        // x = a
        for (const auto &b: fence_y) {
            // y = b
            int i_quad = 0, ii_quad = 0, iii_quad = 0, iv_quad = 0;
            // Calculate the M
            for (auto [x, y]: locations) {
                if (x > a && y > b) {
                    i_quad++;
                } else if (x < a && y > b) {
                    ii_quad++;
                } else if (x < a && y < b) {
                    iii_quad++;
                } else if (x > a && y < b) {
                    iv_quad++;
                }
            }
            min_m = min(min_m, max({i_quad, ii_quad, iii_quad, iv_quad})); // Compare overall lowest M with current M
        }
    }
    cout << min_m << '\n';
}

// Set to true for old USACO (file I/O), false for modern problems (stdin/stdout)
constexpr bool USE_FILE_IO = true;
constexpr string_view FILENAME = "balancing";

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
