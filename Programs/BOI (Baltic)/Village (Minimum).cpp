#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int N = 100010;

int n;
vector<int> graph[N];
int label[N];
int result[N];

int dp0[N];
vector<int> choice0[N];

int dp1[N];
int choice1[N];

void dfs(int node, int par) {
	int sum = 0;
	choice0[node].resize(graph[node].size());
	for (int i = 0; i < (int)graph[node].size(); ++i) {
		int to = graph[node][i];
		if (to == par) continue;
		dfs(to, node);
		if (2 + dp0[to] < dp1[to]) {
			// swap
			sum += 2 + dp0[to];
			choice0[node][i] = 0;
		} else {
			// leave, must swap next
			sum += dp1[to];
			choice0[node][i] = 1;
		}
	}
	dp0[node] = sum;
	dp1[node] = inf;
	for (int i = 0; i < (int)graph[node].size(); ++i) {
		int to = graph[node][i];
		if (to == par) continue;
		// swap
		int alt = 2 + dp0[to] + sum - min(2 + dp0[to], dp1[to]);
		if (alt < dp1[node]) {
			dp1[node] = alt;
			choice1[node] = i;
		}
	}
}

void dfs2(int node, int par, int c) {
	for (int i = 0; i < (int)graph[node].size(); ++i) {
		int to = graph[node][i];
		if (to == par) continue;
		if (c == 1 && choice1[node] == i) {
			// must swap
			swap(label[node], label[to]);
			dfs2(to, node, 0);
		} else {
			// the better choice
			if (choice0[node][i] == 0) {
				swap(label[node], label[to]);
				dfs2(to, node, 0);
			} else {
				dfs2(to, node, 1);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; ++i) {
		label[i] = i;
	}
	dfs2(1, -1, 1);
	for (int i = 1; i <= n; ++i) {
		result[label[i]] = i;
	}
	cout << dp1[1] << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << result[i] << ' ';
	}
}
