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
		vector<pair<string, int>> a(n);
		set<string> present;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			a[i].first = to_string(x);
			while (a[i].first.length() < 4) {
				a[i].first = '0' + a[i].first;
			}
			a[i].second = i;
			present.insert(a[i].first);
		}
		sort(a.begin(), a.end());
		vector<string> final(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int j = i;
			while (j < n && a[j].first == a[i].first) {
				++j;
			}
			// [i, j-1] are equal
			ans += j-1 - i + 1 - 1;
			final[a[i].second] = a[i].first;
			for (int k = i+1; k < j; ++k) {
				string s = a[k].first;
				for (int p = 0; p < 4; ++p) {
					char original = s[p];
					for (char ch = '0'; ch <= '9'; ++ch) {
						if (ch == original) continue;
						s[p] = ch;
						if (!present.count(s)) {
							present.insert(s);
							p = 4;
							final[a[k].second] = s;
							break;
						}
					}
					s[i] = original;
				}
			}
			i = j-1;
		}
		cout << ans << endl;
		for (int i = 0; i < n; ++i) {
			cout << final[i] << endl;
		}
	}
}
