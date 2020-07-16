#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 20;

int n, H;
ll ch[N], cw[N], cs[N];
ll dp[1<<N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	#endif
	cin >> n >> H;
	for (int i = 0; i < n; ++i) {
		cin >> ch[i] >> cw[i] >> cs[i];
	}
	for (int m = 0; m < (1<<n); ++m) {
		dp[m] = -1;
	}
	dp[0] = 1e18;
	for (int m = 0; m < (1<<n); ++m) {
		ll sumw = 0;
		for (int i = 0; i < n; ++i) {
			if (m & (1 << i)) {
				sumw += cw[i];
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!(m & (1<<i)) && cs[i] >= sumw) {
				dp[m|(1<<i)] = max(dp[m|(1<<i)], min(dp[m], cs[i] - sumw));
			}
		}
	}
	ll ans = -1;
	for (int m = 0; m < (1 << n); ++m) {
		ll sumh = 0;
		for (int i = 0; i < n; ++i) {
			if (m & (1 << i)) {
				sumh += ch[i];
			}
		}
		if (sumh >= H) {
			ans = max(ans, dp[m]);
		}
	}
	if (ans == -1) {
		cout << "Mark is too tall\n";
	} else {
		cout << ans << '\n';
	}
}
