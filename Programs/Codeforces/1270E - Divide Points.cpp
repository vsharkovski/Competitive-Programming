
// Problem : E. Divide Points
// Contest : Good Bye 2019
// URL : https://codeforces.com/contest/1270/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	vector<int> cur[2][2];
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		x[i] += 1e6;
		y[i] += 1e6;
	}
	int cnt[2][2] = {};
	while (true) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) {
			++cnt[x[i]%2][y[i]%2];
		}
		bool single = false;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (cnt[i][j] == n) {
					single = true;
					break;
				}
			}
		}
		if (!single) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			x[i] = x[i] / 2;
			y[i] = y[i] / 2;
		}
	}
	if (cnt[0][0] + cnt[1][1] == n) {
		cout << cnt[0][0] << endl;
		for (int i = 0; i < n; ++i) {
			if (x[i] % 2 == 0 && y[i] % 2 == 0) {
				cout << i+1 << ' ';
			}
		}
	}
	else if (cnt[0][1] + cnt[1][0] == n) {
		cout << cnt[0][1] << endl;
		for (int i = 0; i < n; ++i) {
			if (x[i] % 2 == 0 && y[i] % 2 == 1) {
				cout << i+1 << ' ';
			}
		}
	}
	else {
		cout << cnt[0][0] + cnt[1][1] << endl;
		for (int i = 0; i < n; ++i) {
			if ((x[i] % 2 == 0 && y[i] % 2 == 0) ||
			    (x[i] % 2 == 1 && y[i] % 2 == 1)) {
				cout << i+1 << ' ';
			}
		}
	}
}
