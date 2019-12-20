#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct DSU {
	int n, numCC;
	vector<int> p, rank;
	DSU(int _n) {
		n = _n;
		numCC = n;
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		rank.assign(n, 0);
	}
	inline int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}
	inline bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y);
		if (rank[x] == rank[y]) ++rank[x];
		p[y] = x;
		--numCC;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int last[26];
	for (int j = 0; j < 26; ++j) {
		last[j] = -1;
	}
	DSU dsu(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		bool had[26] = {};
		for (char& ch : s) {
			had[int(ch - 'a')] = true;
		}
		for (int j = 0; j < 26; ++j) {
			if (had[j]) {
				if (last[j] == -1) {
					last[j] = i;
				} else {
					dsu.unite(last[j], i);
					last[j] = dsu.get(i);
				}
			}
		}
	}
	cout << dsu.numCC << endl;
}
