
// Problem : D. Omkar and Circle
// Contest : Codeforces - Codeforces Round #655 (Div. 2)
// URL : https://codeforces.com/contest/1372/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(2*n+2), p(2*n+2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << a[1] << '\n';
		return 0;
	}
	if (n == 3) {
		cout << max(a[1]+a[2], max(a[2]+a[3], a[3]+a[1])) << '\n';
		return 0;
	}
	for (int i = n+1; i <= 2*n; ++i) {
		a[i] = a[i-n];
	}
	p[0] = 0;
	p[1] = a[1];
	for (int i = 2; i <= 2*n; ++i) {
		p[i] = p[i-2] + a[i];
	}
	ll ans = 0;
	for (int i = 1; i+n-2 <= 2*n; ++i) {
		ans = max(ans, p[i+n-2] - p[i+1] + a[i] + a[i+1]);
	}
	/*
	cout << "a: ";
	for (int i = 1; i <= 2*n; ++i) {
		cout << setw(2) << right << a[i] << ' ';
	}
	cout << "\np: ";
	for (int i = 1; i <= 2*n; ++i) {
		cout << setw(2) << right << p[i] << ' ';
	}
	cout << '\n';
	*/
	cout << ans << '\n';
}
