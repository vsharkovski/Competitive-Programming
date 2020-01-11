// Problem : E. Tree Painting
// Contest : Educational Codeforces Round 67 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1187/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 200010;

int n;
vector<int> adj[N];
int sbsz[N];
ll down[N];
ll ans;

void dfs(int u, int p) {
	sbsz[u] = 1;
	down[u] = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		sbsz[u] += sbsz[v];
		down[u] += down[v];
	}
	down[u] += sbsz[u];
}

void dfs2(int u, int p, ll updata) {
	ans = max(ans, updata + down[u] - sbsz[u] + n);
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs2(v, u, updata + (n - sbsz[v]) + down[u] - sbsz[u] - down[v]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	ans = 0;
	dfs2(1, -1, 0);
	cout << ans << endl;
}
