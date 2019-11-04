#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e7 + 10;
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

inline ll inv(ll a) {
	return powmod(a, mod-2);
}

int n;
ll fact[maxn];
ll invfact[maxn];
ll pow2[maxn];

ll choose(ll a, ll b) {
	if (a < b) return 0;
	ll res = fact[a];
	res = (res * invfact[b]) % mod;
	res = (res * invfact[a-b]) % mod;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fact[0] = invfact[0] = 1;
	pow2[0] = 1;
	ll pow3 = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (fact[i-1] * i) % mod;
		invfact[i] = inv(fact[i]);
		pow2[i] = (pow2[i-1] * 2) % mod;
		pow3 = (pow3 * 3) % mod;
	}
	ll ans = pow3;
	for (int i = n/2 + 1; i <= n; ++i) {
		ll res = 2;
		res = (res * choose(n, i)) % mod;
		res = (res * pow2[n - i]) % mod;
		ans = (ans - res + mod) % mod;
	}
	cout << ans << endl;
}
