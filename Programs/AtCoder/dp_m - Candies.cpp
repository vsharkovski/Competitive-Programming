#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; // m candies total
	cin >> n >> m;
	vector<int> pre(m+1, 0), cur(m+1);
	pre[0] = 1;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int k = 0; k <= m; ++k) {
			if (k) pre[k] = add(pre[k], pre[k-1]);
			cur[k] = pre[k];
			if (k-a-1 >= 0) cur[k] = add(cur[k], -pre[k-a-1]);
			// dp[i][k] = sum(dp[i-1][j]) as j=k-a[i] to k
			// i.e cur[k] = sum(pre[j]) as j=k-a[i] to k
			// we can make pre a prefix sum array and use that
		}
		swap(pre, cur);
	}
	cout << pre[m] << '\n';
}
