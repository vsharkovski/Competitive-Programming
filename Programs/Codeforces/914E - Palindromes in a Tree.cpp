// Problem : E. Palindromes in a Tree
// Contest : Codecraft-18 and Codeforces Round #458 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/914/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200010;
const int M = 20;

int n;
int label[N];
vector<int> adj[N];

bool removed[N];
int sbsz[N];

ll ans[N];
int cnt[1<<M];
int rootval;

void change(int u, int p, int m, int modifier) {
	m ^= label[u];
	cnt[m] += modifier;
	for (int v : adj[u]) {
		if (v == p || removed[v]) continue;
		change(v, u, m, modifier);
	}
}

pll dfs(int u, int p, int m) {
	m ^= label[u];
	pll up(0, 0);
	// to a node in the subtree of a child of root
	up.first += cnt[m];
	for (int i = 0; i < M; ++i) {
		up.first += cnt[m ^ (1<<i)];
	}
	// to root itself (must be 0 or perfect power of 2)
	int toroot = m ^ rootval;
	if (toroot == 0 || (toroot & (toroot-1)) == 0) {
		up.second += 1;
	}
	for (int v : adj[u]) {
		if (v == p || removed[v]) continue;
		pll up2 = dfs(v, u, m);
		up.first += up2.first;
		up.second += up2.second;
	}
	ans[u] += up.first + up.second;
	return up;
}

void solve_rooted(int root) {
	rootval = label[root];
	for (int v : adj[root]) {
		if (removed[v]) continue;
		change(v, root, rootval, 1);
	}
	pll upsum(0, 0);
	for (int v : adj[root]) {
		if (removed[v]) continue;
		change(v, root, rootval, -1);
		pll up = dfs(v, root, 0);
		upsum.first += up.first;
		upsum.second += up.second;
		change(v, root, rootval, 1);
	}
	ans[root] += upsum.first / 2;
	ans[root] += upsum.second;
	for (int v : adj[root]) {
		if (removed[v]) continue;
		change(v, root, rootval, -1);
	}
}

void dfs_sbsz(int u, int p) {
	sbsz[u] = 1;
	for (int v : adj[u]) {
		if (v == p || removed[v]) continue;
		dfs_sbsz(v, u);
		sbsz[u] += sbsz[v];
	}
}

int find_centroid(int u, int p, int n) {
	for (int v : adj[u]) {
		if (v == p || removed[v]) continue;
		if (sbsz[v] > n/2) {
			return find_centroid(v, u, n);
		}
	}
	return u;
}

void decompose(int root) {
	dfs_sbsz(root, -1);
	int centroid = find_centroid(root, -1, sbsz[root]);
	solve_rooted(centroid);
	removed[centroid] = true;
	for (int v : adj[centroid]) {
		if (removed[v]) continue;
		decompose(v);
	}
	removed[centroid] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		label[i] = 1 << int(ch - 'a');
		ans[i] = 1;
		removed[i] = false;
	}
	memset(cnt, 0, sizeof(cnt));
	decompose(1);
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
}
