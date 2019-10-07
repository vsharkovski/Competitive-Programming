#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	ll sum = 0, maxi = 0;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		maxi = max(maxi, a[i]);
	}
	if (sum % 2 != 0 || maxi > sum - maxi) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}
