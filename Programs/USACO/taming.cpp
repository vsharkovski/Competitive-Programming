
// Problem : Problem 3. Taming the Herd
// Contest : USACO 2018 February Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=815
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;
const int inf = N*N*N;

int n;
int a[N];
int dp[N][N][N];

int dfs(int i, int j, int b) {
	int& res = dp[i][j][b];
	if (res != -1) return res;
	if (i == n+1) {
		if (b == 0) {
			return res = 0;
		} else {
			return res = inf;
		}
	}
	res = inf;
	if (b > 0 && j != i) {
		res = min(res, dfs(i, i, b-1));
	}
	if (i-a[i] != j) {
		res = min(res, 1 + dfs(i+1, j, b));
	} else {
		res = min(res, dfs(i+1, j, b));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	for (int b = 1; b <= n; ++b) {
		cout << dfs(1, 1, b-1) << '\n';
	}
}
