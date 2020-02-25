
// Problem : Problem 1. Swapity Swapity Swap
// Contest : USACO 2020 February Contest, Silver
// URL : http://usaco.org/current/index.php?page=viewproblem&cpid=1002
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;
const int M = 105;
const int logK = 31;

int n, m, k;
pii range[M];
int arr[N];
int P[N][logK];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		range[i] = make_pair(l-1, r);
	}
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		reverse(arr+range[i].first, arr+range[i].second);
	}
	for (int i = 0; i < n; ++i) {
		P[i][0] = arr[i];
	}
	for (int j = 1; j < logK; ++j) {
		for (int i = 0; i < n; ++i) {
			P[i][j] = P[P[i][j-1]][j-1];
		}
	}
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
	}
	for (int j = logK-1; j >= 0; --j) {
		if (k - (1<<j) >= 0) {
			for (int i = 0; i < n; ++i) {
				arr[i] = P[arr[i]][j];
			}
			k -= (1<<j);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << arr[i]+1 << '\n';
	}
}
