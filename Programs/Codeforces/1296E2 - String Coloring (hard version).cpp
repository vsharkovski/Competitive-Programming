// Problem : E2. String Coloring (hard version)
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/E2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans(n+1);
	char last[26] = {};
	int numcolors = 0;
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		int best = -1;
		for (int x = 0; x < numcolors; ++x) {
			if (last[x] <= c && (best == -1 || last[x] > last[best])) {
				best = x;
			}
		}
		if (best == -1) {
			ans[i] = numcolors;
			++numcolors;
		} else {
			ans[i] = best;
		}
		last[ans[i]] = c;
	}
	cout << numcolors << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << ans[i]+1 << ' ';
	}
}
