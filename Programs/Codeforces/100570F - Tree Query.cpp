#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100010;

int n, q;
vector<pii> adj[maxn];

bool removed[maxn];
int sbsz[maxn];
int centroid_parent[maxn];

unordered_map<int, int> panc_id[maxn];
unordered_map<int, ll> dist[maxn];
vector<ll> data[maxn];
vector<vector<ll>> data_c[maxn];

void dfs(int u, int p, ll d, int panc, unordered_map<int, int>& pmp,
    unordered_map<int, ll>& distmp, vector<ll>& vec1, vector<ll>& vec2) {
    pmp[u] = panc;
    distmp[u] = d;
    vec1.push_back(d);
    vec2.push_back(d);
    for (auto &to : adj[u]) {
        int v = to.first, w = to.second;
        if (v != p && !removed[v]) {
            dfs(v, u, d+w, panc, pmp, distmp, vec1, vec2);
        }
    }
}

void solve_rooted(int root) {
    int pid = 0;
    data[root].push_back(0);
    for (auto &to : adj[root]) {
        int v = to.first, w = to.second;
        if (!removed[v]) {
            data_c[root].push_back(vector<ll>());
            dfs(v, root, w, pid, panc_id[root], dist[root], data[root], data_c[root].back());
            sort(data_c[root].back().begin(), data_c[root].back().end());
            ++pid;
        }
    }
    sort(data[root].begin(), data[root].end());
}

inline ll getcnt(vector<ll> &v, ll d) {
    // #x, x <= d
    return distance(v.begin(), upper_bound(v.begin(), v.end(), d));
}

void dfssbsz(int u, int p) {
    sbsz[u] = 1;
    for (auto &to : adj[u]) {
        if (to.first != p && !removed[to.first]) {
            dfssbsz(to.first, u);
            sbsz[u] += sbsz[to.first];
        }
    }
}

int findcentroid(int u, int p, int n) {
    for (auto &to : adj[u]) {
        if (to.first != p && !removed[to.first] && sbsz[to.first] >= n/2) {
            return findcentroid(to.first, u, n);
        }
    }
    return u;
}

void decompose(int root, int parent) {
    dfssbsz(root, -1);
    int centroid = findcentroid(root, -1, sbsz[root]);
    centroid_parent[centroid] = parent;
    solve_rooted(centroid);
    removed[centroid] = true;
    for (auto & to : adj[centroid]) {
        if (!removed[to.first]) {
            decompose(to.first, centroid);
        }
    }
    removed[centroid] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n-1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    decompose(1, -1);
    while (q--) {
        int v;
        ll l;
        cin >> v >> l;
        int root = v;
        ll ans = 0;
        do {
            if (root == v) {
                ans += getcnt(data[root], l);
            } else {
                ll want_dist = l - dist[root][v];
                ans += getcnt(data[root], want_dist) - getcnt(data_c[root][panc_id[root][v]], want_dist);
            }
            root = centroid_parent[root];
        } while (root != -1);
        cout << ans << endl;
    }
}
