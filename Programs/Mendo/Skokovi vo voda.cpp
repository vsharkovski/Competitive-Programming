#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, r, k, ans;
	int m_count[100] = {};
	int f_count[100] = {};
	int m_pref[100] = {};
	int f_pref[100] = {};

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		m_count[x] += 1;
	}
	
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		f_count[x] += 1;
	}

	cin >> r >> k;
	ans = 0;

	for (int w = 30; w <= 90; ++w) {
		m_pref[w] = m_pref[w-1] + m_count[w];
		f_pref[w] = f_pref[w-1] + f_count[w];
	}

	for (int w1 = 30; w1 <= 90; ++w1) {
		if (f_count[w1] == 0) {
			// must have at least one female with this weight
			continue;
		}
		for (int w2 = w1; w2 <= 90; ++w2) {
			if (f_count[w2] == 0) {
				// same as above
				continue;
			}
			if (f_pref[w2] - f_pref[w1-1] < k) {
				// must have at least k females
				continue;
			}
			int males = m_pref[min(w1+r, 90)] - m_pref[max(w2-r, 30)-1];
			ans = max(ans, males);
		}
	}

	cout << ans << "\n";

}
