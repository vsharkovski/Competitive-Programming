
// Problem : C. Flag
// Contest : Codeforces Round #567 (Div. 2)
// URL : https://codeforces.com/contest/1181/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;
const int M = 1<<12;
const int inf = 1e9;

ll ans;
int R, C;
int grid[N][N];
int d[N][N];
int f[N][N];

struct segtree {
	int tree[M];
	void build(int v, int tl, int tr, int c) {
		if (tl == tr) {
			tree[v] = f[tl][c];
		} else {
			int tm = (tl + tr) / 2;
			build(2*v, tl, tm, c);
			build(2*v+1, tm+1, tr, c);
			tree[v] = min(tree[2*v], tree[2*v+1]);
		}
	}
	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) return inf;
		if (l <= tl && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return	min(query(2*v, tl, tm, l, min(r, tm)),
					query(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
} tree[N]; // for each column

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			char ch;
			cin >> ch;
			grid[r][c] = ch - 'a';
		}
	}
	for (int c = 0; c < C; ++c) {
		d[R-1][c] = R;
		for (int r = R-2; r >= 0; --r) {
			if (grid[r][c] == grid[r+1][c]) {
				d[r][c] = d[r+1][c];
			} else {
				d[r][c] = r+1;
			}
		}
	}
	for (int r = 0; r < R; ++r) {
		f[r][C-1] = 1;
		for (int c = C-2; c >= 0; --c) {
			if (grid[r][c] == grid[r][c+1]) {
				f[r][c] = 1 + f[r][c+1];
			} else {
				f[r][c] = 1;
			}
		}
	}
	for (int c = 0; c < C; ++c) {
		tree[c].build(1, 0, R-1, c);
	}
	ans = 0;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			int h = d[r][c] - r;
			if (r+h+h+h-1 >= R) continue;
			if (d[r+h][c] - (r+h) != h) continue;
			if (d[r+h+h][c] - (r+h+h) < h) continue;
			int l = tree[c].query(1, 0, R-1, r, r+h+h+h-1);
			ans += l;
			//cout << "r="<<r<<" c="<<c<<" h="<<h<<" l="<<l<<"\n";
		}
	}
	cout << ans << '\n';
}
