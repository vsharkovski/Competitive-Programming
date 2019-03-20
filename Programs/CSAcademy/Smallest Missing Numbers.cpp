#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




inline ll getsum(ll x) {
    return x*(x+1)/2;
}

inline ll getsum(ll x, ll y) {
    if (x > y) return 0;
    return getsum(y) - getsum(x-1);
}

void Main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<ll, ll>> vec;
    if (a[0] > 1) {
        vec.emplace_back(1, a[0]-1);
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i-1] + 1) {
            vec.emplace_back(a[i-1] + 1, a[i] - 1);
        }
    }
    vec.emplace_back(a[n-1] + 1, 1e12);
    ll ans = 0;
    int i = 0;
    while (m > 0) {
        ll l = vec[i].first, r = vec[i].second;
        if (r - l + 1 <= m) {
            ans += getsum(l, r);
            m -= (r - l + 1);
            ++i;
        } else {
            ll r2 = l + m - 1;
            ans += getsum(l, r2);
            m = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
