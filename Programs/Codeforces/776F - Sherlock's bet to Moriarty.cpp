#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


const int maxn = 100010;
const int maxm = maxn;

int n, m, k;
pii edges[maxm];

vector<int> regions[maxn];
vector<int> adj[maxn];
map<pii, int> edge_found;

bool removed[maxn];
int sbsz[maxn];
int color[maxn];

void form_regions() {
	sort(edges, edges + m, [&] (pii& x, pii& y) {
    	int vx = min(x.second-x.first-1, n+x.first-x.second-1);
    	int vy = min(y.second-y.first-1, n+y.first-y.second-1);
    	return vx < vy;
    });
	set<int> nodes;
    for (int i = 1; i <= n; ++i) {
    	nodes.insert(i);
    }
    k = 0; // number of regions
    for (int i = 0; i < m; ++i) {
    	int a = edges[i].first, b = edges[i].second;
    	if (b-a-1 < n+a-b-1) { // clockwise from a to b
    		regions[k].push_back(a);
    		auto it = nodes.upper_bound(a);
    		while (*it < b) {
    			regions[k].push_back(*it);
    			++it;
    		}
    		regions[k].push_back(b);
    	} else { // clockwise from b to a
    		auto it = nodes.begin();
    		while (*it < a) {
    			regions[k].push_back(*it);
    			++it;
    		}
    		regions[k].push_back(a);
    		regions[k].push_back(b);
    		it = nodes.upper_bound(b);
    		while (it != nodes.end()) {
    			regions[k].push_back(*it);
    			++it;
    		}
    	}
        for (int c : regions[k]) {
    		if (c != a && c != b) {
                nodes.erase(c);
    		}
    	}
    	reverse(regions[k].begin(), regions[k].end());
    	++k;
    }
    while (!nodes.empty()) {
    	regions[k].push_back(*nodes.begin());
    	nodes.erase(nodes.begin());
    }
    reverse(regions[k].begin(), regions[k].end());
    ++k;
    // each region is sorted in descending order
    // the comparison with powers of 2 in the problem statement
    // is now equivalent to lexicographical comparison
    sort(regions, regions + k);
}

void check_edge(int i, int u, int v) {
	if (u == v || u == v+1) return;
	pii p(u, v);
	if (edge_found.count(p)) {
		int j = edge_found[p];
		if (j != i) {
			adj[i].push_back(j);
			adj[j].push_back(i);
			edge_found.erase(p);
		}
	} else {
		edge_found[p] = i;
	}
}

void connect_regions() {
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < (int)regions[i].size() - 1; ++j) {
			check_edge(i, regions[i][j], regions[i][j+1]);
		}
		check_edge(i, regions[i][0], regions[i].back());
	}
}

void dfs_sbsz(int u, int p) {
	sbsz[u] = 1;
	for (int v : adj[u]) {
		if (v != p && !removed[v]) {
			dfs_sbsz(v, u);
			sbsz[u] += sbsz[v];
		}
	}
}

int find_centroid(int u, int p, int n) {
	for (int v : adj[u]) {
		if (v != p && !removed[v] && sbsz[v] > n/2) {
			return find_centroid(v, u, n);
		}
	}
	return u;
}

void centroid_decomposition(int root, int parent, int iteration) {
	dfs_sbsz(root, parent);
	int centroid = find_centroid(root, parent, sbsz[root]);
	color[centroid] = iteration;
	removed[centroid] = true;
	for (int v : adj[centroid]) {
		if (!removed[v]) {
			centroid_decomposition(v, centroid, iteration+1);
		}
	}
	removed[centroid] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
    	int a, b;
    	cin >> a >> b;
    	if (a > b) swap(a, b);
    	edges[i] = {a, b};
    }
  	// cout << "forming regions\n";
    form_regions();
    // cout << "connecting regions\n";
    connect_regions();
   	// cout << "decomposing centroids\n";
    memset(removed, false, sizeof(removed));
    centroid_decomposition(0, -1, 1);
    for (int i = 0; i < k; ++i) {
    	cout << color[i] << ' ';
    }
}
