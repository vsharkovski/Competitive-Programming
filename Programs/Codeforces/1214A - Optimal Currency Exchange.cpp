#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n, d, e, ans = n;
    cin >> n >> d >> e;
    e *= 5;
    for (int i = 0; e*i <= n; ++i) {
        ans = min(ans, (n-e*i)%d);
    }
    cout << ans;
}
