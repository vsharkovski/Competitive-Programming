
// Problem : E1. Reading Books (easy version)
// Contest : Codeforces - Codeforces Round #653 (Div. 3)
// URL : https://codeforces.com/contest/1374/problem/E1
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
	int n, k;
	cin >> n >> k;
	vector<int> t[4], p[4];
	for (int i = 0; i < n; ++i) {
		int x, a, b;
		cin >> x >> a >> b;
		t[a | (b<<1)].push_back(x);
	}
	for (int m = 0; m < 4; ++m) {
		sort(t[m].begin(), t[m].end());
		p[m].resize(t[m].size());
		for (int i = 0; i < (int)t[m].size(); ++i) {
			p[m][i] = t[m][i];
			if (i > 0) p[m][i] += p[m][i-1];
		}
	}
	int ans = -1;
	for (int takeboth = 0; takeboth <= min(k, (int)t[0b11].size()); ++takeboth) {
		int res = 0;
		if (takeboth > 0) res += p[0b11][takeboth-1];
		int needsingle = k - takeboth;
		if (needsingle > 0) {
			if ((int)t[0b01].size() < needsingle) continue;
			if ((int)t[0b10].size() < needsingle) continue;
			res += p[0b01][needsingle-1];
			res += p[0b10][needsingle-1];
		}
		if (ans == -1 || res < ans) {
			ans = res;
		}
	}
	cout << ans << '\n';
}
