#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;
		if (a < b) {
			int n = (b-a)/5;
			a += n*5;
			ans += n;
			if (a+1 == b || a+2 == b) {
				ans += 1;
			} else if (a+3 == b || a+4 == b) {
				ans += 2;
			}
		} else {
			int n = (a-b)/5;
			a -= n*5;
			ans += n;
			if (a-1 == b || a-2 == b) {
				ans += 1;
			} else if (a-3 == b || a-4 == b) {
				ans += 2;
			}
		}
		cout << ans << endl;
	}
}
