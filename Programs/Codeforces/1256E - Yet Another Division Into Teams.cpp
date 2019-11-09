#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pll> a(n+2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin()+1, a.end()-1);
	vector<ll> dp(n+2), pre(n+2);
	set<pll> s;
	dp[3] = a[3].first - a[1].first;
	pre[3] = 0;
	s.emplace(dp[3] - a[4].first, 3);
	for (int i = 4; i <= n; ++i) {
		int j = -1;
		for (auto it = s.begin(); it != s.end(); ++it) {
			j = it->second;
			if (j+2 < i) {
				break;
			}
			j = -1;
		}
		dp[i] = a[i].first - a[1].first;
		pre[i] = 0;
		if (j != -1) {
			ll dp2 = dp[j] - a[j+1].first + a[i].first;
			if (dp2 < dp[i]) {
				dp[i] = dp2;
				pre[i] = j;
			}
		}
		s.emplace(dp[i] - a[i+1].first, i);
	}
	vector<int> team(n+1);
	int numteams = 0;
	int x = n;
	while (x != 0) {
		++numteams;
		for (int i = pre[x] + 1; i <= x; ++i) {
			team[a[i].second] = numteams;
		}
		x = pre[x];
	}
	cout << dp[n] << ' ' << numteams << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << team[i] << ' ';
	}
}
