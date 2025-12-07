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

void solve() {
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
