#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int m = 8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> cur(m), nxt(m);
	cur[0] = 1;
	for (int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		int a = ch - '0';
		nxt.assign(m, 0);
		for (int j = 0; j < m; ++j) {
			nxt[j] = (nxt[j] + cur[j]) % mod;
			nxt[(10*j + a)%m] = (nxt[(10*j + a)%m] + cur[j]) % mod;
		}
		swap(cur, nxt);
	}
	cout << cur[0]-1 << endl;
}
