// Problem : C. Yet Another Walking Robot
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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
		vector<map<int, int>> data(2*n+10);
		int l = -1, r = 1e9;
		int h = 0, v = 0;
		data[h+n][v] = 1;
		for (int i = 1; i <= n; ++i) {
			char ch;
			cin >> ch;
			if (ch == 'L') --h;
			if (ch == 'R') ++h;
			if (ch == 'U') --v;
			if (ch == 'D') ++v;
			int& j = data[h+n][v];
			if (j != 0) {
				if (l == -1 || r-l+1 > i-j+1) {
					l = j, r = i;
				}
			}
			j = i+1;
		}
		if (l == -1) {
			cout << -1 << '\n';
		} else {
			cout << l << ' ' << r << '\n';
		}
	}
}
