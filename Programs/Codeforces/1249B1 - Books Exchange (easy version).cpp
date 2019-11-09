#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int n;
vector<vector<int>> adj;
vector<int> ccsz;
vector<int> num, low, stk, instk;
int calls;

void tarjan(int u) {
	num[u] = low[u] = calls++;
	instk[u] = 1;
	stk.push_back(u);
	for (int v : adj[u]) {
		if (num[v] == -1) {
			tarjan(v);
		}
		if (instk[v]) {
			low[u] = min(low[u], low[v]);
		}
	}
	if (low[u] == num[u]) {
		vector<int> cc;
		while (true) {
			int v = stk.back();
			stk.pop_back();
			instk[v] = 0;
			cc.push_back(v);
			if (v == u) break;
		}
		for (int v : cc) {
			ccsz[v] = cc.size();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		cin >> n;
		adj.assign(n+1, vector<int>());
		for (int i = 1; i <= n; ++i) {
			int j;
			cin >> j;
			adj[i].push_back(j);
		}
		num.assign(n+1, -1);
		low.resize(n+1);
		instk.assign(n+1, 0);
		calls = 0;
		ccsz.resize(n+1);
		for (int i = 1; i <= n; ++i) {
			if (num[i] == -1) {
				tarjan(i);
			}
		}
		for (int i = 1; i <= n; ++i) {
			cout << ccsz[i] << ' ';
		}
		cout << endl;
	}
}
