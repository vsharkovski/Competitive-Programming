#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 200010;
const int maxd = 9;

int n, m;
int a[maxn];

struct segtree {
    struct node {
        int ans;
        int bestnum[maxd];
        node() {
            ans = 2*inf;
            for (int i = 0; i < maxd; ++i) {
                bestnum[i] = inf;
            }
        }
        void upd_bestnum(int x) {
            int y = x;
            for (int i = 0; i < maxd; ++i) {
                if (y > 0) {
                    if (y % 10 != 0) {
                        bestnum[i] = x;
                    } else {
                        bestnum[i] = inf;
                    }
                    y /= 10;
                } else {
                    bestnum[i] = inf;
                }
            }
        }
        void merge(node& l, node& r) {
            ans = min(l.ans, r.ans);
            for (int i = 0; i < maxd; ++i) {
                int L = l.bestnum[i], R = r.bestnum[i];
                bestnum[i] = min(L, R);
                if (L < inf && R < inf) {
                    ans = min(ans, L + R);
                }
            }
        }
    } tree[1<<19];
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v].upd_bestnum(a[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(2*v, tl, tm);
            build(2*v+1, tm+1, tr);
            tree[v].merge(tree[2*v], tree[2*v+1]);
        }
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v].upd_bestnum(val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2*v, tl, tm, pos, val);
            } else {
                update(2*v+1, tm+1, tr, pos, val);
            }
            tree[v].merge(tree[2*v], tree[2*v+1]);
        }
    }
    node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return node();
        } else if (l <= tl && tr <= r) {
            return tree[v];
        } else {
            int tm = (tl + tr) / 2;
            node res1 = query(2*v, tl, tm, l, min(r, tm));
            node res2 = query(2*v+1, tm+1, tr, max(l, tm+1), r);
            node res;
            res.merge(res1, res2);
            return res;
        }
    }
} tree;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    tree.build(1, 1, n);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            tree.update(1, 1, n, i, x);
        } else {
            int l, r;
            cin >> l >> r;
            auto res = tree.query(1, 1, n, l, r);
            if (res.ans == 2*inf) {
                cout << -1 << endl;
            } else {
                cout << res.ans << endl;
            }
        }
    }
}
