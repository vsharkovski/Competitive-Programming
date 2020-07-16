#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 505;

int n, K;
int X[N], Y[N];
int dp[N][N];

inline int D(int a, int b) {
	return abs(X[a] - X[b]) + abs(Y[a] - Y[b]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	#endif
	cin >> n >> K;
	for (int i = 1; i <= n; ++i) {
		cin >> X[i] >> Y[i];
	}
	for (int j = 0; j <= K; ++j) {
		dp[1][j] = 1e9;
	}
	dp[1][K] = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= K; ++j) {
			dp[i][j] = 1e9;
			for (int x = max(1, j+i-K-1); x < i; ++x) {
				dp[i][j] = min(dp[i][j], dp[x][j+i-x-1] + D(x, i));
			}
		}
	}
	int ans = 1e9;
	for (int j = 0; j <= K; ++j) {
		ans = min(ans, dp[n][j]);
	}
	cout << ans << '\n';
}
