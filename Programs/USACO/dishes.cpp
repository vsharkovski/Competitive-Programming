
// Problem : Problem 2. Dishwashing
// Contest : USACO 2019 February Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=922
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int M = 1<<18;

struct segtree {
	struct node {
		int minval, maxval;
		node() : minval(N), maxval(-1) {}
		node(node l, node r) {
			merge(l, r);
		}
		inline void merge(node& l, node& r) {
			minval = min(l.minval, r.minval);
			maxval = max(l.maxval, r.maxval);
		}
	} tree[M];
	void reset(int n) {
		int m = 1;
		while (m < n) m *= 2;
		for (int i = 0; i < 2*m; ++i) {
			tree[i] = node();
		}
	}
	void update(int v, int tl, int tr, int pos, int val) {
		if (tl == tr) {
			if (val == -1) {
				tree[v] = node();
			} else {
				tree[v].minval = val;
				tree[v].maxval = val;
			}
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(2*v, tl, tm, pos, val);
		} else {
			update(2*v+1, tm+1, tr, pos, val);
		}
		tree[v].merge(tree[2*v], tree[2*v+1]);
	}
	node query(int v, int tl, int tr, int l, int r) {
		if (l > r) return node();
		if (l <= tl && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return node(query(2*v, tl, tm, l, min(r, tm)),
					query(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
} tree;

int nn;
int initperm[N];
pii uniques[N];
int p[N];
vector<int> stacks[N];

bool possible(int n) {
	for (int i = 0; i < n; ++i) {
		uniques[i] = make_pair(initperm[i], i);
		stacks[i].clear();
	}
	sort(uniques, uniques+n);
	for (int i = 0; i < n; ++i) {
		p[uniques[i].second] = i;
	}
	tree.reset(n);
	int L = 0, R = 0;
	int target = 0;
	for (int pos = 0; pos < n; ++pos) {
		int x = p[pos];
		int i = tree.query(1, 0, n-1, 0, x-1).maxval + 1;
		int j = tree.query(1, 0, n-1, x+1, n-1).minval;
		i = max(i, L);
		R = max(R, i);
		if (i > j) {
			return false;
		}
		tree.update(1, 0, n-1, x, i);
		stacks[i].push_back(x);
		while (true) {
			while (L <= R && stacks[L].empty()) {
				++L;
			}
			if (L > R || stacks[L].back() > target) {
				break;
			}
			stacks[L].pop_back();
			tree.update(1, 0, n-1, target, -1);
			++target;
		}
	}
	return target == n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
	#endif
	cin >> nn;
	for (int i = 0; i < nn; ++i) {
		cin >> initperm[i];
	}
	int lo = 1, hi = nn, mid, ans = lo;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (possible(mid)) {
			ans = mid;
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	cout << ans << '\n';
}
