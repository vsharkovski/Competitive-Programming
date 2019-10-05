#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int l, r;
	cin >> l >> r;
	for (int x = l; x <= r; ++x) {
		int y = x;
		bool had[10] = {};
		bool ok = true;
		while (y) {
			if (had[y % 10]) {
				ok = false;
				break;
			}
			had[y % 10] = true;
			y /= 10;
		}
		if (ok) {
			cout << x << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
