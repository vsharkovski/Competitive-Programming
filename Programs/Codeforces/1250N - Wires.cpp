// Problem : N. Wires
// Contest : 2019-2020 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Teams Preferred)
// URL : https://codeforces.com/contest/1250/problem/N
// Memory Limit : 512.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int n;
unordered_map<int, int> nodemap;
unordered_map<int, int> nodemap_inv;

int newnode(int x) {
	if (nodemap.count(x)) return nodemap[x];
	nodemap[x] = n;
	nodemap_inv[n] = x;
	++n;
	return n-1;
}

int m;
vector<pii> edges;

vector<vector<pii>> adj;
int leafnode, leafedge;
int cyclenode, cycleedge;
int multinode, multiedge;

const int unvisited = 0, explored = 1, visited = 2;
vector<int> status;

void dfs(int u, int p) {
	status[u] = explored;
	if (adj[u].size() == 1 && adj[u][0].first == p) {
		leafedge = adj[u][0].second;
		leafnode = u;
	}
	int pcnt = 0, pedge = -1;
	for (auto& to : adj[u]) {
		int v = to.first;
		if (status[v] == unvisited) {
			dfs(v, u);
		} else if (status[v] == explored && v != p) {
			cyclenode = u;
			cycleedge = to.second;
		} else if (v == p) {
			if (pedge == -1) {
				pedge = to.second;
			} else {
				multinode = u;
				multiedge = pedge;
			}
		}
	}
	status[u] = visited;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> m;
		n = 0;
		nodemap.clear();
		edges.resize(m);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			x = newnode(x), y = newnode(y);
			edges[i] = pii(x, y);
		}
		adj.assign(n, vector<pii>());
		for (int i = 0; i < m; ++i) {
			int x = edges[i].first;
			int y = edges[i].second;
			adj[x].emplace_back(y, i);
			adj[y].emplace_back(x, i);
		}
		status.assign(n, unvisited);
		vector<tuple<int, int, int>> ans;
		for (int i = 0; i < n; ++i) {
			if (status[i] == unvisited) {
				leafnode = leafedge = -1;
				cyclenode = cycleedge = -1;
				multinode = multiedge = -1;
				dfs(i, -1);
				if (i != 0) {
					if (leafnode != -1) {
						ans.emplace_back(leafedge, leafnode, 0);
					} else if (cyclenode != -1) {
						ans.emplace_back(cycleedge, cyclenode, 0);
					} else {
						ans.emplace_back(multiedge, multinode, 0);
					}
				}
			}
		}
		cout << ans.size() << endl;
		for (auto& tup : ans) {
			cout << get<0>(tup)+1 << ' ';
			cout << nodemap_inv[get<1>(tup)] << ' ';
			cout << nodemap_inv[get<2>(tup)] << '\n';
		}
	}
}
