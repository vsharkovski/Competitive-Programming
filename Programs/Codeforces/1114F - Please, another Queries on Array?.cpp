#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const ll mod = 1e9 + 7;
const int maxn = 400010;

ll powmod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    static ll memo[310] = {};
    ll res;
    if (a <= 300) {
        if (memo[a] == 0) {
            memo[a] = powmod(a, mod-2);
        }
        res = memo[a];
    } else {
        res = powmod(a, mod-2);
    }
    return res;
}

struct Node {
    ll primemask;
    ll product;
    Node() {
        primemask = 0;
        product = 1;
    }
    Node(ll mask, ll prod) {
        primemask = mask;
        product = prod;
    }
};

int n, q;
int a[maxn];

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
int primeidx[310];
ll singlemask[maxn];
ll maskvalue[4][1<<15];

Node tree[4*maxn];
Node lazy[4*maxn];

void maskvalues_preprocess() {
    for (int a = 0; a < 4; ++a) {
        for (int m = 0; m < (1 << 15); ++m) {
            ll res = 1;
            for (int i = 0; i < 15; ++i) {
                if (m & (1 << i)) {
                    res = (res * (primes[15*a+i]-1)) % mod;
                    res = (res * inv(primes[15*a+i])) % mod;
                }
            }
            maskvalue[a][m] = res;
        }
    }
}

ll getmaskvalue(ll msk) {
    static const ll screen = (1LL << 15) - 1;
    ll res = 1;
    for (int i = 0; i < 62; ++i) {
        if (msk & (1LL << i)) {
            res = (res * (primes[i]-1)) % mod;
            res = (res * inv(primes[i])) % mod;
        }
    }
    return res;
    // 0 to 14
    res = (res * maskvalue[0][msk & screen]) % mod;
    // 15 to 29
    res = (res * maskvalue[1][(msk >> 15) % screen]) % mod;
    // 30 to 44
    res = (res * maskvalue[2][(msk >> 30) % screen]) % mod;
    // 45 to 59
    res = (res * maskvalue[3][(msk >> 45) % screen]) % mod;
    // 60, 61
    if (msk & (1LL << 60)) {
        res = (res * (primes[60]-1)) % mod;
        res = (res * inv(primes[60])) % mod;
    }
    if (msk & (1LL << 61)) {
        res = (res * (primes[61]-1)) % mod;
        res = (res * inv(primes[61])) % mod;
    }
    return res;
}

void merge(Node& v, Node& l, Node& r) {
    v.product = (l.product * r.product) % mod;
    v.primemask = l.primemask | r.primemask;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].product = a[tl];
        tree[v].primemask = singlemask[a[tl]];
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        merge(tree[v], tree[2*v], tree[2*v+1]);
    }
}

void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    tree[2*v].product = (tree[2*v].product * powmod(lazy[v].product, tm-tl+1)) % mod;
    lazy[2*v].product = (lazy[2*v].product * lazy[v].product) % mod;
    tree[2*v+1].product = (tree[2*v+1].product * powmod(lazy[v].product, tr-(tm+1)+1)) % mod;
    lazy[2*v+1].product = (lazy[2*v+1].product * lazy[v].product) % mod;
    lazy[v].product = 1;
    tree[2*v].primemask |= lazy[v].primemask;
    lazy[2*v].primemask |= lazy[v].primemask;
    tree[2*v+1].primemask |= lazy[v].primemask;
    lazy[2*v+1].primemask |= lazy[v].primemask;
    lazy[v].primemask = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) {
        return;
    } else if (l == tl && tr == r) {
        tree[v].product = (tree[v].product * powmod(x, r-l+1)) % mod;
        tree[v].primemask |= singlemask[x];
        lazy[v].product = (lazy[v].product * x) % mod;
        lazy[v].primemask |= singlemask[x];
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2*v, tl, tm, l, min(r, tm), x);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, x);
        merge(tree[v], tree[2*v], tree[2*v+1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return Node(0, 1);
    } else if (l <= tl && tr <= r) {
        return tree[v];
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        Node res1 = query(2*v, tl, tm, l, min(tm, r));
        Node res2 = query(2*v+1, tm+1, tr, max(tm+1, l), r);
        res1.primemask |= res2.primemask;
        res1.product = (res1.product * res2.product) % mod;
        return res1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < primes.size(); ++i) {
        primeidx[primes[i]] = i;
    }
    singlemask[1] = 0;
    for (int x = 2; x <= 300; ++x) {
        int y = x;
        singlemask[x] = 0;
        for (int p : primes) {
            if (p*p > y) {
                break;
            } else if (y % p == 0) {
                singlemask[x] |= (1LL << primeidx[p]);
                while (y % p == 0) {
                    y /= p;
                }
            }
        }
        if (y > 1) {
            singlemask[x] |= (1LL << primeidx[y]);
        }
    }
    maskvalues_preprocess();
    build(1, 0, n-1);
    while (q--) {
        string type;
        int l, r, x;
        cin >> type >> l >> r;
        --l, --r;
        if (type == "MULTIPLY") {
            cin >> x;
            update(1, 0, n-1, l, r, x);
        } else {
            Node res = query(1, 0, n-1, l, r);
            ll ans = (res.product * getmaskvalue(res.primemask)) % mod;
            cout << ans << '\n';
        }
    }
}
