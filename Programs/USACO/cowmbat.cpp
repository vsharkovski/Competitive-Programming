
// Problem : Problem 3. Moortal Cowmbat
// Contest : USACO 2019 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=971
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int M = 26;
const int SZ = 1<<18;
const int inf = 1e9;

int n, m, k;
int cost[M][M];
int arr[N];
int pre[M][N]; // pre[c][i] = cost to convert [1, i] to char c
int dp[N];

struct segtree {
	int tree[SZ];
	segtree() {
		for (int i = 0; i < SZ; ++i) {
			tree[i] = inf;
		}
	}
	void update(int v, int tl, int tr, int pos, int val) {
		tree[v] = min(tree[v], val);
		if (tl < tr) {
			int tm = (tl + tr) / 2;
			if (pos <= tm) {
				update(2*v, tl, tm, pos, val);
			} else {
				update(2*v+1, tm+1, tr, pos, val);
			}
		}
	}
	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) return inf;
		if (l <= tl && tr <= r) return tree[v];
		int tm = (tl + tr) / 2;
		return	min(query(2*v, tl, tm, l, min(r, tm)),
					query(2*v+1, tm+1, tr, max(l, tm+1), r));
	}
} tree[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("cowmbat.in", "r", stdin);
	freopen("cowmbat.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		arr[i] = ch - 'a';
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> cost[i][j];
		}
	}
	for (int k = 0; k < m; ++k) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	for (int c = 0; c < m; ++c) {
		pre[c][0] = 0;
		for (int i = 1; i <= n+1; ++i) {
			pre[c][i] = pre[c][i-1];
			if (i <= n) pre[c][i] += cost[arr[i]][c];
		}
	}
	dp[n+1] = 0;
	for (int i = n; i >= 1; --i) {
		for (int c = 0; c < m; ++c) {
			tree[c].update(1, 1, n+1, i+1, dp[i+1] + pre[c][i]);
		}
		dp[i] = inf;
		if (i+k > n+1) continue;
		for (int c = 0; c < m; ++c) {
			int res = tree[c].query(1, 1, n+1, i+k, n+1);
			if (res < inf) {
				dp[i] = min(dp[i], -pre[c][i-1] + res);
			}
		}
	}
	cout << dp[1] << '\n';
}
