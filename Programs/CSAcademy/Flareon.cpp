#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 200010;
const int maxm = 500010;

int n, m;
vector<int> adj[maxn];
vector<int> monsters[maxn]; // powers of monsters at each node
ll dmg[maxn];

bool removed[maxn];
int sbsz[maxn];

void dfs_data(int u, int p, int d, vector<int> &data) {
    for (int power : monsters[u]) {
        data.push_back(power - d);
    }
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            dfs_data(v, u, d+1, data);
        }
    }
}

void make_suf(vector<int> &data, vector<ll> &suf) {
    sort(data.begin(), data.end());
    suf.resize(data.size());
    for (int i = data.size() - 1; i >= 0; --i) {
        suf[i] = data[i];
        if (i+1 < (int)data.size()) {
            suf[i] += suf[i+1];
        }
    }
}

inline ll get_sum(int d, vector<int> &data, vector<ll> &suf) {
    // data[i] - d > 0
    // ==> data[i+1] - d > 0
    // data[i] > d
    int sz = data.size();
    int i = distance(data.begin(), upper_bound(data.begin(), data.end(), d));
    return (i == sz ? 0 : suf[i]) - (ll)d * (sz-i);
}

void dfs_dmg(int u, int par, int dep, vector<int> &rd, vector<ll> &rs, vector<int> &cd, vector<ll> &cs) {
    dmg[u] += get_sum(dep, rd, rs) - get_sum(dep, cd, cs);
    for (int v : adj[u]) {
        if (v != par && !removed[v]) {
            dfs_dmg(v, u, dep+1, rd, rs, cd, cs);
        }
    }
}

void solve_rooted(int root) {
    vector<int> root_data;
    vector<ll> root_suf;
    dfs_data(root, -1, 0, root_data);
    make_suf(root_data, root_suf);
    dmg[root] += get_sum(0, root_data, root_suf);
    for (int v : adj[root]) {
        if (!removed[v]) {
            vector<int> child_data;
            vector<ll> child_suf;
            dfs_data(v, root, 1, child_data);
            make_suf(child_data, child_suf);
            dfs_dmg(v, root, 1, root_data, root_suf, child_data, child_suf);
        }
    }
}

void dfs_sbsz(int u, int p) {
    sbsz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            dfs_sbsz(v, u);
            sbsz[u] += sbsz[v];
        }
    }
}

int find_centroid(int u, int p, int n) {
    for (int v : adj[u]) {
        if (v != p && !removed[v] && sbsz[v] > n/2) {
            return find_centroid(v, u, n);
        }
    }
    return u;
}

void decompose(int root) {
    dfs_sbsz(root, -1);
    int centroid = find_centroid(root, -1, sbsz[root]);
    solve_rooted(centroid);
    removed[centroid] = true;
    for (int v : adj[centroid]) {
        if (!removed[v]) {
            decompose(v);
        }
    }
    removed[centroid] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int j;
        cin >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        int pos, power;
        cin >> pos >> power;
        monsters[pos].push_back(power);
    }
    fill(dmg, dmg+n+1, 0);
    memset(removed, false, sizeof(removed));
    decompose(1);
    for (int i = 1; i <= n; ++i) {
        cout << dmg[i] << '\n';
    }
}
