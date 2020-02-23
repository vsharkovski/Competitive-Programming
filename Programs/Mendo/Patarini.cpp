#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 100100;

int n, k;
ll ans;
bool special[N];

pair<pii, int> edges[N];
bool bought[N];
vector<int> adj[N];

inline int other(int i, int a) {
	return edges[i].first.first == a ? edges[i].first.second : edges[i].first.first;
}

inline int betteredge(int i, int j) {
	if (i == -1) return j;
	if (j == -1) return i;
	if (edges[i].second < edges[j].second) return i;
	return j;
}

inline int worseedge(int i, int j) {
	if (i == -1) return j;
	if (j == -1) return i;
	if (edges[i].second >= edges[j].second) return i;
	return j;
}

bool removed[N];
int sbsz[N];

void getsbsz(int u, int p) {
	sbsz[u] = 1;
	for (int i : adj[u]) {
		int v = other(i, u);
		if (v == p || removed[v]) continue;
		getsbsz(v, u);
		sbsz[u] += sbsz[v];
	}
}

int getcentroid(int u, int p, int m) {
	for (int i : adj[u]) {
		int v = other(i, u);
		if (v != p && !removed[v] && sbsz[v] > m/2) {
			return getcentroid(v, u, m);
		}
	}
	return u;
}

int bestedgedfs(int u, int p, int bestedge) {
	if (special[u]) return bestedge;
	int be = -1;
	for (int i : adj[u]) {
		if (bought[i]) continue;
		int v = other(i, u);
		if (v == p || removed[v]) continue;
		int e = bestedgedfs(v, u, betteredge(bestedge, i));
		be = betteredge(be, e);
	}
	return be;
}

void decompose(int src) {
	getsbsz(src, -1);
	int c = getcentroid(src, -1, sbsz[src]);
	removed[c] = true;
	for (int i : adj[c]) {
		int v = other(i, c);
		if (removed[v]) continue;
		decompose(v);
	}
	removed[c] = false;
	int worstedgeused = -1;
	for (int i : adj[c]) {
		int v = other(i, c);
		if (removed[v]) continue;
		int e = bestedgedfs(v, c, i);
		if (e == -1) continue;
		worstedgeused = worseedge(worstedgeused, e);
		ans += edges[e].second;
		bought[e] = true;
	}
	if (!special[c] && worstedgeused != -1) {
		ans -= edges[worstedgeused].second;
		bought[worstedgeused] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = make_pair(pii(a, b), w);
		bought[i] = false;
		adj[a].push_back(i);
		adj[b].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		special[i] = false;
		removed[i] = false;
	}
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		special[a] = true;
	}
	ans = 0;
	decompose(0);
	cout << ans << '\n';
}
