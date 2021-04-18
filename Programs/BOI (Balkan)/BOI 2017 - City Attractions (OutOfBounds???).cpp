#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 300010;

int n, k;
vector<int> graph[N];
array<pii,2> dp[N]; // pair: (val, node)
int succ[N];
int dist[N];

string P(pii x) {
	return "("+to_string(x.first)+","+to_string(x.second)+")";
}

array<pii,2> combine(array<pii,2> a, array<pii,2> b) {
	vector<pii> res;
	for (int i = 0; i < 2; ++i) {
		res.push_back(a[i]);
		b[i].first -= 1;
		res.push_back(b[i]);
	}
	sort(res.begin(), res.end(), [&](const pii& x, const pii& y){
		if (x.first != y.first) return x.first > y.first;
		return x.second < y.second;
	});
	array<pii,2> ans;
	int i = 0;
	for (pii p : res) {
		if (i == 1 && ans[0].second == p.second) continue;
		ans[i++] = p;
		if (i == 2) break;
	}
	return ans;
}

void dfs1(int node, int par) {
	for (int to : graph[node]) {
		if (to == par) continue;
		dfs1(to, node);
		dp[node] = combine(dp[node], dp[to]);
	}
}

void dfs2(int node, int par) {
	for (int to : graph[node]) {
		if (to == par) continue;
		dp[to] = combine(dp[to], dp[node]);
		dfs2(to, node);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		dp[i] = {{{a, i}, {-inf, inf}}};
	}
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs1(1, -1);
	dfs2(1, -1);
	for (int i = 1; i <= n; ++i) {
		if (dp[i][0].second == i) {
			succ[i] = dp[i][1].second;
		} else {
			succ[i] = dp[i][0].second;
		}
		dist[i] = -1;
//		cout<<"dp["<<i<<"][0]="<<P(dp[i][0])<<"\n";
//		cout<<"dp["<<i<<"][1]="<<P(dp[i][1])<<"\n";
//		cout<<"succ["<<i<<"]="<<succ[i]<<"\n";
	}
	bool entered_cycle = false;
	int i = 1;
	dist[i] = 0;
	while (k > 0) {
		int j = succ[i];
		if (dist[j] == -1 || entered_cycle) {
			dist[j] = dist[i] + 1;
			i = j;
			--k;
		} else {
			// found cycle
			int csize = dist[i] - dist[j] + 1;
			k %= csize;
			entered_cycle = true;
		}
	}
	cout << i << '\n';
}
