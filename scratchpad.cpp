#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        vec.push_back(val);
    }
    sort(vec.begin(), vec.end());
    int current_val = 0;
    int total_diffs = 0;
    for (int val : vec) {
        if (val != current_val) {
            current_val = val;
            total_diffs++;
        }
    }
    cout << total_diffs << '\n';
}
