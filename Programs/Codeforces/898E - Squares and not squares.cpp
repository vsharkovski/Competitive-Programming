
// Problem : E. Squares and not squares
// Contest : Codeforces Round #451 (Div. 2)
// URL : https://codeforces.com/contest/898/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int squares = 0, zeroes = 0;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		int rt = sqrt(a);
		if (rt*rt == a) {
			if (a == 0) ++zeroes;
			else ++squares;
		} else {
			v.push_back(min(a - rt*rt, (rt+1)*(rt+1) - a));
		}
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	if (zeroes + squares > n/2) {
		int need = zeroes + squares - n/2;
		if (need <= squares) {
			ans += need;
			squares -= need;
		} else {
			ans += squares;
			squares -= squares;
			need = zeroes - n/2;
			ans += 2*need;
			zeroes -= need;
		}
	} else if (zeroes + squares < n/2) {
		int i = 0;
		while (zeroes + squares < n/2) {
			ans += v[i];
			++i;
			++squares;
		}
	}
	cout << ans << '\n';
}
