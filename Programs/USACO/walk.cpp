
// Problem : Problem 2. I Would Walk 500 Miles
// Contest : USACO 2019 US Open Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=946
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int P1 = 2019201913;
const int P2 = 2019201949;
const int P3 = 2019201997;

const int N = 7505;

inline int add(ll x, int y) {
	x += y;
	if (x >= P3) x -= P3;
	return x;
}

inline int mult(int x, int y) {
	return (ll)x * y % P3;
}

int n, k;
int res[N];
int order[N];
int group[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	#endif
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		group[i] = 0;
		res[i] = P3;
		order[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			int val = add(mult(P1, i), mult(P2, j));
			res[i] = min(res[i], val);
			res[j] = min(res[j], val);
		}
	}
	int rem = n;
	sort(order+1, order+1+n, [&] (int i, int j) {
		return res[i] < res[j];
	});
	for (int p = 1; p <= n; ++p) {
		int i = order[p];
		if (rem == k-1) break;
		if (group[i] != 0) continue;
		group[i] = 1;
		--rem;
	}
	int gid = 2;
	for (int i = 1; i <= n; ++i) {
		if (group[i] == 0) {
			group[i] = gid;
			++gid;
		}
	}
	int ans = P3;
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			if (group[i] != group[j]) {
				ans = min(ans, add(mult(P1, i), mult(P2, j)));
			}
		}
	}
	cout << ans << '\n';
}
