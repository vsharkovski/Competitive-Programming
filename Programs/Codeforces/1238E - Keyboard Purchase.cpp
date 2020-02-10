// Problem : E. Keyboard Purchase
// Contest : Educational Codeforces Round 74 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1238/E
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int M = 20;

int m;
int cnt[M][M];
int dp[1<<M];

int dfs(int msk) {
	int& res = dp[msk];
	if (res != -1) return res;
	if (msk == (1<<m)-1) return res = 0;
	res = 1e9;
	int sum = 0;
	for (int i = 0; i < m; ++i) {
		if (!(msk & (1 << i))) {
			for (int j = 0; j < m; ++j) {
				if (msk & (1 << j)) {
					sum += cnt[i][j];
				}
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		if (!(msk & (1 << i))) {
			res = min(res, sum + dfs(msk | (1 << i)));
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cnt[i][j] = 0;
		}
	}
	for (int i = 1; i < n; ++i) {
		int p = s[i-1] - 'a';
		int c = s[i] - 'a';
		++cnt[p][c];
		if (p != c) ++cnt[c][p];
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0) << '\n';
}
