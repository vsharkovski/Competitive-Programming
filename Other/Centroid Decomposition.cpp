#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

int n;
vector<int> adj[N];

struct CentroidDecomposition {
	bool removed[N];
	int subtree_size[N];
	int centroid_parent[N]; // in the tree built from centroids

	CentroidDecomposition() {
		memset(removed, false, sizeof(removed));
	}
	void decompose(int source, int parent) {
		get_subtree_size(source, -1);
		int centroid = get_centroid(source, -1, subtree_size[source]);
		// do things
		cout << "centroid: " << centroid << "\n";
		// ...
		centroid_parent[centroid] = parent;
		removed[centroid] = true;
		for (int v : adj[centroid]) {
			if (!removed[v]) {
				decompose(v, centroid);
			}
		}
	}
	void get_subtree_size(int node, int parent) {
		subtree_size[node] = 1;
		for (int v : adj[node]) {
			if (v != parent && !removed[v]) {
				get_subtree_size(v, node);
				subtree_size[node] += subtree_size[v];
			}
		}
	}
	int get_centroid(int node, int parent, int graph_size) {
		for (int v : adj[node]) {
			if (v != parent && !removed[v] && subtree_size[v] > graph_size/2) {
				return get_centroid(v, node, graph_size);
			}
		}
		return node;
	}
} cd;

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
	cd.decompose(1, -1);
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
