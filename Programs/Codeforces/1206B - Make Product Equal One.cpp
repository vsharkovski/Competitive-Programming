#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	ll ans = 0;
	int cnt[3] = {};
	for (int i = 0; i < n; ++i) {
		int a;
		cin >>a;
		if (a > 1) {
			ans += a - 1;
			a = 1;
		} else if (a < -1) {
			ans += -1 - a;
			a = -1;
		}
		++cnt[a+1];
	}
	if (cnt[0] % 2 == 1) {
		if (cnt[1] > 0) {
			ans += 1;
			ans += cnt[1]-1;
			cnt[1] = 0;
		} else {
			ans+=2;
		}
	}
	ans +=cnt[1];
	cout << ans << endl;
}
