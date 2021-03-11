
// Problem : E. Tree Shuffling
// Contest : Codeforces - Codeforces Round #646 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1363/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 200100;

int n;
vector<int> adj[N];
int cost[N];
int B[N], C[N];
ll ans;

pii dfs(int u, int p, int mincostup) {
	pii w;
	if (B[u] == 0 && C[u] == 1) ++w.second;
	else if (B[u] == 1 && C[u] == 0) ++w.first;
	for (int v : adj[u]) {
		if (v == p) continue;
		pii res = dfs(v, u, min(mincostup, cost[u]));
		w.first += res.first;
		w.second += res.second;
	}
	if (cost[u] < mincostup) {
		int m = min(w.first, w.second);
		ans += (ll)cost[u] * 2 * m;
		w.first -= m;
		w.second -= m;
	}
	return w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i] >> B[i] >> C[i];
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0;
	pii res = dfs(1, -1, 1e9 + 1);
	if (res.first + res.second > 0) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
}
