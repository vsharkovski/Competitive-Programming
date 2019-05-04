#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




struct DSU {
    int n;
    vector<int> p, rank, size;
    DSU(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
        size.assign(n, 1);
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        size[y] += size[x];
        if (rank[x] == rank[y]) ++rank[y];
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    DSU dsu0(n), dsu1(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x, --y;
        if (c == 0) {
            dsu0.unite(x, y);
        } else {
            dsu1.unite(x, y);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll sz0 = dsu0.size[dsu0.get(i)];
        ll sz1 = dsu1.size[dsu1.get(i)];
        ans += sz0 - 1; // in this CC
        ans += sz1 - 1; // in this CC
        ans += (sz0 - 1) * (sz1 - 1);
    }
    cout << ans << '\n';
}
