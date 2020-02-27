#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 410;
const int inf = 1e9;

int n, K;
int a[N];
int dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	#endif
	cin >> n >> K;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int mx = 0, sum = 0;
	dp[0][n+1] = 0;
	for (int i = n; i >= 1; --i) {
		mx = max(mx, a[i]);
		sum += a[i];
		dp[0][i] = mx*(n-i+1) - sum;
	}
	for (int k = 1; k <= K; ++k) {
		dp[k][n+1] = 0;
		for (int i = n; i >= 1; --i) {
			dp[k][i] = inf;
			mx = 0, sum = 0;
			for (int j = i; j <= n; ++j) {
				mx = max(mx, a[j]);
				sum += a[j];
				dp[k][i] = min(dp[k][i], mx*(j-i+1) - sum + dp[k-1][j+1]);
			}
		}
	}
	cout << dp[K][1] << '\n';
}
