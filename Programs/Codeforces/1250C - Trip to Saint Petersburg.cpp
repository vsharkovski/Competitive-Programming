// Problem : C. Trip to Saint Petersburg
// Contest : 2019-2020 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Teams Preferred)
// URL : https://codeforces.com/contest/1250/problem/C
// Memory Limit : 512.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll inf = 1e18;
const int N = 200010;
const int SZ = 1<<19;

ll k;
vector<tuple<int,int,ll>> projects[N];

struct node {
	ll lazy, maxval;
	int maxpos;
	bool active;
	node() : lazy(0), maxval(-inf), maxpos(-1), active(true) {}
	inline void push(node& l, node& r) {
		l.lazy += lazy;
		l.maxval += lazy;
		r.lazy += lazy;
		r.maxval += lazy;
		lazy = 0;
	}
	inline void merge(node& l, node& r) {
		maxval = -inf;
		maxpos = -1;
		if (l.active && l.maxval > maxval) {
			maxval = l.maxval;
			maxpos = l.maxpos;
		}
		if (r.active && r.maxval > maxval) {
			maxval = r.maxval;
			maxpos = r.maxpos;
		}
	}
} tree[SZ];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		tree[v].active = false;
		tree[v].maxpos = tl;
		tree[v].maxval = -k*(tl+1);
		tree[v].lazy = 0;
	} else {
		int tm = (tl + tr) / 2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
	}
}

void activate_node(int v, int tl, int tr, int pos) {
	if (tl == tr) {
		tree[v].active = true;
	} else {
		tree[v].push(tree[2*v], tree[2*v+1]);
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			activate_node(2*v, tl, tm, pos);
		} else {
			activate_node(2*v+1, tm+1, tr, pos);
		}
		tree[v].merge(tree[2*v], tree[2*v+1]);
	}
}

void add_range(int v, int tl, int tr, int l, int r, ll val) {
	if (l > r) return;
	if (l == tl && tr == r) {
		tree[v].maxval += val;
		tree[v].lazy += val;
	} else {
		tree[v].push(tree[2*v], tree[2*v+1]);
		int tm = (tl + tr) / 2;
		add_range(2*v, tl, tm, l, min(r, tm), val);
		add_range(2*v+1, tm+1, tr, max(l, tm+1), r, val);
		tree[v].merge(tree[2*v], tree[2*v+1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		ll p;
		cin >> l >> r >> p;
		projects[l].emplace_back(i, r, p);
	}
	build(1, 1, N-1);
	ll bestprofit = 0;
	int bestL = -1, bestR = -1;
	for (int L = N-1; L >= 1; --L) {
		for (auto& project : projects[L]) {
			int r = get<1>(project);
			ll p = get<2>(project);
			activate_node(1, 1, N-1, r);
			add_range(1, 1, N-1, r, N-1, p);
		}
		int R = tree[1].maxpos;
		ll profit = k*L + tree[1].maxval;
		if (!projects[L].empty())
		if (profit > bestprofit) {
			bestprofit = profit;
			bestL = L;
			bestR = R;
		}
	}
	if (bestprofit == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << bestprofit << ' ' << bestL << ' ' << bestR << ' ';
	vector<int> taken;
	for (int x = bestL; x <= bestR; ++x) {
		for (auto& project : projects[x]) {
			int i = get<0>(project);
			int r = get<1>(project);
			if (r <= bestR) {
				taken.push_back(i);
			}
		}
	}
	cout << taken.size() << endl;
	for (int i : taken) {
		cout << i << ' ';
	}
	cout << endl;
}
