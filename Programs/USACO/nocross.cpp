#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int D = 4;

struct segtree {
	int base;
	vector<int> tree;
	segtree(int size) {
		base = 1;
		while (base < size) base *= 2;
		tree.resize(2*base + 2);
	}
	void update(int pos, int val) {
		update(1, 0, base-1, pos, val);
	}
	void update(int v, int tl, int tr, int pos, int val) {
		if (tl == tr) {
			tree[v] = max(tree[v], val);
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(2*v, tl, tm, pos, val);
		} else {
			update(2*v+1, tm+1, tr, pos, val);
		}
		tree[v] = max(tree[2*v], tree[2*v+1]);
	}
	int query(int l, int r) {
		return query(1, 0, base-1, l, r);
	}
	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) return 0;
		if (l <= tl && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return	max(query(2*v, tl, tm, l, min(r, tm)),
					query(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
    #endif
	int n;
	cin >> n;
	vector<int> a(n), pos(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		--b;
		pos[b] = i;
	}
	segtree tree(n+1);
    // key factor: a and b are permutations
    // so this solution is O(n * d * log n)
    // dp[i] = max(1 + dp[j]); 0 <= j < i; abs(a[i]-b[j]) <= D
	for (int i = 0; i < n; ++i) {
		vector<int> pot;
		for (int x = max(0, a[i]-D); x <= min(n-1, a[i]+D); ++x) {
			pot.push_back(pos[x]);
		}
		sort(pot.rbegin(), pot.rend());
		for (int j : pot) {
			int dp = 1 + tree.query(0, j-1);
			tree.update(j, dp);
		}
	}
	cout << tree.query(0, n-1) << '\n';
}

/*
// // // // O(n^2) solution:

#include <bits/stdc++.h>
using namespace std;

inline void self_max(int &a, const int b) {
	if (b > a) {
		a = b;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	#ifndef _DEBUG
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = n-1; i >= 0; --i) {
		for (int j = n-1; j >= 0; --j) {
			dp[i][j] = 0;
			if (i+1 < n) {
				self_max(dp[i][j], dp[i+1][j]);
			}
			if (j+1 < n) {
				self_max(dp[i][j], dp[i][j+1]);
			}
			if (abs(a[i] - b[j]) <= 4) {
				self_max(dp[i][j], 1 + dp[i+1][j+1]);
			}
		}
	}
	cout << dp[0][0] << '\n';
}
*/
