#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> b(n+1);
    vector<pair<ll, int>> c(n+1);
    for (int i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        c[i] = {a*i*(n-i+1), i};
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    sort(c.begin()+1, c.end());
    sort(b.begin()+1, b.end(), greater<ll>());
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (c[i].first%mod)*b[i];
        ans %= mod;
    }
    cout << ans << '\n';
}
