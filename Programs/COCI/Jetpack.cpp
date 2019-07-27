#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
 
const int maxn = 100010;
 
int n;
bool blocked[10][maxn];
bool visited[10][maxn];
bool should_use[10][maxn];
int di[2] = {1, -1};
 
bool dfs(int i, int j) {
	if (visited[i][j]) {
		return false;
	}
	visited[i][j] = true;
	if (j == n) {
		return true;
	}
	for (int d = 0; d < 2; ++d) {
		int i1 = max(0, min(9, i + di[d]));
		if (!blocked[i1][j+1] && dfs(i1, j+1)) {
			should_use[i][j] = d;
			return true;
		}
	}
	return false;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < n; ++j) {
			char ch;
			cin >> ch;
			blocked[i][j] = ch == 'X';
		}
	}
	if (dfs(9, 0) == false) {
		cout << "Found no solution\n";
		return 0;
	}
	vector<int> used;
	for (int i = 9, j = 0; j < n;) {
		if (should_use[i][j]) {
			i = max(0, i-1);
			used.push_back(j);
		} else {
			i = min(9, i+1);
		}
		++j;
	}
	vector<pii> ans;
	for (int t : used) {
		if (!ans.empty() && t == ans.back().first + ans.back().second) {
			ans.back().second += 1;
		} else {
			ans.emplace_back(t, 1);
		}
	}
	cout << ans.size() << '\n';
	for (auto& p : ans) {
		cout << p.first << ' ' << p.second << '\n';
	}
}
