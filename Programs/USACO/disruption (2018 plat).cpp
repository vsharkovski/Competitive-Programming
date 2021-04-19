// USACO 2018 US Open Contest, Platinum
// Problem 3. Disruption
// disrupt.cpp

#include <bits/stdc++.h>
using namespace std;

const int N = 50010;
const int LOGN = 18;
const int M = 50010;

using pii = pair<int, int>;

int n, m;
vector<pii> graph[N];
vector<pii> tokens[N];
int ans[N];

inline void try_add(set<pii> &s, pii t) {
	auto ptr = s.find(t);
	if (ptr != s.end()) {
		s.erase(ptr);
	} else {
		s.insert(t);
	}
}

void dfs(int node, int par_edge, set<pii> &s) {
	vector<set<pii>> results;
	int final_idx = -1;
	for (auto to : graph[node]) {
		if (to.second == par_edge) continue;
		results.push_back(set<pii>());
		dfs(to.first, to.second, results.back());
		if (final_idx == -1 || results.back().size() > results[final_idx].size()) {
			final_idx = results.size()-1;
		}
	}
	if (final_idx != -1) {
		s.swap(results[final_idx]);
	}
	for (auto t : tokens[node]) {
		try_add(s, t);
	}
	for (int i = 0; i < (int)results.size(); ++i) {
		if (i == final_idx) continue;
		for (auto res : results[i]) {
			try_add(s, res);
		}
	}
//	cout<<"node="<<node<<" pe="<<par_edge<<" s={";for(auto x:s)cout<<"("<<x.first<<","<<x.second<<"),";cout<<"}\n";
	if (par_edge != -1) {
		ans[par_edge] = -1;
		if (!s.empty()) {
			ans[par_edge] = s.begin()->first;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifndef _DEBUG
	freopen("disrupt.in", "r", stdin);
	freopen("disrupt.out", "w", stdout);
	#endif // _DEBUG
	cin >> n >> m;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b, i);
		graph[b].emplace_back(a, i);
//		cout<<"edge "<<i<<": "<<a<<"-"<<b<<"\n";
	}
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		tokens[a].emplace_back(w, a);
		tokens[b].emplace_back(w, a);
	}
	set<pii> tmp;
	dfs(1, -1, tmp);
	for (int i = 0; i < n-1; ++i) {
		cout << ans[i] << '\n';
	}
}
