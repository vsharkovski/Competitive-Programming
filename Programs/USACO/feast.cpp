#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	#ifndef _DEBUG
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	#endif
	const int T = 5000100;
	bitset<T> dp[2];
	int t, a, b;
	cin >> t >> a >> b;
	int ans = 0;
	dp[0][0] = true;
	for (int x = 0; x <= t; ++x) {
		if (!dp[0][x]) continue;
		ans = max(ans, x);
		if (x+a <= t) dp[0][x+a] = true;
		if (x+b <= t) dp[0][x+b] = true;
		dp[1][x/2] = true;
	}
	for (int x = 0; x <= t; ++x) {
		if (!dp[1][x]) continue;
		ans = max(ans, x);
		if (x+a <= t) dp[1][x+a] = true;
		if (x+b <= t) dp[1][x+b] = true;
	}
	cout << ans << '\n';
}
