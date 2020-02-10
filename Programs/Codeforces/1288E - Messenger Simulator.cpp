// Problem : E. Messenger Simulator
// Contest : Educational Codeforces Round 80 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1288/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 300010;

int n, m;
int last[N];
int ans[N];

struct fenwick {
	int tree[N];
	fenwick() {
		memset(tree, 0, sizeof(tree));
	}
	void update(int pos, int val) {
		while (pos < N) {
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
} treeinit, treecnts;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		last[i] = -1;
		ans[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		int j = last[x];
		if (j == -1) {
			// first time moving
			// need how many numbers bigger than it
			// were moved at least once
			ans[x] = max(ans[x], x + treeinit.sum(x+1, n));
			treeinit.update(x, 1);
		} else {
			// moved before
			// need how many unique numbers were moved
			// after last time it was at position 1
			ans[x] = max(ans[x], 1 + treecnts.sum(j+1, i-1));
			treecnts.update(last[x], -1);
		}
		last[x] = i;
		treecnts.update(i, 1);
	}
	for (int x = 1; x <= n; ++x) {
		int j = last[x];
		if (j == -1) {
			ans[x] = max(ans[x], x + treeinit.sum(x+1, n));
		} else {
			ans[x] = max(ans[x], 1 + treecnts.sum(j+1, m));
		}
		//cout << "x=" << x << " ";
		cout << (j == -1 ? x : 1) << ' ' << ans[x] << '\n';
	}
}
