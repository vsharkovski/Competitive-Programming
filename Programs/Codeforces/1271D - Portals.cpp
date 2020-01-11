// Problem : D. Portals
// Contest : Codeforces Round #608 (Div. 2)
// URL : https://codeforces.com/contest/1271/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int inf = 1e9;
	int n, portals, initw, sumw;
	cin >> n >> portals >> initw;
	vector<int> wreq(n+1), wget(n+1), val(n+1);
	vector<int> rightmost(n+1);
	sumw = initw;
	for (int i = 1; i <= n; ++i) {
		cin >> wreq[i] >> wget[i] >> val[i];
		rightmost[i] = i;
		if (sumw < wreq[i]) {
			cout << "-1\n";
			return 0;
		}
		sumw += wget[i];
	}
	for (int i = 0; i < portals; ++i) {
		int u, v;
		cin >> u >> v;
		rightmost[v] = max(rightmost[v], u);
	}
	vector<vector<int>> lefties(n+1);
	for (int i = 1; i <= n; ++i) {
		lefties[rightmost[i]].push_back(i);
		sort(lefties[i].begin(), lefties[i].end(),
			[&] (int a, int b) {
				return val[a] > val[b];
			}
		);
	}
	vector<int> cur(sumw+1, -inf), nxt;
	cur[initw] = 0;
	for (int i = 1; i <= n; ++i) {
		nxt.assign(sumw+1, -inf);
		int m = lefties[i].size();
		int reward = 0;
		for (int x = 0; x <= m; ++x) {
			for (int w = wreq[i]; w <= sumw - wget[i]; ++w) {
				int w1 = w + wget[i] - x;
				if (w1 < 0) continue;
				nxt[w1] = max(nxt[w1], reward + cur[w]);
			}
			if (x < m) {
				reward += val[lefties[i][x]];
			}
		}
		swap(cur, nxt);
	}
	int ans = -inf;
	for (int w = 0; w <= sumw; ++w) {
		ans = max(ans, cur[w]);
	}
	cout << ans << endl;
}
