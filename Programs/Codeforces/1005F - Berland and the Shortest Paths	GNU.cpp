// Problem : F. Berland and the Shortest Paths
// Contest : Codeforces Round #496 (Div. 3)
// URL : https://codeforces.com/contest/1005/problem/F
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200010;

int n, m, k;
pii edges[N];
vector<int> adj[N];

int dist[N];
vector<int> lst[N];
vector<int> goodlsts;

int numdone;
bool used[N];
vector<bool> ans[N];

inline int other(int i, int u) {
	return edges[i].first == u ? edges[i].second : edges[i].first;
}

void rec(int idx) {
	if (numdone == k) return;
	if (idx == (int)goodlsts.size()) {
		ans[numdone].resize(m);
		for (int i = 0; i < m; ++i) {
			ans[numdone][i] = used[i];
		}
		++numdone;
	} else {
		int u = goodlsts[idx];
		for (int i : lst[u]) {
			used[i] = true;
			rec(idx+1);
			if (numdone == k) return;
			used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		edges[i] = make_pair(a, b);
		adj[a].push_back(i);
		adj[b].push_back(i);
	}
	memset(dist, -1, sizeof(dist));
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i : adj[u]) {
			int v = other(i, u);
			if (dist[v] == -1 || dist[u]+1 == dist[v]) {
				lst[v].push_back(i);
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
	}
	for (int u = 1; u <= n; ++u) {
		if (lst[u].size() == 1) {
			used[lst[u][0]] = true;
		} else if (lst[u].size() > 1) {
			goodlsts.push_back(u);
			for (int i : lst[u]) {
				used[i] = false;
			}
		}
	}
	numdone = 0;
	rec(0);
	cout << numdone << '\n';
	for (int i = 0; i < numdone; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
}
