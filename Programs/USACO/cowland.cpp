
// Problem : Problem 1. Cow Land
// Contest : USACO 2019 February Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=921
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;

int n;
vector<int> adj[N];
int value[N];

int sbsz[N];
bool removed[N];

vector<pii> cL[N], cR[N];

inline int getlabel(vector<pii>& v, int a) {
	auto it = lower_bound(v.begin(), v.end(), pii(a, 0));
	if (it == v.end() || it->first != a) return -1;
	return it->second;
}

struct segtree {
	int dfscalls, base, root;
	vector<int> initval;
	segtree() {
		dfscalls = 0;
	}
	void getpaths(int u, int p, int x) {
		x ^= value[u];
		initval.push_back(x);
		cL[u].emplace_back(root, dfscalls++);
		for (int v : adj[u]) {
			if (v == p || removed[v]) continue;
			getpaths(v, u, x);
		}
		cR[u].emplace_back(root, dfscalls-1);
	}
	struct node {
		int val, lazy;
		node() : val(0), lazy(0) {};
		inline void push(node& l, node& r) {
			l.take(lazy);
			r.take(lazy);
			lazy = 0;
		}
		inline void take(int x) {
			val ^= x;
			lazy ^= x;
		}
	};
	vector<node> tree;
	void build() {
		base = 1;
		while (base < dfscalls) base *= 2;
		tree.resize(2*base);
		build(1, 0, base-1);
	}
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v].val = initval[tl];
		} else {
			int tm = (tl + tr) / 2;
			build(2*v, tl, tm);
			build(2*v+1, tm+1, tr);
		}
	}
	void update(int v, int tl, int tr, int l, int r, int x) {
		if (l > r) return;
		if (l == tl && tr == r) {
			tree[v].take(x);
			return;
		}
		tree[v].push(tree[2*v], tree[2*v+1]);
		int tm = (tl + tr) / 2;
		update(2*v, tl, tm, l, min(r, tm), x);
		update(2*v+1, tm+1, tr, max(l, tm+1), r, x);
	}
	int query(int v, int tl, int tr, int pos) {
		if (tl == tr) {
			return tree[v].val;
		}
		tree[v].push(tree[2*v], tree[2*v+1]);
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			return query(2*v, tl, tm, pos);
		} else {
			return query(2*v+1, tm+1, tr, pos);
		}
	}
};

segtree tree[N];
int cparent[N];
int cdepth[N];

void getsbsz(int u, int p) {
	sbsz[u] = 1;
	for (int v : adj[u]) {
		if (v == p || removed[v]) continue;
		getsbsz(v, u);
		sbsz[u] += sbsz[v];
	}
}
int findcentroid(int u, int p, int m) {
	for (int v : adj[u])
		if (v != p && !removed[v] && sbsz[v] > m/2)
			return findcentroid(v, u, m);
	return u;
}
int decompose(int u, int p) {
	getsbsz(u, -1);
	int c = findcentroid(u, -1, sbsz[u]);
	//
	cparent[c] = p;
	cdepth[c] = p == -1 ? 0 : cdepth[p]+1;
	tree[c].root = c;
	tree[c].getpaths(c, -1, 0);
	tree[c].build();
	//
	removed[c] = true;
	for (int v : adj[c]) {
		if (removed[v]) continue;
		decompose(v, c);
	}
	removed[c] = false;
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("cowland.in", "r", stdin);
	freopen("cowland.out", "w", stdout);
	#endif
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> value[i];
		removed[i] = false;
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	decompose(1, -1);
	for (int i = 1; i <= n; ++i) {
		sort(cL[i].begin(), cL[i].end());
		sort(cR[i].begin(), cR[i].end());
	}
	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, x;
			cin >> u >> x;
			x = value[u] ^ x;
			value[u] ^= x;
			int a = u;
			while (a != -1) {
				tree[a].update(1, 0, tree[a].base-1, getlabel(cL[u], a), getlabel(cR[u], a), x);
				a = cparent[a];
			}
		} else {
			int u, v;
			cin >> u >> v;
			int a = u, b = v;
			if (cdepth[a] < cdepth[b]) swap(a, b);
			while (cdepth[a] > cdepth[b]) a = cparent[a];
			while (a != b) {
				a = cparent[a];
				b = cparent[b];
			}
			int ul = getlabel(cL[u], a), ur = getlabel(cR[u], a);
			int vl = getlabel(cL[v], a), vr = getlabel(cR[v], a);
			int res = 0;
			res ^= tree[a].query(1, 0, tree[a].base-1, ul);
			res ^= tree[a].query(1, 0, tree[a].base-1, vl);
			if (ul <= vl && vr <= ur) {
				// u is ancestor of v in the decomposition
				// the path from root to u was cancelled
				res ^= value[u];
			} else if (vl <= ul && ur <= vr) {
				// v is ancestor of u
				res ^= value[v];
			} else {
				// both have ancestors which are different children of root
				// value[root] was cancelled because it was counted twice
				res ^= value[a];
			}
			cout << res << '\n';
		}
		//if (qi == 1) break;
	}
}
