#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		bool had[101] = {};
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			had[a] = true;
		}
		int ans = 0;
		for (int i = 1; i <= 100; ++i) {
			if (had[i]) {
				++ans;
				had[i] = false;
				int pr = i;
				for (int j = i+1; j <= 100; ++j) {
					if (had[j]) {
						if (pr+1 == j) {
							continue;
						} else {
							had[j] = false;
							pr = j;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
}
