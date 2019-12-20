#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if ((2*a-b)%3 != 0) {
			cout << "NO\n";
		} else {
			ll y = (2*a-b)/3;
			ll x = y+b-a;
			if (x >= 0 && y >= 0) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}
