#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll nummoves(vector<pii>& v) {
	int n = v.size()-1;
	int cnt[26] = {};
	for (int i = n; i >= 1; --i) {
		int x = v[i].first;
		for (int y = 0; y < x; ++y) {
			v[i].second += cnt[y];
		}
		++cnt[x];
	}
	sort(v.begin()+1, v.end());
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		int j = v[i].second;
		res += j - i;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<pii> v[2];
		int cnt[2][26] = {};
		for (int j = 0; j < 2; ++j) {
			v[j].emplace_back(0, 0);
			for (int i = 1; i <= n; ++i) {
				char ch;
				cin >> ch;
				int x = ch - 'a';
				v[j].emplace_back(x, i);
				++cnt[j][x];
			}
		}
		bool bad = false;
		bool inf = false;
		for (int x = 0; x < 26; ++x) {
			if (cnt[0][x] != cnt[1][x]) {
				bad = true;
				break;
			}
			if (cnt[0][x] >= 2) {
				inf = true;
			}
		}
		if (bad) {
			cout << "NO\n";
			continue;
		}
		if (inf) {
			cout << "YES\n";
			continue;
		}
		ll a = nummoves(v[0]);
		ll b = nummoves(v[1]);
		if (a % 2 == b % 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
