// Problem : D. Ghd
// Contest : Codeforces Round #213 (Div. 1)
// URL : https://codeforces.com/contest/364/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

const int N = 1000010;

int n;
ll a[N];
ll divs[N/10];
ll cnt[N/10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dist(0, n-1);
	ll ans = 1;
	for (int A = 0; A < 10; ++A) {
		int idx = dist(rng);
		ll x = a[idx];
		int divcnt = 0;
		for (ll y = 1; y*y <= x; ++y) {
			if (x % y == 0) {
				divs[divcnt++] = y;
				if (y != x/y) divs[divcnt++] = x/y;
			}
		}
		sort(divs, divs+divcnt);
		for (int i = 0; i < divcnt; ++i) {
			cnt[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			ll g = gcd(x, a[i]);
			++cnt[lower_bound(divs, divs+divcnt, g) - divs];
		}
		for (int i = 0; i < divcnt; ++i) {
			int totcnt = 0;
			for (int j = i; j < divcnt; ++j) {
				if (divs[j] % divs[i] == 0) {
					totcnt += cnt[j];
				}
			}
			if (2*totcnt >= n) {
				ans = max(ans, divs[i]);
			}
		}
	}
	cout << ans << endl;
}
