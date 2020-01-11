// Problem : L. Divide The Students
// Contest : 2019-2020 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Teams Preferred)
// URL : https://codeforces.com/contest/1250/problem/L
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int solve(int b, vector<int> v) {
	sort(v.begin(), v.end());
	b -= v[2] - v[0];
	b -= v[2] - v[1];
	if (b < 0) return v[2];
	v[2] += b / 3;
	if (b % 3 != 0) v[2] += 1;
	return v[2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 1e9;
		ans = min(ans, solve(b, {a, 0, c}));
		for (int a1 = 1; a1 < a; ++a1) {
			ans = min(ans, solve(b, {a1, a-a1, c}));
		}
		for (int c1 = 1; c1 < c; ++c1) {
			ans = min(ans, solve(b, {a, c-c1, c1}));
		}
		cout << ans << endl;
	}
}
