#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll median = a[n/2];
	ll cnteq = 0;
	for (int i = n/2; i < n; ++i) {
		if (a[i] == median) {
			++cnteq;
		} else {
			ll diff = a[i] - median;
			if (diff * cnteq <= k) {
				k -= diff * cnteq;
				median = a[i];
				++cnteq;
			} else {
				break;
			}
		}
	}
	median += k / cnteq;
	cout << median << endl;
}
