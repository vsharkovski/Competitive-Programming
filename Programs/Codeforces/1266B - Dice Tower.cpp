// Problem : B. Dice Tower
// Contest : Codeforces Global Round 6
// URL : https://codeforces.com/contest/1266/problem/B
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
	int T;
	cin >> T;
	while (T--) {
		ll x;
		cin >> x;
		if (x >= 15 && 1 <= (x%14) && (x%14) <= 6) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
