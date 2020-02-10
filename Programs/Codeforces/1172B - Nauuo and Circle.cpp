// Problem : B. Nauuo and Circle
// Contest : Codeforces Round #564 (Div. 1)
// URL : https://codeforces.com/contest/1172/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353;

int mul(int a, int b) {
	return ((ll)a * b) % mod;
}

const int N = 200010;

int n;
vector<int> adj[N];
int fac[N];

int dfs(int u, int p) {
	int res = 1, ch = (p != -1);
	for (int v : adj[u]) {
		if (v == p) continue;
		++ch;
		res = mul(res, dfs(v, u));
	}
	res = mul(res, fac[ch]);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = mul(fac[i-1], i);
	}
	int ans = dfs(1, -1);
	ans = mul(ans, n);
	cout << ans << endl;
}
