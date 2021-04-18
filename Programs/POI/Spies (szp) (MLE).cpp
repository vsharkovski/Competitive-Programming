// MLE because they set the memory limit to 32 MB instead of 256 for some reason.

#include <bits/stdc++.h>
using namespace std;

void dfs(int, int);
void dfs2(int);
int dfs3(int, int, int);
void process_cycle();

const int inf = 1e9;
const int N = 1000010;

int n, ans;
vector<int> graph[N];

int status[N];
int cycle_start, cycle_next;
vector<int> cycle;
bitset<N> in_cycle;

void dfs(int node, int par) {
	status[node] = 1;
	for (int to : graph[node]) {
		if (status[to] == 0) {
			dfs(to, node);
		} else if (status[to] == 1) {
			// cycle
			cycle_start = to;
			cycle_next = node;
		}
	}
	if (cycle_start != 0 && cycle_next == node) {
		cycle.push_back(node);
		in_cycle[node] = true;
		cycle_next = par;
	}
	if (cycle_start == node) {
		process_cycle();
		cycle_start = 0;
		cycle.clear();
	}
	status[node] = 2;
}

int status2[N];
int dp[N][2];

int m;
int cdp[N][2];

void process_cycle() {
	for (int node : cycle) {
		if (status2[node] == 0) {
			dfs2(node);
		}
	}
	reverse(cycle.begin(), cycle.end());
//	cout << "cycle: ";for (int x : cycle) cout << x << " ";cout<< "\n";
	m = cycle.size();
	int res = 0;
	for (int c0 = 0; c0 < 2; ++c0) {
		for (int i = 0; i < m; ++i) {
			for (int ci = 0; ci < 2; ++ci) {
				cdp[i][ci] = -1;
			}
		}
		res = max(res, dfs3(0, c0, c0));
	}
	ans += res;
}

void dfs2(int node) {
	status2[node] = 1;
	int sum = 0;
	int best0 = -inf, best0x = inf;
	for (int to : graph[node]) {
		if (!in_cycle[to]  && status2[to] == 0) {
			dfs2(to);
			int x = max(dp[to][0], dp[to][1]);
			sum += x;
			if (dp[to][0] > best0) {
				best0 = dp[to][0]; // maximize best0
				best0x = x;
			} else if (dp[to][0] == best0 && x < best0x) {
				best0x = x; // minimize best0x
			}
		}
	}
	dp[node][0] = sum;
	dp[node][1] = best0 == -inf ? -inf : (1 + sum - best0x + best0);
//	cout << "node="<<node<<" dp0="<<dp[node][0] << " dp1="<<dp[node][1]<<"\n";
}

int dfs3(int i, int ci, int c0) {
	int &res = cdp[i][ci];
	if (res != -1) return res;
	res = -inf;
	if (i < m-1) {
		if (ci == 0) {
			res = max(res, dp[cycle[i]][0] + dfs3(i+1, 0, c0));
			res = max(res, dp[cycle[i]][0] + dfs3(i+1, 1, c0));
		} else {
			// one child 0, next 0
			res = max(res, dp[cycle[i]][1] + dfs3(i+1, 0, c0));
			// one child 0, next 1
			res = max(res, dp[cycle[i]][1] + dfs3(i+1, 1, c0));
			// all child 0 or 1, next 0
			res = max(res, 1 + dp[cycle[i]][0] + dfs3(i+1, 0, c0));
		}
	} else {
		if (ci == 0 && c0 == 0) {
			res = max(res, dp[cycle[i]][0]);
		} else if (ci == 0 && c0 == 1) {
			res = max(res, dp[cycle[i]][0]);
		} else if (ci == 1 && c0 == 0) {
			// one child 0, next 0
			res = max(res, dp[cycle[i]][1]);
			// all child 0 or 1, next 0
			res = max(res, 1 + dp[cycle[i]][0]);
		} else { // ci == 1 && c0 == 1
			// one child 0, next 1
			res = max(res, dp[cycle[i]][1]);
		}
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int j;
		cin >> j;
		graph[j].push_back(i);
		status[i] = 0;
		status2[i] = 0;
//		cout<<j<<"->"<<i<<"\n";
	}
	ans = 0;
	cycle_start = 0;
	for (int i = 1; i <= n; ++i) {
		if (status[i] == 0) {
			dfs(i, -1);
		}
	}
	cout << ans << '\n';
}
