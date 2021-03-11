
// Problem : C. Functions again
// Contest : Codeforces Round #407 (Div. 2)
// URL : https://codeforces.com/contest/789/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const ll inf = 1e18;
	const int N = 100100;
	static ll a[N];
	static ll s[N];
	static ll m[N];
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	a[n+1] = a[n+2] = 0;
	s[n+1] = s[n+2] = 0;
	s[n] = 0;
	m[n] = 0;
	for (int i = n-1; i >= 1; --i) {
		s[i] = s[i+2] + abs(a[i] - a[i+1]);
		m[i] = s[i] - s[i+1];
	}
	ll ans = -inf;
	ll maxx[2] = {0, 0};
	for (int i = n; i >= 1; --i) {
		int p = i % 2;
		// l and r have same parity
		ans = max(ans, m[i] + maxx[1-p]);
		// l and r have different parity
		ans = max(ans, m[i] - maxx[1-p]);
		maxx[p] = max(maxx[p], m[i]);
	}
	cout << ans << '\n';
}
