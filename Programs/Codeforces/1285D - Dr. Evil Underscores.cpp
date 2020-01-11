// Problem : D. Dr. Evil Underscores
// Contest : Codeforces Round #613 (Div. 2)
// URL : https://codeforces.com/contest/1285/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int dfs(vector<int>& a, int bit) {
	if (a.empty() || bit < 0) return 0;
	vector<int> on, off;
	for (int x : a) {
		if (x & (1 << bit)) {
			on.push_back(x);
		} else {
			off.push_back(x);
		}
	}
	if (on.empty()) return dfs(off, bit-1);
	if (off.empty()) return dfs(on, bit-1);
    // no matter whether we choose 0 or 1, the answer will contain 2^bit.
    // put 0 => the "on" set is relevant, since it will contain 2^bit
    // put 1 => the "off" set is relevant, since it will contain 2^bit
    // if a set is relevant I mean that the max element will be in there
	return (1<<bit) + min(dfs(on, bit-1), dfs(off, bit-1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << dfs(a, 29) << endl;
}
