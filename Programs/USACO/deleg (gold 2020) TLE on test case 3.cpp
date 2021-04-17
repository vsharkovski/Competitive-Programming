// 

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, k;
vector<int> graph[N];

int dfs_slow(int node, int par) {
	vector<int> values;
	for (int to : graph[node]) {
		if (to == par) continue;
		int x = dfs_slow(to, node);
		if (x == -1) {
			return -1;
		}
		if (x != k-1) {
			values.push_back(x+1);
		}
	}
	sort(values.begin(), values.end());
	int f1 = -1, f2 = -1;
	for (int i = 0, j = values.size()-1; i <= j; ++i, --j) {
		if (values[i] + values[j] != k) {
			f1 = i, f2 = j;
			break;
		}
	}
	if (f1 == -1 && f2 == -1) {
		if ((int)values.size() % 2 == 0) {
			return 0;
		} else {
			return values[values.size()/2];
		}
	}
	// assume f1 is outlier
	bool good = true;
	for (int i = f1+1, j = f2; i <= j; ++i, --j) {
		if (values[i] + values[j] != k) {
			good = false;
			break;
		}
	}
	if (good) {
		return values[f1];
	}
	// assume f2 is outlier
	good = true;
	for (int i = f1, j = f2-1; i <= j; ++i, --j) {
		if (values[i] + values[j] != k) {
			good = false;
			break;
		}
	}
	if (good) {
		return values[f2];
	}
	return -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifndef _DEBUG
	freopen("deleg.in", "r", stdin);
	freopen("deleg.out", "w", stdout);
	#endif // _DEBUG
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (k = 1; k <= n-1; ++k) {
		if ((n-1) % k == 0) {
			if (dfs_slow(1, -1) == 0) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
	}
}
