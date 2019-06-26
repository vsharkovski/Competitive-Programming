#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const ll inf = 1e18;
const int maxn = 2e5 + 5;

int n;
vector<int> adj[maxn]; // graph, original labels
int a[maxn]; // value, original labels
int label[maxn]; // new label of node after dfs traversal
int stsz[maxn]; // subtree size (new)
ll stsum[maxn]; // subtree sum (new)
static ll tree[4*maxn];
ll ans;

void dfs(int u, int p) {
    static int counter = 0;
    int unew = counter;
    label[u] = unew;
    stsz[unew] = 1;
    stsum[unew] = a[u];
    for (int v : adj[u]) {
        if (v != p) {
            ++counter;
            dfs(v, u);
            int vnew = label[v];
            stsz[unew] += stsz[vnew];
            stsum[unew] += stsum[vnew];
        }
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = stsum[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
}

void update(int v, int tl, int tr, int nd, ll val) {
    if (tl == tr) {
        tree[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (nd <= tm) {
            update(2*v, tl, tm, nd, val);
        } else {
            update(2*v+1, tm+1, tr, nd, val);
        }
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
}

ll getmax(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return -inf;
    }
    if (l <= tl && tr <= r) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return max(getmax(2*v, tl, tm, l, min(r, tm)),
               getmax(2*v+1, tm+1, tr, max(l, tm+1), r));
}

void dfs2(int u, int p) {
    int unew = label[u];
    update(1, 0, n-1, unew, -inf);
    ans = max(ans, stsum[unew] + max(getmax(1, 0, n-1, 0, unew-1),
                                     getmax(1, 0, n-1, unew+stsz[unew], n-1)));
    for (int v : adj[u]) {
        if (v != p) {
            dfs2(v, u);
        }
    }
    update(1, 0, n-1, unew, stsum[unew]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = -inf;

    dfs(0, -1);
    build(1, 0, n-1);
    dfs2(0, -1);

    if (ans < ll(maxn)*ll(-1e9)) {
        cout << "Impossible\n";
    } else {
        cout << ans << "\n";
    }

}
