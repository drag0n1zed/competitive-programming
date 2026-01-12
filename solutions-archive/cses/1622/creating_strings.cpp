// C++17
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> results;
    do {
        results.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << results.size() << '\n';
    for (const auto &result : results) {
        cout << result << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen(("NAME.in"), "r", stdin);
    // freopen(("NAME.out"), "w", stdout);

    int t = 1;
    // cin >> t; // Multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}
