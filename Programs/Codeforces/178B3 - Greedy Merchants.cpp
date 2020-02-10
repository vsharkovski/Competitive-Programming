// Problem : B3. Greedy Merchants
// Contest : ABBYY Cup 2.0 - Hard
// URL : https://codeforces.com/contest/178/problem/B3
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int K = 17;

int k;
pii merch[N];

int n, m;
pii edges[N];
vector<int> adj[N];

int calls;
int tin[N];
int low[N];
bool isbridge[N];

int n2;
int ccid[N];
vector<int> adj2[N];
int depth[N];
int P[N][K];

inline int get_other(int u, int i) {
	return edges[i].first == u ? edges[i].second : edges[i].first;
}

void dfs(int u, int p) {
	tin[u] = low[u] = calls++;
	for (int i : adj[u]) {
		int v = get_other(u, i);
		if (tin[v] == -1) {
			dfs(v, u);
			if (low[v] > tin[u]) {
				isbridge[i] = true;
				//cout << "edge " << i << " ("<<edges[i].first<<','<<edges[i].second<<") is bridge\n";
			}
			low[u] = min(low[u], low[v]);
		} else if (v != p) {
			low[u] = min(low[u], tin[v]);
		}
	}
}

void dfs2(int u) {
	for (int i : adj[u]) {
		int v = get_other(u, i);
		if (ccid[v] == -1) {
			if (isbridge[i]) {
				ccid[v] = n2++;
				adj2[ccid[u]].push_back(ccid[v]);
				adj2[ccid[v]].push_back(ccid[u]);
				//cout << "cc edge: " << ccid[u] << " - " << ccid[v] << "\n";
			} else {
				ccid[v] = ccid[u];
			}
			dfs2(v);
		}
	}
}

void dfs3(int u, int p, int d) {
	depth[u] = d;
	for (int v : adj2[u]) {
		if (v == p) continue;
		dfs3(v, u, d+1);
		P[v][0] = u;
	}
}

int getdist(int a, int b) {
	int res = 0;
	if (depth[a] < depth[b]) swap(a, b);
	for (int j = K-1; j >= 0; --j) {
		if (depth[a] - (1<<j) >= depth[b]) {
			res += (1<<j);
			a = P[a][j];
		}
	}
	if (a == b) return res;
	for (int j = K-1; j >= 0; --j) {
		if (P[a][j] != -1 && P[a][j] != P[b][j]) {
			res += 2*(1<<j);
			a = P[a][j];
			b = P[b][j];
		}
	}
	res += 2;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(i);
		adj[b].push_back(i);
		edges[i] = make_pair(a, b);
		isbridge[i] = false;
		//cout << "edge " << a << "-" << b << "\n";
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> merch[i].first >> merch[i].second;
	}
	calls = 0;
	for (int i = 1; i <= n; ++i) {
		tin[i] = -1;
		ccid[i] = -1;
	}
	dfs(1, -1);
	n2 = 1;
	ccid[1] = 0;
	dfs2(1);
	for (int i = 0; i < n2; ++i) {
		P[i][0] = -1;
	}
	dfs3(0, -1, 0);
	for (int j = 1; j < K; ++j) {
		for (int i = 0; i < n2; ++i) {
			if (P[i][j-1] != -1) {
				P[i][j] = P[ P[i][j-1] ][j-1];
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		int a = ccid[merch[i].first];
		int b = ccid[merch[i].second];
		cout << getdist(a, b) << '\n';
	}
}
