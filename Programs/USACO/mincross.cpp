
// Problem : Problem 1. Why Did the Cow Cross the Road
// Contest : USACO 2017 February Contest, Platinum
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=720
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;

int n;
int a[N], b[N];
int order[N], arr[N];

int tree[N];
void upd(int pos, int val) {
	while (pos <= n) {
		tree[pos] += val;
		pos += pos & -pos;
	}
}
int sum(int pos) {
	int res = 0;
	while (pos >= 1) {
		res += tree[pos];
		pos -= pos & -pos;
	}
	return res;
}
int sum(int l, int r) {
	if (l > r) return 0;
	return sum(r) - sum(l-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("mincross.in", "r", stdin);
	freopen("mincross.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	ll ans = 1e18;
	for (int A = 0; A < 2; ++A) {
		for (int i = 1; i <= n; ++i) {
			swap(a[i], b[i]);
			order[a[i]] = i;
		}
		for (int i = 1; i <= n; ++i) {
			arr[i] = order[b[i]];
		}
		ll res = 0;
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; ++i) {
			upd(i, 1);
		}
		for (int i = 1; i <= n; ++i) {
			res += sum(1, arr[i]-1);
			upd(arr[i], -1);
		}
		ans = res;
		for (int i = n; i >= 1; --i) {
			res += 2*arr[i] - n - 1;
			ans = min(ans, res);
		}
	}
	cout << ans << '\n';
}
