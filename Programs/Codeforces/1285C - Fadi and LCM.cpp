// Problem : C. Fadi and LCM
// Contest : Codeforces Round #613 (Div. 2)
// URL : https://codeforces.com/contest/1285/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll X;
	cin >> X;
	vector<ll> divs;
	int m;
	for (ll y = 2; y*y <= X; ++y) {
		ll ypwr = 1;
		while (X % y == 0) {
			X /= y;
			ypwr *= y;
		}
		if (ypwr > 1) {
			divs.emplace_back(ypwr);
		}
	}
	if (X > 1) {
		divs.emplace_back(X);
	}
	m = divs.size();
	ll A = 1, B = 1e18;
	for (int msk = 0; msk < (1 << m); ++msk) {
		ll a = 1, b = 1;
		for (int i = 0; i < m; ++i) {
			if (msk & (1 << i)) {
				a *= divs[i];
			} else {
				b *= divs[i];
			}
		}
		if (max(a, b) < max(A, B)) {
			A = a;
			B = b;
		}
	}
	cout << A << ' ' << B << endl;
}
