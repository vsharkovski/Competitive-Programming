#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	int L = n-1;
	for (int R = n-1; R >= 0; --R) {
		int want = m/n + (R+1 <= (m%n));
		L = min(L, R-1);
		while (a[R] < want) {
			while (L >= 0 && a[L] == 0) --L;
			if (L < 0) break;
			int giving = max(0, min(want - a[R], a[L]));
			a[L] -= giving;
			a[R] += giving;
			if (giving > 0) {
				ans = max(ans, R-L);
			}
		}
	}
	cout << ans << endl;
}
