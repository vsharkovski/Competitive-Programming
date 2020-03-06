// Maximum cardinality biparite matching
#include <bits/stdc++.h>
using namespace std;

int n, m; // size of left, size of right set
vector<vector<int>> adj; // L -> R
vector<int> match; // for each in R
vector<bool> visited; // for each in L

bool augmented_path(int l) {
	if (visited[l]) return false;
	visited[l] = true;
	for (int r : adj[l]) {
		if (match[r] == -1 || augmented_path(match[r])) {
			match[r] = l;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// read the graph, make adjacency list
	match.assign(m, -1);
	int matches = 0;
	for (int l = 0; l < n; ++l) {
		visited.assign(n, false);
		if (augmented_path(l)) {
			++matches;
		}
	}
	cout << matches << '\n';
}
