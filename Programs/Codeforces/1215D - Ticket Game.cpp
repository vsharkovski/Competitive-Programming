#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int t = 0, a = 0, b = 0;
	for (int i = 1; i <= n; ++i) {
		char d;
		cin >> d;
		if (i <= n/2) {
			if (d == '?') {
				++a;
			} else {
				t -= d-'0';
			}
		} else {
			if (d == '?') {
				++b;
			} else {
				t += d-'0';
			}
		}
	}
	if (t >= 0) t = -t, swap(a, b);
	if (a > b) {
		cout << "Monocarp\n";
	} else if (a == b) {
		if (t == 0) {
			cout << "Bicarp\n";
		} else {
			cout << "Monocarp\n";
		}
	} else {
		b -= a;
		t = -t;
		if (!(1*b <= t && t <= 9*b)) {
			cout << "Monocarp\n";
		} else {
			if ((b+1)/2*0 + b/2*9 < t || (b+1)/2*9 + b/2*0 > t) {
				cout << "Monocarp\n";
			} else {
				cout << "Bicarp\n";
			}
		}
	}
}
