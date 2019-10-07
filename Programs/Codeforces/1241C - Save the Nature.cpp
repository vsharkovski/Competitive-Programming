#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200010;

inline ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll n, x, k, a, y, b, lcm;
ll p[maxn];
ll pre[maxn];

inline ll norm(ll x) {
	if (x < 0) x = 0;
	if (x > n) x = n;
	return x;
}

bool possible(int d) {
	ll ca = d / a;
	ll cb = d / b;
	ca = norm(ca);
	cb = norm(cb);
	ll cab = d / lcm;
	cab = norm(cab);
	ll cao = ca - cab;
	ll cbo = cb - cab;
	cao = norm(cao);
	cbo = norm(cbo);
	ca = cao;
	cb = cbo;
	ll res = 0;
	res += (pre[cab])/100 * (x+y);
	ll res1 = res;
	ll l = cab + 1;
	ll r = min(n, cab + 1 + ca - 1);
	if (l <= r) {
		res1 += (pre[r]-pre[l-1])/100 * x;
		l = cab + ca + 1;
		r = min(n, cab + ca + 1 + cb - 1);
		if (l <= r) {
			res1 += (pre[r]-pre[l-1])/100 * y;
		}
	}	
	ll res2 = res;
	l = cab + 1;
	r = min(n, cab + 1 + cb - 1);
	if (l <= r) {
		res2 += (pre[r]-pre[l-1])/100 * y;
		l = cab + cb + 1;
		r = min(n, cab + cb + 1 + ca - 1);
		if (l <= r) {
			res2 += (pre[r]-pre[l-1])/100 * x;
		}
	}
	return res1 >= k || res2 >= k;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
		}
		sort(p+1, p+1+n, greater<ll>());
		pre[0] = 0;
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i-1] + p[i];
		}
		cin >> x >> a >> y >> b >> k;
		lcm = a * b / gcd(a, b);
		int lo = 1, hi = n, mid, ans = 1e9;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (possible(mid)) {
				ans = mid;
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		if (ans == 1e9) ans = -1;
		cout << ans << endl;
	}
}
