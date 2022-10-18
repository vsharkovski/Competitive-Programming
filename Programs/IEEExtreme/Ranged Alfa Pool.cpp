#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
	return x;
}

const int N = 1e6 + 5;

int dp[N];
int dp_prefix_sum[N];

int main() {
	dp[0] = 1;
	dp[1] = 2;
	for (int x = 2; x < N; ++x) {
		dp[x] = 0;
		for (int i = 1; x - ((1 << i) - 1) >= 0; ++i) {
			int y = x - ((1 << i) - 1);
			if (y == 0) {
				dp[x] = add(dp[x], 2);
			} else {
				dp[x] = add(dp[x], dp[x - ((1 << i) - 1)]);
			}
		}
	}
	dp_prefix_sum[0] = dp[0];
	for (int x = 1; x < N; ++x) {
		dp_prefix_sum[x] = add(dp_prefix_sum[x-1], dp[x]);
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		int ans = dp_prefix_sum[b];
		if (a > 0) ans = add(ans, -dp_prefix_sum[a-1]);
		cout << ans << endl;
	}
}
