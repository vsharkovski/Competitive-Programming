
// Problem : Problem 2. Farmer John Solves 3SUM
// Contest : USACO 2020 January Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=994
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5005;
const int OFS = 2000010;
const int SZ = 2*OFS;

int n, q;
int a[N];
int cnt[SZ];
int last[SZ]; // last i such that this cnt was updated
ll cnt2[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("threesum.in", "r", stdin);
	freopen("threesum.out", "w", stdout);
	#endif
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			int s = OFS - (a[i] + a[j]);
			if (last[s] == i) {
				cnt2[i][j] += cnt[s];
			}
			s = OFS + a[j];
			if (last[s] == i) {
				++cnt[s];
			} else {
				last[s] = i;
				cnt[s] = 1;
			}
		}
	}
	for (int sz = 2; sz <= n; ++sz) {
		for (int l = 1, r = sz; r <= n; ++l, ++r) {
			cnt2[l][r] += cnt2[l+1][r];
			cnt2[l][r] += cnt2[l][r-1];
			cnt2[l][r] -= cnt2[l+1][r-1];
		}
	}
	for (int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << cnt2[l][r] << '\n';
	}
}
