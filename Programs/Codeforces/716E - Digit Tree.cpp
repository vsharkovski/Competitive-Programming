#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using Data = unordered_map<int, int>;

void add_data(Data& d1, Data& d2) {
	for (auto& kvp : d2) {
		d1[kvp.first] += kvp.second;
	}
}

void remove_data(Data& d1, Data& d2) {
	for (auto& kvp : d2) {
		d1[kvp.first] -= kvp.second;
	}
}

const int maxn = 100010;

int n;
vector<pii> adj[maxn];

ll M, ans, inv10;
ll pow10[maxn];
ll pow10inv[maxn]; // ( 1 / pow10[i] ) mod M

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % M;
		a = (a * a) % M;
		b >>= 1;
	}
	return res;
}

ll eulerphi(ll a) {
	ll b = 1;
	for (ll p = 2; p*p <= a; ++p) {
		if (a % p == 0) {
			int cnt = 0;
			while (a % p == 0) {
				if (cnt > 0) {
					b *= p;
				}
				++cnt;
				a /= p;
			}
			b *= p-1;
		}
	}
	if (a > 1) {
		b *= a-1;
	}
	return b;
}

bool removed[maxn];
int centroid;
int sbsz[maxn];
ll depth[maxn];
ll up[maxn];
ll down[maxn];
int ROOT;

void dfs_dp(int u, int p) {
	if (up[u] == 0 && u != ROOT) ++ans;
	if (down[u] == 0 && u != ROOT) ++ans;
	for (auto& to : adj[u]) {
		int v = to.first, w = to.second;
		if (v != p && !removed[v]) {
			depth[v] = depth[u] + 1;
			up[v] = (pow10[depth[v]-1]*w + up[u]) % M;
			down[v] = (10*down[u] + w) % M;
			dfs_dp(v, u);
		}
	}
}

// up[u] * 10**depth[v] + down[v] = 0 (mod M)
// up[u] = -down[v] / 10**depth[v] (mod M)
// keep counts of RHS
// afterwards, for each subtree of root, remove it from data,
// and calculate # of paths into other subtrees

void dfs_data(int u, int p, Data& data) {
	++data[(((M - down[u]) % M) * pow10inv[depth[u]]) % M];
	for (auto& to : adj[u]) {
		int v = to.first;
		if (v != p && !removed[v]) {
			dfs_data(to.first, u, data);
		}
	}
}

void dfs_final(int u, int p, Data& data) {
	ans += data[up[u]];
	for (auto& to : adj[u]) {
		int v = to.first;
		if (v != p && !removed[v]) {
			dfs_final(v, u, data);
		}
	}
}

void solve_rooted(int root) {
	ROOT = root;
	depth[root] = up[root] = down[root] = 0;
	dfs_dp(root, -1);
	vector<int> children;
	vector<Data> child_data;
	Data root_data;
	for (auto& to : adj[root]) {
		int v = to.first;
		if (!removed[v]) {
			children.push_back(v);
			child_data.push_back(Data());
			dfs_data(v, root, child_data.back());
			add_data(root_data, child_data.back());
		}
	}
	// u -> root -> v
	for (int i = 0; i < (int)children.size(); ++i) {
		int v = children[i];
		remove_data(root_data, child_data[i]);
		dfs_final(v, root, root_data);
		add_data(root_data, child_data[i]);
	}
}

void dfs_sbsz(int u, int p) {
	sbsz[u] = 1;
	for (auto& to : adj[u]) {
		int v = to.first;
		if (v != p && !removed[v]) {
			dfs_sbsz(v, u);
			sbsz[u] += sbsz[v];
		}
	}
}

int find_centroid(int u, int p, int n) {
	for (auto& to : adj[u]) {
		int v = to.first;
		if (v != p && !removed[v] && sbsz[v] > n/2) {
			return find_centroid(v, u, n);
		}
	}
	return u;
}

void centroid_decomposition(int root, int parent) {
	dfs_sbsz(root, parent);
	centroid = find_centroid(root, parent, sbsz[root]);
	solve_rooted(centroid);
	removed[centroid] = true;
	for (auto& to : adj[centroid]) {
		int v = to.first;
		if (v != parent && !removed[v]) {
			centroid_decomposition(v, centroid);
		}
	}
	removed[centroid] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> M;
    for (int i = 0; i < n-1; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	adj[u].emplace_back(v, w);
    	adj[v].emplace_back(u, w);
    }
    inv10 = binpow(10, eulerphi(M) - 1);
    pow10[0] = 1;
    pow10inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
    	pow10[i] = (pow10[i-1] * 10) % M;
    	pow10inv[i] = (pow10inv[i-1] * inv10) % M;
    }
    ans = 0;
    memset(removed, false, sizeof(removed));
    centroid_decomposition(0, -1);
    cout << ans << '\n';
}
