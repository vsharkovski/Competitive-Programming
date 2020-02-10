// Problem : D. Match & Catch
// Contest : Codeforces Round #244 (Div. 2)
// URL : https://codeforces.com/contest/427/problem/D
// Memory Limit : 512.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5005;

int n, m;
int lcp[N][N];
int mu1[N], mu2[N];

void calc_lcp(string& s, string& t) {
	memset(lcp, 0, sizeof(lcp));
	int n = s.length(), m = t.length();
	for (int i = n-1; i >= 0; --i) {
		for (int j = m-1; j >= 0; --j) {
			if (s[i] == t[j]) {
				lcp[i][j] = 1 + lcp[i+1][j+1];
			} else {
				lcp[i][j] = 0;
			}
		}
	}
}

void calc_mu(int mu[N], int n) {
	for (int i = 0; i < n; ++i) {
		mu[i] = 1;
		for (int j = 0; j < n; ++j) {
			if (j == i) continue;
			mu[i] = max(mu[i], lcp[i][j] + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	n = s.length(), m = t.length();
	calc_lcp(s, s);
	calc_mu(mu1, n);
	calc_lcp(t, t);
	calc_mu(mu2, m);
	calc_lcp(s, t);
	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (lcp[i][j] >= max(mu1[i], mu2[j])) {
				ans = min(ans, max(mu1[i], mu2[j]));
			}
		}
	}
	if (ans == 1e9) ans = -1;
	cout << ans << endl;
}
