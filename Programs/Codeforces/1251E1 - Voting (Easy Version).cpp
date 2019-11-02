#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> v;
vector<vector<ll>> dp;

ll dfs(int i, int cnt) {
	ll& res = dp[i][cnt];
	if (res != -1) {
		return res;
	}
	if (i == 0) {
		if (v[i].first <= cnt) {
			return res = 0;
		} else {
			return res = v[i].second;
		}
	}
	res = v[i].second + dfs(i-1, cnt+1);
	if (v[i].first <= cnt + i) {
		res = min(res, dfs(i-1, cnt));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		cin >> n;
		v.resize(n);
		dp.assign(n, vector<ll>(n, -1));
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());
		cout << dfs(n-1, 0) << endl;
	}
}
