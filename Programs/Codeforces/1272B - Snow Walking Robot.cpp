// Problem : B. Snow Walking Robot
// Contest : Codeforces Round #605 (Div. 3)
// URL : https://codeforces.com/contest/1272/problem/B
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
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		int nl = 0, nr = 0, nu = 0, nd = 0;
		for (char& ch : s) {
			if (ch == 'L') ++nl;
			else if (ch == 'R') ++nr;
			else if (ch == 'U') ++nu;
			else if (ch == 'D') ++nd;
		}
		int x = min(nl, nr), y = min(nu, nd);
		if (x == 0 && y == 0) {
			cout << 0 << endl;	
		} else if (x == 0 && y > 0) {
			cout << "2\nUD\n";
		} else if (x > 0 && y == 0) {
			cout << "2\nLR\n";
		} else {
			cout << x + y + x + y << endl;
			for (int i = 0; i < x; ++i) cout << 'R';
			for (int i = 0; i < y; ++i) cout << 'D';
			for (int i = 0; i < x; ++i) cout << 'L';
			for (int i = 0; i < y; ++i) cout << 'U';
			cout << endl;
		}
	}
}
