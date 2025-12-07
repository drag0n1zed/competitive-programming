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
    int n, m;
    cin >> n >> m; // Amount of spotty/plain cows, amount of genome positions per cow
    vector spotty_genomes(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> spotty_genomes[i][j];
        }
    }
    vector plain_genomes(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plain_genomes[i][j];
        }
    }

    int explain_pos = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                bool explains_spottiness = true;

                set<string> spotty_strings;
                string genome_maker;
                for (int cow_index = 0; cow_index < n; cow_index++) {
                    genome_maker.clear();
                    genome_maker += spotty_genomes[cow_index][i];
                    genome_maker += spotty_genomes[cow_index][j];
                    genome_maker += spotty_genomes[cow_index][k];
                    spotty_strings.insert(genome_maker);
                }

                for (int cow_index = 0; cow_index < n; cow_index++) {
                    genome_maker.clear();
                    genome_maker += plain_genomes[cow_index][i];
                    genome_maker += plain_genomes[cow_index][j];
                    genome_maker += plain_genomes[cow_index][k];
                    if (spotty_strings.find(genome_maker) != spotty_strings.end()) {
                        explains_spottiness = false;
                        break;
                    }
                }
                if (explains_spottiness) explain_pos++;
            }
        }
    }
    cout << explain_pos << '\n';
}

// Set to true for old USACO (file I/O), false for modern problems (stdin/stdout)
constexpr bool USE_FILE_IO = true;
constexpr string_view FILENAME = "cownomics";

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
