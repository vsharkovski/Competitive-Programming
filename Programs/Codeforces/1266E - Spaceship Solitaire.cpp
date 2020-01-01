#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n+1), cnt(n+1), req(n+1);
	vector<set<pii>> awards(n+1);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[i] = 0;
		req[i] = a[i];
		ans += req[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int s, t, u;
		cin >> s >> t >> u;
		auto it = awards[s].lower_bound(pii(t, 0));
		if (it != awards[s].end() && it->first == t) {
			// remove old reward
			int v = it->second;
			ans -= req[v];
			--cnt[v];
			req[v] = max(0, a[v] - cnt[v]);
			ans += req[v];
			awards[s].erase(it);
		}
		if (u != 0) {
			// add new reward
			ans -= req[u];
			++cnt[u];
			req[u] = max(0, a[u] - cnt[u]);
			ans += req[u];
			awards[s].emplace(t, u);
		}
		cout << ans << endl;
	}
}
