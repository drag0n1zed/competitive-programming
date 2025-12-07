// C++17
// #pragma GCC optimize("O3,unroll-loops")
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
    int n;
    cin >> n; // Number of cows
    vi a(n), b(n); // Cow species, "vet likes this" species
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int base_matches = 0;

    for (int i = 0; i < n; i++) base_matches += a[i] == b[i]; // How many matches it has without any reversal

    // matches[k] represents the amount of [l, r] pairs that results in k cows being checked (matches)
    vi matches(n + 1, 0);

    for (int m = 0; m < n; m++) {
        // Centered at m -> Check (m, m), then (m-1, m+1), etc
        int current_matches = base_matches;
        for (int l = m, r = m; l >= 0 && r < n; l--, r++) {
            // Gain if reversal increases match count
            const int gain = (a[l] == b[r]) + (a[r] == b[l]); // How many matches it has after reversal (0, 1, 2)
            // Loss if originally increased match count
            const int loss = (a[l] == b[l]) + (a[r] == b[r]); // How many matches it has before reversal
            current_matches += gain - loss; // How many matches after reversing our pair
            matches[current_matches]++;
        }
        // Centered at m.5 -> (m, m+1), (m-1, m+2), etc
        current_matches = base_matches;
        for (int l = m, r = m + 1; l >= 0 && r < n; l--, r++) {
            const int gain = (a[l] == b[r]) + (a[r] == b[l]);
            const int loss = (a[l] == b[l]) + (a[r] == b[r]);
            current_matches += gain - loss;
            matches[current_matches]++;
        }
    }

    for (const auto &check_count: matches) {
        cout << check_count << '\n';
    }
}

// Set to true for old USACO (file I/O), false for modern problems (stdin/stdout)
constexpr bool USE_FILE_IO = false;
constexpr string_view FILENAME = "CHANGE_THIS";

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
