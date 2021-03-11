
// Problem : E. Erase Subsequences
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 404;
const int A = 26;

int n, m, k;
int s[N], t[N];
int nxt[A][N];
int dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string s1, t1;
		cin >> s1 >> t1;
		n = s1.length();
		m = t1.length();
		for (int i = 0; i < n; ++i) {
			s[i] = s1[i] - 'a';
		}
		for (int i = 0; i < m; ++i) {
			t[i] = t1[i] - 'a';
		}
		for (int c = 0; c < A; ++c) {
			nxt[c][n] = n;
			for (int i = n-1; i >= 0; --i) {
				nxt[c][i] = nxt[c][i+1];
				if (s[i] == c) {
					nxt[c][i] = i;
				}
			}
		}
		/*/
		cout << "s: ";
		for (int i = 0; i < n; ++i) {
			cout << setw(2)<<right<<s[i]<<" ";
		}
		cout << "\nt: ";
		for (int i = 0; i < m; ++i) {
			cout << setw(2)<<right<<t[i]<<" ";
		}
		cout << "\n";
		/*/
		/*
		a: first subsequence, len = k
		b: second subsequence, len = m-k
		dp[pa][pb] = min length of prefix of s such that
		prefixes of len pa for a and len pb for b
		can be formed from that prefix of s
		*/
		bool found = false;
		for (k = 0; k < m; ++k) {
			for (int i = 0; i <= m; ++i) {
				for (int j = 0; j <= m; ++j) {
					dp[i][j] = 1e9;
				}
			}
			dp[0][0] = 0;
			for (int pa = 0; pa <= k; ++pa) {
				for (int pb = 0; pb <= m-k; ++pb) {
					if (dp[pa][pb] == 1e9) continue;
					//cout << "dp["<<pa<<"]["<<pb<<"]="<<dp[pa][pb]<<"\n";
					// add to a
					if (pa < k) {
						int i = nxt[t[pa]][dp[pa][pb]];
						if (i < n) {
							//cout << "i="<<i<<" incr a\n";
							dp[pa+1][pb] = min(dp[pa+1][pb], i+1);
						}
					}
					// add to b
					if (pb < m-k) {
						int i = nxt[t[k+pb]][dp[pa][pb]];
						if (i < n) {
							//cout << "i="<<i<<" incr b\n";
							dp[pa][pb+1] = min(dp[pa][pb+1], i+1);
						}
					}
				}
			}
			if (dp[k][m-k] <= n) {
				found = true;
				//cout << "found |a|="<<k<<" |b|="<<m-k<<"\n";
				break;
			}
		}
		if (found) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
