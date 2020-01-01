// Problem : C. Diverse Matrix
// Contest : Codeforces Global Round 6
// URL : https://codeforces.com/contest/1266/problem/C
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
	int R, C;
	cin >> R >> C;
	if (R == 1 && C == 1) {
		cout << 0 << endl;
		return 0;
	}
	bool butt = R == 1 || C == 1;
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			if (butt) {
				cout << r+c << ' ';
			} else {
				int x = c+1;
				if (r >= 2) x *= C+r;
				cout << x << ' ';
			}
		}
		cout << endl;
	}
	cout << endl;
}
