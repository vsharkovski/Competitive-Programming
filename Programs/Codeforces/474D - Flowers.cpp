#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int mod = 1e9 + 7;
const int maxval = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie();

    int t, k;
    cin >> t >> k;

    int dp[maxval];
    dp[0] = 1;
    for (int i = 1; i < maxval; ++i) {
        dp[i] = dp[i-1];
        if (i >= k) {
            dp[i] += dp[i-k];
            if (dp[i] >= mod) dp[i] -= mod;
        }
    }

    int prefsum[maxval];
    for (int i = 1; i < maxval; ++i) {
        prefsum[i] = (prefsum[i-1] + dp[i]) % mod;
    }

    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = prefsum[b] - prefsum[a-1];
        if (ans < 0) ans += mod;
        cout << ans << '\n';
    }
}

