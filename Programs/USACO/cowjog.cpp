#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	#endif
	int n;
	ll T;
	cin >> n >> T;
	vector<pair<ll, ll>> cows(n);
	for (int i = 0; i < n; ++i) {
		cin >> cows[i].first >> cows[i].second;
	}
	int ans = 0;
	ll xfj = 3*1e18;
	for (int i = n-1; i >= 0; --i) {
		ll xf = cows[i].first + cows[i].second * T;
		if (xf < xfj) {
			++ans;
			xfj = xf;
		}
	}
	cout << ans << '\n';
}
