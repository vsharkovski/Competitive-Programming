// Problem : E. Two Fairs
// Contest : Codeforces Round #606 (Div. 2, based on Technocup 2020 Elimination Round 4)
// URL : https://codeforces.com/contest/1277/problem/E
// Memory Limit : 256.000000MB 
// Time Limit : 3000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200010;

int n, m, a, b;
vector<int> adj[N];

int numcalls;
int tin[N], low[N];
bool choke[N];

void dfs1(int u, int p) {
	tin[u] = low[u] = numcalls++;
	int children = 0;
	for (int v : adj[u]) {
		if (tin[v] == -1) {
			++children;
			dfs1(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= tin[u] && p != -1) {
				choke[u] = true;
			}
		} else if (v != p) {
			low[u] = min(low[u], tin[v]);
		}
	}
	if (p == -1 && children > 1) {
		choke[u] = true;
	}
}

pair<bool, int> dfs2(int u, int trg) {
	tin[u] = 1;
	pair<bool, int> res(u == trg, 1);
	for (int v : adj[u]) {
		if (tin[v] == -1) {
			auto res2 = dfs2(v, trg);
			res.first |= res2.first;
			if (res2.first == false) {
				res.second += res2.second;
			}
		}
	}
	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> a >> b;
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			//cout << u << " - " << v << "\n";
		}
		for (int i = 1; i <= n; ++i) {
			tin[i] = -1;
			choke[i] = false;
		}
		numcalls = 0;
		dfs1(a, -1);
		//cout << "a=" << a << " cha=" << choke[a] << " b=" << b << " chb=" << choke[b] << "\n";
		if (!choke[a] || !choke[b]) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			tin[i] = -1;
		}
		int cnt1 = dfs2(a, b).second - 1;
		for (int i = 1; i <= n; ++i) {
			tin[i] = -1;
		}
		int cnt2 = dfs2(b, a).second - 1;
		//cout << "cnt1=" << cnt1 << " cnt2=" << cnt2 << endl;
		cout << ll(cnt1)*ll(cnt2) << endl;
	}
}
