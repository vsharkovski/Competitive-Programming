#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
 
const int maxn = 16;
const int A = 26;
const int inf = 1e9;
 
int n;
int cnt[maxn][A];
int dp[1<<maxn];
 
int num_common(int mask) {
	int mincnt[A];
	for (int j = 0; j < A; ++j) {
		mincnt[j] = inf;
	}
	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			for (int j = 0; j < A; ++j) {
				mincnt[j] = min(mincnt[j], cnt[i][j]);
			}
		}
	}
	int res = 0;
	for (int j = 0; j < A; ++j) {
		res += mincnt[j];
	}
	return res;
}
 
int dfs(int mask) {
	int& res = dp[mask];
	if (res != -1) {
		return res;
	}
	int common = num_common(mask);
	if ((mask == 0 || mask-(mask&-mask)) == 0) {
		// 0 or 1 bit on
		return res = common; // just the length of the word
	}
	res = inf;
	for (int submask = (mask-1) & mask; submask > 0; submask = (submask-1) & mask) {
		res = min(res, -common + dfs(submask) + dfs(mask ^ submask));
	}
	return res;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < A; ++j) {
			cnt[i][j] = 0;
		}
		for (char ch : s) {
			++cnt[i][ch-'a'];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << 1 + dfs((1 << n) - 1) << '\n';
}
