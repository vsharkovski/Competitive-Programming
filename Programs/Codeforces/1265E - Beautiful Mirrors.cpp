#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 998244353;

ll powmod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

inline ll inv(ll x) {
    return powmod(x, mod-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll inv100 = inv(100);
    ll prod = 1; // p1 * p2 * ... * pi
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll p;
        cin >> p;
        p = (p * inv100) % mod;
        ans = (ans + prod) % mod;
        prod = (prod * p) % mod;
    }
    ans = (ans * inv(prod)) % mod;
    cout << ans << endl;
}
