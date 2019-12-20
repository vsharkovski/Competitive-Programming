// Problem : C. As Simple as One and Two
// Contest : Codeforces Round #606 (Div. 2, based on Technocup 2020 Elimination Round 4)
// URL : https://codeforces.com/contest/1277/problem/C
// Memory Limit : 256.000000MB 
// Time Limit : 3000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int SZ = 150010;

const int O = 0, N = 1, E = 2, T = 3, W = 4, X = 5;
const string Letters = "onetwx";

int n;
int a[SZ];
int dp[SZ][6][6];
int chs[SZ][6][6];

int dfs(int i, int p2, int p1) {
	int& res = dp[i][p2][p1];
	if (res != -1) return res;
	if (i == n) return res = 0;
	int& opt = chs[i][p2][p1];
	res = inf;
	int p0 = a[i], res1;
	if (p2 == O && p1 == N && p0 == E) {
		res = 1 + dfs(i+1, O, N), opt = 0;
	} else if (p2 == T && p1 == W && p0 == O) {
		res = 1 + dfs(i+1, T, W), opt = 0;
	} else {
		res = dfs(i+1, p1, p0), opt = -1;
		res1 = 1 + dfs(i+1, p2, p1);
		if (res > res1) res = res1, opt = 0;
		res1 = 1 + dfs(i+1, p2, p0);
		if (res > res1) res = res1, opt = 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		n = s.length();
		for (int i = 0; i < n; ++i) {
			a[i] = -1;
			for (int j = 0; j < 6; ++j) {
				if (Letters[j] == s[i]) {
					a[i] = j;
					break;
				}
			}
			if (a[i] == -1) a[i] = X;
		}
		a[n+1] = X;
		for (int i = 0; i <= n; ++i) {
			for (int x = 0; x < 6; ++x) {
				for (int y = 0; y < 6; ++y) {
					dp[i][x][y] = -1;
				}
			}
		}
		int ans = dfs(0, X, X);
		cout << ans << endl;
		vector<int> pos, rem;
		pos.push_back(n+1);
		pos.push_back(n+1);
		int i = 0;
		while (i < n) {
			pos.push_back(i);
			vector<int>::iterator p[3];
			for (int j = 0; j < 3; ++j) {
				p[j] = prev(pos.end(), j+1);
			}
			int& opt = chs[i][a[*p[2]]][a[*p[1]]];
			if (opt == -1) {

			} else {
				rem.push_back(*p[opt]);
				pos.erase(p[opt]);
			}
			++i;
		}
		for (int x : rem) {
			cout << x+1 << ' ';
		}
		cout << endl;
	}
}
