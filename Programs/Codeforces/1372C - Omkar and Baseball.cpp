
// Problem : C. Omkar and Baseball
// Contest : Codeforces - Codeforces Round #655 (Div. 2)
// URL : https://codeforces.com/contest/1372/problem/C
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
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			--a[i];
		}
		int l = 0;
		
		while (l < n && a[l] == l) {
			++l;
		}
		
		int r = n-1;
		
		while (r >= 0 && a[r] == r) {
			--r;
		}
		
		if (l > r) {
			cout << 0 << '\n';
			continue;
		}
		int cnt = 0;
		for (int i = l; i <= r; ++i) {
			if (a[i] == i) {
				++cnt;
			}
		}
		if (cnt == r-l+1) {
			cout << 0 << '\n';
		} else if (cnt == 0) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}
