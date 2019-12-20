#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n+1), b(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a.begin()+1, a.end());
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		b[i] = a[i];
		if (i > m) b[i] += b[i-m];
		res += b[i];
		cout << res << ' ';
	}
}
