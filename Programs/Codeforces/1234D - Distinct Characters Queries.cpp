#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int A = 26;
const int N = 100010;

int n, q;
int arr[N];
set<int> pos[A];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s >> q;
	n = s.length();
	for (int i = 1; i <= n; ++i) {
		int c = s[i-1] - 'a';
		arr[i] = c;
		pos[c].insert(i);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i, c;
			char ch;
			cin >> i >> ch;
			c = ch - 'a';
			pos[arr[i]].erase(i);
			pos[c].insert(i);
			arr[i] = c;
		} else {
			int l, r;
			cin >> l >> r;
			int ans = 0;
			for (int c = 0; c < A; ++c) {
				if (pos[c].empty()) continue;
				auto it = pos[c].lower_bound(l);
				if (it != pos[c].end() && *it <= r) {
					++ans;
				}
			}
			cout << ans << endl;
		}
	}
}
