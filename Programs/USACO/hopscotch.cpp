#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
	return x;
}

inline void add_self(int &x, int y) {
	x = add(x, y);
}

const int N = 752;

struct Fenwick {
	int n;
	vector<int> tree;
	void init(int _n) {
		n = _n;
		tree.assign(n+1, 0);
	}
	void update(int pos, int val) {
		while (pos <= n) {
			add_self(tree[pos], val);
			pos += pos & -pos;
		}
	}
	int sum(int pos) {
		int res = 0;
		while (pos >= 1) {
			add_self(res, tree[pos]);
			pos -= pos & -pos;
		}
		return res;
	}
};

int R, C, K;
int value[N][N];
int ways[N][N];
int ways_pref[N][N];
vector<int> dist_c[N*N];
Fenwick tree[N*N];

inline int get_compressed(int v, int c) {
	return lower_bound(dist_c[v].begin(), dist_c[v].end(), c) - dist_c[v].begin();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifndef _DEBUG
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	#endif // _DEBUG
	cin >> R >> C >> K;
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			cin >> value[r][c];
			dist_c[value[r][c]].push_back(c);
		}
	}
	for (int i = 1; i <= K; ++i) {
		sort(dist_c[i].begin(), dist_c[i].end());
		dist_c[i].erase(unique(dist_c[i].begin(), dist_c[i].end()), dist_c[i].end());
		tree[i].init(dist_c[i].size());
	}
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			int cnew = get_compressed(value[r][c], c) + 1;
			ways[r][c] = 0;
			if (r == 1 && c == 1)
				ways[r][c] = 1;
			if (r > 1 && c > 1)
				ways[r][c] = ways_pref[r-1][c-1];
			add_self(ways[r][c], -tree[value[r][c]].sum(cnew-1));
			ways_pref[r][c] = ways[r][c];
			if (r > 1)
				add_self(ways_pref[r][c], ways_pref[r-1][c]);
			if (c > 1)
				add_self(ways_pref[r][c], ways_pref[r][c-1]);
			if (r > 1 && c > 1)
				add_self(ways_pref[r][c], -ways_pref[r-1][c-1]);
//			cout<<"ways["<<r<<","<<c<<"]="<<ways[r][c]<<"\n";
		}
		for (int c = 1; c <= C; ++c) {
			int cnew = get_compressed(value[r][c], c) + 1;
			tree[value[r][c]].update(cnew, ways[r][c]);
		}
	}
	cout << ways[R][C] << '\n';
}
