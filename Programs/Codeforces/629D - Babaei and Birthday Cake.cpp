
// Problem : D. Babaei and Birthday Cake
// Contest : Codeforces Round #343 (Div. 2)
// URL : https://codeforces.com/contest/629/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;

int n;
ll v[N], vs[N];
int vc[N];

ll tree[4*N];

void update(int v, int tl, int tr, int pos, ll val) {
	if (tl == tr) {
		tree[v] = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm) {
		update(2*v, tl, tm, pos, val);
	} else {
		update(2*v+1, tm+1, tr, pos, val);
	}
	tree[v] = max(tree[2*v], tree[2*v+1]);
}

ll query(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l <= tl && tr <= r) return tree[v];
	int tm = (tl + tr) / 2;
	return	max(query(2*v, tl, tm, l, min(r, tm)),
				query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	v[0] = 0;
	for (int i = 1; i <= n; ++i) {
		ll r, h;
		cin >> r >> h;
		v[i] = r*r*h;
		vs[i] = v[i];
	}
	sort(vs, vs+n+1);
	for (int i = 0; i <= n; ++i) {
		vc[i] = distance(vs, lower_bound(vs, vs+n+1, v[i]));
	}
	memset(tree, 0, sizeof(tree));
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll dp_here = v[i] + query(1, 0, n+1, 0, vc[i]-1);
		ans = max(ans, dp_here);
		update(1, 0, n+1, vc[i], dp_here);
	}
	const double pi = acos(-1);
	double ans_real = (double)ans * pi;
	//cout << setprecision(10) << fixed << pi << '\n';
	cout << setprecision(10) << fixed << ans_real << '\n';
}
