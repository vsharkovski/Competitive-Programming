#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 100100;
const int BASE = 1<<17;
const int inf = 1e9;

int n, Q;
int X[N], Y[N];

inline int D(int i, int j) {
	return abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
}

struct FenwickTree {
	int tree[N];
	FenwickTree() {
		memset(tree, 0, sizeof(tree));
	}
	void update(int pos, int val) {
		while (pos <= n) {
			tree[pos] += val;
			pos += pos & -pos;
		}
	}
	int sum(int pos) {
		int res = 0;
		while (pos >= 1) {
			res += tree[pos];
			pos -= pos & -pos;
		}
		return res;
	}
} fenwick;

struct SegmentTree {
	int tree[2*BASE];
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			if (tl == 1 || tl == n) {
				// edges, will never be queried
				tree[v] = inf;
			} else {
				tree[v] = -D(tl-1, tl) - D(tl, tl+1) + D(tl-1, tl+1);
			}
			return;
		}
		int tm = (tl + tr) / 2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
		tree[v] = min(tree[2*v], tree[2*v+1]);
	}
	void update(int v, int tl, int tr, int pos) {
		if (tl == tr) {
			tree[v] = -D(tl-1, tl) - D(tl, tl+1) + D(tl-1, tl+1);
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(2*v, tl, tm, pos);
		} else {
			update(2*v+1, tm+1, tr, pos);
		}
		tree[v] = min(tree[2*v], tree[2*v+1]);
	}
	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) return inf;
		if (l <= tl && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return	min(query(2*v, tl, tm, l, min(r, tm)),
					query(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
} mintree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	#endif
	cin >> n >> Q;
	for (int i = 1; i <= n; ++i) {
		cin >> X[i] >> Y[i];
		if (i > 1) {
			fenwick.update(i, D(i-1, i));
		}
	}
	mintree.build(1, 1, n);
	while (Q--) {
		char ch;
		cin >> ch;
		if (ch == 'U') {
			int i, x, y;
			cin >> i >> x >> y;
			if (i > 1) {
				fenwick.update(i, -D(i-1, i));
			}
			if (i < n) {
				fenwick.update(i+1, -D(i, i+1));
			}
			X[i] = x, Y[i] = y;
			if (i > 1) {
				fenwick.update(i, D(i-1, i));
				mintree.update(1, 1, n, i-1);
			}
			if (i < n) {
				fenwick.update(i+1, D(i, i+1));
				mintree.update(1, 1, n, i+1);
			}
			if (i > 1 && i < n) {
				mintree.update(1, 1, n, i);
			}
		} else {
			int I, J;
			cin >> I >> J;
			if (I == J) {
				cout << 0 << '\n';
			} else if (I+1 == J) {
				cout << D(I, I+1) << '\n';
			} else {
				int res = fenwick.sum(J) - fenwick.sum(I);
				res += mintree.query(1, 1, n, I+1, J-1);
				cout << res << '\n';
			}
		}
	}
}
