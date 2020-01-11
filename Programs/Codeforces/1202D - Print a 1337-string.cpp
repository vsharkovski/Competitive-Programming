// Problem : D. Print a 1337-string...
// Contest : Educational Codeforces Round 70 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1202/problem/D
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
	const int M = 1e5;
	int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		bool found = false;
		for (ll a = 1; a*a <= n; ++a) {
			if (n % a == 0) {
				ll b = n/a;
				if (a+b+2 < M) {
					found = true;
					for (int i = 0; i < a; ++i) cout << '1';
					cout << "33";
					for (int i = 0; i < b; ++i) cout << '7';
					cout << endl;
					break;
				}
			}
		}
		if (found) continue;
		ll c = 1;
		while (!found) {
			for (ll x = 2; x*x <= n-c; ++x) {
				if ((n-c)%x == 0) {
					ll y = (n-c)/x;
					ll a = x, b = y-6;
					if (b >= 0 && x+y+c-1 < M) {
						found = true;
						for (int i = 0; i < a; ++i) cout << '1';
						cout << "33";
						for (int i = 0; i < b; ++i) cout << '7';
						for (int i = 0; i < c; ++i) cout << '1';
						break;
					}
				}
			}
			++c;
		}
		cout << "337";
		cout << endl;
	}
}
