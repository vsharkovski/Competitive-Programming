
// Problem : B. Neighbor Grid
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		int mx = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
				mx = max(mx, a[i][j]);
			}
		}
		if (mx > 4) {
			cout << "NO\n";
			continue;
		}
		if (a[0][0] > 2 || a[n-1][0] > 2 || a[0][m-1] > 2 || a[n-1][m-1] > 2) {
			cout << "NO\n";
			continue;
		}
		a[0][0] = a[n-1][0] = a[0][m-1] = a[n-1][m-1] = 2;
		bool bad = false;
		for (int j = 1; j < m-1; ++j) {
			if (a[0][j] > 3 || a[n-1][j] > 3) {
				bad = true;
				break;
			}
			a[0][j] = a[n-1][j] = 3;
		}
		for (int i = 1; i < n-1; ++i) {
			if (a[i][0] > 3 || a[i][m-1] > 3) {
				bad = true;
				break;
			}
			a[i][0] = a[i][m-1] = 3;
		}
		if (bad) {
			cout << "NO\n";
			continue;
		}
		for (int i = 1; i < n-1; ++i) {
			for (int j = 1; j < m-1; ++j) {
				a[i][j] = 4;
			}
		}
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}
