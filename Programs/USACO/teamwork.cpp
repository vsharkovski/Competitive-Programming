
// Problem : Problem 3. Teamwork
// Contest : USACO 2018 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=863
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vector<ll> a(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<ll> dp(n+1);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i-1];
		ll mx = 0;
		for (int j = i; j >= max(i+1-k, 1); --j) {
			mx = max(mx, a[j]);
			dp[i] = max(dp[i], dp[j-1] + mx*(i-j+1));	
		}
	}
	cout << dp[n] << '\n';
}
