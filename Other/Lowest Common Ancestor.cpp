#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const int maxlog = 17;

int n;
vector<int> adj[maxn];

int depth[maxn];
int P[maxn][maxlog];

void dfs(int u) {
    for (int v : adj[u]) {
        if (P[v][0] == -1) {
            P[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

void preprocessLCA() {
    for (int j = 0; j < maxlog; ++j) {
        for (int i = 1; i <= n; ++i) {
            P[i][j] = -1;
        }
    }
    depth[1] = 0;
    dfs(1);
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int j = maxlog-1; j >= 0; --j) {
        if (depth[a] - (1 << j) >= depth[b]) {
            a = P[a][j];
        }
    }
    if (a == b) return a;
    for (int j = maxlog-1; j >= 0; --j) {
        if (P[a][j] != -1 && P[a][j] != P[b][j]) {
            a = P[a][j];
            b = P[b][j];
        }
    }
    return P[a][0];
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    preprocessLCA();
    while (true) {
        cout << "Enter 2 numbers" << endl;
        int a, b;
        cin >> a >> b;
        cout << "LCA(" << a << ", " << b << ") = " << LCA(a, b) << endl;
    }
}
