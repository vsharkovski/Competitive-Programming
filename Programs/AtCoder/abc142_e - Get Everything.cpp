#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 12;
const int maxm = 1010;
 
int n, m;
int a[maxm];
int b[maxm];
int dp[2][1<<maxn];
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int c;
		cin >> a[i] >> c;
		b[i] = 0;
		for (int j = 0; j < c; ++j) {
			int k;
			cin >> k;
			b[i] |= (1 << (k-1));
		}
	}
	for (int msk = 0; msk < (1 << n); ++msk) {
		dp[1][msk] = inf;
	}
	dp[1][0] = 0;
	for (int i = 1; i <= m; ++i) {
		// swap dp[0] and dp[1], set dp[1] to inf
		for (int msk = 0; msk < (1 << n); ++msk) {
			dp[0][msk] = dp[1][msk];
			dp[1][msk] = inf;
		}
		// transitions
		for (int msk = (1 << n)-1; msk >= 0; --msk) {
			dp[1][msk] = min(dp[1][msk], dp[0][msk]);
			dp[1][msk | b[i]] = min(dp[1][msk | b[i]], dp[0][msk] + a[i]);
		}
	}
	if (dp[1][(1 << n)-1] == inf) {
		cout << -1 << endl;
	} else {
		cout << dp[1][(1 << n)-1] << endl;
	}
}
