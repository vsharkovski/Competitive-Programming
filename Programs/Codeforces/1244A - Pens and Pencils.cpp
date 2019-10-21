#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		bool found = false;
		for (int k1 = 0; k1 <= k; ++k1) {
			int k2 = k - k1;
			// k1 pen, k2 pencil
			if (c*k1 >= a && d*k2 >= b) {
				cout << k1 << ' ' << k2 << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "-1\n";
		}
	}
}
