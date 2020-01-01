#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


struct MedianFinder {
	priority_queue<int, vector<int>, less<int>> lo;
	priority_queue<int, vector<int>, greater<int>> hi;
	void push(int x) {
		lo.push(x);
		hi.push(lo.top());
		lo.pop();
		if (lo.size() < hi.size()) {
			lo.push(hi.top());
			hi.pop();
		}
	}
	int getmedian() {
		if (lo.size() >= hi.size()) {
			return lo.top();
		}
		return hi.top();
	}
} heaps;

const int N = 200010;
const int SZ = 1<<19;

int n;
int invperm[N];

struct segtree {
	struct node {
		int cnt;
		ll sum, lazy;
		node() : cnt(0), sum(0), lazy(0) {}
		inline void merge(node& l, node& r) {
			cnt = sum = 0;
			if (l.cnt) cnt += l.cnt, sum += l.sum;
			if (r.cnt) cnt += r.cnt, sum += r.sum;
		}
		inline void push(node& l, node& r) {
			l.receive(lazy);
			r.receive(lazy);
			lazy = 0;
		}
		inline void receive(int lz) {
			lazy += lz;
			sum += ll(lz) * cnt;
		}
	};
	node tree[SZ];
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			tree[v].sum = 0;
			tree[v].lazy = 0;
			tree[v].cnt = 1;
		} else {
			int tm = (tl + tr) / 2;
			build(2*v, tl, tm);
			build(2*v+1, tm+1, tr);
			tree[v].merge(tree[2*v], tree[2*v+1]);
		}
	}
	pll getdata(int v, int tl, int tr, int l, int r) {
		if (l > r) return pll(0, 0);
		if (l <= tl && tr <= r) {
			return pll(tree[v].sum*(tree[v].cnt>0), tree[v].cnt);	
		}
		tree[v].push(tree[2*v], tree[2*v+1]);
		int tm = (tl + tr) / 2;
		pll lres = getdata(2*v, tl, tm, l, min(r, tm));
		pll rres = getdata(2*v+1, tm+1, tr, max(l, tm+1), r);
		return pll(lres.first + rres.first, lres.second + rres.second);
	}
	void disable(int v, int tl, int tr, int pos) {
		if (tl == tr) {
			tree[v].cnt = 0;
		} else {
			tree[v].push(tree[2*v], tree[2*v+1]);
			int tm = (tl + tr) / 2;
			if (pos <= tm) {
				disable(2*v, tl, tm, pos);
			} else {
				disable(2*v+1, tm+1, tr, pos);
			}
			tree[v].merge(tree[2*v], tree[2*v+1]);
		}
	}
	void update(int v, int tl, int tr, int l, int r) {
		if (l > r) return;
		if (l <= tl && tr <= r) {
			tree[v].receive(1);
			return;
		}
		tree[v].push(tree[2*v], tree[2*v+1]);
		int tm = (tl + tr) / 2;
		update(2*v, tl, tm, l, min(r, tm));
		update(2*v+1, tm+1, tr, max(l, tm+1), r);
		tree[v].merge(tree[2*v], tree[2*v+1]);
	}
} tree;

struct fenwicktree {
	int tree[N];
	void build() {
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
	int sum(int l, int r) {
		return sum(r) - sum(l-1);
	}
} inversiontree;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int perm;
        cin >> perm;
		invperm[perm] = i;
	}
	tree.build(1, 1, n);
	inversiontree.build();
	ll total_inversions = 0;
	int minpos = n+1, maxpos = -1;
	for (int k = 1; k <= n; ++k) {
		int i = invperm[k];
		minpos = min(minpos, i);
		maxpos = max(maxpos, i);
		inversiontree.update(i, 1);
		total_inversions += inversiontree.sum(i+1, n);
		ll ans = total_inversions;
		tree.update(1, 1, n, i, n);
		tree.disable(1, 1, n, i);
		heaps.push(i);
		int median = heaps.getmedian();
		pll res1 = tree.getdata(1, 1, n, minpos, median);
		pll res2 = tree.getdata(1, 1, n, median+1, maxpos);
		ans += res1.first + (res2.second*k - res2.first);
		cout << ans << ' ';
	}
}
