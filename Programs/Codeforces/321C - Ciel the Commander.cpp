#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


const int maxn = 100010;

int n;
vector<int> adj[maxn];
int sbsz[maxn];
bool removed[maxn];

int label[maxn];

void get_sbsz(int node, int parent) {
	sbsz[node] = 1;
	for (int v : adj[node]) {
		if (!removed[v] && v != parent) {
			get_sbsz(v, node);
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

void centroidDecomposition(int root, int parent, int iteration) {
	// cout << "centroidDecomposition(root=" << root << ", parent=" << parent << ", iteration=" << iteration << ")\n";
	get_sbsz(root, parent);
	int centroid = findCentroid(root, parent, sbsz[root]);
	// cout << "centroid is " << centroid << '\n';
	removed[centroid] = true;
	label[centroid] = iteration;
	for (int v : adj[centroid]) {
		if (!removed[v] && v != parent) {
			centroidDecomposition(v, centroid, iteration+1);
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
    centroidDecomposition(1, -1, 0);
    for (int i = 1; i <= n; ++i) {
    	cout << char(label[i]+'A') << ' ';
    }
}
