#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll mod = 1e9 + 7;
const int maxn = 100010;
 
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
 
int n;
ll ans;
vector<int> adj[maxn];
ll val[maxn];
 
void dfs(int u, int p, map<ll, ll>& gcds) {
	for (auto& p : gcds) {
		ans += p.first * p.second;
		ans %= mod;
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		map<ll, ll> m2;
		m2[val[v]] += 1;
		for (auto& p : gcds) {
			ll g2 = gcd(p.first, val[v]);
			m2[g2] += p.second;
		}
		dfs(v, u, m2);
	}
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0;
	map<ll, ll> aux;
	aux[val[1]] += 1;
	dfs(1, -1, aux);
	cout << ans << endl;
}
