#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	for (int m = 0; m < (1<<4); ++m) {
		int s1 = 0, s2 = 0;
		for (int i = 0; i < 4; ++i) {
			if (m & (1 << i)) {
				s1 += a[i];
			} else {
				s2 += a[i];
			}
		}
		if (s1 == s2) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}
