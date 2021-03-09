#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, maxw, sumv;
	cin >> n >> maxw;
	sumv = 0;
	vector<int> itemw(n), itemv(n);
	for (int i = 0; i < n; ++i) {
		cin >> itemw[i] >> itemv[i];
		sumv += itemv[i];
	}
	vector<int> dp(sumv+1, maxw+1);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int v = sumv-itemv[i]; v >= 0; --v) {
			dp[v+itemv[i]] = min(dp[v+itemv[i]], dp[v] + itemw[i]);
		}
	}
	for (int v = sumv; v >= 0; --v) {
		if (dp[v] != -1 && dp[v] <= maxw) {
			cout << v << '\n';
			return 0;
		}
	}
}
