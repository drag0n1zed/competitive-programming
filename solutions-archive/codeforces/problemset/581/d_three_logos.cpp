// C++17
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct Rect {
    int w, h;
    char c;
    int size;
    bool operator<(const Rect &other) const { return c < other.c; }
};

void print(char c, int num, bool newline) {
    for (int i = 0; i < num; i++) {
        cout << c;
    }
    if (newline) {
        cout << '\n';
    }
}

void solve() {
    Rect rects[3];
    uint64_t total_size = 0;
    for (int i = 0; i < 3; i++) {
        cin >> rects[i].w >> rects[i].h;
        rects[i].c = 'A' + i;
        total_size += rects[i].w * rects[i].h;
    }

    // side length
    int s = sqrt(total_size);
    if ((uint64_t)s * s != total_size) {
        cout << "-1\n";
        return;
    }

    sort(begin(rects), end(rects)); // just in case

    do {
        for (int i = 0; i < 8; ++i) {
            if (i & 1) {
                swap(rects[0].h, rects[0].w);
            }
            if (i & 2) {
                swap(rects[1].h, rects[1].w);
            }
            if (i & 4) {
                swap(rects[2].h, rects[2].w);
            }

            // three stripes
            if (rects[0].w == s && rects[1].w == s && rects[2].w == s && rects[0].h + rects[1].h + rects[2].h == s) {
                cout << s << '\n';
                for (Rect rect : rects) {
                    for (int line = 0; line < rect.h; ++line) {
                        print(rect.c, s, true);
                    }
                }
                return;
            }

            // 1 + 2
            if (rects[0].w == s && rects[1].w + rects[2].w == s && rects[1].h == rects[2].h &&
                rects[0].h + rects[1].h == s) {
                cout << s << '\n';
                for (int line = 0; line < rects[0].h; ++line) {
                    print(rects[0].c, s, true);
                }
                for (int line = 0; line < rects[1].h; ++line) {
                    print(rects[1].c, rects[1].w, false);
                    print(rects[2].c, rects[2].w, true);
                }
                return;
            }

            if (i & 1) {
                swap(rects[0].h, rects[0].w);
            }
            if (i & 2) {
                swap(rects[1].h, rects[1].w);
            }
            if (i & 4) {
                swap(rects[2].h, rects[2].w);
            }
        }
    } while (next_permutation(begin(rects), end(rects)));
    cout << "-1\n";
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
