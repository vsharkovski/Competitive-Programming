#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
const int m = 8;

const int N = 200010;

int n;
int a[N];
int dp[N][m];

int dfs(int i, int j) {
	int& res = dp[i][j];
	if (res != -1) return res;
	if (i == n) return res = (j == 0);
	res = 0;
	res = (res + dfs(i+1, j)) % mod;
	res = (res + dfs(i+1, (10*j + a[i]) % m)) % mod;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0)-1 << endl;
}
