/*
USACO 2015 December Contest, Gold
Problem 3. Bessie's Dream
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};;

const int N = 1010;

int n, m;
int grid[N][N];

bool vis[N][N][2][5];

struct State {
	int dist;
	int r, c;
	int smell;
	int slidedir;
	State() {}
	State(int dist, int r, int c, int smell, int slidedir)
		: dist(dist), r(r), c(c), smell(smell), slidedir(slidedir) {};
};
queue<State> q;

int moving(const State& t, int d) {
	int r1 = t.r + dr[d];
	int c1 = t.c + dc[d];
	if (grid[r1][c1] == 0 || (grid[r1][c1] == 3 && t.smell == 0)) {
		return 0; // blocked
	}
	int smell1 = t.smell;
	if (grid[r1][c1] == 2) smell1 = 1;
	else if (grid[r1][c1] == 4) smell1 = 0;
	int slidedir1 = 4;
	if (grid[r1][c1] == 4) slidedir1 = d;
	if (vis[r1][c1][smell1][slidedir1]) {
		return 1; // already visited
	}
	vis[r1][c1][smell1][slidedir1] = true;
	q.emplace(t.dist+1, r1, c1, smell1, slidedir1);
	return 2; // moved
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	#ifndef _DEBUG
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	#endif
	cin >> n >> m;
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= m; ++c) {
			cin >> grid[r][c];
		}
	}
	for (int r = 0; r <= n+1; ++r) {
		grid[r][0] = grid[r][m+1] = 0;
	}
	for (int c = 0; c <= n+1; ++c) {
		grid[0][c] = grid[n+1][c] = 0;
	}
	memset(vis, false, sizeof(vis));
	vis[1][1][0][4] = true;
	q.emplace(0, 1, 1, 0, 4);
	while (!q.empty()) {
		State t = q.front();
		q.pop();
		if (t.r == n && t.c == m) {
			cout << t.dist << "\n";
			return 0;
		}
		if (t.slidedir != 4) {
			if (moving(t, t.slidedir) == 0) {
				t.slidedir = 4;
			}
		}
		if (t.slidedir == 4) {
			for (int d = 0; d < 4; ++d) {
				moving(t, d);
			}
		}
	}
	cout << "-1\n";
}
