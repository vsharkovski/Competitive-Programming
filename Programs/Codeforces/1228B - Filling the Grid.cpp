#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	static int status[1001][1001];
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			status[i][j] = 2;
		}
	}
	for (int i = 0; i < h; ++i) {
		int r;
		cin >> r;
		for (int j = 0; j < r; ++j) {
			if (status[i][j] == 0) {
				cout << 0 << endl;
				return 0;
			}
			status[i][j] = 1;
		}
		if (status[i][r] == 1) {
			cout << 0 << endl;
			return 0;
		}
		status[i][r] = 0;
	}
	for (int j = 0; j < w; ++j) {
		int c;
		cin >> c;
		for (int i = 0; i < c; ++i) {
			if (status[i][j] == 0) {
				cout << 0 << endl;
				return 0;
			}
			status[i][j] = 1;
		}
		if (status[c][j] == 1) {
			cout << 0 << endl;
			return 0;
		}
		status[c][j] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (status[i][j] == 2) {
				++cnt;
			}
		}
	}
	const int mod = 1e9 + 7;
	int ans = 1;
	for (int i = 0; i < cnt; ++i) {
		ans = (ans * 2) % mod;
	}
	cout << ans << endl;
}
