#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int n, m;
vector<int> adj[maxn];

int timer;
int tin[maxn]; // time entered in dfs
int low[maxn]; // min{tin[u], tin[p] (u-p is back edge), low[v] (u-v is tree edge)}

void artpb(int u, int p) {
    tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) {
            // parent
            continue;
        } else if (tin[v] != -1) {
            // back edge
            low[u] = min(low[u], tin[v]);
        } else {
            // tree edge
            ++children;
            artpb(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) {
                // u is articulation point
                cout << "cut point: " << u << endl;
            }
            if (low[v] > tin[u]) {
                // (u, v) is articulation bridge
                cout << "bridge: " << u << "-" << v << endl;
            }
        }
    }
    if (p == -1 && children > 1) {
        // u (root) is also articulation point
        cout << "cut point: " << u << endl;
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
    timer = 0;
    memset(tin, -1, sizeof(tin));
    artpb(1, -1);
}
