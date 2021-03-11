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

const int N = 10010;
const int M = 101;

int n, m;
int a[N];
int dp[N][M][2];

int dfs(int i, int rem, int free) {
	int &res = dp[i][rem][free];
	if (res != -1) return res;
	if (i == n) return res = (rem == 0);
	res = 0;
	if (free) {
		for (int d = 0; d <= 9; ++d) {
			res = add(res, dfs(i+1, (rem+d)%m, 1));
		}
	} else {
		for (int d = 0; d < a[i]; ++d) {
			res = add(res, dfs(i+1, (rem+d)%m, 1));
		}
		res = add(res, dfs(i+1, (rem+a[i])%m, 0));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str >> m;
	n = str.length();
	for (int i = 0; i < n; ++i) {
		a[i] = str[i] - '0';
	}
	memset(dp, -1, sizeof(dp));
	int ans = dfs(0, 0, 0) - 1; // skip 000..000
	if (ans < 0) ans += mod;
	cout << ans << '\n';
}
