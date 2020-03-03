
// Problem : Problem 3. Talent Show
// Contest : USACO 2018 US Open Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=839
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 256;
const int W = 1024;

int n, minw;
int w[N], t[N];
pii dp[N][W];

pii better(pii a, pii b) {
	if (a.first == 0 && a.second == 0) return b;
	if (b.first == 0 && b.second == 0) return a;
	double ra = double(a.first)/double(a.second);
	double rb = double(b.first)/double(b.second);
	if (ra >= rb) return a;
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
	#endif
	cin >> n >> minw;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> t[i];
	}
	for (int i = 0; i < n; ++i) {
		{
			int w1 = min(minw, w[i]);
			dp[i+1][w1] = better(dp[i+1][w1], make_pair(t[i], w[i]));
		}
		for (int sw = 0; sw <= minw; ++sw) {
			if (dp[i][sw].first == 0 && dp[i][sw].second == 0) continue;
			dp[i+1][sw] = better(dp[i+1][sw], dp[i][sw]);
			int sw1 = min(minw, sw + w[i]);
			int t1 = dp[i][sw].first + t[i];
			int w1 = dp[i][sw].second + w[i];
			dp[i+1][sw1] = better(dp[i+1][sw1], make_pair(t1, w1));
		}
	}
	int ft = dp[n][minw].first;
	int fw = dp[n][minw].second;
	if (fw == 0) {cout << "fw=0\n"; return 0;}
	double a = double(ft) / double(fw);
	cout << floor(a*1000.0) << '\n';
}
