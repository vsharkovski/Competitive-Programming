#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


const int maxn = 100010;

int n;
vector<int> adj[maxn];

int sbsz[maxn];
bool removed[maxn];

void getSubtreeSize(int node, int parent) {
	sbsz[node] = 1;
	for (int v : adj[node]) {
		if (!removed[v] && v != parent) {
			getSubtreeSize(v, node);
			sbsz[node] += sbsz[v];
		}
	}
}

int findCentroid(int node, int parent, int tree_size) {
	for (int v : adj[node]) {
		if (!removed[v] && v != parent && sbsz[v] > tree_size/2) {
			return findCentroid(v, node, tree_size);
		}
	}
	return node;
}

void centroidDecomposition(int root, int parent) {
	getSubtreeSize(root, parent);
	int centroid = findCentroid(root, parent, sbsz[root]);
	removed[centroid] = true;
	// do stuff with centroid
	
	//
	for (int v : adj[centroid]) {
		if (!removed[v] && v != parent) {
			centroidDecomposition(v, centroid);
		}
	}
	removed[centroid] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
    	int a, b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    memset(removed, false, sizeof(removed));
    centroidDecomposition(1, -1);
}
