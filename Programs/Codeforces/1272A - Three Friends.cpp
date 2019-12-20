// Problem : A. Three Friends
// Contest : Codeforces Round #605 (Div. 3)
// URL : https://codeforces.com/contest/1272/problem/A
// Memory Limit : 256.000000MB 
// Time Limit : 1000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		ll ans = 1e18;
		for (int k = 0; k < (1 << 3); ++k) {
			for (int m = 0; m < (1 << 3); ++m) {
				int x[3] = {a, b, c};
				ll res = 0;
				for (int i = 0; i < 3; ++i) {
					if (k & (1 << i)) {
						if (m & (1 << i)) {
							++x[i];
						} else {
							--x[i];
						}
					}
					for (int j = 0; j < i; ++j) {
						res += abs(x[i] - x[j]);
					}
				}
				ans = min(ans, res);
			}
		}
		cout << ans << endl;
	}
	
	
}
