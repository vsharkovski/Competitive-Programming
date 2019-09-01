#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const ll inf = 1e14;
const int maxn = 200010;
 
int n;
ll S[maxn], P[maxn];
 
struct segtree {
    ll tree[4*maxn];
    ll lazy[4*maxn];
    inline void merge(int v) {
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
    inline void push(int v) {
        tree[2*v] += lazy[v];
        lazy[2*v] += lazy[v];
        tree[2*v+1] += lazy[v];
        lazy[2*v+1] += lazy[v];
        lazy[v] = 0;
    }
    void build() {
        for (int i = 0; i < 4*maxn; ++i) {
            tree[i] = inf;
            lazy[i] = 0;
        }
        build(1, 1, n);
    }
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = S[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(2*v, tl, tm);
            build(2*v+1, tm+1, tr);
            merge(v);
        }
    }
    void update(int v, int tl, int tr, int l, int r, ll val) {
        if (l > r) return;
        if (l <= tl && tr <= r) {
            // cerr << "added " << val << " to [" << l << ", " << r << "]\n";
            tree[v] += val;
            lazy[v] += val;
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm), val);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        merge(v);
    }
    int find0(int v, int tl, int tr) {
        if (tl == tr) return tl;
        push(v);
        int tm = (tl + tr) / 2;
        if (tree[2*v+1] == 0) {
            return find0(2*v+1, tm+1, tr);
        } else {
            return find0(2*v, tl, tm);
        }
    }
} tree;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> S[i];
    }
    tree.build();
    for (ll step = 1; step <= n; ++step) {
        int i = tree.find0(1, 1, n);
        tree.update(1, 1, n, i, i, inf - step);
        tree.update(1, 1, n, i+1, n, -step); 
        P[i] = step;
    }
    for (int i = 1; i <= n; ++i) {
        cout << P[i] << ' ';
    }
    cout << '\n';
}
