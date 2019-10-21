#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		int n, r;
		cin >> n >> r;
		set<int> s;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			s.insert(x);
		}
		int ans = 0;
		while (true) {
			if (s.empty()) break;
			while (!s.empty() && *s.begin() - ans*r <= 0) {
				s.erase(s.begin());
			}
			if (s.empty()) break;
			++ans;
			s.erase(prev(s.end()));
		}
		cout << ans << endl;
	}
}
