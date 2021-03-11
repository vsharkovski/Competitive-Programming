#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 200100;

struct DSU {
    int n;
    int p[N], rank[N], size[N];
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            rank[i] = 1;
            size[i] = 1;
        }
    }
    inline int get(int u) {
        return p[u] == u ? u : (p[u] = get(p[u]));
    }
    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        p[y] = x;
        size[x] += size[y];
        if (rank[x] == rank[y]) ++rank[x];
        return true;
    }
} dsu;

int n, oe, se;
pii edges[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> oe;
    dsu.init(n);
    for (int i = 0; i < oe; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        dsu.unite(a, b);
        edges[i] = make_pair(a, b);
    }
    cin >> se;
    for (int i = 0; i < se; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        edges[oe+i] = make_pair(a, b);
    }
    for (int i = 0; i < n; ++i) {
        res[i] = dsu.size[dsu.get(i)] - 1;
    }
    for (int i = 0; i < oe+se; ++i) {
        int a = edges[i].first;
        int b = edges[i].second;
        if (dsu.get(a) == dsu.get(b)) {
            res[a] -= 1;
            res[b] -= 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << '\n';
    }
}
