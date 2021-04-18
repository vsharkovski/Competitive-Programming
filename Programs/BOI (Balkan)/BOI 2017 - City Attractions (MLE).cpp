#include <bits/stdc++.h>
using namespace std;

const int N = 300010;
const int M = 1<<20;

int n, k;
int a[N];
int init_val[N];

vector<int> graph[N];
int timer;
int tin[N], tout[N];

int succ[N];
int dist[N];

struct segtree {
	struct node {
		int mxval, mxpos, lazy;
		inline void push(node &l, node &r) {
			l.mxval += lazy;
			l.lazy += lazy;
			r.mxval += lazy;
			r.lazy += lazy;
			lazy = 0;
		}
		inline void pull(node &l, node &r) {
			if (l.mxval >= r.mxval) { // >= is important, not just =
				mxval = l.mxval;
				mxpos = l.mxpos;
			} else {
				mxval = r.mxval;
				mxpos = r.mxpos;
			}
		}
	};
	node tree[M];
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v].mxval = init_val[tl];
			tree[v].mxpos = tl;
			tree[v].lazy = 0;
			return;
		}
		int tm = (tl + tr) / 2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
		tree[v].pull(tree[2*v], tree[2*v+1]);
	}
	void update(int v, int tl, int tr, int l, int r, int x) {
		if (l > r) return;
		if (l <= tl && tr <= r) {
			tree[v].mxval += x;
			tree[v].lazy += x;
			return;
		}
		tree[v].push(tree[2*v], tree[2*v+1]);
		int tm = (tl + tr) / 2;
		update(2*v, tl, tm, l, min(r, tm), x);
		update(2*v+1, tm+1, tr, max(l, tm+1), r, x);
		tree[v].pull(tree[2*v], tree[2*v+1]);
	}
	inline int find_best() {
		return tree[1].mxpos;
	}
};
segtree tree;

void dfs1(int node, int par, int d) {
	tin[node] = timer++;
	init_val[tin[node]] = a[node] + d;
	for (int to : graph[node]) {
		if (to == par) continue;
		dfs1(to, node, d+1);
	}
	tout[node] = timer-1;
}

void dfs2(int node, int par) {
	succ[tin[node]] = tree.find_best();
	for (int to : graph[node]) {
		if (to == par) continue;
		// update nodes in subtree to be +1, all others -1
		tree.update(1, 1, n, 1, n, -1);
		tree.update(1, 1, n, tin[to], tout[to], 2);
		// go to child
		dfs2(to, node);
		// undo updates
		tree.update(1, 1, n, 1, n, 1);
		tree.update(1, 1, n, tin[to], tout[to], -2);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	timer = 1;
	dfs1(1, -1, 0);
	tree.build(1, 1, n);
	dfs2(1, -1);
	// simulate walking
	for (int i = 1; i <= n; ++i) {
		dist[i] = -1;
	}
	bool entered_cycle = false;
	int i = tin[1];
	dist[i] = 0;
	while (k > 0) {
		int j = succ[i];
		if (dist[j] == -1 || entered_cycle) {
			dist[j] = dist[i] + 1;
			i = j;
			--k;
		} else {
			// found cycle
			int csize = dist[i] - dist[j] + 1;
			k %= csize;
			entered_cycle = true;
		}
	}
	for (int node = 1; node <= n; ++node) {
		if (tin[node] == i) {
			cout << node << '\n';
			return 0;
		}
	}
}
