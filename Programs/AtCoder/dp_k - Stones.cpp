#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<bool> dp(k+1);
	for (int i = 0; i <= k; ++i) {
		dp[i] = false;
		for (int x : a) {
			if (i-x < 0 || dp[i]) break;
			dp[i] = !dp[i-x];
			if (dp[i]) break;
		}
	}
	cout << (dp[k] ? "First" : "Second") << '\n';
}
