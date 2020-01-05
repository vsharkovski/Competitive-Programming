// Problem : C. Stack of Presents
// Contest : Educational Codeforces Round 79 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1279/problem/c
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

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
		int n, m;
		cin >> n >> m;
		vector<int> a(n+1), inv(n+1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			inv[a[i]] = i;
		}
		ll ans = 0;
		int maxpos = 0;
		for (int i = 1; i <= m; ++i) {
			int b;
			cin >> b;
			b = inv[b];
			if (maxpos >= b) {
				ans += 1;
			} else {
				int realpos = b - (i-1);
				ans += 2*realpos - 1;
			}
			maxpos = max(maxpos, b);
		}
		cout << ans << endl;
	}
}
