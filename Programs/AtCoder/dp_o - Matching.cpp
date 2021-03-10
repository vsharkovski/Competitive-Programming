#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline void add_self(int& x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> cur(1<<n), nxt(1<<n);
	cur[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int can;
			cin >> can;
			if (can == 0) continue;
			for (int mask = 0; mask < (1<<n); ++mask) {
				if (mask & (1<<j)) continue;
				add_self(nxt[mask | (1<<j)], cur[mask]);
			}
		}
		swap(cur, nxt);
		nxt.assign(1<<n, 0);
	}
	cout << cur[(1<<n) - 1] << '\n';
}
