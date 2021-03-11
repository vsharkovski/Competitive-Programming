
// Problem : D. TediousLee
// Contest : Codeforces - Codeforces Round #652 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1369/D
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

const int N = 2000100;

int dp[N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	dp[1][0] = dp[1][1] = 0;
	dp[2][0] = dp[2][1] = 0;

	for (int n = 3; n < N; ++n) {
		int	dont = add(dp[n-1][0], add(dp[n-2][0], dp[n-2][0]));
		dp[n][1] = dont;
		dp[n][0] = dont;
		if (n % 3 != 2) {
			// should color (magic)
			int color = add(4, add(dp[n-1][1], add(dp[n-2][1], dp[n-2][1])));
			dp[n][0] = color;
		}
	}
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n][0] << '\n';
	}
}
