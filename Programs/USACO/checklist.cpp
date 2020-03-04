
// Problem : Problem 2. Cow Checklist
// Contest : USACO 2016 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=670
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e18;
const int N = 1010;

int n[2];
ll x[2][N], y[2][N];
ll dp[2][N][N];

ll dist(int k1, int i1, int k2, int i2) {
	return (x[k1][i1]-x[k2][i2])*(x[k1][i1]-x[k2][i2]) + (y[k1][i1]-y[k2][i2])*(y[k1][i1]-y[k2][i2]);
}

ll dfs(int k, int i, int j) {
	ll& res = dp[k][i][j];
	if (res != -1) {
		return res;
	}
	if (i == n[0] && j == n[1]) {
		return res = k == 0 ? 0 : inf;
	}
	res = inf;
	if (i < n[0]) {
		if (k == 0) {
			res = min(res, dist(0, i, 0, i+1) + dfs(0, i+1, j));
		} else {
			res = min(res, dist(1, j, 0, i+1) + dfs(0, i+1, j));
		}
	}
	if (j < n[1]) {
		if (k == 0) {
			res = min(res, dist(0, i, 1, j+1) + dfs(1, i, j+1));
		} else {
			res = min(res, dist(1, j, 1, j+1) + dfs(1, i, j+1));
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	#endif
	cin >> n[0] >> n[1];
	for (int k = 0; k < 2; ++k) {
		for (int i = 1; i <= n[k]; ++i) {
			cin >> x[k][i] >> y[k][i];
		}
		x[k][0] = y[k][0] = 0;
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1, 0) << '\n';
}
