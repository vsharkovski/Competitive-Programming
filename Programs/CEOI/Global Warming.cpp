#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 200010;
const int maxd = 2*maxn; // max # of distinct

int numunique;
unordered_map<int, int> newid;

int n, x, ans;
int a[maxn];
int anew[maxn]; // newid[a[i]]
int bnew[maxn]; // newid[a[i] + d]
int LIS[maxn];
int LDS[maxn];

struct segtree {
    int tree[4*maxd];
    void build() {
        for (int i = 0; i < 4*maxd; ++i) {
            tree[i] = -inf;
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return -inf;
        if (l <= tl && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return max(query(2*v, tl, tm, l, min(r, tm)),
                   query(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2*v, tl, tm, pos, val);
            } else {
                update(2*v+1, tm+1, tr, pos, val);
            }
            tree[v] = max(tree[2*v], tree[2*v+1]);
        }
    }
} tree;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> x;
    vector<int> distinct;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        distinct.push_back(a[i]);
        distinct.push_back(a[i] + x);
    }
    sort(distinct.begin(), distinct.end());
    numunique = 0;
    for (int i = 0; i < (int)distinct.size(); ++i) {
        if (i == 0 || distinct[i] != distinct[i-1]) {
            newid[distinct[i]] = numunique;
            ++numunique;
        }
    }
    for (int i = 1; i <= n; ++i) {
        anew[i] = newid[a[i]];
        bnew[i] = newid[a[i] + x];
    }
    tree.build();
    for (int i = n; i >= 1; --i) {
        int res = tree.query(1, 0, maxd-1, bnew[i]+1, maxd-1);
        LDS[i] = res == -inf ? 1 : res + 1;
        tree.update(1, 0, maxd-1, bnew[i], LDS[i]);
    }
    tree.build();
    for (int i = 1; i <= n; ++i) {
        int res = tree.query(1, 0, maxd-1, 0, bnew[i]-1);
        LIS[i] = res == -inf ? 1 : res + 1;
        res = tree.query(1, 0, maxd-1, 0, anew[i]-1);
        tree.update(1, 0, maxd-1, anew[i], res == -inf ? 1 : res + 1);
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, LIS[i] + LDS[i] - 1);
    }
    cout << ans << endl;
}
