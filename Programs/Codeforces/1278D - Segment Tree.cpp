// Problem : D. Segment Tree
// Contest : Educational Codeforces Round 78 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1278/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 500010;

int n, edges;
vector<int> adj[N];
int L[N], R[N];
int data[2*N];

struct Compare {
	bool operator () (const int& a, const int& b) {
		return R[a] < R[b];
	}
};

const int unvisited = 0, visited = 2, explored = 1;
bool cycle;
int nodecnt;
int status[N];

void dfs(int u, int p) {
	++nodecnt;
	status[u] = explored;
	for (int v : adj[u]) {
		if (status[v] == unvisited) {
			dfs(v, u);
			if (cycle) return;
		} else if (v != p && status[v] == explored) {
			cycle = true;
			return;
		}
	}
	status[u] = visited;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		L[i] = l;
		R[i] = r;
		data[l] = i;
		data[r] = -i;
	}
	set<int, Compare> active;
	edges = 0;
	for (int i = 1; i <= 2*n; ++i) {
		if (edges >= n) break;
		int x = data[i];
		if (x > 0) {
			active.insert(x);
			for (auto it = active.begin(); *it != x; ++it) {
				if (edges >= n) break;
				++edges;
				adj[x].push_back(*it);
				adj[*it].push_back(x);
			}
		} else {
			x = -x;
			active.erase(x);
		}
	}
	if (edges == n) {
		cout << "NO\n";
		return 0;
	}
	memset(status, unvisited, sizeof(status));
	cycle = false;
	nodecnt = 0;
	dfs(1, -1);
	if (cycle) {
		cout << "NO\n";
		return 0;
	}
	if (nodecnt < n) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}
