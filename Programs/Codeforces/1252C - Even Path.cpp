#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> R(n+1), C(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> R[i];
		R[i] = (R[i] % 2) + R[i-1];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> C[i];
		C[i] = (C[i] % 2) + C[i-1];
	}
	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		if (r1 > r2) {
			swap(r1, r2);
		}
		if (c1 > c2) {
			swap(c1, c2);
		}
		int dr = R[r2] - R[r1-1];
		int dc = C[c2] - C[c1-1];
		if (dr == 0) {
			if (dc == 0) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else if (dr == r2-r1+1) {
			if (dc == c2-c1+1) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			cout << "NO\n";
		}
	}
}
