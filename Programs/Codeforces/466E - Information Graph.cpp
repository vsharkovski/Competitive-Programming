// Problem : E. Information Graph
// Contest : Codeforces Round #266 (Div. 2)
// URL : https://codeforces.com/contest/466/problem/E
// Memory Limit : 512.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;

int n, m, numpackets;
vector<pii> queries[N]; // for each number: (wanted packet, query id)
int ans[N]; // answer for query
vector<int> children[N];
vector<int> toremove[N]; // numbers to remove at this node
vector<int> toadd[N]; // numbers to add at this node
set<int> nums[N];
bool done[N];

struct DSU {
	int p[N];
	DSU() {
		for (int i = 0; i < N; ++i) p[i] = i;
	}
	inline int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}
	inline void unite(int x, int y) {
		p[x] = y;
	}
} dsu;

void dfs(int u) {
	int bestch = -1;
	for (int v : children[u]) {
		dfs(v);
		if (bestch == -1 || nums[bestch].size() < nums[v].size()) {
			bestch = v;
		}
	}
	if (bestch != -1) {
		swap(nums[u], nums[bestch]);
	}
	for (int p : toadd[u]) {
		nums[u].insert(p);
	}
	for (int v : children[u]) {
		if (v == bestch) continue;
		while (!nums[v].empty()) {
			auto it = nums[v].begin();
			nums[u].insert(*it);
			nums[v].erase(it);
		}
	}
	/*
	cout << "u=" << u << " nums:{";
	for (int x : nums[u]) cout << x << ' ';
	cout << "}\n"; 
	/*/
	for (pii& query : queries[u]) {
		int p = query.first, id = query.second;
		ans[id] = nums[u].find(p) != nums[u].end();
	}
	for (int p : toremove[u]) {
		nums[u].erase(p);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	numpackets = 0;
	for (int i = 1; i <= m; ++i) {
		ans[i] = -1;
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			children[y].push_back(x);
			dsu.unite(x, y);
			//cout << "i=" << i <<" p[" << x << "]=" << y << "\n";
		} else if (t == 2) {
			int x;
			cin >> x;
			int root = dsu.get(x);
			++numpackets;
			toadd[x].push_back(numpackets);
			toremove[root].push_back(numpackets);
			//cout << "i=" << i << ", pck="<<numpackets<<" x=" << x << ", root=" <<root<<"\n";
		} else {
			int x, p;
			cin >> x >> p;
			queries[x].emplace_back(p, i);
			//cout << "i="<<i<<", x="<<x<<" p=" << p << "\n";
		}
	}
	memset(done, false, sizeof(done));
	for (int i = 1; i <= n; ++i) {
		int root = dsu.get(i);
		if (!done[root]) {
			done[root] = true;
			dfs(root);
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (ans[i] != -1) {
			//cout << "i=" << i << " ans=";
		}
		if (ans[i] == 0) {
			cout << "NO\n";
		} else if (ans[i] == 1) {
			cout << "YES\n";
		}
	}
}
