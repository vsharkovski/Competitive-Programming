#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll p, d, n;
    cin >> p >> d >> n;
    ll ans = 0;
    ll cur = p;
    for (int i = 0; i < n-1; ++i) {
        ans += cur;
        cur += d;
    }
    cout << ans;
}
