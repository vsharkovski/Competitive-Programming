// Problem : D. Domino for Young
// Contest : Codeforces Round #609 (Div. 2)
// URL : https://codeforces.com/contest/1269/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll cnt[2] = {};
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j < n && a[j] == a[i]) {
			++j;
		}
		ll x = a[i];
		ll len = j-i;
		int m = i % 2;
		cnt[m] += x * len / 2;
		cnt[1-m] += x * len / 2;
		if (x % 2 == 1 && len % 2 == 1) {
			cnt[m] += 1;
		}
		i = j-1;
	}
	cout << min(cnt[0], cnt[1]) << endl;
}
