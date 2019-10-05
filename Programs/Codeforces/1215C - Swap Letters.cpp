#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<int> pos[2];
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) pos[s[i] == 'a'].push_back(i);
	}
	if (pos[0].size() % 2 != pos[1].size() % 2) {
		cout << "-1\n";
		return 0;
	}
	vector<pii> ops;
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i+1 < (int)pos[j].size(); i += 2) {
			ops.emplace_back(pos[j][i], pos[j][i+1]);
		}
	}
	if (pos[0].size() % 2 == 1) {
		ops.emplace_back(pos[0].back(), pos[0].back());
		ops.emplace_back(pos[0].back(), pos[1].back());
	}
	cout << ops.size() << endl;
	for (int i = 0; i < (int)ops.size(); ++i) {
		cout << ops[i].first+1 << ' ' << ops[i].second+1 << '\n';
	}
}
