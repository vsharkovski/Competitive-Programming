// Problem : F1. Wrong Answer on test 233 (Easy Version)
// Contest : Technocup 2020 - Elimination Round 3
// URL : https://codeforces.com/problemset/problem/1227/F1
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 998244353;

int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	return x;
}

int mult(int x, int y) {
	return (ll)x * y % mod;
}

const int N = 2010;

int n, k;
int h[N];
int dp[N][2*N];

int dfs(int pos, int diff) {
	int& res = dp[pos][diff+N];
	if (res != -1) return res;
	if (pos == n) return diff > 0;
	res = 0;
	// put h[i]
	res = add(res, dfs(pos+1, diff - 1 + (h[pos+1] == h[pos])));
	// put h[i+1]
	if (h[pos+1] != h[pos]) {
		res = add(res, dfs(pos+1, diff+1));
	}
	// put other
	int choices = h[pos+1] == h[pos] ? k-1 : k-2;
	if (choices > 0) {
		res = add(res, mult(choices, dfs(pos+1, diff)));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	h[n] = h[0];
	memset(dp, -1, sizeof(dp));
	int ans = dfs(0, 0);
	cout << ans << endl;
}
