#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



// unite all characters that must be the same
// so the condition that all k-length substrings
// are palindromes is fulfilled
// answer = m ** (groups)

struct DSU {
    int n;
    vector<int> p, rank;
    DSU(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                ++rank[y];
            }
        }
        return true;
    }
};

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    DSU dsu(n);
    int groups = n;

    for (int i = 0; i+k-1 < n; ++i) {
        for (int L = i, R = i+k-1; L < R; ++L, --R) {
            if (dsu.unite(L, R)) {
                --groups;
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < groups; ++i) {
        ans = (ll(ans) * m) % mod;
    }

    cout << ans << '\n';

}
