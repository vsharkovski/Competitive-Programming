
// Problem : Problem 2. Cowpatibility
// Contest : USACO 2018 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=862
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 50010;
const int K = 5;
const int M = 1000010;

const int mod1 = 1e9 + 7;
const int prime1 = 1000003;
int prime1pow[K];
const int mod2 = 1e9 + 9;
const int prime2 = 1000033;
int prime2pow[K];

inline int add(int x, int y, int mod) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
	return x;
}

inline int mult(int x, int y, int mod) {
	return (ll) x * y % mod;
}

inline pii addHash(pii h, int sz, int x) {
	h.first = add(h.first, mult(x, prime1pow[sz], mod1), mod1);
	h.second = add(h.second, mult(x, prime2pow[sz], mod2), mod2);
	return h;
}

ll ans;
int data[K];
map<pii, int> cnt;

int getcnt(int i, int sz, pii hsh) {
	if (i == K) {
		if (sz > 0) {
			int res = cnt[hsh]++;
			if (sz % 2 == 0) res = -res;
			return res;
		}
		return 0;
	}
	return	getcnt(i+1, sz, hsh) +
			getcnt(i+1, sz+1, addHash(hsh, sz, data[i]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("cowpatibility.in", "r", stdin);
	freopen("cowpatibility.out", "w", stdout);
	#endif
	prime1pow[0] = 1;
	prime2pow[0] = 1;
	for (int i = 1; i < K; ++i) {
		prime1pow[i] = mult(prime1pow[i-1], prime1, mod1);
		prime2pow[i] = mult(prime2pow[i-1], prime2, mod2);
	}
	ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < K; ++j) {
			cin >> data[j];
		}
		sort(data, data+K);
		int num = getcnt(0, 0, pii(0, 0)); // # so far with any of these flavours
		ans += i - num;
	}
	cout << ans << '\n';
}
