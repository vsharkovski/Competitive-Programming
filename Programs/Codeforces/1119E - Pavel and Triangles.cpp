#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




void Main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        while (k < i) {
            if (a[k] == 0) {
                ++k;
            } else if (a[i] >= 2) {
                ll cnt = min(a[k], a[i] / 2);
                ans += cnt;
                a[k] -= cnt;
                a[i] -= cnt*2;
            } else {
                break;
            }
        }
        ans += a[i] / 3;
        a[i] %= 3;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
