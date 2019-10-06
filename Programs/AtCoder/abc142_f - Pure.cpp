#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n+1), h(n+1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		h[b].push_back(a);
	}
	vector<int> bestcycle;
	for (int i = 1; i <= n; ++i) {
		vector<int> dist(n+1, -1);
		vector<int> pre(n+1, -1);
		queue<int> q;
		dist[i] = 0;
		q.push(i);
		while (!q.empty()) {
			int j = q.front();
			q.pop();
			for (int k : h[j]) {
				if (dist[k] == -1) {
					dist[k] = dist[j] + 1;
					pre[k] = j;
					q.push(k);
				}
			}
		}
		for (int j : g[i]) {
			if (dist[j] != -1 && (bestcycle.empty() || dist[j] + 1 < bestcycle.size())) {
				bestcycle.clear();
				while (j != -1) {
					bestcycle.push_back(j);
					j = pre[j];
				}
			}
		}
	}
	if (bestcycle.empty()) {
		cout << "-1\n";
	} else {
		cout << bestcycle.size() << endl;
		for (int x : bestcycle) {
			cout << x << endl;
		}
	}
}
