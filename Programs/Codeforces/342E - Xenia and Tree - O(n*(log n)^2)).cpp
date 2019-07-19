#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;
const int maxn = 100010;
const int maxlog = 17;

int n, q;
vector<int> adj[maxn];
int ans[maxn]; // minimum distance from this node to red node

int depth[maxn];
int P[maxn][maxlog]; // P[i][j] = 2**j -th parent of node i

void dfs_LCA(int u, int p, int d) {
	depth[u] = d;
	P[u][0] = p;
	for (int v : adj[u]) {
		if (v != p) {
			dfs_LCA(v, u, d+1);
		}
	}
}

void preprocess_LCA() {
	memset(P, -1, sizeof(P));
	dfs_LCA(1, -1, 0);
	for (int j = 1; j < maxlog; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (P[i][j-1] != -1) {
				P[i][j] = P[ P[i][j-1] ][j-1];
			}
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	for (int j = maxlog-1; j >= 0; --j) {
		if (depth[u] - (1 << j) >= depth[v]) {
			u = P[u][j];
		}
	}
	if (u == v) return u;
	for (int j = maxlog-1; j >= 0; --j) {
		if (P[u][j] != -1 && P[u][j] != P[v][j]) {
			u = P[u][j];
			v = P[v][j];
		}
	}
	return P[u][0];
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2*depth[LCA(u, v)];
}

bool removed[maxn];
int sbsz[maxn];
int par[maxn]; // parent of this node in the centroid tree

void dfs_sbsz(int u, int p) {
	sbsz[u] = 1;
	for (int v : adj[u]) {
		if (v != p && !removed[v]) {
			dfs_sbsz(v, u);
			sbsz[u] += sbsz[v];
		}
	}
}

int find_centroid(int u, int p, int n) {
	for (int v : adj[u]) {
		if (v != p && !removed[v] && sbsz[v] > n/2) {
			return find_centroid(v, u, n);
		}
	}
	return u;
}

void decompose(int root, int parent) {
	dfs_sbsz(root, parent);
	int centroid = find_centroid(root, parent, sbsz[root]);
	par[centroid] = parent;
	removed[centroid] = true;
	for (int v : adj[centroid]) {
		if (!removed[v]) {
			decompose(v, centroid);
		}
	}
	removed[centroid] = false;
}

void paint(int u) {
	for (int v = u; v != -1; v = par[v]) {
		ans[v] = min(ans[v], dist(u, v));
	}
}

int ask(int u) {
	int res = inf;
	for (int v = u; v != -1; v = par[v]) {
		res = min(res, dist(u, v) + ans[v]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	preprocess_LCA();
	decompose(1, -1);
	fill(ans, ans+maxn, inf);
	paint(1);
	for (int i = 1; i <= q; ++i) {
		int t, v;
		cin >> t >> v;
		if (t == 1) {
			paint(v);
		} else {
			cout << ask(v) << '\n';
		}
	}
}
