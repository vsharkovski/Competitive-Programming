#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	vector<ll> d[2];
	for (int i = 0; i < 2; ++i) {
		ll x;
		cin >> x;
		for (ll p = 2; p*p <= x; ++p) {
			if (x % p == 0) {
				d[i].push_back(p);
				while (x % p == 0) {
					x /= p;
				}
			}
		}
		if (x > 1) {
			d[i].push_back(x);
		}
	}
	int ans = 0;
	int i = 0, j = 0;
	while (i < d[0].size() && j < d[1].size()) {
		if (d[0][i] < d[1][j]) {
			++i;
		} else if (d[0][i] > d[1][j]) {
			++j;
		} else {
			++ans;
			++i;
			++j;
		}
	}
	cout << 1+ans << endl;
}
