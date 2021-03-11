#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200100;

int n, m;
vector<int> adj[N];

int dist[N];
vector<int> nxt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	int k;
	cin >> k;
	vector<int> p(k);
	for (int i = 0; i < k; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		dist[i] = -1;
	}
	dist[p.back()] = 0;
	queue<int> q;
	q.push(p.back());
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dist[v] == -1) {
				nxt[v].push_back(u);
				dist[v] = dist[u] + 1;
				q.push(v);
			} else if (dist[v] == dist[u] + 1) {
				nxt[v].push_back(u);
			}
		}
	}
	int mini = 0, maxi = 0;
	for (int i = 0; i < k-1; ++i) {
		int u = p[i];
		int w = p[i+1];
		bool found = false;
		for (int v : nxt[u]) {
			if (v == w) {
				found = true;
				break;
			}
		}
		if (found) {
			if (nxt[u].size() > 1) {
				++maxi;
			}
		} else {
			++mini;
			++maxi;
		}
	}
	cout << mini << ' ' << maxi << '\n';
}
