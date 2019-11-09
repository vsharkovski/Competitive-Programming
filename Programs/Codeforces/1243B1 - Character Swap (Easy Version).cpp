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
		string s, t;
		cin >> s >> t;
		int cnt[26][26] = {};
		int tot = 0;
		for (int i = 0; i < n; ++i) {
			int a = s[i] - 'a';
			int b = t[i] - 'a';
			if (a != b) {
				++tot;
				++cnt[a][b];
			}
		}
		if (tot != 2) {
			cout << "No\n";
			continue;
		}
		bool done = false;
		for (int a = 0; a < 26; ++a) {
			for (int b = 0; b < 26; ++b) {
				if (cnt[a][b] > 0) {
					done = cnt[a][b] == 2;
					a = b = 26;
				}
			}
		}
		if (done) {
			cout << "Yes\n";	
		} else {
			cout << "No\n";
		}
	}
}
