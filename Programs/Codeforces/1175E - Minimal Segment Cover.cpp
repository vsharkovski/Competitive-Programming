#include <bits/stdc++.h>
using namespace std;

const int maxw = 500010;
const int maxn = 200010;
const int maxlog = 19;

int n, m;
int sp[maxw][maxlog];

struct segtree {
    int tree[1<<20];
    void build() {
        memset(tree, -1, sizeof(tree));
    }
    void update(int v, int tl, int tr, int pos, int val) {
        tree[v] = max(tree[v], val);
        if (tl < tr) {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2*v, tl, tm, pos, val);
            } else {
                update(2*v+1, tm+1, tr, pos, val);
            }
        }
    }
    int getmax(int v, int tl, int tr, int l, int r) {
        if (l > r) return -1;
        if (l <= tl && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return max(getmax(2*v, tl, tm, l, min(r, tm)),
                   getmax(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
} tree;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    tree.build();
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        tree.update(1, 0, maxw-1, l, r);
    }
    for (int j = 0; j < maxlog; ++j) {
        for (int i = 0; i < maxw; ++i) {
            sp[i][j] = -1;
        }
    }
    for (int i = 0; i < maxw; ++i) {
        sp[i][0] = tree.getmax(1, 0, maxw-1, 0, i);
        if (sp[i][0] <= i) sp[i][0] = -1;
    }
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 0; i < maxw; ++i) {
            if (sp[i][j-1] != -1) {
                sp[i][j] = sp[ sp[i][j-1] ][j-1];
            }
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        int steps = 0;
        for (int j = maxlog-1; j >= 0 && x < y; --j) {
            if (sp[x][j] != -1 && sp[x][j] <= y) {
                x = sp[x][j];
                steps += (1 << j);
            }
        }
        if (x < y && sp[x][0] != -1) {
            x = sp[x][0];
            steps += 1;
        }
        if (x < y) {
            cout << -1 << '\n';
        } else {
            cout << steps << '\n';
        }
    }
}
