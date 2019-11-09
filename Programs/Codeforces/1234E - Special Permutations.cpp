#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void upd(vector<ll>& d, int l, int r, int x) {
	if (l <= r) {
		d[l] += x;
		d[r+1] -= x;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> diff(n+2, 0);
	int pre = -1, cur, a, b;
	while (m--) {
		cin >> cur;
		a = pre, b = cur;
		pre = cur;
		if (a == -1) continue; // no previous element
		if (a == b) continue;
		if (a > b) swap(a, b);
		upd(diff, 1, a-1, b-a);
		upd(diff, a, a, b-1);
		upd(diff, a+1, b-1, abs(a+1-b));
		upd(diff, b, b, a);
		upd(diff, b+1, n, b-a);
	}
	ll here = 0;
	for (int i = 1; i <= n; ++i) {
		here += diff[i];
		cout << here << ' ';
	}
}
