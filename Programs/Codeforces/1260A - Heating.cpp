#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll c, sum;
		cin >> c >> sum;
		ll ans;
		if (c >= sum) {
			ans = sum;
		} else {
			ans = (sum/c)*(sum/c)*(c-(sum%c)) + (sum/c+1)*(sum/c+1)*(sum%c);
		}
		cout << ans << endl;
	}
}
