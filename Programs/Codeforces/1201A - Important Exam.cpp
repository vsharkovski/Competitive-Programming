#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> cnt(m, vector<int>(5, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char ch;
			cin >> ch;
			++cnt[j][ch-'A'];
		}
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int maxcnt = 0;
		for (int j = 0; j < 5; ++j) {
			maxcnt = max(maxcnt, cnt[i][j]);
		}
		int a;
		cin >> a;
		ans += maxcnt * a;
	}
	cout << ans << endl;
}
