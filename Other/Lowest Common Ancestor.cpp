#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;
const int K = 17;

int n;
vector<int> adj[N];

int depth[N];
int P[N][K];

void dfs(int node, int parent, int dpth) {
	P[node][0] = parent;
	depth[node] = dpth;
	for (int v : adj[node]) {
		if (v == parent) continue;
		dfs(v, node, dpth+1);
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int j = K-1; j >= 0; --j) {
		if (depth[a] - (1<<j) >= depth[b]) {
			a = P[a][j];
		}
	}
	if (a == b) return a;
	for (int j = K-1; j >= 0; --j) {
		if (P[a][j] != -1 && P[a][j] != P[b][j]) {
			a = P[a][j];
			b = P[b][j];
		}
	}
	return P[a][0];
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
	dfs(1, -1, 0);
	for (int j = 1; j < K; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (P[i][j-1] == -1) {
				P[i][j] = -1;
			} else {
				P[i][j] = P[ P[i][j-1] ][j-1];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			cout << "LCA(" << i << ", " << j << ") = " << LCA(i, j) << '\n';
		}
	}
}

/*
sample input:
10
1 2
2 3
2 4
4 5
5 6
5 7
4 8
8 9
8 10
*/
