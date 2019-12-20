// Problem : C. Yet Another Broken Keyboard
// Contest : Codeforces Round #605 (Div. 3)
// URL : https://codeforces.com/contest/1272/problem/C
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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool ok[256] = {};
	for (int i = 0; i < k; ++i) {
		char ch;
		cin >> ch;
		ok[ch] = true;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!ok[s[i]]) continue;
		int j = i;
		while (j < n && ok[s[j]]) {
			++j;
		}
		// [i, j-1]
		ll len = j-1 - i + 1;
		ans += len * (len+1) / 2;
		i = j-1;
	}
	cout << ans << endl;
	
}
