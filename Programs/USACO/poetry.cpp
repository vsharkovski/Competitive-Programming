
// Problem : Problem 1. Cow Poetry
// Contest : USACO 2019 January Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=897
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	return x;
}

inline void add_self(int& x, int y) {
	x = add(x, y);
}

inline int mult(int x, int y) {
	return (ll) x * y % mod;
}

int power(int x, int y) {
	int res = 1;
	while (y > 0) {
		if (y & 1) res = mult(res, x);
		x = mult(x, x);
		y /= 2;
	}
	return res;
}

const int N = 5005;
const int M = 100005;
const int K = 5005;
const int A = 30;

int n, m, k;
int syl[N], cls[N];
int dp[K]; // how many lines can be made for a specific prefix
int classlines[N];
int grouplines[A];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> syl[i] >> cls[i];
		--cls[i];
		classlines[i] = 0;
	}
	for (int g = 0; g < A; ++g) {
		grouplines[g] = 0;
	}
	for (int i = 0; i < m; ++i) {
		char ch;
		cin >> ch;
		int g = ch - 'A';
		++grouplines[g];
	}
	dp[0] = 1;
	for (int i = 0; i < k; ++i) {
		for (int w = 0; w < n; ++w) {
			if (i + syl[w] <= k) {
				add_self(dp[i + syl[w]], dp[i]);
			}
		}
	}
	for (int w = 0; w < n; ++w) {
		add_self(classlines[cls[w]], dp[k - syl[w]]);
	}
	int cur = 1, nxt;
	for (int g = 0; g < A; ++g) {
		if (grouplines[g] == 0) continue;
		nxt = 0;
		for (int c = 0; c < n; ++c) {
			if (classlines[c] == 0) continue;
			add_self(nxt, mult(cur, power(classlines[c], grouplines[g])));
		}
		cur = nxt;
	}
	cout << cur << '\n';
}
