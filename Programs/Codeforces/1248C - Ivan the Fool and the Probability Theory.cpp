#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int mod = 1e9 + 7;
	int n, m;
	cin >> n >> m;
	int k = max(n, m);
	vector<int> dp(k+1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= k; ++i) {
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}
	int ans = 0;
	ans = (ans + dp[n]) % mod;
	ans = (ans + dp[n]) % mod;
	ans = (ans + dp[m]) % mod;
	ans = (ans + dp[m]) % mod;
	ans = (ans - 2 + mod) % mod;
	cout << ans << endl;
}
