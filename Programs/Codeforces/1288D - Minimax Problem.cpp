// Problem : D. Minimax Problem
// Contest : Educational Codeforces Round 80 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1288/problem/D
// Memory Limit : 512.000000 MB 
// Time Limit : 5000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 300010;
const int M = 8;
int ALL;

int n, m;
int a[N][M];

pii possible(int limit) {
	int had[1 << M];
	memset(had, -1, sizeof(had));
	for (int i = 0; i < n; ++i) {
		int msk = 0;
		for (int b = 0; b < m; ++b) {
			if (a[i][b] >= limit) {
				msk |= (1 << b);
			}
		}
		had[0] = i;
		int j = had[ALL ^ msk];
		if (j != -1) {
			return pii(i, j);
		}
		//cout << "msk=" << bitset<M>(msk) << endl; 
		for (int s = msk; s > 0; s = (s-1) & msk) {
			had[s] = i;
			//cout << "  s="<<bitset<M>(s)<<endl;
		}
	}
	return pii(-1, -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	ALL = (1 << m) - 1;
	int lo = 0, hi = 1e9, mid, ans = lo;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (possible(mid).first != -1) {
			lo = mid+1;
			ans = mid;
		} else {
			hi = mid-1;
		}
	}
	pii res = possible(ans);
	cout << res.first+1 << ' ' << res.second+1 << endl;
}
