#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200010;

int n, m;
vector<int> adj[N];
bool vis[N];
int mx, mn;
int add[N], rem[N];

void dfs(int u) {
	vis[u] = true;
	mx = max(mx, u);
	mn = min(mn, u);
	for (int v : adj[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			mx = -1, mn = n+1;
			dfs(i);
			add[mn] += 1;
			rem[mx] += 1;
			// cout << "[" << mn << "," << mx << "]\n";
		}
	}
	int ans = 0;
	int active = 0;
	for (int i = 1; i <= n; ++i) {
		if (active > 0 && add[i] > 0) {
			ans += add[i];
		} else if (active == 0 && add[i] > 1) {
			ans += add[i] - 1;
		}
		active += add[i];
		active -= rem[i];
	}
	cout << ans << endl;
}
