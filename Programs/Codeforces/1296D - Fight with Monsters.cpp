// Problem : D. Fight with Monsters
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		h[i] %= (a+b);
		if (h[i] == 0) h[i] = a+b;
	}
	sort(h.begin(), h.end());
	/*cout << "h: ";
	for (int x : h )cout << x << ' ';
	cout << '\n';
	cout << "a="<<a<<" b="<<b<<'\n';/*/
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int need = (h[i] + a-1)/a - 1; // ceiling of h[i]/a, -1
		if (k < need) break;
		k -= need;
		++ans;
	}
	cout << ans << '\n';
}
