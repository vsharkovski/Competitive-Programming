
// Problem : Problem 1. Convention
// Contest : USACO 2018 December Contest, Silver
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=858
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, c;
vector<int> t;

bool possible(int maxwait) {
	int buses = m;
	for (int i = 0; i < n; ++i) {
		if (buses == 0) return false;
		int j = i;
		while (j < n && j-i < c && t[j]-t[i] <= maxwait) {
			++j;
		}
		// take [i, j-1] on one bus
		--buses;
		i = j-1;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	#endif
	cin >> n >> m >> c;
	t.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	sort(t.begin(), t.end());
	int lo = 0, hi = t[n-1], mid, ans = hi;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (possible(mid)) {
			ans = mid;
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	cout << ans << '\n';
}
