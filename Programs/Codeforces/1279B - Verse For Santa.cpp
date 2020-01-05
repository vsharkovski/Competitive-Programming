// Problem : B. Verse For Santa
// Contest : Educational Codeforces Round 79 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1279/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

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
		ll s;
		cin >> n >> s;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			b[i] = a[i];
			if (i) b[i] += b[i-1];
		}
		int bestcnt = 0, bestpos = -1;
		if (b[n-1] <= s) {
			bestcnt = n;
			bestpos = -1;
		} else {
			for (int i = 0; i < n; ++i) {
				if (s < 0) break;
				int lo = i, hi = n-1, mid, endpos = lo;
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					if (b[mid] - b[i] <= s) {
						endpos = mid;
						lo = mid+1;
					} else {
						hi = mid-1;
					}
				}
				int cnt = endpos;
				if (cnt > bestcnt) {
					bestcnt = cnt;
					bestpos = i;
				}
				s -= a[i];
			}
		}
		cout << bestpos+1 << endl;
	}
}
