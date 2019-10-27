#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const ll maxa = sqrt(100010) + 1;
	bitset<maxa> iscomp;
	vector<ll> primes;
	for (ll i = 2; i < maxa; ++i) {
		if (iscomp[i]) continue;
		primes.push_back(i);
		for (ll j = i*i; j < maxa; j += i) {
			iscomp[j] = true;
		}
	}
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	map<vector<pii>, ll> cnt;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		vector<pii> pd, pd2;
		for (ll p : primes) {
			if (p*p > a) continue;
			if (a % p == 0) {
				ll c = 0;
				while (a % p == 0) {
					++c;
					a /= p;
				}
				c = c % k;
				if (c > 0) {
					pd.emplace_back(p, c);
					pd2.emplace_back(p, k - c);
				}
			}
		}
		if (a > 1) {
			pd.emplace_back(a, 1);
			pd2.emplace_back(a, k - 1);
		}
		ans += cnt[pd2];
		++cnt[pd];
	}
	cout << ans << endl;
}
