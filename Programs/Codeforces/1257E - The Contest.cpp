// Problem : E. The Contest
// Contest : Educational Codeforces Round 76 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1257/E
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sizes[3];
	cin >> sizes[0] >> sizes[1] >> sizes[2];
	int n = sizes[0] + sizes[1] + sizes[2];
	vector<int> a(n+2);
	for (int j = 1; j <= 3; ++j) {
		for (int i = 0; i < sizes[j-1]; ++i) {
			int x;
			cin >> x;
			a[x] = j;
		}
	}
	vector<int> dp1(n+2), dp2(n+2), dp3(n+2);
	/*
	first: 1, second: 3, third: 2 in input
	dp1[i] = cost to move [1..i] to first
	dp2[i] = cost to move [i..n] to second
	dp3[i] = cost to move [1..i] to third
	*/
	dp1[0] = 0;
	dp3[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp1[i] = dp1[i-1] + (a[i] != 1);
		dp3[i] = dp3[i-1] + (a[i] != 2);
	}
	dp2[n+1] = 0;
	for (int i = n; i >= 1; --i) {
		dp2[i] = dp2[i+1] + (a[i] != 3);
	}
	int ans = 1e9;
	int best = dp1[0] - dp3[0];
	for (int i = 1; i <= n+1; ++i) {
		int x = best + dp2[i] + dp3[i-1];
		ans = min(ans, x);
		best = min(best, dp1[i] - dp3[i]);
	}
	cout << ans << endl;
}
