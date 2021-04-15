#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifndef _DEBUG
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	#endif
	int A, B, n, m;
	cin >> A >> B >> n >> m;
	++n, ++m;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n-1; ++i) {
		cin >> a[i];
	}
	a[n-1] = A;
	for (int i = 0; i < m-1; ++i) {
		cin >> b[i];
	}
	b[m-1] = B;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = n-1; i >= 1; --i) {
		a[i] -= a[i-1];
	}
	for (int i = m-1; i >= 1; --i) {
		b[i] -= b[i-1];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
//	cout<<"a: ";for(int x:a)cout<<x<<" ";cout<<"\n";
//	cout<<"b: ";for(int x:b)cout<<x<<" ";cout<<"\n";
	ll ans = 0;
	ans += b[0]*(n-1);
	ans += a[0]*(m-1);
	for (int i = 1, j = 1; i < n && j < m;) {
		if (a[i] < b[j]) {
			ans += a[i]*(m-j);
			++i;
		} else {
			ans += b[j]*(n-i);
			++j;
		}
	}
	cout << ans << '\n';
}
