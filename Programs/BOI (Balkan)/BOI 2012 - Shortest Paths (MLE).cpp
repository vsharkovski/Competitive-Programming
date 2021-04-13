#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;
const int N = 2010;

int n, m, k;
vector<pair<int, int>> graph[N];
int seq[N];
int seqpos[N];
int dist[N][N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> seq[1] >> seq[1];
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
	}
	for (int i = 1; i <= n; ++i) {
		seqpos[i] = 0;
	}
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> seq[i];
		seqpos[seq[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dist[i][j] = inf;
		}
	}
	using pqState = tuple<int, int, int>;
	priority_queue<pqState, vector<pqState>, greater<pqState>> pq;
	dist[seq[1]][0] = 0;
	pq.emplace(0, seq[1], 0);
	while (!pq.empty()) {
		int curdist, node, last;
		tie(curdist, node, last) = pq.top();
		pq.pop();
		if (curdist != dist[node][last]) continue;
//		cout << "curdist="<<curdist<<" node="<<node<<" last="<<last<<"; seqpos["<<node<<"]="<<seqpos[node]<<"\n";
		for (auto edge : graph[node]) {
			int to = edge.first;
			int alt = curdist + edge.second;
			if (last == 0) {
				// the whole path until here has been on the initial sequence
				if (seqpos[to] == seqpos[node] + 1) {
					// to is the next node in the sequence
					if (alt < dist[to][0]) {
						dist[to][0] = alt;
						pq.emplace(alt, to, 0);
					}
				} else {
					// move off the initial sequence
					if (alt < dist[to][seqpos[node]]) {
						dist[to][seqpos[node]] = alt;
						pq.emplace(alt, to, seqpos[node]);
					}
				}
			} else {
				// we moved off the initial sequence previously
				if (seqpos[to] > 0 && seqpos[to] <= last) {
					// don't move back
				} else {
					if (alt < dist[to][last]) {
						dist[to][last] = alt;
						pq.emplace(alt, to, last);
					}
				}
			}
		}
	}
	int ans = inf;
	for (int i = 1; i <= k-1; ++i) {
		ans = min(ans, dist[seq[k]][i]);
		cout << (ans == inf ? -1 : ans) << '\n';
	}
}
