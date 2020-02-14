
// Problem : Problem 3. Mountain View
// Contest : USACO 2019 January Contest, Silver
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=896
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
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<pii> points;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		int x1 = x + y, y1 = y - x;
		points.emplace_back(x1, y1);
	}
	sort(points.begin(), points.end(), [] (const pii a, const pii b) {
		return a.first != b.first ? a.first > b.first : a.second > b.second;
	});
	set<int> s;
	int ans = 0;
	for (pii& p : points) {
		int y = p.second;
		auto it = s.lower_bound(y);
		if (it == s.end()) {
			++ans;
		}
		s.insert(y);
	}
	cout << ans << '\n';
}
