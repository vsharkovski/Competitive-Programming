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
		string p, h;
		cin >> p >> h;
		int cnt1[26] = {};
		for (char ch : p) {
			++cnt1[ch - 'a'];
		}
		int n = p.length(), m = h.length();
		bool found = false;
		for (int i = 0; i+n-1 < m; ++i) {
			int cnt2[26] = {};
			for (int k = i; k <= i+n-1; ++k) {
				++cnt2[h[k]-'a'];
			}
			bool good = true;
			for (int j = 0; j < 26; ++j) {
				if (cnt1[j] != cnt2[j]) {
					good = false;
					break;
				}
			}
			if (good) {
				found = true;
				break;
			}
		}
		if (found) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		} 
	}
}
