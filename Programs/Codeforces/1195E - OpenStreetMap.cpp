// Problem : E. OpenStreetMap
// Contest : Codeforces Round #574 (Div. 2)
// URL : https://codeforces.com/contest/1195/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct MinimumQueue {
	deque<int> q;
	inline void push(int x) {
		while (!q.empty() && q.back() > x) {
			q.pop_back();
		}
		q.push_back(x);
	}
	inline void erase(int x) {
		if (!q.empty() && q.front() == x) {
			q.pop_front();
		}
	}
	inline int min() {
		return q.front();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	ll G, X, Y, Z;
	cin >> G >> X >> Y >> Z;
	vector<vector<int>> h(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			h[i][j] = G;
			G = (G * X + Y) % Z;
		}
	}
	vector<vector<int>> g(n, vector<int>(m));
	for (int j = 0; j < m; ++j) {
		MinimumQueue q;
		for (int i = 0; i < n; ++i) {
			q.push(h[i][j]);
			if (i >= a) {
				q.erase(h[i-a][j]);
			}
			if (i >= a-1) {
				g[i][j] = q.min();
			}
		}
	}
	ll ans = 0;
	for (int i = a-1; i < n; ++i) {
		MinimumQueue q;
		for (int j = 0; j < m; ++j) {
			q.push(g[i][j]);
			if (j >= b) {
				q.erase(g[i][j-b]);
			}
			if (j >= b-1) {
				ans += q.min();
			}
		}
	}
	cout << ans << endl;
}
