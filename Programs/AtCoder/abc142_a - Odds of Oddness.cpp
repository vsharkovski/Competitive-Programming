#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << 0.5 << endl;
	} else {
		cout << double((int)n/2+1)/double(n) << endl;
	}
}
