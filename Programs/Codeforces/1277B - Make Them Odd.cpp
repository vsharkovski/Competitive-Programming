// Problem : B. Make Them Odd
// Contest : Codeforces Round #606 (Div. 2, based on Technocup 2020 Elimination Round 4)
// URL : https://codeforces.com/contest/1277/problem/B
// Memory Limit : 256.000000MB 
// Time Limit : 3000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<int> s;
		map<int, int> m;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			s.insert(x);
			m[x] += 1;
		}
		int ans = 0;
		for (auto it = s.rbegin(); it != s.rend(); ++it) {
			int x = *it;
			int cnt = m[x];
			while (x % 2 == 0) {
				x /= 2;
				++ans;
				if (m[x] > 0) {
					break;
				}
			}
		}
		cout << ans << endl;
	}
}
