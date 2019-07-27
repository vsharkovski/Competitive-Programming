#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
 
 
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int k = min(a[n-2] - 1, n-2);
		if (n < 3) {
			cout << 0 << '\n';
		} else {
			cout << k << '\n';
		}
	}
 
}
