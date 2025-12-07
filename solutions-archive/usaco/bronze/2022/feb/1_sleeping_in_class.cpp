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
    int n;
    cin >> n; // Number of periods
    vi sleep_counts(n);
    for (int i = 0; i < n; i++) {
        int sleep_count;
        cin >> sleep_count;
        sleep_counts[i] = sleep_count;
    }

    // Total sleep count
    const int total_sleep_count = accumulate(sleep_counts.begin(), sleep_counts.end(), 0);
    if (total_sleep_count == 0) {
        cout << "0" << '\n';
        return;
    }

    // Factors of the sum
    vi factors;
    for (int i = 1; i * i <= total_sleep_count; i++) {
        if (total_sleep_count % i == 0) {
            factors.push_back(i);
            if (i * i != total_sleep_count) { factors.push_back(total_sleep_count / i); }
        }
    }
    sort(factors.begin(), factors.end()); // Sort from smallest to largest

    for (const auto &factor: factors) {
        int running_sum = 0;
        int merges = 0;
        for (int i = n - 1; i >= 0; i--) {
            running_sum += sleep_counts[i];
            if (running_sum < factor) {
                merges++;
            }
            if (running_sum == factor) {
                running_sum = 0;
            } else if (running_sum > factor) {
                break;
            }
        }
        if (running_sum == 0) {
            cout << merges << '\n';
            return;
        }
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
    cin >> t; // Multiple test cases
    while (t--) { solve(); }

    return 0;
}
