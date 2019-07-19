#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll inf = 1e18;
const int MAXN = 100010;
const int MAXLOG = 17;

int N, S, Q, E;
pii edges[MAXN];
vector<pii> adj[MAXN];
bool shop[MAXN];
ll dist[MAXN];

int depth[MAXN];
int P[MAXN][MAXLOG];
ll dp[MAXN][MAXLOG];

void dfs(int u, int p, int d, ll w) {
	depth[u] = d;
	P[u][0] = p;
	dist[u] = w;
	dp[u][0] = shop[u] ? w : inf;
	for (auto& to : adj[u]) {
		int v = to.first;
		if (v != p) {
			dfs(v, u, d+1, w+to.second);
			dp[u][0] = min(dp[u][0], dp[v][0]);
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int j = MAXLOG-1; j >= 0; --j) {
		if (depth[a] - (1<<j) >= depth[b]) {
			a = P[a][j];
		}
	}
	if (a == b) return a;
	for (int j = MAXLOG-1; j >= 0; --j) {
		if (P[a][j] != -1 && P[a][j] != P[b][j]) {
			a = P[a][j];
			b = P[b][j];
		}
	}
	return P[a][0];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> S >> Q >> E;
	for (int i = 1; i <= N-1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = {u, v};
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for (int i = 0; i < S; ++i) {
		int c;
		cin >> c;
		shop[c] = true;
	}
	memset(P, -1, sizeof(P));
	dfs(E, -1, 0, 0);
	for (int i = 1; i <= N; ++i) {
		dp[i][0] -= 2*dist[i];
	}
	for (int j = 1; j < MAXLOG; ++j) {
		for (int i = 1; i <= N; ++i) {
			if (P[i][j-1] != -1) {
				P[i][j] = P[ P[i][j-1] ][j-1];
				dp[i][j] = min(dp[i][j-1], dp[ P[i][j-1] ][j-1]);
			}
		}
	}
	for (int i = 1; i <= N-1; ++i) {
		int &u = edges[i].first, &v = edges[i].second;
		if (depth[u] > depth[v]) {
			swap(u, v); // deeper node should be second
		}
	}
	for (int q = 1; q <= Q; ++q) {
		int I, R;
		cin >> I >> R;
		I = edges[I].second;
		if (LCA(I, R) != I) { // can escape
			cout << "escaped\n";
		} else if (dp[I][0] > ll(N-1)*1e9) { // no shop in I's subtree
			cout << "oo\n";
		} else { // there is shop
			ll res = inf;
			int u = R;
			for (int j = MAXLOG-1; j >= 0; --j) {
				int pr = P[u][j];
				if (pr != -1 && depth[pr] >= depth[I]) {
					res = min(res, dp[u][j]);
					u = pr;
				}
			}
			res = min(res, dp[I][0]);
			res += dist[R];
			cout << res << '\n';
		}
	}
}
