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
constexpr bool USE_FILE_IO = true;
constexpr auto FILENAME = "speeding";

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

void solve() {
    int n, m;
    cin >> n >> m;

    // Input values
    vpii road_segments, cow_segments; // first is length, second is speed (limit).
    for (int i = 0; i < n; i++) {
        int length, limit;
        cin >> length >> limit;
        road_segments.emplace_back(length, limit);
    }
    for (int i = 0; i < m; i++) {
        int length, speed;
        cin >> length >> speed;
        cow_segments.emplace_back(length, speed);
    }

    // Fill in speed / speed limit for every mile in two vectors
    vi speed_limit_every_mile(101), cow_speed_every_mile(101);
    int mile_count = 1;
    for (auto [length, limit]: road_segments) {
        for (int i = 1; i <= length; ++i) {
            speed_limit_every_mile[mile_count] = limit;
            mile_count++;
        }
    }
    mile_count = 1;
    for (auto [length, speed]: cow_segments) {
        for (int i = 1; i <= length; ++i) {
            cow_speed_every_mile[mile_count] = speed;
            mile_count++;
        }
    }

    // Find max speeding over limit
    int max_speeding_over_limit = 0;
    for (int i = 1; i <= 100; i++) {
        max_speeding_over_limit =
                max(max_speeding_over_limit, cow_speed_every_mile[i] - speed_limit_every_mile[i]);
    }

    cout << max_speeding_over_limit << '\n';
}

int main() {
    setup_io();

    if constexpr (USE_FILE_IO && FILENAME == "CHANGE_THIS") {
        cerr << "Error: you are in USE_FILE_IO mode but forgot to set the FILENAME variable!" << '\n';
        exit(1);
    }

    int t = 1;
    // cin >> t; // Multiple test cases
    while (t--) { solve(); }

    return 0;
}
