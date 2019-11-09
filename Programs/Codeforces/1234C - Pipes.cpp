#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<vector<int>> t(2, vector<int>(n+1));
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= n; ++j) {
				char ch;
				cin >> ch;
				if (ch == '2') ch = '1';
				if (ch >= '3') ch = '2';
				t[i][j] = ch - '0';
			}
		}
		int r = 0, c = 1, pr = 0, pc = 0;
		while (r >= 0 && r <= 1 && c >= 0 && c <= n) {
			if (t[r][c] == 1) {
				if (pc < c) {
					// go right (straight)
					pr = r;
					pc = c;
					c += 1;
				} else {
					break;
				}
			} else {
				// turn
				if (pc < c) {
					// go down or up
					pr = r;
					pc = c;
					if (r == 0) {
						r = 1;
					} else {
						r = 0;
					}
				} else {
					// go right
					pr = r;
					pc = c;
					c += 1;
				}
			}
		}
		if (r == 1 && c == n+1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
