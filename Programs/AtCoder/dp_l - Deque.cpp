#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 3003;
	int n;
	cin >> n;
	ll a[N];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	static ll dp[N][N][2];
	for (int i = 0; i < n; ++i) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for (int d = 1; d < n; ++d) {
		for (int i = 0; i+d < n; ++i) {
			int j = i+d;
			// taro (maximize)
			dp[i][j][0] = max(a[i] + dp[i+1][j][1], a[j] + dp[i][j-1][1]);
			// jiro (minimize)
			dp[i][j][1] = min(-a[i] + dp[i+1][j][0], -a[j] + dp[i][j-1][0]);
		}
	}
	cout << dp[0][n-1][0] << '\n';
}
