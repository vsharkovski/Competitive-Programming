#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int maxn = 1000010;
 
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
 
int n;
vector<int> adj[maxn];
int x[maxn];
int up[maxn];
int down[maxn][2];
 
void dfs1(int u, int p) {
	down[u][0] = down[u][1] = 0;
	for (int v : adj[u]) {
		if (v != p) {
			dfs1(v, u);
			if (x[v] == 1) {
				int res = 1 + down[v][0];
				if (res >= down[u][0]) {
					down[u][1] = down[u][0];
					down[u][0] = res;
				} else if (res > down[u][1]) {
					down[u][1] = res;
				}
			}
		}
	}
}
 
void dfs2(int u, int p) {
	up[u] = 0;
	if (p != -1 && x[p] == 1) {
		if (x[u] == 1 && down[p][0] == 1 + down[u][0]) {
			up[u] = max(1 + up[p], 1 + down[p][1]);
		} else {
			up[u] = max(1 + up[p], 1 + down[p][0]);
		}
	}
	for (int v : adj[u]) {
		if (v != p) {
			dfs2(v, u);
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	dfs1(1, -1);
	dfs2(1, -1);
	long double bestres = 1e18, res;
	ll bestp, bestq, p, q;
	for (int i = 1; i <= n; ++i) {
		vector<int> options = {down[i][0], down[i][1], up[i]};
		sort(options.rbegin(), options.rend());
		p = x[i];
		q = 1 + options[0] + options[1];
		res = (long double)p / (long double)q;
		if (res < bestres) {
			bestres = res;
			bestp = p;
			bestq = q;
		}
	}
	ll g = gcd(bestp, bestq);
	bestp /= g, bestq /= g;
	cout << bestp << '/' << bestq << '\n';
}
