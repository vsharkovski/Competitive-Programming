#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		int cnt = 0, d = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			if (cnt == -1) continue;
			int di = b[i] - a[i];
			if (di != 0) {
				if (d == 0) {
					++cnt;
					d = di;
				} else {
					if (di != d) {
						cnt = -1;
					} else {
						if (i > 0 && b[i-1] - a[i-1] == 0 && cnt > 0) {
							cnt = -1;
						} else {
							cnt = 1;
						}
					}
				}
			}
		}
		if (cnt >= 0 && d >= 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
