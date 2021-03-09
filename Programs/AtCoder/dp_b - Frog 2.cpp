#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	vector<int> dp(n, 1e9);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j <= min(i+k, n-1); ++j) {
			dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
		}
	}
	cout << dp[n-1] << '\n';
}
