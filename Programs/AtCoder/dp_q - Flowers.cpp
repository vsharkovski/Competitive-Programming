#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200100;

int n;
int h1[N];
ll tree[1<<19];

ll getmax(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l <= tl && tr <= r) return tree[v];
	int tm = (tl + tr) / 2;
	return max(	getmax(2*v, tl, tm, l, min(r, tm)),
				getmax(2*v+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, ll val) {
	if (tl == tr) {
		tree[v] = max(tree[v], val);
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<int> h2(n);
	for (int i = 0; i < n; ++i) {
		cin >> h1[i];
		h2[i] = h1[i];
	}
	sort(h2.begin(), h2.end());
	h2.erase(unique(h2.begin(), h2.end()), h2.end());
	memset(tree, 0, sizeof(tree));
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		int h = lower_bound(h2.begin(), h2.end(), h1[i]) - h2.begin();
		ll res = a + getmax(1, 0, n-1, 0, h-1);
		update(1, 0, n-1, h, res);
		ans = max(ans, res);
	}
	cout << ans << '\n';
}
