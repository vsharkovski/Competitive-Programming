#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;
const int BASE = 1<<17;

int n;
pii pos[N];
int other[N];

struct node {
	vector<int> values;
	void merge(node& l, node& r) {
		values.resize(l.values.size()+r.values.size());
		auto it3 = values.begin();
		auto it1 = l.values.begin(), it2 = r.values.begin();
		while (it1 != l.values.end() && it2 != r.values.end()) {
			if (*it1 < *it2) {
				*it3 = *it1;
				++it3, ++it1;
			} else {
				*it3 = *it2;
				++it3, ++it2;
			}
		}
		while (it1 != l.values.end()) {
			*it3 = *it1;
			++it3, ++it1;
		}
		while (it2 != r.values.end()) {
			*it3 = *it2;
			++it3, ++it2;
		}
	}
	inline int get_count(int l, int r) {
		auto it1 = lower_bound(values.begin(), values.end(), l);
		auto it2 = upper_bound(values.begin(), values.end(), r);
		return distance(it1, it2);
	}
} tree[2*BASE];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		tree[v].values.push_back(other[tl]);
		return;
	}
	int tm = (tl + tr) / 2;
	build(2*v, tl, tm);
	build(2*v+1, tm+1, tr);
	tree[v].merge(tree[2*v], tree[2*v+1]);
}

int query(int v, int tl, int tr, int l, int r, int ql, int qr) {
	if (l > r) return 0;
	if (l == tl && tr == r) return tree[v].get_count(ql, qr);
	int tm = (tl + tr) / 2;
	int res = 0;
	res += query(2*v, tl, tm, l, min(r, tm), ql, qr);
	res += query(2*v+1, tm+1, tr, max(l, tm+1), r, ql, qr);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
    #endif
	cin >> n;
	n *= 2;
	for (int x = 1; x <= n/2; ++x) {
		pos[x].first = pos[x].second = -1;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (pos[x].first == -1) {
			pos[x].first = i;
		} else {
			pos[x].second = i;
		}
	}
	for (int x = 1; x <= n/2; ++x) {
		other[pos[x].first] = pos[x].second;
		other[pos[x].second] = pos[x].first;
	}
	build(1, 0, n-1);
    ll ans = 0;
    for (int x = 1; x <= n/2; ++x) {
		int l = pos[x].first, r = pos[x].second;
		if (l > r) swap(l, r);
		ans += query(1, 0, n-1, r+1, n-1, l+1, r-1);
		ans += query(1, 0, n-1, 0, l-1, l+1, r-1);
	}
	ans /= 2;
    cout << ans << '\n';
}
