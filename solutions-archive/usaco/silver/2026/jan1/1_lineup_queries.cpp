#include <bits/stdc++.h>
using namespace std;

void solve_1(long long c, long long t) {
    long long now = c * 2 - 1; // Cow spawns at time t = c, moves first time at t = c * 2
    long long pos = c; // Cow spawns as position x = c
    while (now < t) {
        if (pos > 0) {
            long long dt = min(pos, t - now);
            now += dt;
            pos -= dt;
        } else {
            now++;
            pos = now / 2;
        }
    }
    cout << pos << '\n';
}

// At time t, target cow is at x. Cow is in "static" when larger than m=t/2. if not, still in shift cycle.
void solve_2(long long x, long long t) {
    while (x <= t/2) {
        if (t % 2 == 0) {
            x = (x + 1) % (t / 2 + 1);
            t--;
        } else {
            long long double_step_times = (t / 2 - x) / 3; // Every double step x += 2 and t -= 2, and don't let it jump back to pos 0
            if (double_step_times > 0) {
                x += double_step_times * 2;
                t -= double_step_times * 2;
            } else {
                // Either jump back or enter static zone
                x = (x + 1) % (t / 2 + 1);
                t--;
            }
        }
    }
    cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        long long arg1, arg2;
        cin >> type >> arg1 >> arg2;
        if (type == 1) {
            solve_1(arg1, arg2);
        } else {
            solve_2(arg1, arg2);
        }
    }


    return 0;
}
