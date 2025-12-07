#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

// Set to true for modern problems (stdin/stdout), false for old USACO (file I/O).
constexpr bool IS_MODERN = false;
const string FILENAME = "shell";

void setup_io() {
#ifndef LOCAL
    if (!IS_MODERN) {
        freopen((FILENAME + ".in").c_str(), "r", stdin);
        freopen((FILENAME + ".out").c_str(), "w", stdout);
    }
#endif
}

void solve() {
    int n;
    cin >> n;

    // Store data first
    vector<int> swap1(n), swap2(n), guess(n);
    for (int i = 0; i < n; i++) {
        cin >> swap1[i] >> swap2[i] >> guess[i];
    }

    int max_score = 0;

    // Simulate for all 3 cases - shell started in 1, 2 or 3
    for (int start_pos = 1; start_pos <= 3; start_pos++) {
        int score = 0;
        int current_shell = start_pos;

        // Swap N times
        for (int i = 0; i < n; i++) {
            if (current_shell == swap1[i]) {
                current_shell = swap2[i];
            } else if (current_shell == swap2[i]) {
                current_shell = swap1[i];
            }
            // Add 1 to score if guess is correct
            if (current_shell == guess[i]) {
                score++;
            }
        }
        // Compare size
        max_score = max(max_score, score);
    }

    cout << max_score << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    setup_io();

    int t = 1;
    // cin >> t; // Multiple test cases
    while (t--) { solve(); }
    return 0;
}
