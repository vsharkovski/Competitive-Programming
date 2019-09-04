#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
(not created by me)
Data structure that contains lines, sorted by slope
It allows a query for the highest line at some x
*/

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
            x->p = div(y->m - x->m, x->k -  y->k);
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
        if (x != begin() && isect(--x, y)) {
            y = erase(y);
            isect(x, y);
        }
        while ((y = x) != begin() && (--x)->p >= y->p) {
            isect(x, erase(y));
        }
    }
    ll query(ll x) {
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
