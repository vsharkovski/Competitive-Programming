// Problem : A. New Year and Naming
// Contest : Hello 2020
// URL : https://codeforces.com/contest/1284/problem/0
// Memory Limit : 1024.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> t[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int y;
		cin >> y;
		--y;
		int i = y % n;
		int j = y % m;
		cout << s[i] << t[j] << endl;
	}
}
