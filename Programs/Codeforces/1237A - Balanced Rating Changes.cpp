#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<double> a(n), b(n);
	int tot = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i] / 2.0;
		if (abs(int(a[i])) % 2 == 1) {
			++tot;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (abs(int(a[i])) % 2 == 1) {
			++cur;
			if (cur <= tot/2) {
				b[i] -= 0.5;
			} else {
				b[i] += 0.5;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << (int)b[i] << endl;
	}
}
