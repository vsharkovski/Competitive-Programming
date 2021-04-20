#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
const int M = 1<<18;

int n;
int a[N];
int apos[N];
int b[N];
int tree[M];

int query(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r) return 0;
	if (l <= tl && tr <= r) return tree[v];
	int tm = (tl + tr) / 2;
	return max(query(l, min(r, tm), 2*v, tl, tm), query(max(l, tm+1), r, 2*v+1, tm+1, tr));
}

void update(int pos, int val, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		tree[v] = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm) {
		update(pos, val, 2*v, tl, tm);
	} else {
		update(pos, val, 2*v+1, tm+1, tr);
	}
	tree[v] = max(tree[2*v], tree[2*v+1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(tree, 0, sizeof(tree));
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		apos[a[i]] = i;
		a[i] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		b[i] = apos[b[i]];
		int res = 1 + query(1, b[i]-1);
		ans = max(ans, res);
		update(b[i], res);
	}
	cout << ans << '\n';
}
