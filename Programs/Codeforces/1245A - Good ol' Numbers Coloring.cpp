#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin>> a >> b;
		int g = gcd(a, b);
		if (g == 1) {
			cout << "Finite\n";
		}else {
			cout << "Infinite\n";
		}
	}
}
