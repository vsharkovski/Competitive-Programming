// IOI 2005 - Garden

#include <bits/stdc++.h>
using namespace std;

const int M = 255;
const int inf = 1e9;

int R, C;
int n, k;
int grid[M][M];
int dp1[M][M];
int dp2[M][M];

inline int subgridsum(int r1, int c1, int r2, int c2) {
	return grid[r2][c2] - grid[r2][c1-1] - grid[r1-1][c2] + grid[r1-1][c1-1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> C >> R >> n >> k;
	for (int r = 0; r <= R+1; ++r) {
		for (int c = 0; c <= C+1; ++c) {
			grid[r][c] = 0;
			dp1[r][c] = inf;
			dp2[r][c] = inf;
		}
	}
	for (int i = 0; i < n; ++i) {
		int c, r;
		cin >> c >> r;
		++grid[r][c];
	}
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			grid[r][c] += grid[r-1][c];
			grid[r][c] += grid[r][c-1];
			grid[r][c] -= grid[r-1][c-1];
		}
	}
	for (int r1 = 1; r1 <= R; ++r1) {
		for (int r2 = r1; r2 <= R; ++r2) {
			for (int c1 = 1, c2 = 1; c2 <= C; ++c2) {
				while (c1 < c2 && subgridsum(r1, c1+1, r2, c2) >= k) {
					++c1;
				}
				if (subgridsum(r1, c1, r2, c2) == k) {
					int perimeter = 2*(r2-r1+1) + 2*(c2-c1+1);
					dp1[r2][c2] = min(dp1[r2][c2], perimeter);
					dp2[r1][c1] = min(dp2[r1][c1], perimeter);
				}
			}
		}
	}
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			dp1[r][c] = min(dp1[r][c], dp1[r-1][c]);
			dp1[r][c] = min(dp1[r][c], dp1[r][c-1]);
		}
	}
	for (int r = R; r >= 1; --r) {
		for (int c = C; c >= 1; --c) {
			dp2[r][c] = min(dp2[r][c], dp2[r+1][c]);
			dp2[r][c] = min(dp2[r][c], dp2[r][c+1]);
		}
	}
	int ans = inf;
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			ans = min(ans, dp1[r][c] + dp2[r+1][1]);
			ans = min(ans, dp1[r][c] + dp2[1][c+1]);
		}
	}
	if (ans == inf) {
		cout << "NO\n";
	} else {
		cout << ans << '\n';
	}
}
