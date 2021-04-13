#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


const int inf = 1e9;
const int maxn = 500005;
const int maxq = 500005;

struct Node {
	int sum, msuf;
	Node(int s, int m) : sum(s), msuf(m) {}
	Node() : sum(0), msuf(0) {}
};

int n, q;
int a[maxn];
Node tree[4*maxn];

int answer[maxq];
int ql[maxq], qr[maxq];
vector<int> queries[maxn]; // query[i] = ids of queries such that L=i

void merge(Node& v, Node& l, Node& r) {
	v.sum = l.sum + r.sum;
	v.msuf = min(l.msuf + r.sum, r.msuf);
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		tree[v].sum = a[tl];
		tree[v].msuf = min(0, a[tl]);
		return;
	}
	int tm = (tl + tr) / 2;
	build(2*v, tl, tm);
	build(2*v+1, tm+1, tr);
	merge(tree[v], tree[2*v], tree[2*v+1]);
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		tree[v].sum = val;
		tree[v].msuf = min(0, val);
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm) {
		update(2*v, tl, tm, pos, val);
	} else {
		update(2*v+1, tm+1, tr, pos, val);
	}
	merge(tree[v], tree[2*v], tree[2*v+1]);
}

Node query(int v, int tl, int tr, int l, int r) {
	if (l > r) return Node(0, inf);
	if (l <= tl && tr <= r) return tree[v];
	int tm = (tl + tr) / 2;
	Node res1 = query(2*v, tl, tm, l, min(r, tm));
	Node res2 = query(2*v+1, tm+1, tr, max(l, tm+1), r);
	res1.msuf += res2.sum;
	return Node(res1.sum + res2.sum, min(res1.msuf, res2.msuf));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		a[i] = (ch == 'C') ? 1 : -1;
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> ql[i] >> qr[i];
		queries[ql[i]].push_back(i);
	}
	build(1, 1, n);
	vector<int> stk; // which positions should be removed (decreasing order)
	for (int L = n; L >= 1; --L) {
		if (a[L] == 1 && !stk.empty()) {
			int i = stk.back();
			stk.pop_back();
			update(1, 1, n, i, a[i]); // original value
		} else if (a[L] == -1) {
			stk.push_back(L);
			update(1, 1, n, L, 0); // set it to 0
		}
		for (int i : queries[L]) {
			int R = qr[i];
			auto it = upper_bound(stk.rbegin(), stk.rend()	, R);
			answer[i] = 0;
			answer[i] += distance(stk.rbegin(), it); // which votes will be removed by pass from L to R
			answer[i] += -query(1, 1, n, L, R).msuf; // which will be removed from R to L (assuming the previous pass was done)
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << answer[i] << '\n';
	}
}
