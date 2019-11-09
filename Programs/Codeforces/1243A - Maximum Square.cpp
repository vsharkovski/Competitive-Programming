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
		int n;
		cin >> n;
		int cnt[1001] = {};
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			++cnt[x];
		}
		for (int i = 1000 - 1; i >= 1; --i) {
			cnt[i] += cnt[i+1];
		}
		int ans = 1;
		for (int i = 1000; i >= 1; --i) {
			if (cnt[i] >= i) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
}
