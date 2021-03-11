
// Problem : D. Zero Remainder Array
// Contest : Codeforces - Codeforces Round #653 (Div. 3)
// URL : https://codeforces.com/contest/1374/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i] %= k;
		}
		sort(a.begin(), a.end());
		if (a[n-1] == 0) {
			cout << 0 << '\n';
			continue;
		}
		int maxcnt = 0, maxval = -1;
		for (int i = 0; i < n; ++i) {
			int val = (k - a[i]) % k;
			int j = i;
			while (j < n && a[j] == a[i]) {
				++j;
			}
			int cnt = j-i;
			if (val != 0) {
				if (cnt > maxcnt) {
					maxcnt = cnt;
					maxval = val;
				} else if (cnt == maxcnt && val > maxval) {
					maxval = val;
				}
			}
			i = j-1;
		}
		//for(int i=0;i<n;++i){cout<<a[i]<<" ";}cout<<'\n';
		//cout << "maxcnt="<<maxcnt <<" maxval="<<maxval<<'\n';
		ll ans = (ll)k * (maxcnt-1) + maxval + 1;
		cout << ans << '\n';
	}
}
