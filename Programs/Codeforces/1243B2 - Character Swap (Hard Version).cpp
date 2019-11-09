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
		int cnt[26] = {};
		for (int i = 0; i < n; ++i) {
			++cnt[s[i]-'a'];
			++cnt[t[i]-'a'];
		}
		bool good = true;
		for (int i = 0; i < 26; ++i) {
			good &= !(cnt[i] % 2);
		}
		if (!good) {
			cout << "No\n";
			continue;
		}
		vector<pii> swaps;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				int j = -1;
				for (int jj = i+1; jj < n; ++jj) {
					if (s[jj] == s[i]) {
						j = jj;
						break;
					}
				}
				if (j != -1) {
					swaps.emplace_back(j, i);
					swap(s[j], t[i]);
				} else {
					for (int jj = i+1; jj < n; ++jj) {
						if (t[jj] == s[i]) {
							j = jj;
							break;
						}
					}
					swaps.emplace_back(i+1, j);
					swaps.emplace_back(i+1, i);
					swap(s[i+1], t[j]);
					swap(s[i+1], t[i]);
				}
			}
		}
		cout << "Yes\n" << swaps.size() << '\n';
		for (auto& p : swaps) {
			cout << p.first+1 << ' ' << p.second+1 << '\n';
		}
	}
}
