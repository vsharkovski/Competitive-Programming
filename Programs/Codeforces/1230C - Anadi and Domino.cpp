#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[8];
int msk[8];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
    }
	if (n <= 6) {
		cout << m << endl;
		return 0;
	}
	for (int i = 1; i <= 7; ++i) {
		msk[i] = 0;
		for (int j : adj[i]) {
			msk[i] |= (1 << j);
		}
	}
	int ans = 0;
	for (int x = 1; x <= 7; ++x) {
		for (int y = x+1; y <= 7; ++y) {
			ans = max(ans, m - __builtin_popcount(msk[x] & msk[y]));
		}
	}
	cout << ans << endl;
}
