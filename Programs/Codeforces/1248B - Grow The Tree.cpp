#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	ll x = 0, y = 0;
	int i = 0, j = n-1, k = 0;
	while (i <= j) {
		if (k == 0) {
			x += a[i];
			++i;
		} else {
			y += a[j];
			--j;
		}
		k = 1 - k;
	}
	cout << x*x + y*y << endl;
}
