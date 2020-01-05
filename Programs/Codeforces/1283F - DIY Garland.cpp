// Problem : F. DIY Garland
// Contest : Codeforces Round #611 (Div. 3)
// URL : https://codeforces.com/contest/1283/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int N = 200010;

int n;
int a[N];
int cnt[N];
vector<pii> edges;

int tree[1<<19];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		if (cnt[tl] > 0) {
			tree[v] = N;
		} else {
			tree[v] = tl;
		}
	} else {
		int tm = (tl + tr) / 2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
		tree[v] = min(tree[2*v], tree[2*v+1]);
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		tree[v] = val;
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(2*v, tl, tm, pos, val);
		} else {
			update(2*v+1, tm+1, tr, pos, val);
		}
		tree[v] = min(tree[2*v], tree[2*v+1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	build(1, 1, n);
	for (int i = n-1; i >= 1; --i) {
		int u = a[i];
		int v = tree[1];
		if (v == N) {
			cout << "-1\n";
			return 0;
		}
		edges.emplace_back(u, v);
		update(1, 1, n, v, N);
		--cnt[u];
		if (cnt[u] == 0) {
			update(1, 1, n, u, u);
		}
	}
	cout << a[1] << endl;
	for (pii& e : edges) {
		cout << e.first << ' ' << e.second << '\n';
	}
}
