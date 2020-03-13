
// Problem : Problem 1. Bovine Genomics
// Contest : USACO 2017 US Open Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=741
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 505;
const int M = 505;

const int mod = 1e9 + 7;
const int prime = 7;
const int prime_inv = 142857144;
int prime_inv_pow[N];

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
	return x;
}

inline int mult(int x, int y) {
	return (ll)x * y % mod;
}

int n, m;
int hsh[2][N][M];

inline int subhash(int h[M], int l, int r) {
	int res = h[r];
	if (l) res = add(res, -h[l-1]);
	res = mult(res, prime_inv_pow[l]);
	return res;
}

bool possible(int l, int r) {
	vector<int> hashes;
	for (int i = 0; i < n; ++i) {
		hashes.push_back(subhash(hsh[0][i], l, r));
	}
	sort(hashes.begin(), hashes.end());
	for (int i = 0; i < n; ++i) {
		if (binary_search(hashes.begin(), hashes.end(), subhash(hsh[1][i], l, r))) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	#endif
	int charval[256] = {};
	charval['A'] = 1;
	charval['C'] = 2;
	charval['G'] = 3;
	charval['T'] = 4;
	{
		int p = 1;
		for (int i = 0; i < M; ++i) {
			prime_inv_pow[i] = p;
			p = mult(p, prime_inv);
		}
	}
	cin >> n >> m;
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < n; ++i) {
			int p = 1, h = 0;
			for (int j = 0; j < m; ++j) {
				char ch;
				cin >> ch;
				p = mult(p, prime);
				h = add(h, mult(p, charval[(int)ch]));
				hsh[k][i][j] = h;
			}
		}
	}
	int ans = m;
	for (int l = 0; l < m; ++l) {
		int lo = l, hi = m-1, mid, r = m*m*m;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (possible(l, mid)) {
				r = mid;
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		ans = min(ans, r-l+1);
	}
	cout << ans << '\n';
}
