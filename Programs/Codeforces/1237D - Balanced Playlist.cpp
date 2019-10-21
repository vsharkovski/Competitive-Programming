#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int maxn = 100010;
const int maxm = 200010;

int n;
int a[maxn];
vector<pii> order;

int m;
vector<int> values;
unordered_map<int, int> newvalmp;
int tree[1<<19];

int idx1[maxn];
int idx2[maxn];
int ans[maxn];

void build(int v, int tl, int tr) {
	tree[v] = inf;
	if (tl < tr) {
		int tm = (tl + tr) / 2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	tree[v] = min(tree[v], val);
	if (tl < tr) {
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(2*v, tl, tm, pos, val);
		} else {
			update(2*v+1, tm+1, tr, pos, val);
		}
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) return inf;
	if (l <= tl && tr <= r) return tree[v];
	int tm = (tl + tr) / 2;
	return min(query(2*v, tl, tm, l, min(r, tm)),
			   query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int mx = -1, mn = inf;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		order.emplace_back(a[i], i);
		values.push_back(a[i]);
		values.push_back(a[i]/2 - (a[i] % 2 == 0));
	}
	if (2*mn >= mx) {
		for (int i = 1; i <= n; ++i) {
			cout << -1 << ' ';
		}
		return 0;
	}
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	m = values.size();
	for (int i = 0; i < m; ++i) {
		newvalmp[values[i]] = i;
	}
	build(1, 0, m-1);
	for (int i = n; i >= 1; --i) {
		int x = newvalmp[a[i]];
		update(1, 0, m-1, x, i+n);
	}
	for (int i = n; i >= 1; --i) {
		int x = newvalmp[a[i]];
		int y = newvalmp[a[i]/2 - (a[i]%2 == 0)];
		idx1[i] = query(1, 0, m-1, x+1, m-1);
		idx2[i] = query(1, 0, m-1, 0, y);
		update(1, 0, m-1, x, i);
	}
	sort(order.rbegin(), order.rend());
	for (auto& p : order) {
		int x = p.first, i = p.second;
		int j = idx1[i], k = idx2[i];
		if (k < j) {
			ans[i] = k - i;
		} else {
			ans[i] = j - i;
			while (j > n) j -= n;
			ans[i] += ans[j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
}
