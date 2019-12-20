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
		vector<int> ans;
		int x = 1;
		while (x <= n) {
			int l = x, r = n, m, y = x;
			while (l <= r) {
				m = (l + r) / 2;
				if (n / m == n / x) {
					y = m;
					l = m+1;
				} else {
					r = m-1;
				}
			}
			ans.push_back(n / x);
			x = y+1;
		}
		ans.push_back(n/(n+1));
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int x : ans) {
			cout << x << ' ';
		}
		cout << endl;
	}
}
