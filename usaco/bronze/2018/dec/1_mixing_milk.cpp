#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

// Set to true for modern problems (stdin/stdout), false for old USACO (file I/O).
constexpr bool IS_MODERN = false;
const string FILENAME = "mixmilk";

void setup_io() {
#ifndef LOCAL
    if (!IS_MODERN) {
        freopen((FILENAME + ".in").c_str(), "r", stdin);
        freopen((FILENAME + ".out").c_str(), "w", stdout);
    }
#endif
}

struct Bucket {
    int capacity;
    int milk;
};

void pour(Bucket &from, Bucket &to) {
    int amount_to_pour = min(from.milk, to.capacity - to.milk);
    from.milk -= amount_to_pour;
    to.milk += amount_to_pour;
}

void solve() {
    // Store input
    constexpr int N = 3;
    vector<Bucket> buckets;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        buckets.push_back({a, b});
    }

    // Repeat 100 times
    for (int i = 0; i < 100; ++i) {
        Bucket &from = buckets[i % N];
        Bucket &to = buckets[(i + 1) % N];
        int amount_to_pour = min(from.milk, to.capacity - to.milk);
        from.milk -= amount_to_pour;
        to.milk += amount_to_pour;
    }

    // Output
    for (Bucket b : buckets) {
        cout << b.milk << '\n';
    }
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
