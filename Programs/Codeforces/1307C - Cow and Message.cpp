
// Problem : C. Cow and Message
// Contest : Codeforces Round #621 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1307/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	ll cnt[26] = {};
	ll cnt2[26][26] = {};
	for (int i = 0; i < n; ++i) {
		int x = s[i] - 'a';
		for (int y = 0; y < 26; ++y) {
			cnt2[y][x] += cnt[y];
		}
		++cnt[x];
	}
	ll ans = 0;
	for (int x = 0; x < 26; ++x) {
		ans = max(ans, cnt[x]);
		for (int y = 0; y < 26; ++y) {
			ans = max(ans, cnt2[x][y]);
		}
	}
	cout << ans << '\n';
}
