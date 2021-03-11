#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
const int N = 100100;
const int N2 = 1<<18;
 
int n, m;
int val[N];
int p[N], pp[N], ppp[N];
 
struct segtree {
    struct node {
        int maxval, lazy;
        node() : maxval(0), lazy(0) {}
        inline void update(int x) {
            maxval += x;
            lazy += x;
        }
        inline void push(node& ln, node& rn) {
            ln.update(lazy);
            rn.update(lazy);
            lazy = 0;
        }
        inline void pull(node& ln, node& rn) {
            maxval = max(ln.maxval, rn.maxval);
        }
    };
    node tree[N2];
    int getmax(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl <= l && r <= tr) return tree[v].maxval;
        tree[v].push(tree[2*v], tree[2*v+1]);
        int tm = (tl + tr) / 2;
        return max( getmax(2*v, tl, tm, l, min(r, tm)),
                    getmax(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
    void update(int v, int tl, int tr, int l, int r, int x) {
        if (l > r) return;
        if (l == tl && tr == r) {
            tree[v].update(x);
            return;
        }
        tree[v].push(tree[2*v], tree[2*v+1]);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm), x);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, x);
        tree[v].pull(tree[2*v], tree[2*v+1]);
    }
} tree;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> distincts;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        distincts.push_back(val[i]);
    }
    sort(distincts.begin(), distincts.end());
    distincts.erase(unique(distincts.begin(), distincts.end()),
                    distincts.end());
    m = distincts.size();
    for (int i = 1; i <= n; ++i) {
        val[i] = 1 + distance(  distincts.begin(),
                                lower_bound(distincts.begin(),
                                            distincts.end(),
                                            val[i]));
        p[i] = pp[i] = ppp[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = val[i];
        if (pp[x] > 0) {
            tree.update(1, 1, n, ppp[x]+1, pp[x], -1);
        }
        ppp[x] = pp[x];
        pp[x] = p[x];
        p[x] = i;
        if (pp[x] > 0) {
            tree.update(1, 1, n, ppp[x]+1, pp[x], 1);
        }
        ans = max(ans, tree.getmax(1, 1, n, 1, i));
    }
    cout << ans << '\n';
}
