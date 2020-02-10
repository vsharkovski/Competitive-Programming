// Problem : E. Alternating Tree
// Contest : Divide by Zero 2018 and Codeforces Round #474 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/960/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
	return x;
}

inline int mult(int x, int y) {
	return (ll)x * y % mod;
}

const int N = 200010;

int n, ans;
vector<int> adj[N];
int V[N];

bool removed[N];
int sbsz[N];

int totalsum, numpaths;

pii getsums(int u, int p, int d, int sum) {
	sum = add(sum, V[u] * (d ? -1 : 1));
	pii res(sum, 1);
	for (int v : adj[u]) {
		if (v == p || removed[v]) continue;
		pii res2 = getsums(v, u, 1-d, sum);
		res.first = add(res.first, res2.first);
		res.second = add(res.second, res2.second);
	}
	return res;
}

void dfs(int u, int p, int d, int sum) {
	sum = add(mod, -sum);
	sum = add(sum, V[u]);
	if (d == 0) {
		ans = add(ans, mult(numpaths, sum));
		ans = add(ans, totalsum);
	} else {
		ans = add(ans, mult(numpaths, sum));
		ans = add(ans, add(mod, -totalsum));
	}
	for (int v : adj[u]) {
		if (v == p || removed[v]) continue;
		dfs(v, u, 1-d, sum);
	}
}

void solve_rooted(int root) {
	totalsum = V[root];
	numpaths = 1;
	vector<pii> data;
	for (int v : adj[root]) {
		if (removed[v]) continue;
		pii res = getsums(v, root, 1, V[root]);
		totalsum = add(totalsum, res.first);
		numpaths = add(numpaths, res.second);
		data.push_back(res);
	}
	ans = add(ans, totalsum); // root -> descendant
	int i = 0;
	for (int v : adj[root]) {
		if (removed[v]) continue;
		totalsum = add(totalsum, -data[i].first);
		numpaths = add(numpaths, -data[i].second);
		dfs(v, root, 1, 0);
		totalsum = add(totalsum, data[i].first);
		numpaths = add(numpaths, data[i].second);
		++i;
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
		if (sbsz[v] > n/2) return find_centroid(v, u, n);
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
	for (int i = 1; i <= n; ++i) {
		cin >> V[i];
		removed[i] = false;
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0;
	decompose(1);
	cout << ans << endl;
}
