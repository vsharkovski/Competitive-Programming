#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int maxn = 500010;

int n, m;
vector<int> adj[maxn];

int timer;
int tin[maxn], low[maxn];
vector<pii> stk;

vector<int> adj2[maxn];

void bcc_solve(int fnd1, int fnd2) {
    vector<int> nodes;
    cout << "BCC: ";
    while (true) {
        int u = stk.back().first, v = stk.back().second;
        cout << u << "-" << v << " ";
        nodes.push_back(u);
        nodes.push_back(v);
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        stk.pop_back();
        if (stk.empty() || (u == fnd1 && v == fnd2)) {
            break;
        }
    }
    cout << endl;
    // do stuff
    // note: "nodes" have duplicates
    // ...
    while (!nodes.empty()) {
        adj2[nodes.back()].clear();
        nodes.pop_back();
    }
}

void bcc_dfs(int u, int p) {
    tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (tin[v] == -1) {
            // tree edge
            ++children;
            stk.emplace_back(u, v);
            bcc_dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u]) {
                bcc_solve(u, v);
            }
        } else if (v != p) {
            // back edge
            // low[u] = min(low[u], tin[v]);
            if (tin[v] < low[u]) {
                low[u] = tin[v];
                stk.emplace_back(u, v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(tin, -1, sizeof(tin));
    bcc_dfs(1, -1);
}
