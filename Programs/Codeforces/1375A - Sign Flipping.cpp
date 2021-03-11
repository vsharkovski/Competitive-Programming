
// Problem : A. Sign Flipping
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 100;

int n;
int a[N];
int sign[N];
bool vis[N][N][N][2];

bool dfs(int i, int cp, int cn, int prs) {
	if (vis[i][cp][cn][prs]) return false;
	vis[i][cp][cn][prs] = true;
	if (i == n) {
		if (cp >= (n-1)/2 && cn >= (n-1)/2) {
			return true;
		} else {
			return false;
		}
	}
	if (i == 0) {
		for (int s = 0; s < 2; ++s) {
			if (dfs(i+1, 0, 0, s)) {
				sign[i] = s;
				return true;
			}
		}
	} else {
		int pre = prs == 0 ? a[i-1] : -a[i-1];
		for (int s = 0; s < 2; ++s) {
			int cur = s == 0 ? a[i] : -a[i];
			int cp1 = cp, cn1 = cn;
			if (cur - pre >= 0) ++cp1;
			if (cur - pre <= 0) ++cn1;
			if (dfs(i+1, cp1, cn1, s)) {
				sign[i] = s;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i <= n; ++i) {
			for (int cp = 0; cp <= n; ++cp) {
				for (int cn = 0; cn <= n; ++cn) {
					for (int prs = 0; prs < 2; ++prs) {
						vis[i][cp][cn][prs] = false;
					}
				}
			}
		}
		dfs(0, 0, 0, 0);
		for (int i = 0; i < n; ++i) {
			cout << (sign[i] == 0 ? a[i] : -a[i]) << ' ';
		}
		cout << '\n';
	}
}
