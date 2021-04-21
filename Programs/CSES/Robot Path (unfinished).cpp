/*
What's left to do: Detect intersections between two vertical lines. It's just casework.
I gave up because it's too annoying to implement and I'm tired.
Might finish it some day.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T>
string P(T p) {
	return "("+to_string(p.first)+","+to_string(p.second)+")";
}

pair<int, pii> better_result(pair<int, pii> a, pair<int, pii> b) {
	return a.first < b.first ? a : b;
}

pair<int, pii> rotate_result(pair<int, pii> a) {
	swap(a.second.first, a.second.second);
	return a;
}

// U, R, D, L
int chtod[256];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int N = 100010;
const int M = 1<<19;

int n, mx, my;
int command[N];
pll preal[N];
pii pcomp[N];
vector<tuple<int, int, int>> events[2*N];
multiset<int> values[2*N];

namespace Tree {
	int tree[M];
	void build() {
		for (int i = 0; i < M; ++i) {
			tree[i] = N;
		}
	}
	void update(int pos, int val, int v = 1, int tl = 0, int tr = mx-1) {
		if (tl == tr) {
			tree[v] = val;
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(pos, val, 2*v, tl, tm);
		} else {
			update(pos, val, 2*v+1, tm+1, tr);
		}
		tree[v] = min(tree[2*v], tree[2*v+1]);
	}
	int query(int l, int r, int v = 1, int tl = 0, int tr = mx-1) {
		if (l > r) return N;
		if (l <= tl && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return min(query(l, min(r, tm), 2*v, tl, tm), query(max(l, tm+1), r, 2*v+1, tm+1, tr));
	}
}

pair<int, pii> sweep() {
	pair<int, pii> ans(n, pcomp[n]);
	cout<<"SWEEP\n";
	for (int i = 0; i <= n; ++i) {
		cout << i << " "<<P(preal[i])<<" "<<P(pcomp[i]) << "\n";
	}
	for (int y = 0; y < my; ++y) {
		events[y].clear();
	}
	for (int x = 0; x < mx; ++x) {
		values[x].clear();
	}
	Tree::build();
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		tie(x1, y1) = pcomp[i];
		tie(x2, y2) = pcomp[i+1];
		if (x1 == x2) {
			// vertical line
			if (y1 > y2) swap(y1, y2);
			events[y1].emplace_back(-1, i, x1);
			events[y2].emplace_back(-2, i, x1);
		} else {
			// horizontal line
			if (x1 > x2) swap(x1, x2);
			events[y1].emplace_back(i, x1, x2);
		}
	}
	for (int y = 0; y < my; ++y) {
		for (auto& event : events[y]) {
			int type, i, x;
			tie(type, i, x) = event;
			if (type != -1) continue;
			cout<<"started vertical, i="<<i<<", at "<<P(pii(x,y))<<"\n";
			int j = values[x].empty() ? N : *values[x].begin();
			values[x].insert(i);
			if (j > i) {
				// new minimum value for the leaf corresponding to this position
				Tree::update(x, *ptr);
				cout<<" updated min to i\n";
			}
		}
		for (auto& event : events[y]) {
			int i, x1, x2;
			tie(i, x1, x2) = event;
			if (i < 0) continue;
			int j = Tree::query(x1, x2);
			cout<<"found horizontal, i="<<i<<", at y="<<y<<", x["<<x1<<","<<x2<<"]\n";
			cout<<" min. active in range: "<<j<<"\n";
			if (j < i && j+1 != i) {
				// collision will happen
				cout<<" collision\n";
				ans = better_result(ans, make_pair(i, pii(pcomp[j].first, y)));
			}
		}
		for (auto& event : events[y]) {
			int type, i, x;
			tie(type, i, x) = event;
			if (type != -2) continue;
			cout<<"removed vertical, i="<<i<<", at "<<P(pii(x, y))<<"\n";
			auto ptr = values[x].find(i);
			bool first = ptr == values[x].begin();
			values[x].erase(ptr);
			if (first && !values[x].empty()) {
				// new min value
				Tree::update(x, *values[x].begin());
				cout<<" updated min to "<<*values[x].begin()<<"\n";
			}
		}
	}
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	chtod['U'] = 0;
	chtod['R'] = 1;
	chtod['D'] = 2;
	chtod['L'] = 3;
	cin >> n;
	ll x = 0, y = 0;
	vector<ll> cx, cy;
	cx.push_back(0);
	cy.push_back(0);
	preal[0] = pii(0, 0);
	for (int i = 1; i <= n; ++i) {
		char ch;
		ll len;
		cin >> ch >> len;
		ll x1 = x + len * dx[chtod[(int)ch]];
		ll y1 = y + len * dy[chtod[(int)ch]];
		cx.push_back(x1);
		cy.push_back(y1);
		preal[i] = pii(x1, y1);
		x = x1;
		y = y1;
	}
	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());
	cx.erase(unique(cx.begin(), cx.end()), cx.end());
	cy.erase(unique(cy.begin(), cy.end()), cy.end());
	mx = cx.size();
	my = cy.size();
	for (int i = 0; i <= n; ++i) {
		pcomp[i].first = lower_bound(cx.begin(), cx.end(), preal[i].first) - cx.begin();
		pcomp[i].second = lower_bound(cy.begin(), cy.end(), preal[i].second) - cy.begin();
	}
	auto res = make_pair(n, pcomp[n]);
	for (int iter = 0; iter < 2; ++iter) {
		auto res2 = sweep();
		if (iter) res2 = rotate_result(res2);
		res = better_result(res, res2);
		// rotate
		swap(mx, my);
		for (int i = 0; i <= n; ++i) {
			swap(preal[i].first, preal[i].second);
			swap(pcomp[i].first, pcomp[i].second);
		}
	}
//	cout << "lastline="<<res.first<<" lastpoint="<<P(res.second)<<"\n";
	pll lastpreal;
	lastpreal.first = cx[res.second.first];
	lastpreal.second = cy[res.second.second];
	preal[res.first+1] = lastpreal;
	ll ans = 0;
	for (int i = 0; i <= res.first; ++i) {
		if (preal[i].first == preal[i+1].first) {
			ans += abs(preal[i+1].second - preal[i].second);
		} else {
			ans += abs(preal[i+1].first - preal[i].first);
		}
	}
	cout << ans << '\n';
}
