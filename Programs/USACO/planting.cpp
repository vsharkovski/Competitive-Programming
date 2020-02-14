
// Problem : Problem 1. Grass Planting
// Contest : USACO 2019 January Contest, Silver
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=894
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<int> deg(n+1, 0);
	int ans = 0;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		ans = max(ans, ++deg[a]);
		ans = max(ans, ++deg[b]);
	}
	++ans;
	cout << ans << '\n';
}
