// C++17
#include <bits/stdc++.h>
using namespace std;

int result;
bool row_taken[8] = {};
bool main_diag_taken[15] = {};
bool anti_diag_taken[15] = {};
bool reserved[8][8] = {};

void recurse(int col) {
    if (col == 8) {
        result++;
        return;
    }
    for (int row = 0; row < 8; row++) {
        if (row_taken[row] || main_diag_taken[col - row + 7] || anti_diag_taken[col + row] ||
            reserved[col][row] == true) {
            continue;
        }

        row_taken[row] = main_diag_taken[col - row + 7] = anti_diag_taken[col + row] = true;

        recurse(col + 1);

        row_taken[row] = main_diag_taken[col - row + 7] = anti_diag_taken[col + row] = false;
    }
}

void solve() {
    char c;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> c;
            reserved[i][j] = c == '*';
        }
    }
    recurse(0);
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen(("NAME.in"), "r", stdin);
    // freopen(("NAME.out"), "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
