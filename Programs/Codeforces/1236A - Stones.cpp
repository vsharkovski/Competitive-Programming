#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int x = min(b, c/2);
		int ans = 3*x;
		b -= x;
		x = min(a, b/2);
		ans += 3*x;
		cout << ans << endl;
	}
}
