// Problem : C. Obtain The String
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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
		string s, t;
		cin >> s >> t;
		int n = s.length(), m = t.length();
		vector<vector<int>> nxt(26, vector<int>(n+2, n));
		for (int i = 25; i >= 0; --i) {
			for (int j = n-1; j >= 0; --j) {
				nxt[i][j] = nxt[i][j+1];
				if (s[j]-'a' == i) {
					nxt[i][j] = j;
				}
			}
		}
		bool good = true;
		int ans = 1;
		int j = 0;
		for (int i = 0; i < m; ++i) {
			int x = t[i]-'a';
			int k = nxt[x][j];
			//cout << "i="<<i<< " x="<<x<<" j="<<j<<" k="<<k<<"\n";
			if (k == n) {
				++ans;
				j = 0;
				k = nxt[x][j];
				//cout << "increasing, j=0, k=" << k << "\n";
			}
			if (k == n) {
				good = false;
				break;
			}
			j = k+1;
		}
		if (!good) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}
}
