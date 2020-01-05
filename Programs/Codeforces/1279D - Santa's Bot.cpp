// Problem : D. Santa's Bot
// Contest : Educational Codeforces Round 79 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1279/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 5000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const ll mod = 998244353;

ll powmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}

inline ll inv(ll x) {
	return powmod(x, mod-2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 1000010;
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	vector<ll> cnt(N, 0);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		a[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> a[i][j];
			++cnt[a[i][j]];
		}
	}
	ll ans = 0;
	ll ninv = inv(n);
	for (int i = 0; i < n; ++i) {
		ll res = 1;
		res = (res * ninv) % mod;
		res = (res * ninv) % mod;
		res = (res * inv(a[i].size())) % mod;
		for (int x : a[i]) {
			ll res2 = (res * cnt[x]) % mod;
			ans = (ans + res2) % mod;
		}
	}
	cout << ans << endl;
}
