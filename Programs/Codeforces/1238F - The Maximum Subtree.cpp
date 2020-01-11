// Problem : F. The Maximum Subtree
// Contest : Educational Codeforces Round 74 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1238/F
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 300010;

int n, ans;
vector<int> adj[N];
int down[N];

int dfs(int u, int p) {
	int d[2] = {0, 0};
	for (int v : adj[u]) {
		if (v == p) continue;
		int x = dfs(v, u);
		if (x >= d[0]) {
			d[1] = d[0];
			d[0] = x;
		} else if (x > d[1]) {
			d[1] = x;
		}
	}
	int res = 1 + adj[u].size() - (p != -1);
	if (d[0]) res += d[0] - 1;
	if (d[1]) res += d[1] - 1;
	ans = max(ans, res);
	if (d[1]) res -= d[1] - 1;
	down[u] = res;
	return res;
}

void dfs2(int u, int p, int updata) {
	multiset<int> s;
	for (int v : adj[u]) {
		if (v == p) continue;
		s.insert(down[v]);
	}
	s.insert(updata);
	// assume u is root
	int res = 1 + adj[u].size();
	int i = 0;
	for (auto it = s.rbegin(); it != s.rend(); ++it, ++i) {
		if (i == 2) break;
		if (!(*it)) break;
		res += *it - 1;
	}
	ans = max(ans, res);
	for (int v : adj[u]) {
		if (v == p) continue;
		s.erase(s.find(down[v]));
		int res2 = 1 + adj[u].size() - 1;
		i = 0;
		for (auto it = s.rbegin(); it != s.rend(); ++it, ++i) {
			if (i == 1) break;
			if (!(*it)) break;
			res += *it - 1;
		}
		dfs2(v, u, res2);
		s.insert(down[v]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 0; i < n-1; ++i) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		ans = 0;
		dfs(1, -1);
		dfs2(1, -1, 0);
		cout << ans << endl;
	}
}
