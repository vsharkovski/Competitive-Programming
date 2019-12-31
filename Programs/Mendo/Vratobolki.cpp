#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(2*n + 10);
	vector<int> pos[2];
	for (int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		a[i] = ch == 'L';
		a[i+n] = a[i];
		pos[a[i]].push_back(i);
	}
	if (pos[0].empty() || pos[1].empty()) {
		cout << "0 0\n";
		return 0;
	}
	vector<ll> b(2*n + 10);
	for (int i = 0; i < 2*n; ++i) {
		b[i] = a[i];
		if (i) b[i] += b[i-1];
	}
	vector<ll> pref[2];
	int m = pos[0].size();
	int k = pos[1].size();
	for (int j = 0; j < 2; ++j) {
		int sz = pos[j].size();
		pos[j].resize(2*sz + 10);
		for (int i = 0; i < sz; ++i) {
			pos[j][i+sz] = pos[j][i]+n;
		}
		pref[j].assign(2*sz + 10, 1e9);
		for (int i = 0; i < 2*sz; ++i) {
			pref[j][i] = b[pos[j][i]];
			if (i) pref[j][i] += pref[j][i-1];
		}
	}
	ll ans = 0, Lmodif = 0;
	int med1 = k/2;
	int L = 0, R = n-1;
	int L0 = 0, R0 = m-1;
	int M0 = 0;
	while (M0 < 2*m && pos[0][M0+1] < pos[1][med1]) {
		++M0;
	}
	// without shifting the array
	ans = pref[0][M0] + ll(R0-M0)*k - (pref[0][R0]-pref[0][M0]);
	// start shifting
	while (R < 2*n-1) {
		// [L, R] -> [L+1, R+1]
        // note: a[L] = a[R+1], equivalent to moving
        // the first element to the back
		++L;
		++R;
		if (a[R] == 1) {
			--Lmodif;
			++med1;	
			while (M0 < 2*m && pos[0][M0+1] < pos[1][med1]) {
				++M0;
			}
		} else {
			++L0;
			++R0;
		}
		ll res = 0;
		res += Lmodif*(M0-L0+1) + pref[0][M0] - (L0 ? pref[0][L0-1] : 0);
		res += ll(R0-M0)*(k-Lmodif) - (pref[0][R0]-pref[0][M0]);
		ans = min(ans, res);
	}
	cout << 1 << ' ' << ans << endl;
}
