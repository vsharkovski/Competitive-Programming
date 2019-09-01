#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100010;
const int maxt = 1000010;

int n;
ll T0;
int X[maxn], T[maxn];
vector<pii> adj[maxn];

struct segtree {
    struct node {
        ll c, t; // total cookies, total time to eat them
        node() : c(0), t(0) {}
    } tree[4*maxt];
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v].c += val;
            tree[v].t = tree[v].c * tl;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2*v, tl, tm, pos, val);
            } else {
                update(2*v+1, tm+1, tr, pos, val);
            }
            tree[v].c = tree[2*v].c + tree[2*v+1].c;
            tree[v].t = tree[2*v].t + tree[2*v+1].t;
        }
    }
    ll query(int v, int tl, int tr, ll Trem) {
        if (tl == tr) {
            return min(tree[v].c, Trem / tl);
        } else {
            int tm = (tl + tr) / 2;
            if (tree[2*v].t <= Trem) {
                return tree[2*v].c + query(2*v+1, tm+1, tr, Trem - tree[2*v].t);
            } else {
                return query(2*v, tl, tm, Trem);
            }
        }
    }
} tree;

ll dfs(int nd, int pr, ll Trem) {
    ll results[2] = {0, 0};
    tree.update(1, 1, maxt-1, T[nd], X[nd]);
    ll ifstop = tree.query(1, 1, maxt-1, Trem);
    for (auto &to : adj[nd]) {
        int v = to.first, w = to.second;
        if (v != pr && Trem - 2*w > 0) {
            ll res = dfs(v, nd, Trem - 2*w);
            if (res >= results[0]) {
                results[1] = results[0];
                results[0] = res;
            } else if (res > results[1]) {
                results[1] = res;
            }
        }
    }
    tree.update(1, 1, maxt-1, T[nd], -X[nd]);
    if (pr == -1) {
        return max(ifstop, results[0]);
    } else {
        return max(ifstop, results[1]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> T0;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> T[i];
    }
    for (int i = 2; i <= n; ++i) {
        int p, l;
        cin >> p >> l;
        adj[p].emplace_back(i, l);
    }
    ll ans = dfs(1, -1, T0);
    cout << ans << endl;
}
