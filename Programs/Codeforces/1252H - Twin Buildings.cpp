#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ll ans = 0;
	vector<pll> buildings(n);
	map<ll, vector<pll>> data;
	multiset<pll> active;
	for (int i = 0; i < n; ++i) {
		ll l, w;
		cin >> l >> w;
		l *= 2, w *= 2;
		buildings[i] = {l, w};
		active.emplace(l, i);
		active.emplace(w, i);
		data[l].emplace_back(w, i);
		data[w].emplace_back(l, i);
		ans = max(ans, (l/2) * w);
		ans = max(ans, l * (w/2));
	}
	for (auto& kvp : data) {
		ll a = kvp.first;
		int i1 = -1, i2 = -1;
		ll b1 = -1, b2 = -1;
		for (auto it = active.rbegin(); it != active.rend(); ++it) {
			if (i1 == -1) {
				i1 = it->second;
				b1 = it->first;
			} else if (i2 == -1 && i1 != it->second) {
				i2 = it->second;
				b2 = it->first;
				break;
			}
		}
		if (i1 != -1 && i2 != -1) {
			ans = max(ans, a * min(b1, b2));
		}
		for (pll& p : kvp.second) {
			active.erase(active.find(p));
		}
	}
	cout << ans/4;
	if (ans % 4 != 0) cout << ".5";
	else cout << ".0";
	cout << endl;
}
