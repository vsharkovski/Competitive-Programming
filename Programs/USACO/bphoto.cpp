#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


struct fenwick {
	int n;
	vector<int> tree;
	fenwick(int _n) {
		n = _n;
		tree.assign(n+1, 0);
	}
	void upd(int pos, int val) {
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
		if (l > r) return 0;
		return sum(r) - sum(l-1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("bphoto.in", "r", stdin);
	freopen("bphoto.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<int> h(n), uniques(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		uniques[i] = h[i];
	}
	sort(uniques.begin(), uniques.end());
	uniques.erase(unique(uniques.begin(), uniques.end()), uniques.end());
	int m = uniques.size();
	for (int i = 0; i < n; ++i) {
		h[i] = 1 + distance(uniques.begin(), lower_bound(uniques.begin(), uniques.end(), h[i]));
	}
	fenwick tl(m), tr(m);
	for (int i = 0; i < n; ++i) {
		tr.upd(h[i], 1);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		tr.upd(h[i], -1);
		int l = tl.sum(h[i]+1, m);
		int r = tr.sum(h[i]+1, m);
		if (max(l, r) > 2*min(l, r)) {
			++ans;
		}
		tl.upd(h[i], 1);
	}
	cout << ans << '\n';
}
