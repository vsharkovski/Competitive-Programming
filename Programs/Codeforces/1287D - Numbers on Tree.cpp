// Problem : D. Numbers on Tree
// Contest : Codeforces Round #612 (Div. 2)
// URL : https://codeforces.com/contest/1287/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 2010;

int n, root;
int c[N], ans[N];
vector<int> adj[N];
vector<int> vec[N];
bool bad;

void dfs(int u) {
	for (int v : adj[u]) {
		dfs(v);
		if (bad) return;
		for (int x : vec[v]) {
			vec[u].push_back(x);
		}
		vector<int> temp;
		vec[v].swap(temp);
	}
	if (c[u] <= (int)vec[u].size()) {
		vec[u].insert(vec[u].begin() + c[u], u);
	} else {
		bad = true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p >> c[i];
		if (p == 0) {
			root = i;
		} else {
			adj[p].push_back(i);
		}
	}
	bad = false;
	dfs(root);
	if (bad) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < (int)vec[root].size(); ++i) {
		ans[vec[root][i]] = i+1;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
