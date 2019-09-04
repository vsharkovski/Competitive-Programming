#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Line {
    mutable ll k, m, p;
    Line(ll k, ll m, ll p) : k(k), m(m), p(p) {}
    bool operator < (const Line& o) const {
        return k < o.k;
    }
    bool operator < (ll x) const {
        return p < x;
    }
};

struct LineContainer : multiset<Line, less<>> {
    const ll inf = 1e18;
    ll div(ll a, ll b) {
        return a/b - ((a^b) < 0 && a%b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf;
            return false;
        }
        if (x->k >= y->k) {
            x->p = x->m > y->m ? inf : -inf;
        } else {
            x->p = div(y->m - x->m, x->k - y->k);
        }
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = emplace(k, m, 0);
        auto y = z++;
        while (isect(y, z)) {
            z = erase(z);
        }
        auto x = y;
        while (x != begin() && isect(--x, y)) {
            y = erase(y);
            isect(x, y);
        }
        while ((y = x) != begin() && (--x)->p >= y->p) {
            isect(x, erase(y));
        }
    }
    ll query(ll x) {
        auto l = lower_bound(x);
        return l->k * x + l->m;
    }
};

const int maxn = 100010;

int n;
ll a[maxn];
ll b[maxn];
LineContainer hull;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    ll dp = 0;
    hull.add(-b[1], -dp);
    for (int i = 2; i <= n; ++i) {
        dp = -hull.query(a[i]);
        hull.add(-b[i], -dp);
    }
    cout << dp << endl;
}
