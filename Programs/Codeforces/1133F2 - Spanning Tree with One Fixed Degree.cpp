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

int n, m, d;
vector<vector<int>> G;
vector<pair<int, int>> edges;
vector<int> visited;
vector<vector<int>> CCs;

void dfs(int u) {
    visited[u] = 1;
    CCs.back().push_back(u);
    for (int v : G[u]) {
        if (visited[v] == 0 && v != 1) {
            dfs(v);
        }
    }
}

void Main() {
    cin >> n >> m >> d;
    G.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (G[1].size() < d) {
        cout << "NO\n";
        return;
    }
    for (int u = 1; u <= n; ++u) {
        sort(G[u].begin(), G[u].end());
    }
    visited.assign(n+1, 0);
    for (int u = 2; u <= n; ++u) {
        if (visited[u] == 0) {
            CCs.push_back(vector<int>());
            dfs(u);
        }
    }
    if (CCs.size() > d) {
        cout << "NO\n";
        return;
    }
    DSU dsu(n+1);
    for (auto& cc : CCs) {
        for (int v : cc) {
            if (binary_search(G[1].begin(), G[1].end(), v)) {
                edges.emplace_back(1, v);
                dsu.unite(1, v);
                --d;
                break;
            }
        }
    }
    int i = 0;
    while (d > 0) {
        int v = G[1][i];
        if (dsu.unite(1, v)) {
            edges.emplace_back(1, v);
            --d;
        }
        ++i;
    }
    for (int u = 2; u <= n; ++u) {
        for (int v : G[u]) {
            if (v != 1 && dsu.unite(u, v)) {
                edges.emplace_back(u, v);
            }
        }
    }
    if (edges.size() != n-1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto& e : edges) {
        cout << e.first << ' ' << e.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
