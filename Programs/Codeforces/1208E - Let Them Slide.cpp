#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 2e9;
const int maxn = 1e6 + 10;
const int maxw = 1e6 + 10;

struct segtree {
    vector<int> tree;
    void build(vector<int> &a, int n) {
        tree.resize(4*n);
        build(a, 1, 1, n);
    }
    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, 2*v, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            tree[v] = max(tree[2*v], tree[2*v+1]);
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return -inf;
        if (l <= tl && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return max(query(2*v, tl, tm, l, min(r, tm)),
                   query(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
};

int n, w;
vector<int> change1[maxw], change2[maxw];

int len[maxn];
int queryresult[maxn];
segtree tree[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        len[i] = l;
        vector<int> a(l+1);
        for (int j = 1; j <= l; ++j) {
            cin >> a[j];
        }
        tree[i].build(a, l);
        if (w-l+2 <= l) {
            change1[1].push_back(i);
        } else {
            change1[1].push_back(i);
            change2[l+1].push_back(i);
            change1[w-l+2].push_back(i);
        }
    }
    ll ans = 0;
    unordered_set<int> active;
    for (int j = 1; j <= w; ++j) {
        for (int i : change2[j]) {
            active.erase(i);
        }
        for (int i : change1[j]) {
            active.insert(i);
        }
        for (int i : active) {
            ans -= queryresult[i];
            int L = max(1, j + len[i] - w);
            int R = min(len[i], j);
            queryresult[i] = tree[i].query(1, 1, len[i], L, R);
            if (queryresult[i] < 0 && (j > len[i] || j < w-len[i]+1)) {
                queryresult[i] = 0;
            }
            ans += queryresult[i];
        }
        cout << ans << ' ';
    }
}
