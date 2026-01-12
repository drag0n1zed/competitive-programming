// C++17
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

long long find_least_diff(const vector<long long> &numbers_left, int index, long long sum1, long long sum2) {
    if (index == numbers_left.size()) {
        return abs(sum1 - sum2);
    }
    long long num = numbers_left[index];
    long long diff1 = find_least_diff(numbers_left, index + 1, sum1 + num, sum2);
    long long diff2 = find_least_diff(numbers_left, index + 1, sum1, sum2 + num);
    return min(diff1, diff2);
}

void solve() {
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    cout << find_least_diff(numbers, 0, 0, 0) << '\n';
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
