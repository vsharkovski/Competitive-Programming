// Problem : D. Remove One Element
// Contest : Codeforces Round #605 (Div. 3)
// URL : https://codeforces.com/contest/1272/problem/D
// Memory Limit : 256.000000MB 
// Time Limit : 2000.000000milisec 
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
	vector<int> a(n), len(n), id(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	int numsegs = 0;
	for (int i = 0; i < n; ++i) {
		int j = i+1;
		while (j < n && a[j-1] < a[j]) {
			++j;
		}
		++numsegs;
		int curlen = j-i;
		ans = max(ans, curlen);
		for (int k = i; k < j; ++k) {
			len[k] = curlen;
			id[k] = numsegs;
		}
		i = j-1;
	}
	for (int j = 1; j < n-1; ++j) {
		if (a[j-1] < a[j+1] && id[j-1] != id[j+1]) {
			int res = len[j-1] + len[j+1];
			if (id[j-1] == id[j] || id[j] == id[j+1]) {
				--res;
			}
			ans = max(ans, res);
		}
	}
	cout << ans << endl;
}
