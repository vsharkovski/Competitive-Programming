
// Problem : Problem 1. MooTube
// Contest : USACO 2018 January Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=789
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 2e9;
const int N = 100100;
const int Q = 100100;
const int M = N + Q;

int n, q, m;

struct Edge {
	int a, b, w;
	inline int other(int u) {
		return u == a ? b : a;
	}
} edges[N];
vector<int> adj[N];

int queryans[Q];
vector<pii> queries[N]; // for each node, (k, query id)

bool removed[N];
int sbsz[N];

void getsbsz(int u, int p) {
	sbsz[u] = 1;
	for (int e : adj[u]) {
		int v = edges[e].other(u);
		if (v == p || removed[v]) continue;
		getsbsz(v, u);
		sbsz[u] += sbsz[v];
	}
}

int findcentroid(int u, int p, int s) {
	for (int e : adj[u]) {
		int v = edges[e].other(u);
		if (v != p && !removed[v] && sbsz[v] > s/2) {
			return findcentroid(v, u, s);
		}
	}
	return u;
}

void merge(vector<int>& v1, vector<int>& v2) {
	vector<int> v(v1.size() + v2.size());
	auto it = v.begin();
	auto it1 = v1.begin(), it2 = v2.begin();
	while (it1 != v1.end() && it2 != v2.end()) {
		if (*it1 <= *it2) {
			*it = *it1;
			++it, ++it1;
		} else {
			*it = *it2;
			++it, ++it2;
		}
	}
	while (it1 != v1.end()) {
		*it = *it1;
		++it, ++it1;
	}
	while (it2 != v2.end()) {
		*it = *it2;
		++it, ++it2;
	}
	v1.swap(v);
}

inline int getcnt(int k, vector<int>& results) {
	auto it = lower_bound(results.begin(), results.end(), k);
	return distance(it, results.end());
}

void dfs(int u, int p, int minw, vector<int>& results) {
	results.push_back(minw);
	for (int e : adj[u]) {
		int v = edges[e].other(u);
		if (v == p || removed[v]) continue;
		dfs(v, u, min(minw, edges[e].w), results);
	}
}

void querydfs(int u, int p, int minw, vector<int>& all, vector<int>& cur) {
	for (pii& query : queries[u]) {
		int k = query.first, i = query.second;
		if (minw < k) continue;
		queryans[i] += getcnt(k, all) - getcnt(k, cur);
	}
	for (int e : adj[u]) {
		int v = edges[e].other(u);
		if (v == p || removed[v]) continue;
		querydfs(v, u, min(minw, edges[e].w), all, cur);
	}
}


void decompose(int src) {
	getsbsz(src, -1);
	int c = findcentroid(src, -1, sbsz[src]);
	
	vector<vector<int>> results;
	for (int e : adj[c]) {
		int v = edges[e].other(c);
		if (removed[v]) continue;
		results.push_back(vector<int>());
		dfs(v, c, edges[e].w, results.back());
	}
	vector<int> allresults;
	allresults.push_back(inf); // for root
	for (vector<int>& v : results) {
		sort(v.begin(), v.end());
		merge(allresults, v);
	}
	for (pii& query : queries[c]) {
		int k = query.first, i = query.second;
		queryans[i] += getcnt(k, allresults) - 1; // -1 is because path to itself
	}
	int i = 0;
	for (int e : adj[c]) {
		int v = edges[e].other(c);
		if (removed[v]) continue;
		querydfs(v, c, edges[e].w, allresults, results[i]);
		++i;
	}
	
	removed[c] = true;
	for (int e : adj[c]) {
		int v = edges[e].other(c);
		if (removed[v]) continue;
		decompose(v);
	}
	removed[c] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	#endif
	cin >> n >> q;
	for (int i = 0; i < n-1; ++i) {
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
		adj[edges[i].a].push_back(i);
		adj[edges[i].b].push_back(i);
	}
	for (int i = 0; i < q; ++i) {
		int k, u;
		cin >> k >> u;
		queries[u].emplace_back(k, i);
		queryans[i] = 0;
	}
	decompose(1);
	for (int i = 0; i < q; ++i) {
		cout << queryans[i] << '\n';
	}
}
