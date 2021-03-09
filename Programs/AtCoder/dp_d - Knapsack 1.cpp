#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const ll inf = 1e9;
	int n, maxw;
	cin >> n >> maxw;
	vector<ll> dp(maxw+1, -inf);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		int wi;
		ll vi;
		cin >> wi >> vi;
		for (int sumw = maxw-wi; sumw >= 0; --sumw) {
			dp[sumw+wi] = max(dp[sumw+wi], dp[sumw] + vi);
		}
	}
	ll ans = 0;
	for (int sumw = 0; sumw <= maxw; ++sumw) {
		ans = max(ans, dp[sumw]);
	}
	cout << ans << '\n';
}
