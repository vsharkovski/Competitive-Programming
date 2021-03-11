
// Problem : D. Alarm Clock
// Contest : Codeforces Round #451 (Div. 2)
// URL : https://codeforces.com/contest/898/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<bool> removed(n, false);
	int ans = 0;
	int j = 0, active = 0;
	for (int i = 0; i < n; ++i) {
		if (removed[i]) continue;
		if (j < i) {
			j = i;
			active = 0;
		}
		while (!removed[i] && j < n && a[j]-a[i] < m) {
			++active;
			if (active == k) {
				--active;
				++ans;
				removed[j] = true;
			}
			++j;
		}
		if (!removed[i]) {
			--active;
		}
	}
	cout << ans << '\n';
}
