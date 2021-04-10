#include <bits/stdc++.h>
using namespace std;

const int N = 22;

// up, right, down, left;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};;

int n;
bool wall[N][N];
bool vis[4][N][N][N][N];

struct State {
	int dist;
	int d1, r1, c1;
	int d2, r2, c2;
	State() {}
	State(int dist, int d1, int r1, int c1, int d2, int r2, int c2)
		: dist(dist), d1(d1), r1(r1), c1(c1), d2(d2), r2(r2), c2(c2) {}
	inline bool was_visited() {
		return vis[d1][r1][c1][r2][c2];
	}
	inline void mark_visited() {
		vis[d1][r1][c1][r2][c2] = true;
	}
	inline void left() {
		d1 = (d1 - 1 + 4) % 4;
		d2 = (d2 - 1 + 4) % 4;
	}
	inline void right() {
		d1 = (d1 + 1) % 4;
		d2 = (d2 + 1) % 4;
	}
	inline void go() {
		if ((r1 != 1 || c1 != n) && !wall[r1 + dr[d1]][c1 + dc[d1]]) {
			r1 += dr[d1];
			c1 += dc[d1];
		}
		if ((r2 != 1 || c2 != n) && !wall[r2 + dr[d2]][c2 + dc[d2]]) {
			r2 += dr[d2];
			c2 += dc[d2];
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	#ifndef _DEBUG
	freopen("cownav.in", "r", stdin);
	freopen("cownav.out", "w", stdout);
	#endif
	cin >> n;
	for (int r = 0; r <= n+1; ++r) {
		wall[r][0] = wall[r][n+1] = true;
	}
	for (int c = 0; c <= n+1; ++c) {
		wall[0][c] = wall[n+1][c] = true;
	}
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= n; ++c) {
			char ch;
			cin >> ch;
			wall[r][c] = (ch == 'H');
		}
	}
	memset(vis, false, sizeof(vis));
	queue<State> q;
	State source_state(0, 0, n, 1, 1, n, 1);
	source_state.mark_visited();
	q.push(source_state);
	while (!q.empty()) {
		State t = q.front();
		State t0 = q.front();
		q.pop();
		if (t.r1 == 1 && t.c1 == n && t.r2 == 1 && t.c2 == n) {
			cout << t.dist << "\n";
			return 0;
		}
		t.dist += 1;
		// counterclockwise
		t.left();
		if (!t.was_visited()) {
			t.mark_visited();
			q.push(t);
		}
		t.right();
		// clockwise
		t.right();
		if (!t.was_visited()) {
			t.mark_visited();
			q.push(t);
		}
		t.left();
		// forward
		t.go();
		if (!t.was_visited()) {
			t.mark_visited();
			q.push(t);
		}
	}
}
