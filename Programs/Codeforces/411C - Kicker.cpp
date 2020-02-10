// Problem : C. Kicker
// Contest : Coder-Strike 2014 - Qualification Round
// URL : https://codeforces.com/contest/411/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[2][2], b[2][2];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> a[i][j] >> b[i][j];
		}
	}
	int lost = 0, won = 0;
	for (int i = 0; i < 2; ++i) {
		int def1 = a[0][i];
		int atk1 = b[0][1-i];
		int def2 = a[1][i];
		int atk2 = b[1][1-i];
		int def3 = a[1][1-i];
		int atk3 = b[1][i];
		if (def1 > atk2 && atk1 > def2 && def1 > atk3 && atk1 > def3) {
			++won;
		}
		if ((def2 > atk1 && atk2 > def1) || (def3 > atk1 && atk3 > def1)) {
			++lost;
		}
	}
	if (won > 0) {
		cout << "Team 1\n";
	} else if (lost == 2) {
		cout << "Team 2\n";
	} else {
		cout << "Draw\n";
	}
}
