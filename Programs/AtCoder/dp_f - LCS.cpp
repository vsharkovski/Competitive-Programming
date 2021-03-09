#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline void update(int m1, pii p1, int& m2, pii& p2) {
	if (m1 > m2) {
		m2 = m1;
		p2 = p1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, -n*m));
	vector<vector<pii>> pre(n+1, vector<pii>(m+1, pii(-1, -1)));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i] != t[j]) {
				update(dp[i][j], pre[i][j], dp[i+1][j], pre[i+1][j]);
				update(dp[i][j], pre[i][j], dp[i][j+1], pre[i][j+1]);
			} else {
				update(dp[i][j]+1, pii(i, j), dp[i+1][j+1], pre[i+1][j+1]);
			}
		}
	}
	int lcs = dp[n][m];
	pii c = pre[n][m];
	for (int i = 0; i < n; ++i) {
		update(dp[i][m], pre[i][m], lcs, c);
	}
	for (int j = 0; j < m; ++j) {
		update(dp[n][j], pre[n][j], lcs, c);
	}
	string ans = "";
	while (c.first != -1) {
		ans += s[c.first];
		c = pre[c.first][c.second];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
