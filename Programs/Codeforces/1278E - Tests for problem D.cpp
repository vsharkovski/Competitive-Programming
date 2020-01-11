// Problem : E. Tests for problem D
// Contest : Educational Codeforces Round 78 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1278/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 500010;

int n;
vector<int> adj[N];

int ptr;
int L[N], R[N];

void dfs(int u, int p) {
	int sz = adj[u].size();
	for (int i = 0; i < sz; ++i) {
		int v = adj[u][i];
		if (v == p) continue;
		L[v] = ptr++;
	}
	R[u] = ptr++;
	for (int i = sz-1; i >= 0; --i) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ptr = 1;
	L[1] = ptr++;
	dfs(1, -1);
	for (int i = 1; i <= n; ++i) {
		cout << L[i] << ' ' << R[i] << endl;
	}
}
