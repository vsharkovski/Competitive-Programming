#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 40010;
const int M = (1<<17) + 10;

int n, d;
int milk[N];

struct Node {
	ll a00, a01, a10, a11;
	inline void pull(Node &l, Node &r) {
		a00 = max(l.a01 + r.a00, l.a00 + r.a10);
		a01 = max(l.a01 + r.a01, l.a00 + r.a11);
		a10 = max(l.a11 + r.a00, l.a10 + r.a10);
		a11 = max(l.a11 + r.a01, l.a10 + r.a11);
	}
} tree[M];

void build(int v = 1, int tl = 0, int tr = n-1) {
	if (tl == tr) {
		tree[v].a11 = milk[tl];
		tree[v].a00 = tree[v].a01 = tree[v].a10 = 0;
		return;
	}
	int tm = (tl + tr) / 2;
	build(2*v, tl, tm);
	build(2*v+1, tm+1, tr);
	tree[v].pull(tree[2*v], tree[2*v+1]);
}

void update(int pos, int val, int v = 1, int tl = 0, int tr = n-1) {
	if (tl == tr) {
		tree[v].a11 = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm) {
		update(pos, val, 2*v, tl, tm);
	} else {
		update(pos, val, 2*v+1, tm+1, tr);
	}
	tree[v].pull(tree[2*v], tree[2*v+1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifndef _DEBUG
	freopen("optmilk.in", "r", stdin);
	freopen("optmilk.out", "w", stdout);
	#endif // _DEBUG
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		cin >> milk[i];
	}
	build();
	ll ans = 0;
	for (int i = 0; i < d; ++i) {
		int pos, val;
		cin >> pos >> val;
		--pos;
		update(pos, val);
		ans += tree[1].a11;
	}
	cout << ans << '\n';
}
