// Problem : B. Modulo Equality
// Contest : Codeforces Round #609 (Div. 2)
// URL : https://codeforces.com/contest/1269/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 1e9 + 10;
	for (int k = 0; k < n; ++k) {
		int d = b[k] - a[0];
		if (d < 0) d += m;
		bool good = true;
		for (int i = 0; i < n; ++i) {
			int d2 = b[(i+k)%n] - a[i];
			if (d2 < 0) d2 += m;
			if (d2 != d) {
				good = false;
				break;
			}
		}
		if (good) {
			ans = min(ans, d);
		}
	}
	cout << ans << endl;
}
