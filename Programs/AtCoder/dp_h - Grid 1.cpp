#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline void add(int& x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int R, C;
	cin >> R >> C;
	vector<vector<char>> grid(R, vector<char>(C));
	vector<vector<int>> dp(R, vector<int>(C, 0));
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> grid[r][c];
		}
	}
	dp[0][0] = 1;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (grid[r][c] == '#') continue;
			if (r+1 < R) add(dp[r+1][c], dp[r][c]);
			if (c+1 < C) add(dp[r][c+1], dp[r][c]);
		}
	}
	cout << dp[R-1][C-1] << '\n';
}
