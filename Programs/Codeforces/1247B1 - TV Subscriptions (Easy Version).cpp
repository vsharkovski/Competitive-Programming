#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	vector<int> cnt(1000010, 0);
	while (t--) {
		int n, k, d;
		cin >> n >> k >> d;
		vector<int> a(n+1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			cnt[a[i]] = 0;
		}
		int numactive = 0;
		int ans = k;
		for (int i = 1; i <= n; ++i) {
			if (i-d >= 1) {
				int x = a[i-d];
				--cnt[x];
				if (cnt[x] == 0) {
					--numactive;
				}
			}
			int x = a[i];
			++cnt[x];
			if (cnt[x] == 1) {
				++numactive;
			}
			if (i >= d) {
				ans = min(ans, numactive);
			}
		}
		cout << ans << endl;
	}
}
