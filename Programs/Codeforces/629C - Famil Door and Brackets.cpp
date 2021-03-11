 
// Problem : C. Famil Door and Brackets
// Contest : Codeforces Round #343 (Div. 2)
// URL : https://codeforces.com/contest/629/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	return x;
}

inline int mult(int x, int y) {
	return (ll)x * y % mod;
}

const int N = 100010;
const int K = 2010;

int n, m;
bool s[N];
int dp[K][K];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	dp[0][0] = 1;
	for (int len = 1; len <= n-m; ++len) {
		for (int bal = 0; bal <= len; ++bal) {
			int& p = dp[len][bal];
			p = 0;
			// last character is (
			if (bal > 0) {
				p = add(p, dp[len-1][bal-1]);
			}
			// last character is )
			if (bal+1 <= len-1) {
				p = add(p, dp[len-1][bal+1]);
			}
		}
	}
	int aL = 0, aR = 0;
	for (int i = 0; i < m; ++i) {
		char ch;
		cin >> ch;
		aR += (ch == '(') ? 1 : -1;
		aL = max(aL, -aR);
	}
	//cout << "aL="<<aL <<" aR="<<aR<<'\n';
	int ans = 0;
	for (int lenL = 0; lenL <= n-m; ++lenL) {
		int lenR = n - m - lenL;
		for (int balL = aL; balL <= lenL; ++balL) {
			int balR = aR + balL;
			if (balR > lenR) break;
			//cout << "lenL="<<lenL<<" balL="<<balL<<" lenR="<<lenR<<" balR="<<balR<<"\n";
			//cout << "ways="<<dp[lenL][balL]<<"*"<<dp[lenR][balR]<<"="<<mult(dp[lenL][balL],dp[lenR][balR])<<"\n";
			ans = add(ans, mult(dp[lenL][balL], dp[lenR][balR]));
		}
	}
	cout << ans << '\n';
}
