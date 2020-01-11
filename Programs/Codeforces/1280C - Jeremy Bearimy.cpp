// Problem : C. Jeremy Bearimy
// Contest : Codeforces Round #607 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1280/C
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int K = 300010;
const int N = 2*K;

int k, n;
vector<pii> adj[N];
int down[N];
ll G, M;

void dfs(int u, int p) {
	down[u] = 1;
	for (auto& to : adj[u]) {
		int v = to.first;
		if (v == p) continue;
		dfs(v, u);
		down[u] += down[v];
		int cv = down[v];
		int cu = n - cv;
		ll w = to.second;
		G += w * (cu % 2);
		M += w * min(cu, cv);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> k;
		n = 2*k;
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 0; i < n-1; ++i) {
			int a, b, w;
			cin >> a >> b >> w;
			adj[a].emplace_back(b, w);
			adj[b].emplace_back(a, w);
		}
		G = 0;
		M = 0;
		dfs(1, -1);
		cout << G << ' ' << M << endl;
	}
}
