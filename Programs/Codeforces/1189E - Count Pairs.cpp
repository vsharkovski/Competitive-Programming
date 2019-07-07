#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n, p, k;
    cin >> n >> p >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    ll m = (p - k) % p;
    map<ll, int> cnt;
    for (int i = 0; i < n; ++i) {
        ll x = (a[i]*a[i])%p;
        x = (x*a[i])%p;
        x = (x*a[i])%p;
        x = (x+(m*a[i]))%p;
        ans += cnt[x];
        ++cnt[x];
    }
    cout << ans << endl;
}
