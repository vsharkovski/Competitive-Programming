#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
 
 
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll ans = a[n-1] - a[0];
	vector<ll> b(n-1);
	for (int i = 0; i < n-1; ++i) {
		b[i] = a[i] - a[i+1];
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < k-1; ++i) {
		ans += b[i];
	}
	cout << ans << '\n';
}
