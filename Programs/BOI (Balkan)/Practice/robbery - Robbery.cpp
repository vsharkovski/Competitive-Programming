#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct DSU {
	int n;
	vector<int> p, rank;
	DSU(int n) : n(n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		rank.assign(n, 0);
	}
	inline int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}
	inline void unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return;
		if (rank[x] < rank[y]) swap(x, y);
		if (rank[x] == rank[y]) ++rank[x];
		p[y] = x;
	}	
};

const int maxn = 50010;
const int maxm = 500010;
const int maxw = 205;

int n, m;

vector<int> adj[maxn];
pii edge[maxm];
int edge_weight[maxm];
vector<int> edgesbyweight[maxw];

DSU dsu(maxn);

int isbridge[maxn];
int calls;
int tin[maxn], low[maxn];

void artpb(int u, int p, int okw) {
	tin[u] = low[u] = calls++;
	for (int eid : adj[u]) {
		if (edge_weight[eid] > okw) continue;
		int v = edge[eid].first == u ? edge[eid].second : edge[eid].first;
		if (tin[v] == -1) {
			// tree edge
			artpb(v, u, okw);
			if (low[v] > tin[u]) {
				// (u, v) is bridge
				isbridge[eid] = okw;
			}
			low[u] = min(low[u], low[v]);
		} else if (v != p) {
			// back edge (towards ancestor)
			low[u] = min(low[u], tin[v]);
		}
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(i);
		adj[b].push_back(i);
		edge[i] = {a, b};
		edge_weight[i] = c;
		edgesbyweight[c].push_back(i);
	}
	int cnt[3] = {}; // def, maybe, no
	for (int w = 1; w < maxw; ++w) {
		if (edgesbyweight[w].empty()) {
			continue;
		}
		//cout << "w=" << w << endl;
		calls = 0;
		memset(tin, -1, sizeof(tin));
		for (int i = 1; i <= n; ++i) {
			if (tin[i] == -1) {
				artpb(i, -1, w);
			}
		}
		for (int i : edgesbyweight[w]) {
			int u = edge[i].first, v = edge[i].second;
			//cout << "(" << u << "," << v << "): ";
			if (isbridge[i] == w) {
				++cnt[0];
				//cout << "bridge(def)\n";
			} else if (dsu.get(u) != dsu.get(v)) {
				++cnt[1];
				//cout << "diff. cc (maybe)\n";
			} else {
				//cout << "same cc (never)\n";
				++cnt[2];
			}
		}
		for (int i : edgesbyweight[w]) {
			int u = edge[i].first, v = edge[i].second;
			if (dsu.get(u) != dsu.get(v)) {
				//cout << "united " << u << "," << v << "\n";
				dsu.unite(u, v);
			}
		}
	}
	cout << cnt[0] << endl << cnt[2] << endl << cnt[1] << endl;
}
