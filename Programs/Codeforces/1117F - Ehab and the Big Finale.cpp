#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int ask(int type, int u) {
    if (type == 0) {
        cout << "d " << u << endl;
    } else {
        cout << "s " << u << endl;
    }
    int res;
    cin >> res;
    return res;
}

int n;
vector<int> adj[maxn];
int parent[maxn];
int depth[maxn];
int xdepth, xans;

void dfs(int u) {
    for (int v : adj[u]) {
        if (v != parent[u]) {
            depth[v] = depth[u] + 1;
            parent[v] = u;
            dfs(v);
        }
    }
}

bool removed[maxn];
int sbsz[maxn];

void dfs_sb(int u, int p) {
    sbsz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            dfs_sb(v, u);
            sbsz[u] += sbsz[v];
        }
    }
}

int find_centroid(int u, int p, int m) {
    for (int v : adj[u]) {
        if (v != p && !removed[v] && sbsz[v] > m/2) {
            return find_centroid(v, u, m);
        }
    }
    return u;
}

void decompose(int root) {
    dfs_sb(root, -1);
    int centroid = find_centroid(root, -1, sbsz[root]);
    if (sbsz[root] == 1) {
        xans = root;
        return;
    }
    int dcx = ask(0, centroid);
    if (dcx == 0) {
        xans = centroid;
        return;
    }
    removed[centroid] = true;
    if (depth[centroid] + dcx == xdepth) {
        int nxt = ask(1, centroid);
        decompose(nxt);
    } else {
        decompose(parent[centroid]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent[1] = -1;
    depth[1] = 0;
    dfs(1);
    xdepth = ask(0, 1);
    decompose(1);
    cout << "! " << xans << endl;
}
