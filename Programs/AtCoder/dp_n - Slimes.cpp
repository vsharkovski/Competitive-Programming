#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const ll inf = 1e18;
	const int N = 410;
	int n;
	ll a[N];
	ll pref[N];
	ll dp[N][N];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pref[i] = a[i];
		if (i) pref[i] += pref[i-1];
		dp[i][i] = 0;
	}
	for (int d = 1; d < n; ++d) {
		for (int i = 0; i+d < n; ++i) {
			int j = i+d;
			ll sum = pref[j];
			if (i) sum -= pref[i-1];
			dp[i][j] = inf;
			for (int k = i; k < j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum);
			}
			//cout << "dp["<<i<<","<<j<<"]="<<dp[i][j]<<'\n';
		}
	}
	cout << dp[0][n-1] << '\n';
}
