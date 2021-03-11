
// Problem : C. Circle of Monsters
// Contest : Codeforces - Educational Codeforces Round 85 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1334/problem/C
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<ll> a(n+1), b(n+1);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}
		a[n] = a[0], b[n] = b[0];
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			if (b[i] < a[i+1]) {
				ans += a[i+1] - b[i];
				a[i+1] = b[i];
			}
		}
		a[0] = a[n];
		ll mn = 1e18;
		for (int i = 0; i < n; ++i) {
			mn = min(mn, a[i]);
		}
		ans += mn;
		cout << ans << '\n';
	}
}
