// Problem : J. The Parade
// Contest : 2019-2020 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Teams Preferred)
// URL : https://codeforces.com/contest/1250/problem/J
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 30010;

int n;
ll k;
vector<ll> a;

bool possible(ll c) {
	vector<ll> b = a;
	ll rows = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] >= c) {
			rows += b[i] / c;
			b[i] %= c;
		}
	}
	for (int i = 0; i < n-1; ++i) {
		if (b[i] + b[i+1] >= c) {
			rows += 1;
			b[i+1] -= (c - b[i]);
			b[i] -= b[i];
		}
	}
	return rows >= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ll lo = 1, hi = 1e13, mid, ans = 1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (possible(mid)) {
				ans = mid;
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}
		cout << ans*k << endl;
	}
}
