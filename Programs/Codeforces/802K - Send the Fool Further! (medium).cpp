// Problem : K. Send the Fool Further! (medium)
// Contest : Helvetic Coding Contest 2017 online mirror (teams allowed, unrated)
// URL : https://codeforces.com/contest/802/problem/K
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 300010;

int n, k;
vector<pii> adj[N];

int dp1[N], dp2[N];

/*
dp1: result for this subtree
if you want to go back up later.
can visit at most k-1 children
all children, invoke dp1
(pick k-1 biggest dp1)

dp2: result for this subtree,
if want to end at some descendant.
can visit at most k children
first k-1 children, invoke dp1
the last child, invoke dp2
(for each child, try dp2 and
k-1 biggest dp1 from other children)

final answer: dp2[0]
*/

void dfs(int u, int p) {
	vector<int> res;
	for (auto& to : adj[u]) {
		int v = to.first, w = to.second;
		if (v == p) continue;
		dfs(v, u);
		dp1[v] += w, dp2[v] += w;
		res.push_back(dp1[v]);
	}
	dp1[u] = 0;
	sort(res.rbegin(), res.rend());
	for (int i = 0; i < min(k-1, (int)res.size()); ++i) {
		dp1[u] += res[i];
	}
	dp2[u] = dp1[u];
	for (auto& to : adj[u]) {
		int v = to.first;
		if (v == p) continue;
		int cur = dp1[u] + dp2[v];
		if (k >= 2 && (res.size() < k || dp1[v] >= res[k-2])) {
			// dp1 is among first k-1 trips to other children
			// we have to exclude it, include next best
			//if (u==0)cout<<"u="<<u<<" v="<<v<<"\n"; 
			cur -= dp1[v];
			if (res.size() >= k) {
				cur += res[k-1];
			}
		}
		dp2[u] = max(dp2[u], cur);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	dfs(0, -1);
	//for (int v = 0; v < n; ++v) {
	//	cout << "v=" << v << " dp1="<<dp1[v]<<" dp2="<<dp2[v]<<endl;
	//}
	cout << dp2[0] << endl;
}
