// Problem : F. Leaf Sets
// Contest : Codeforces Round #510 (Div. 2)
// URL : https://codeforces.com/contest/1042/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1000010;

int n, k, ans;
vector<int> adj[N];

int dfs(int u, int p) {
	if (adj[u].size() == 1) {
		return 0;
	}
	vector<int> vec;
	for (int v : adj[u]) {
		if (v == p) continue;
		vec.push_back(dfs(v, u) + 1);
	}
	sort(vec.begin(), vec.end());
	while (vec.size() > 1) {
		if (vec[vec.size()-2] + vec[vec.size()-1] <= k) {
			break;
		}
		++ans;
		vec.pop_back();
	}
	return vec.back();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() > 1) {
			dfs(i, -1);
			break;
		}
	}
	cout << ans << endl;
}
