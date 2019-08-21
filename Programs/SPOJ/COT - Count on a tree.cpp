#include <bits/stdc++.h>
using namespace std;

const int maxq = 100010;
const int maxn = 100010;
const int maxlog = 17;

vector<int> dist_values, old_id;
unordered_map<int, int> new_id;

int n, q;
int val[maxn];
vector<int> adj[maxn];

int depth[maxn];
int P[maxn][maxlog];

struct PersistentTree {
    struct node {
        node *l, *r;
        int cnt;
        node(node *l, node *r) : l(l), r(r), cnt(0) {
            if (l) cnt += l->cnt;
            if (r) cnt += r->cnt;
        }
        node(int cnt) : l(nullptr), r(nullptr), cnt(cnt) {}
    };
    node* roots[maxn];
    node* build(int tl, int tr) {
        if (tl == tr) return new node(0);
        int tm = (tl + tr) / 2;
        return new node(build(tl, tm), build(tm+1, tr));
    }
    node* update(node *v, int tl, int tr, int pos, int val) {
        if (tl == tr) return new node(v->cnt + val);
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return new node(update(v->l, tl, tm, pos, val), v->r);
        } else {
            return new node(v->l, update(v->r, tm+1, tr, pos, val));
        }
    }
    int query(node *v1, node *v2, node *lca, node *plca, int tl, int tr, int k) {
        while (tl < tr) {
            int tm = (tl + tr) / 2;
            int lcnt = v1->l->cnt + v2->l->cnt - lca->l->cnt - plca->l->cnt;
            if (k <= lcnt) {
                v1 = v1->l;
                v2 = v2->l;
                lca = lca->l;
                plca = plca->l;
                tr = tm;
            } else {
                v1 = v1->r;
                v2 = v2->r;
                lca = lca->r;
                plca = plca->r;
                tl = tm+1;
                k = k - lcnt;
            }
        }
        return tl;
    }
} tree;

void dfs(int u) {
    for (int v : adj[u]) {
        if (v != P[u][0]) {
            P[v][0] = u;
            depth[v] = depth[u] + 1;
            tree.roots[v] = tree.update(tree.roots[u], 0, n-1, val[v], 1);
            dfs(v);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int j = maxlog-1; j >= 0; --j) {
        if (depth[a] - (1<<j) >= depth[b]) {
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
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        dist_values.push_back(val[i]);
    }
    sort(dist_values.begin(), dist_values.end());
    for (int i = 0; i < n; ++i) {
        if (i == 0 || dist_values[i] != dist_values[i-1]) {
            new_id[dist_values[i]] = old_id.size();
            old_id.push_back(dist_values[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        val[i] = new_id[val[i]];
    }
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 1; i <= n; ++i) {
            P[i][j] = -1;
        }
    }
    tree.roots[0] = tree.build(0, n-1);
    tree.roots[1] = tree.update(tree.roots[0], 0, n-1, val[1], 1);
    depth[1] = 0;
    P[1][0] = -1;
    dfs(1);
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[ P[i][j-1] ][j-1];
            }
        }
    }
    P[1][0] = 0;
    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;
        int lca = LCA(u, v);
        int plca = P[lca][0];
        int id = tree.query(tree.roots[u], tree.roots[v],
                            tree.roots[lca], tree.roots[plca],
                            0, n-1, k);
        cout << old_id[id] << '\n';
    }   
}
