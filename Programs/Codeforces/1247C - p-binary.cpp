#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, p;
	cin >> n >> p;
	ll ans = -1;
	for (ll k = 0; k <= 30; ++k) {
		ll m = n - k*p;
		if (m < 0 || k > m) {
			break;
		}
		ll sum = k;
		for (int i = k-1; i >= 0; --i) {
			ll x = 1;
			while (sum + x <= m) {
				sum += x;
				x *= 2;
			}
		}
		if (sum == m) {
			ans = k;
			break;
		}
	}
	cout << ans << endl;
}
