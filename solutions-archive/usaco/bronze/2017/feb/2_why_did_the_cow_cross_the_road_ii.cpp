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
    // 1. Start with letter A.
    // 2. Iterate around the circle. Count the number of times every non-'A' letter appears until the second A.
    // 3. If a letter appears only once, then it crossed paths with the A cow.
    // 4. If a letter does not appear or appears twice, then it does not cross paths with the A cow.
    // 5. Add to a global constant.
    // 6. When all letters are counted, divide the final count by 2 to make up for the fact that each is counted twice.

    char input[52];
    cin >> input;
    int paths_crossed = 0;
    for (char current_char = 'A'; current_char <= 'Z'; current_char++) {
        int i = 0;
        while (input[i] != current_char) {
            i++;
            i %= 52;
        }
        int character_count[26] = {0};
        i++;
        while (input[i] != current_char) {
            character_count[input[i] - 'A']++;
            i++;
            i %= 52;
        }

        for (const auto count:character_count) {
            if (count == 1) {
                paths_crossed++;
            }
        }
    }
    paths_crossed /= 2;

    cout << paths_crossed << '\n';
}

// Set to true for old USACO (file I/O), false for modern problems (stdin/stdout)
constexpr bool USE_FILE_IO = true;
constexpr string_view FILENAME = "circlecross";

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
