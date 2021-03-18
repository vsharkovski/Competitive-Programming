#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e18;
const int N = 50010;
const int K = 52;

int n, k;
int type[N];
bool cango[K][K];
int cl[K][N];
int cr[K][N];
vector<pii> adj[N];
ll dist[N];
typedef pair<ll, int> State;
priority_queue<State, vector<State>, greater<State>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> type[i];
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= k; ++j) {
			char ch;
			cin >> ch;
			cango[i][j] = (ch == '1');
		}
	}
	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			cl[j][i] = -1;
			if (i > 1) {
				cl[j][i] = cl[j][i-1];
				if (type[i-1] == j) {
					cl[j][i] = i-1;
				}
				if (cl[j][i] != -1 && cango[type[i]][j]) {
					adj[i].emplace_back(cl[j][i], i - cl[j][i]);
				}
			}
		}
		for (int i = n; i >= 1; --i) {
			cr[j][i] = -1;
			if (i < n) {
				cr[j][i] = cr[j][i+1];
				if (type[i+1] == j) {
					cr[j][i] = i+1;
				}
				if (cr[j][i] != -1 && cango[type[i]][j]) {
					adj[i].emplace_back(cr[j][i], cr[j][i] - i);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (i < n && cango[type[i]][type[n]]) {
			adj[i].emplace_back(n, n - i);
		}
		dist[i] = inf;
	}
	dist[1] = 0;
	pq.emplace(0, 1);
	while (!pq.empty()) {
		ll d;
		int u;
		tie(d, u) = pq.top();
		pq.pop();
		if (d > dist[u]) continue;
		for (auto edge : adj[u]) {
			int v, w;
			tie(v, w) = edge;
			if (d + w < dist[v]) {
				dist[v] = d + w;
				pq.emplace(d + w, v);
			}
		}
	}
	ll ans = dist[n];
	if (ans == inf) ans = -1;
	cout << ans << '\n';
}
