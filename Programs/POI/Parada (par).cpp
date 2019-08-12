#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int maxn = 200010;

int n, ans;
vector<int> adj[maxn];

int val[maxn];
int up[maxn];
int down[maxn][2];

void dfs_down(int u, int p) {
    down[u][0] = -inf;
    down[u][1] = -inf;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_down(v, u);
            int x = max(val[v], val[v] + down[v][0]);
            if (x >= down[u][0]) {
                down[u][1] = down[u][0];
                down[u][0] = x;
            } else if (x > down[u][1]) {
                down[u][1] = x;
            }
        }
    }
}

void dfs_up(int u, int p) {
    up[u] = -inf;
    if (p != -1) {
        up[u] = max(up[u], val[p] + up[p]);
        if (down[p][0] == val[u] || down[p][0] == val[u] + down[u][0]) {
            up[u] = max(up[u], val[p] + down[p][1]);
        } else {
            up[u] = max(up[u], val[p] + down[p][0]);
        }
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs_up(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        val[i] = -2;
    }
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        ++val[a];
        ++val[b];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_down(1, -1);
    dfs_up(1, -1);
    ans = -2*inf;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, val[i] + up[i]);
        ans = max(ans, val[i] + down[i][0]);
        ans = max(ans, val[i] + down[i][0] + up[i]);
        ans = max(ans, val[i] + down[i][0] + down[i][1]);
    }
    cout << 2 + ans << endl;
}
