#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 300005;

int n, m;
vector<int> adj[maxn];

int calls;
int num[maxn], low[maxn];
vector<pii> bridges;
unordered_set<int> hasbridge[maxn];

void dfs_bridges(int u, int p) {
    num[u] = low[u] = calls++;
    for (int v : adj[u]) {
        if (num[v] == -1) {
            dfs_bridges(v, u);
            if (low[v] > num[u]) {
                bridges.emplace_back(u, v);
                hasbridge[u].insert(v);
                hasbridge[v].insert(u);
            }
            low[u] = min(low[u], low[v]);
        } else if (v != p) {
            low[u] = min(low[u], num[v]);
        }
    }
}

int numcc;
int ccid[maxn];
vector<int> adj_cc[maxn];

void dfs_cc(int u) {
    ccid[u] = numcc;
    for (int v : adj[u]) {
        if (ccid[v] == -1 && hasbridge[u].count(v) == 0) {
            dfs_cc(v);
        }
    }
}

pii dfs_diameter(int u, int p) {
    pii res = {u, 0};
    for (int v : adj_cc[u]) {
        if (v != p) {
            pii attempt = dfs_diameter(v, u);
            if (1 + attempt.second > res.second) {
                res.first = attempt.first;
                res.second = 1 + attempt.second;
            }
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    fill(num, num+n, -1);
    calls = 0;
    for (int u = 0; u < n; ++u) {
        if (num[u] == -1) {
            dfs_bridges(u, -1);
        }
    }
    fill(ccid, ccid+n, -1);
    numcc = 0;
    for (auto& b : bridges) {
        for (int u : {b.first, b.second}) {
            if (ccid[u] == -1) {
                dfs_cc(u);
                ++numcc;
            }
        }
        int u = ccid[b.first], v = ccid[b.second];
        adj_cc[u].push_back(v);
        adj_cc[v].push_back(u);
    }
    pii res1 = dfs_diameter(0, -1);
    pii res2 = dfs_diameter(res1.first, -1);
    cout << res2.second << '\n';
}
