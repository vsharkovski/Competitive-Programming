#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	vector<int> dp(n, 1e9);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		if (i+1 < n) dp[i+1] = min(dp[i+1], dp[i]+abs(h[i+1]-h[i]));
		if (i+2 < n) dp[i+2] = min(dp[i+2], dp[i]+abs(h[i+2]-h[i]));
	}
	cout << dp[n-1] << '\n';
}
