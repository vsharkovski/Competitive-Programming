#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
        ans += (n-1) * b[i];
    }
    sort(c.begin(), c.end(), greater<ll>());
    for (int i = 0; i < n; ++i) {
        ans += i * c[i];
    }
    cout << ans << '\n';
}
