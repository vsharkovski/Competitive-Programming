/*
https://szkopul.edu.pl/problemset/problem/Mk-9GNDtSal6h_8T4n9Ezq9M/site/?key=statement
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100;
const int maxd = 51;
int mod;

inline int add(int a, int b) {
    int res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

inline int subt(int a, int b) {
    int res = a - b;
    if (res < 0) res += mod;
    return res;
}

inline int mult(int a, int b) {
    return ((long long)a * b) % mod;
}

int n, m;
vector<int> out[maxn], in[maxn];

// any[d][s][t] = # of paths from s to t with length d
// can touch any node multiple times
int any[maxd][maxn][maxn];

// good[d][s][t] = # of paths from s to t with length d
// can touch s and t only once (start and end)
int good[maxd][maxn][maxn];

// forbidden[d][s][t] = # of paths from s to s with length d
// can't touch s (except start and end), can't touch t ever
int forb[maxd][maxn][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> mod;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        out[a].push_back(b);
        in[b].push_back(a);
    }
    for (int s = 0; s < n; ++s) {
        for (int t = 0; t < n; ++t) {
            any[0][s][t] = 0;
            good[0][s][t] = 0;
            forb[0][s][t] = 0;
        }
        for (int t : out[s]) {
            any[1][s][t] = 1;
            good[1][s][t] = 1;
        }
    }
    for (int d = 2; d < maxd; ++d) {
        for (int s = 0; s < n; ++s) {
            for (int t = 0; t < n; ++t) {
                any[d][s][t] = 0;
                for (int v : in[t]) {
                    any[d][s][t] = add(any[d][s][t], any[d-1][s][v]);
                }
                good[d][s][t] = any[d][s][t];
                for (int k = 0; k < d; ++k) {
                    good[d][s][t] = subt(good[d][s][t], mult(good[k][s][t], any[d-k][t][t]));
                    good[d][s][t] = subt(good[d][s][t], mult(forb[k][s][t], any[d-k][s][t]));
                }
            }
            for (int t = 0; t < n; ++t) {
                forb[d][s][t] = any[d][s][s];
                for (int k = 0; k <= d; ++k) {
                    forb[d][s][t] = subt(forb[d][s][t], mult(forb[k][s][t], any[d-k][s][s]));
                    forb[d][s][t] = subt(forb[d][s][t], mult(good[k][s][t], any[d-k][t][s]));
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        --s, --t;
        cout << good[d][s][t] << '\n';
    }
}
