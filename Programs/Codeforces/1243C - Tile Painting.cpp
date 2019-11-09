#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> pd;
	for (ll p = 2; p*p <= n; ++p) {
		while (n % p == 0) {
			pd.push_back(p);
			n /= p;
		}
	}
	if (n > 1) {
		pd.push_back(n);
	}
	if (pd.empty()) {
		cout << n << endl;
	} else if (pd[0] == pd.back()) {
		cout << pd[0] << endl;
	} else {
		cout << 1 << endl;
	}
}
