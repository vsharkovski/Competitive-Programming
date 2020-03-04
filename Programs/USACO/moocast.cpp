
// Problem : Problem 1. Moocast
// Contest : USACO 2016 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=669
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;

int n;
int x[N], y[N];

int p[N], rrank[N], numcc;

inline int get(int x) {
	return p[x] == x ? x : (p[x] = get(p[x]));
}

inline bool unite(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return false;
	if (rrank[x] < rrank[y]) swap(x, y);
	if (rrank[x] == rrank[y]) ++rrank[x];
	p[y] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	int lo = 0, hi = 2e9, X, ans = hi;
	while (lo <= hi) {
		X = (lo + hi) / 2;
		numcc = n;
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			rrank[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				int d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
				if (d <= X && unite(i, j)) {
					--numcc;
				}
			}
		}
		if (numcc == 1) {
			ans = X;
			hi = X-1;
		} else {
			lo = X+1;
		}
	}
	cout << ans << '\n';
}
