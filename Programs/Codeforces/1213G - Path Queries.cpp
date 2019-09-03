#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct DSU {
    vector<int> p, rank, size;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
        size.assign(n, 1);
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    inline bool unite(int x, int y, ll& ans) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        p[y] = x;
        ans -= (ll)size[x] * (size[x]-1) / 2;
        ans -= (ll)size[y] * (size[y]-1) / 2;
        size[x] += size[y];
        ans += (ll)size[x] * (size[x]-1) / 2;
        return true;
    }
};

const int maxw = 200010;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    static vector<pii> edges[maxw];
    for (int i = 0; i < n-1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        edges[w].emplace_back(a, b);
    }
    DSU dsu(n);
    static ll ans[maxw];
    ans[0] = 0;
    for (int i = 1; i < maxw; ++i) {
        ans[i] = ans[i-1];
        for (auto &e : edges[i]) {
            dsu.unite(e.first, e.second, ans[i]);
        }
    }
    while (q--) {
        int i;
        cin >> i;
        cout << ans[i] << ' ';
    }
}
