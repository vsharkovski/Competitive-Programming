#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n+1), b(n+1), pos1(n+1), pos2(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos1[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		pos2[b[i]] = i;
	}
	int ans = 0;
	int mx = -1;
	for (int p1 = 1; p1 <= n; ++p1) {
		int i = a[p1];
		if (mx > pos2[i]) {
			++ans;
		}
		mx = max(mx, pos2[i]);
	}
	cout << ans << endl;
}
