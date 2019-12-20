// Problem : A. Happy Birthday, Polycarp!
// Contest : Codeforces Round #606 (Div. 2, based on Technocup 2020 Elimination Round 4)
// URL : https://codeforces.com/contest/1277/problem/A
// Memory Limit : 256.000000MB 
// Time Limit : 1000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> v;
	ll m = 1, len = 1;
	while (len <= 10) {
		ll nx = 10*m;
		for (ll k = m; k < nx; k += m) {
			v.push_back(k);
		}
		++len;
		m = 10*m + 1;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		auto it = upper_bound(v.begin(), v.end(), n);
		cout << distance(v.begin(), it) << endl;
	}
}
