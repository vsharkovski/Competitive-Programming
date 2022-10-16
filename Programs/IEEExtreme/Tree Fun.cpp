#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 100010;
const int M = 100010;
const int LOGN = 17;

int n, m;
vector<int> adj[N];
int value[N];
vector<int> nodesAtDepth[N];

// LCA computations
int depth[N];
int parent[LOGN][N];

void dfs(int node, int par) {
    for (int to : adj[node]) {
        if (to != par) {
            parent[0][to] = node;
            depth[to] = depth[node] + 1;
            dfs(to, node);
        }
    }
}

void calcLCAdata() {
    memset(parent, -1, sizeof(parent));
    depth[0] = 0;
    dfs(0, -1);
    for (int k = 1; k < LOGN; ++k) {
        for (int u = 0; u < n; ++u) {
            if (parent[k-1][u] != -1) {
                parent[k][u] = parent[k-1][ parent[k-1][u] ];
            }
        }
    }
}

int getLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int jump = LOGN-1; jump >= 0; --jump) {
        if (depth[u] - (1 << jump) >= depth[v]) {
            u = parent[jump][u];
        }
    }
    if (u == v) return u;
    for (int jump = LOGN-1; jump >= 0; --jump) {
        if (parent[jump][u] != parent[jump][v]) {
            u = parent[jump][u];
            v = parent[jump][v];
        }
    }
    return parent[0][u];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        value[i] = 0;
    }
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calcLCAdata();
    for (int i = 0; i < n; ++i) {
        nodesAtDepth[depth[i]].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        int lca = getLCA(u, v);
        int lcaParent = parent[0][lca];
        // depth[u] <= depth[v]
        if (lca == v) {
            // path is u, p[u], p[p[u]], ..., v
            value[u] += k;
            if (lcaParent != -1) {
                value[lcaParent] -= k;
            }
        } else {
            // path from both u and v to lca
            value[u] += k;
            value[v] += k;
            value[lca] -= k;
            if (lcaParent != -1) {
                value[lcaParent] -= k;
            }
        }
    }
    int ans = 0;
    for (int d = n-1; d >= 0; --d) {
        for (int u : nodesAtDepth[d]) {
            ans = max(ans, value[u]);
            int p = parent[0][u];
            if (p != -1) {
                value[p] += value[u];
            }
        }
    }
    cout << ans << endl;
}
