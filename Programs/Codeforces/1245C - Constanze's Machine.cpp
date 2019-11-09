#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	const ll mod = 1e9 +7;
	const int maxn = 1e5 + 10;
	string s;
	cin >> s;
	int n = s.length();
	vector<ll> dp(maxn);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}
	ll ans = 1;
	int len = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == s[i-1]) {
			++len;
		} else {
			if (s[i-1] == 'm' || s[i-1] == 'w') {
				ans = 0;
			} else if (s[i-1] == 'u' || s[i-1] == 'n') {
				ans = (ans * dp[len]) % mod;
			}
			len = 1;
		}
	}
	if (s[n-1] == 'm' || s[n-1] == 'w') {
		ans = 0;
	} else if (s[n-1] == 'u' || s[n-1] == 'n') {
		ans = (ans * dp[len]) % mod;
	}
	cout << ans << endl;
}
