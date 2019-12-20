// Problem : E. Nearest Opposite Parity
// Contest : Codeforces Round #605 (Div. 3)
// URL : https://codeforces.com/contest/1272/problem/E
// Memory Limit : 256.000000MB 
// Time Limit : 2000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 200010;

int n;
int a[N];
int ans[N];
vector<int> adj[N];
int dist[N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	queue<pii> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans[i] = -1;
		if (i - a[i] >= 1) adj[i - a[i]].push_back(i);
		if (i + a[i] <= n) adj[i + a[i]].push_back(i);
		q.emplace(i, a[i] % 2);
		dist[i][a[i] % 2] = 0;
		dist[i][1 - (a[i] % 2)] = inf;
	}
	while (!q.empty()) {
		auto top = q.front();
		q.pop();
		int u = top.first, b = top.second;
		for (int v : adj[u]) {
			if (dist[v][b] == inf) {
				dist[v][b] = dist[u][b] + 1;
				q.emplace(v, b);
				if (a[v] % 2 != b) {
					ans[v] = dist[v][b];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
}
