
// Problem : F. Removing Leaves
// Contest : Codeforces - Codeforces Round #656 (Div. 3)
// URL : https://codeforces.com/contest/1385/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 200100;

int n, k, root;
vector<int> adj[N];
bool canleaf[N];
int dp0[N];
int dp1[N];

void dfs(int u, int p) {
	int lc = 0, nlc = 0; // leaf children, non leaf children
	dp0[u] = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp0[u] += dp0[v];
		if (canleaf[v]) {
			++lc;
		} else {
			++nlc;
		}
	}
	dp0[u] += lc / k;
	canleaf[u] = false;
	if (lc + nlc == 0 || (nlc == 0 && lc % k == 0)) {
		canleaf[u] = true;
	}
	dp1[u] = dp0[u];
	if (p != -1 && (lc + 1) % k == 0) {
		// can remove one more set
		++dp1[u];
	}
	if (nlc == 1) {
		if ((lc + (p != -1)) % k == 0) {
			int res = (lc + (p != -1)) / k;
			for (int v : adj[u]) {
				if (v == p) continue;
				if (canleaf[v]) {
					res += dp0[v];
				} else {
					res += dp1[v]; // the only one
				}
			}
			dp1[u] = max(dp1[u], res);
		}
	} else if (nlc == 0) {
		if (lc > 0 && (lc + (p != -1) - 1 + k) % k == 0) {
			int res = (lc + (p != -1) - 1) / k;
			for (int v : adj[u]) {
				if (v == p) continue;
				res += dp0[v];
			}
			for (int v : adj[u]) {
				if (v == p) continue;
				dp1[u] = max(dp1[u], res - dp0[v] + dp1[v]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 0; i < n-1; ++i) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		if (k == 1) {
			cout << n-1 << '\n';
			continue;
		}
		if (n == 2) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			if (adj[i].size() >= 2) {
				root = i;
				break;
			}
		}
		dfs(root, -1);
		cout << dp1[root] << '\n';
	}
}
