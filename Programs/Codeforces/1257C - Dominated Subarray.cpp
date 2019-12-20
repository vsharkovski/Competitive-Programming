#include <bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n+1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		vector<int> lastpos(n+1, 0);
		int j = 0;
		int ans = 1e9;
		for (int i = 1; i <= n; ++i) {
			if (j < lastpos[a[i]]) {
				ans = min(ans, i-lastpos[a[i]]+1);
			}
			j = max(j, lastpos[a[i]]);
			lastpos[a[i]] = i;
		}
		if (ans == 1e9) ans = -1;
		cout << ans << endl;
	}
}
