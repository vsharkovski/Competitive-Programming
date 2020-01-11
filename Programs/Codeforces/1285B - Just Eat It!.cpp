// Problem : B. Just Eat It!
// Contest : Codeforces Round #613 (Div. 2)
// URL : https://codeforces.com/contest/1285/problem/B
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
		cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ll bestres = -1e18;
		ll minpref = 0;
		ll pref = 0;
		for (int i = 0; i < n-1; ++i) {
			pref += a[i];
			bestres = max(bestres, pref - minpref);
			minpref = min(minpref, pref);
		}
		minpref = pref = a[0];
		for (int i = 1; i < n; ++i) {
			pref += a[i];
			bestres = max(bestres, pref - minpref);
			minpref = min(minpref, pref);
		}
		if (pref > bestres) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}	
}
