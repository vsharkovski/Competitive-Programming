#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct segtree {
	struct node {
		ll sumx;
		int cnt;
		node(ll sumx, int cnt) : sumx(sumx), cnt(cnt) {}
		node() : sumx(0), cnt(0) {}
		node(node l, node r) {
			sumx = l.sumx + r.sumx;
			cnt = l.cnt + r.cnt;
		}
	};
	int base;
	vector<node> tree;
	segtree(int n) {
		base = 1;
		while (base < n) base *= 2;
		tree.resize(2*base + 2);
	}
	void update(int v, int tl, int tr, int pos, ll x) {
		if (tl == tr) {
			tree[v].sumx += x;
			tree[v].cnt += 1;
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(2*v, tl, tm, pos, x);
		} else {
			update(2*v+1, tm+1, tr, pos, x);
		}
		tree[v] = node(tree[2*v], tree[2*v+1]);
	}
	node query(int v, int tl, int tr, int l, int r) {
		if (l > r) return node();
		if (l <= tl && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return node(query(2*v, tl, tm, l, min(r, tm)),
					query(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
};

ll solve(vector<pii>& points) {
	ll ans = 0;
	int n = points.size();
	if (n == 0) return 0;
	vector<int> uniques(n);
	for (int i = 0; i < n; ++i) {
		uniques[i] = points[i].second;
	}
	sort(uniques.begin(), uniques.end());
	uniques.erase(unique(uniques.begin(), uniques.end()), uniques.end());
	int m = uniques.size();
	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(uniques.begin(), uniques.end(), points[i].second);
		points[i].second = distance(uniques.begin(), it);
	}
	segtree tree(m);
	sort(points.begin(), points.end(), [&](pii& a, pii& b){
		return a.first < b.first;
	});
	for (int i = n-1; i >= 0; --i) {
		ll x = points[i].first;
		int v = points[i].second;
		auto res = tree.query(1, 0, tree.base-1, v, m-1);
		ans += -res.cnt*x + res.sumx;
		tree.update(1, 0, tree.base-1, v, x);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	
	#endif
	int n;
	cin >> n;
	vector<int> xcoords(n), vels(n), order(n);
	vector<pii> points[2];
	for (int i = 0; i < n; ++i) {
		cin >> xcoords[i];
		order[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> vels[i];
		if (vels[i] >= 0) {
			points[0].emplace_back(xcoords[i], vels[i]);
		} else {
			points[1].emplace_back(xcoords[i], -vels[i]);
		}
	}
	for (auto& p : points[1]) {
		p.first = points[1].back().first - p.first;
	}
	for (int i = 10; i < 2; ++i) {
		cout << "i="<<i<<" points: ";
		for (auto& p : points[i]) {
			cout << "("<<p.first<<","<<p.second<<"),";
		}
		cout << "\n";
	}
	ll ans = 0;
	ans += solve(points[0]);
	ans += solve(points[1]);
	sort(order.begin(), order.end(), [&](int i, int j){
		return xcoords[i] < xcoords[j];
	});
	ll res = 0;
	segtree::node negs;
	for (int pos = 0; pos < n; ++pos) {
		int i = order[pos];
		if (vels[i] >= 0) {
			res += (ll)negs.cnt*xcoords[i] - negs.sumx;
		} else { 
			negs.sumx += xcoords[i];
			negs.cnt += 1;
		}
	}
	segtree::node posit;
	for (int pos = n-1; pos >= 0; --pos) {
		int i = order[pos];
		if (vels[i] < 0) {
			res += posit.sumx - (ll)posit.cnt*xcoords[i];
		} else {
			posit.sumx += xcoords[i];
			posit.cnt += 1;
		}
	}
	res /= 2;
	ans += res;
	cout << ans << '\n';
}
