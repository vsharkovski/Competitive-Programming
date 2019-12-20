#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const ll mod = 998244353;
const int N = 200010;

void add_self(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

inline void mul_self(ll& a, ll b) {
    a *= b;
    a %= mod;
}

ll powmod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) mul_self(res, a);
        mul_self(a, a);
        b /= 2;
    }
    return res;
}

inline ll inv(ll a) {
    return powmod(a, mod-2);
}

int n;
ll A[N];
ll B[N];

ll ans;
set<int> points;

/*
Expected number of steps to get from a to b
a is checkpoint, b is (presumably) the point
right before the next checkpoint

A[i] = p[1]p[2]...p[i] = A[i-1]p[i]
B[i] = p[1] + p[1]p[2] + ... + p[1]p[2]...p[i] = B[i-1] + A[i]
note: after getting B, i only need the inverses of A,
      and i do that in the same loop
E(a, b) = (B[b-1] - B[a-2]) / A[b]
take B[-1] = -1
*/

ll calc(ll a, ll b) {
    ll res = B[b-1];
    if (a == 1) {
        add_self(res, 1);
    } else {
        add_self(res, -B[a-2]);
    }
    mul_self(res, A[b]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> n >> q;

    ll inv100 = inv(100);
    A[0] = 1;
    B[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ll p;
        cin >> p;
        mul_self(p, inv100);
        A[i] = A[i-1]; mul_self(A[i], p);
        B[i] = B[i-1]; add_self(B[i], A[i]);
        A[i-1] = inv(A[i-1]);
    }
    A[n] = inv(A[n]);

    ans = 0;
    points.insert(1);
    points.insert(n+1);
    add_self(ans, calc(1, n));
    
    while (q--) {
        int x;
        cin >> x;
        auto it = points.lower_bound(x);
        if (*it > x) {
            // activate
            auto pr = prev(it);
            int b = *it;
            int a = *pr;
            points.insert(x);
            add_self(ans, -calc(a, b-1));
            add_self(ans, calc(a, x-1));
            add_self(ans, calc(x, b-1));
        } else {
            // deactivate
            auto pr = prev(it);
            auto nx = next(it);
            int a = *pr;
            int b = *nx;
            points.erase(it);
            add_self(ans, -calc(a, x-1));
            add_self(ans, -calc(x, b-1));
            add_self(ans, calc(a, b-1));
        }
        cout << ans << endl;
    }
}
