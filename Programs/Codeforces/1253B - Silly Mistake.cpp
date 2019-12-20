#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int maxx = 1e6 + 1;
	int n;
	cin >> n;
	vector<int> tin(maxx, -1), tout(maxx, -1), ans;
	ans.push_back(-1);
	int lastend = -1, cnt = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a > 0) {
			if (lastend < tin[a]) {
				// entered this day
				cout << "-1\n";
				return 0;
			} else {
				// didn't enter this day
				tin[a] = i;
				++cnt;
			}
		} else {
			a = -a;
			if (lastend < tin[a]) {
				// entered this day
				if (tin[a] < tout[a]) {
					// also left
					cout << "-1\n";
					return 0;
				}
				tout[a] = i;
				--cnt;
			} else {
				// didn't enter this day
				cout << "-1\n";
				return 0;
			}
		}
		if (cnt == 0) {
			lastend = i;
			ans.push_back(i);
		}
	}
	if (cnt != 0) {
		cout << "-1\n";
		return 0;
	}
	cout << ans.size()-1 << endl;
	for (int i = 1; i < (int)ans.size(); ++i) {
		cout << ans[i] - ans[i-1] << ' ';
	}
}
