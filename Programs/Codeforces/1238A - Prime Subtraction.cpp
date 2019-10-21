#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		x -= y;
		if (x == 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}
