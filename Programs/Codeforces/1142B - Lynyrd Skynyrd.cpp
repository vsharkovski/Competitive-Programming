#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int K = 18;

int n, m, q;
int p[N];
int pinv[N];
int a[N];
vector<int> apos[N];
int nxt[N][K];
int res[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		pinv[p[i]] = i;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
		a[i] = pinv[a[i]];
		apos[a[i]].push_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		int nxtval = a[i] == n ? 1 : a[i]+1;
		auto ptr = upper_bound(apos[nxtval].begin(), apos[nxtval].end(), i);
		if (ptr == apos[nxtval].end()) {
			nxt[i][0] = -1;
		} else {
			nxt[i][0] = *ptr;
		}
//		cout << "i="<<i<<" a="<<a[i]<<" nxt="<<nxt[i][0]<<"\n";
	}
	for (int k = 1; k < K; ++k) {
		for (int i = 1; i <= m; ++i) {
			nxt[i][k] = -1;
			if (nxt[i][k-1] != -1) {
				nxt[i][k] = nxt[ nxt[i][k-1] ][k-1];
			}
		}
	}
	for (int i = m; i >= 1; --i) {
		int j = i;
		for (int k = 0; k < K; ++k) {
			if (((n-1) & (1 << k)) && j != -1) {
				j = nxt[j][k];
			}
		}
		res[i] = m+1;
		if (j != -1) res[i] = j;
		if (i < m) res[i] = min(res[i], res[i+1]);
//		cout << "i="<<i<<" res="<<res[i]<<"\n";
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (n == 1) {
			cout << 1;
			continue;
		}
		if (n > m) {
			cout << 0;
			continue;
		}
		cout << int(res[l] <= r);
	}
}
