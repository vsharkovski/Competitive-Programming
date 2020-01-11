// Problem : E. Antenna Coverage
// Contest : Codeforces Round #600 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1253/E
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> l(n+1), r(n+1);
	l[0] = r[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int x, s;
		cin >> x >> s;
		l[i] = x-s;
		r[i] = x+s;
	}
	vector<int> dp(m+1);
	dp[m] = 0;
	for (int x = m-1; x >= 0; --x) {
		dp[x] = m-x;
		for (int i = 0; i <= n; ++i) {
			if (x < l[i]) {
				int d = l[i] - (x+1);
				dp[x] = min(dp[x], d + dp[min(m, r[i]+d)]);
			} else if (l[i] <= x+1 && x+1 <= r[i]) {
				dp[x] = dp[x+1];
				break;
			}
		}
	}
	cout << dp[0] << endl;
}
