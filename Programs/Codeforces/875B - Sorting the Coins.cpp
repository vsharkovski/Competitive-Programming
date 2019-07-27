#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
 
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, sufflen = 0;
	cin >> n;
	vector<bool> c(n+1, false);
	cout << 1 << ' ';
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p;
		c[p] = true;
		if (p == n - sufflen) {
			for (int j = p; j >= 1 && c[j]; --j) {
				++sufflen;
			}
		}
		cout << 1 + i - sufflen << ' ';
	}
}
