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
constexpr auto FILENAME = "blocks";

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
    int n;
    cin >> n;
    // Initialize a vector with length 0..25 (0 -> A, 1 -> B, etc)
    vector<int> final_alphabets_count(26);

    // Input
    for (int i = 0; i < n; i++) {
        string word1, word2;
        cin >> word1 >> word2;
        // Count which letters are required to construct the two words of each board
        vector<int> count1(26);
        vector<int> count2(26);
        for (const auto c: word1) {
            count1[c - 'a']++;
        }
        for (const auto c: word2) {
            count2[c - 'a']++;
        }
        // Add maximum character usage for the two words into the final alphabet count
        for (int j=0; j<26; j++) {
            final_alphabets_count[j] += max(count1[j], count2[j]);
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << final_alphabets_count[i] << '\n';
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
