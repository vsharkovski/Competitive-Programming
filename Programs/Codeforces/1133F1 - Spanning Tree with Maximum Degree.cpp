#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




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

int n, m;
vector<vector<int>> G;
int bestsrc;
vector<pair<int, int>> edges;

void Main() {
    cin >> n >> m;
    G.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bestsrc = 1;
    for (int i = 1; i <= n; ++i) {
        if (G[i].size() > G[bestsrc].size()) {
            bestsrc = i;
        }
    }
    DSU dsu(n+1);
    for (int v : G[bestsrc]) {
        edges.emplace_back(bestsrc, v);
        dsu.unite(bestsrc, v);
    }
    for (int u = 1; u <= n; ++u) {
        for (int v : G[u]) {
            if (dsu.unite(u, v)) {
                edges.emplace_back(u, v);
            }
        }
    }
    for (auto& e : edges) {
        cout << e.first << ' ' << e.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
//        freopen("optmilk.in", "r", stdin);
//        freopen("optmilk.out", "w", stdout);
    #endif
    Main();
    return 0;
}
