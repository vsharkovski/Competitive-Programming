#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		int n;
		cin >> n;
		int cnt[2] = {};
		vector<int> lens(n);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			lens[i] = s.length();
			for (int j = 0; j < lens[i]; ++j) {
				++cnt[(int)(s[j]-'0')];
			}
		}
		sort(lens.begin(), lens.end());
		int ans = 0;
		for (int l : lens) {
			if (l % 2 == 1) {
				if (cnt[0] % 2 == 1) {
					--cnt[0];
					--l;
				} else if (cnt[1] % 2 == 1) {
					--cnt[1];
					--l;
				} else if (cnt[0] > 0) {
					--cnt[0];
					--l;
				} else if (cnt[1] > 0) {
					--cnt[1];
					--l;
				} else {
					break;
				}
			}
			// l is even
			for (int k = 0; k < 2; ++k) {
				if (cnt[0] >= l) {
					cnt[0] -= l;
					l = 0;
				} else if (cnt[1] >= l) {
					cnt[1] -= l;
					l = 0;
				} else {
					for (int j = 0; j < 2; ++j) {
						if (l == 0) break;
						if (cnt[j] >= l) {
							cnt[j] -= l;
							l = 0;
						}
						if (l == 0) break;
						if (cnt[0] % 2 == 1) {
							l -= cnt[0] - 1;
							cnt[0] = 1;
						} else {
							l -= cnt[0];
							cnt[0] = 0;
						}	
					}
				}
			}
			if (l == 0) {
				++ans;
			} else {
				break;
			}
		}
		cout << ans << endl;
	}
}
