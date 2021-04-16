#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 100100;

int n, m;
vector<int> graph[N];
int val[N];
int ans[N];

int timer;
int tin[N], tout[N];
int euler_tour[2*N];

int bit[N];

void dfs(int node) {
	tin[node] = timer;
	euler_tour[timer++] = node;
	for (int to : graph[node]) {
		dfs(to);
	}
	tout[node] = timer;
	euler_tour[timer++] = node;
}

void update(int pos, int val) {
	while (pos <= m) {
		bit[pos] += val;
		pos += pos & -pos;
	}
}

int sum(int pos) {
	int res = 0;
	while (pos >= 1) {
		res += bit[pos];
		pos -= pos & -pos;
	}
	return res;
}

inline int sum(int l, int r) {
	if (l > r) return 0;
	return sum(r) - sum(l-1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifndef _DEBUG
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	#endif // _DEBUG
	cin >> n;
	vector<int> valuni(n);
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		valuni[i-1] = val[i];
	}
	sort(valuni.begin(), valuni.end());
	valuni.erase(unique(valuni.begin(), valuni.end()), valuni.end());
	m = valuni.size();
	for (int i = 1; i <= n; ++i) {
		val[i] = 1 + lower_bound(valuni.begin(), valuni.end(), val[i]) - valuni.begin();
	}
	for (int i = 1; i <= m; ++i) {
		bit[i] = 0;
	}
	for (int i = 2; i <= n; ++i) {
		int j;
		cin >> j;
		graph[j].push_back(i);
	}
	timer = 0;
	dfs(1);
	for (int i = 0; i < timer; ++i) {
		int node = euler_tour[i];
		update(val[node], 1);
		if (i == tin[node]) {
			ans[node] = -sum(val[node]+1, m);
		} else { // tout
			ans[node] += sum(val[node]+1, m);
			ans[node] /= 2;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << '\n';
	}
}
