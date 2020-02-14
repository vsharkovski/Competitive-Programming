
// Problem : Problem 3. Mooyo Mooyo
// Contest : USACO 2018 December Contest, Silver
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=860
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int M = 10;
const int N = 105;

int n, m, k;
int grid[N][M];

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

inline bool inside(int r, int c) {
	return r >= 1 && r <= n && c >= 1 && c <= m;
}

int dfs(int r, int c, int x, int y) {
	int res = 1;
	grid[r][c] = y;
	for (int d = 0; d < 4; ++d) {
		int r1 = r + dr[d], c1 = c + dc[d];
		if (inside(r1, c1) && grid[r1][c1] == x) {
			res += dfs(r1, c1, x, y);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	#endif
	cin >> n >> k;
	m = M;
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= m; ++c) {
			char ch;
			cin >> ch;
			grid[r][c] = ch - '0';
		}
	}
	while (true) {
		bool change = false;
		for (int r = 1; r <= n; ++r) {
			for (int c = 1; c <= m; ++c) {
				int x = grid[r][c];
				if (x == 0) continue;
				int cnt = dfs(r, c, x, -1);
				if (cnt >= k) {
					change = true;
					dfs(r, c, -1, 0);
				} else {
					dfs(r, c, -1, x);
				}
			}
		}
		for (int c = 1; c <= m; ++c) {
			int nxtfull = n+1;
			for (int r = n; r >= 1; --r) {
				if (grid[r][c] != 0) {
					swap(grid[r][c], grid[nxtfull-1][c]);
					--nxtfull;
				}
				if (grid[r][c] != 0) {
					nxtfull = r;
				}
			}
		}
		if (!change) break;
	}
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= m; ++c) {
			cout << grid[r][c];
		}
		cout << '\n';
	}
}
