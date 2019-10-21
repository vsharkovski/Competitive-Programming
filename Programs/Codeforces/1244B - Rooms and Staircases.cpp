#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int minx = n+1, maxx = -1;
		for (int i = 1; i <= n; ++i) {
			char ch;
			cin >> ch;
			if (ch == '1') {
				minx = min(minx, i);
				maxx = max(maxx, i);
			}
		}
		int ans = n;
		if (minx <= n) {
			ans = max(ans, 2*maxx);
			ans = max(ans, 2*(n-minx+1));
			ans = max(ans, maxx + (n-maxx+1));
			ans = max(ans, (n-minx+1) + minx);
		}
		cout << ans << endl;
	}
}
