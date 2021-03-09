#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	const int m = 3;
	vector<int> cur(m), nxt(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int a;
			cin >> a;
			for (int k = 0; k < m; ++k) {
				if (k == j) continue;
				nxt[j] = max(nxt[j], cur[k] + a);
			}
		}
		swap(cur, nxt);
		nxt.assign(m, 0);
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ans = max(ans, cur[i]);
	}
	cout << ans << '\n';
}
