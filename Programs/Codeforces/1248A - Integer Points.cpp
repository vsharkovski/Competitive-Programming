#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll cnt[2][2] = {};
		for (int i = 0; i < 2; ++i) {
			int n;
			cin >> n;
			for (int j = 0; j < n; ++j) {
				int x;
				cin >> x;
				++cnt[i][x % 2];
			}
		}
		ll ans = 0;
		ans += (cnt[0][0] * cnt[1][0]);
		ans += (cnt[0][1] * cnt[1][1]);
		cout << ans << endl;
	}
}
