#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 16;
	int n;
	cin >> n;
	int a[N][N];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	ll score[1<<N];
	for (int m = 0; m < (1<<n); ++m) {
		score[m] = 0;
		for (int i = 0; i < n; ++i) {
			if (!(m & (1 << i))) continue;
			for (int j = i+1; j < n; ++j) {
				if (!(m & (1 << j))) continue;
				score[m] += a[i][j];
			}
		}
	}
	ll dp[1<<N];
	dp[0] = 0;
	for (int m = 1; m < (1<<n); ++m) {
		dp[m] = 0; // when all are separate
		for (int s = m; s > 0; s = (s-1) & m) {
			dp[m] = max(dp[m], score[s] + dp[m & ~s]);
		}
	}
	cout << dp[(1<<n)-1] << '\n';
}
