#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n+1), b(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = b[i-1] + a[i];
	}
	if (b[n] == 1) {
		cout << "-1\n";
		return 0;
	}
	vector<ll> divs; // prime
	ll sum = b[n];
	for (ll div = 2; div*div <= sum; ++div) {
		if (sum % div == 0) {
			divs.push_back(div);
			while (sum % div == 0) {
				sum /= div;
			}
		}
	}
	if (sum > 1) {
		divs.push_back(sum);
	}
	ll ans = 1e18;
	for (ll d : divs) {
		ll res = 0;
		for (int i = 1; i <= n; ++i) {
			res += min(b[i] % d, d - (b[i] % d));
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
}
