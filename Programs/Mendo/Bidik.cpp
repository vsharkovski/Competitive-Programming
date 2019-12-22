#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
I think my solution is O(N * log^2 N)
I think it can be done in O(N * log N)
By using segment trees instead of fenwick trees + binary search.
But I didn't want to code that.
*/

const int A = 26;

ll ans;

int n;
vector<int> pos[A];
int Rok[A];

struct fenwick {
	int sz;
	vector<int> tree;
	void build(int x) {
		sz = pos[x].size() + 10;
		tree.assign(sz, 0);
	}
	void update(int p, int x) {
		while (p < sz) {
			tree[p] += x;
			p += p & -p;
		}
	}
	int query(int p) {
		int res = 0;
		while (p >= 1) {
			res += tree[p];
			p -= p & -p;
		}
		return res;
	}
} trees[A];

inline int getat(int p) {
	for (int x = 0; x < A; ++x) {
		int lo = 1, hi = pos[x].size()-1, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			int realpos = pos[x][mid];
			realpos += trees[x].query(mid);
			if (realpos == p) {
				return x;
			} else if (realpos < p) {
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}
	}
	return -1;
}

inline void update_specific(int x, int i, int newval) {
	int val = trees[x].query(i);
	int diff = newval - val;
	trees[x].update(i, diff);
	trees[x].update(i+1, -diff);
}

void update_ranges(int L, int R, int val) {
	for (int x = 0; x < A; ++x) {
		int minidx = -1, maxidx = -1;
		int lo = 1, hi = pos[x].size()-1, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			int realpos = pos[x][mid] + trees[x].query(mid);
			if (realpos < L) {
				lo = mid+1;
			} else if (realpos <= R) {
				minidx = mid;
				hi = mid-1;
			} else {
				hi = mid-1;
			}
		}
		if (minidx == -1) continue;
		lo = 1, hi = pos[x].size()-1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			int realpos = pos[x][mid] + trees[x].query(mid);
			if (realpos < L) {
				lo = mid+1;
			} else if (realpos <= R) {
				maxidx = mid;
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}
		if (maxidx == -1) continue;
		trees[x].update(minidx, val);
		trees[x].update(maxidx+1, -val);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < A; ++i) {
		pos[i].push_back(-1);
	}
	for (int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		int x = ch - 'a';
		pos[x].push_back(i);
	}
	int cntscnts[2] = {};
	for (int i = 0; i < A; ++i) {
		++cntscnts[(pos[i].size()-1) % 2];
		Rok[i] = pos[i].size()-1;
		trees[i].build(i);
	}
	if (cntscnts[1] > 1) {
		cout << "GRESHKA\n";
		return 0;
	}
	ans = 0;
	int centerpos = -1;
	int L = 1, R = n;
	while (L < R) {
		//cout << "L=" << L << " R=" << R << " ";
		int x = getat(L);
		int j = pos[x][Rok[x]] + trees[x].query(Rok[x]);
		//cout << " x=" << char(x+'a') << " j=" << j << endl;
		if (j == R) {
			//cout << "already done\n";
			--Rok[x];
			++L, --R;
		} else if (j == L) {
			centerpos = L;
			++L;
		} else {
			ans += R - j;
			update_specific(x, Rok[x], R);
			update_ranges(j+1, R, -1);
			--Rok[x];
			++L, --R;
		}
	}
	if (centerpos != -1) {
		ans += n/2 + 1 - centerpos;
	}
	//cout << "centerpos=" << centerpos << endl;
	cout << ans << endl;
}
