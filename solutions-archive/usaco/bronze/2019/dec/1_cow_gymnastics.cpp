// C++17
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

int find_better_cow(const vi &ranking, const int cow1, const int cow2) {
    for (const auto cow: ranking) {
        if (cow == cow1 || cow == cow2) return cow;
    }
    return 0;
}

void solve() {
    int k, n;
    cin >> k >> n;
    vvi rankings(k, vi(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rankings[i][j];
        }
    }

    int consistent_pairs = 0;

    // Check for every pair of cows
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // Is this pair consistent?
            bool is_consistent = true;
            const int better_cow = find_better_cow(rankings[0], i, j);
            for (const auto &ranking: rankings) {
                if (better_cow != find_better_cow(ranking, i, j)) {
                    is_consistent = false;
                    break;
                }
            }
            if (is_consistent) consistent_pairs++;
        }
    }

    cout << consistent_pairs << '\n';
}

// Set to true for old USACO (file I/O), false for modern problems (stdin/stdout)
constexpr bool USE_FILE_IO = true;
constexpr auto FILENAME = "gymnastics";

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
