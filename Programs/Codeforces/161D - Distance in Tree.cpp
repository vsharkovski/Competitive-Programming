#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int maxn = 50010;
const int maxk = 501;

int n, k;
ll ans;
vector<int> adj[maxn];

bool removed[maxn];
int sbsz[maxn];

void dfs_dist(int u, int p, int d, vector<int>& dist) {
	if (d > k) return;
	++dist[d];
	for (int v : adj[u]) {
		if (v != p && !removed[v]) {
			dfs_dist(v, u, d+1, dist);
		}
	}
}

void solve_rooted(int root) {
	vector<vector<int>> child_dist;
	for (int v : adj[root]) {
		if (!removed[v]) {
			child_dist.push_back(vector<int>(k+1, 0));
			dfs_dist(v, root, 1, child_dist.back());
		}
	}
	vector<int> dist(k+1, 0);
	for (auto& vec : child_dist) {
		for (int i = 0; i <= k; ++i) {
			dist[i] += vec[i];
		}
	}
	ans += dist[k];
	ll same_dist_cnt = 0;
	for (auto& vec : child_dist) {
		for (int i = 0; i <= k; ++i) {
			dist[i] -= vec[i];
		}
		for (int i = 1; i <= k/2; ++i) {
			ll x = vec[i] * dist[k-i];
			if (i == k-i) {
				same_dist_cnt += x;
			} else {
				ans += x;
			}
		}
		for (int i = 0; i <= k; ++i) {
			dist[i] += vec[i];
		}
	}
	ans += same_dist_cnt / 2;
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

void centorid_decomposition(int root, int parent) {
	dfs_sbsz(root, parent);
	int centroid = find_centroid(root, parent, sbsz[root]);
	solve_rooted(centroid);
	removed[centroid] = true;
	for (int v : adj[centroid]) {
		if (!removed[v]) {
			centorid_decomposition(v, centroid);
		}
	}
	removed[centroid] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n-1; ++i) {
    	int a, b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    ans = 0;
    memset(removed, false, sizeof(removed));
    centorid_decomposition(1, -1);
    cout << ans << '\n';
}
