#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll mod = 1e9 + 9;
 
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
 
ll ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    ll res;
    cin >> res;
    return res;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
 
    vector<ll> primes;
    ll pre = 1, cur, res;
 
    for (int i = 2; i <= n; i += 2) {
        cur = ask(1, i);
        res = (cur * inv(pre)) % mod;
        pre = cur;
        for (ll p = primes.empty() ? 2 : primes.back(); p*p <= res; ++p) {
            if (res % p == 0) {
                primes.push_back(p);
                primes.push_back(res/p);
                break;
            }
        }
    }
 
    if (n % 2 == 1) {
        cur = ask(1, n);
        res = (cur * inv(pre)) % mod;
        primes.push_back(res);
    }
 
    cout << "! ";
    for (ll p : primes) {
        cout << p << ' ';
    }
    cout << endl;
 
}
