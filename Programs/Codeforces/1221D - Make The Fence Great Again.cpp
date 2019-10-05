#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
const ll inf = 1e18;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }
        vector<vector<ll>> dp(3, vector<ll>(n+3, inf));
        a[0] = -5;
        dp[0][0] = dp[1][0] = dp[2][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 2; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    if (a[i-1] + k != a[i] + j) {
                        dp[j][i] = min(dp[j][i], dp[k][i-1]);
                    }
                }
                dp[j][i] += j*b[i];
            }
        }
        ll ans = inf;
        for (int j = 0; j <= 2; ++j) {
            ans = min(ans, dp[j][n]);
        }
        cout << ans << endl;
    }
}
