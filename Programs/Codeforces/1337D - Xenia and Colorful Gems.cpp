
// Problem : D. Xenia and Colorful Gems
// Contest : Codeforces - Codeforces Round #635 (Div. 2)
// URL : https://codeforces.com/contest/1337/problem/D
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	vector<int> data[3];
	int indices[3] = {0, 1, 2};
	while (T--) {
		for (int i = 0; i < 3; ++i) {
			int sz;
			cin >> sz;
			data[i].resize(sz);
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < (int)data[i].size(); ++j) {
				cin >> data[i][j];
			}
			sort(data[i].begin(), data[i].end());
		}
		ll ans = -1;
		do {
			auto& rv = data[indices[0]];
			auto& gv = data[indices[1]];
			auto& bv = data[indices[2]];
			for (int r : rv) {
				auto git = lower_bound(gv.begin(), gv.end(), r);
				if (git != gv.begin()) --git;
				for (int gcnt = 0; gcnt < 2; ++gcnt) {
					if (git == gv.end()) break;
					int g = *git;
					++git;
					vector<int> targets = {r, g};
					for (int x : targets) {
						auto bit = lower_bound(bv.begin(), bv.end(), x);
						if (bit != bv.begin()) --bit;
						for (int bcnt = 0; bcnt < 2; ++bcnt) {
							if (bit == bv.end()) break;
							int b = *bit;
							++bit;
							//cout << "r="<<r<<" g="<<g<<" b="<<b<<"\n";
							ll ans1 = ll(r-g)*(r-g) + ll(g-b)*(g-b) + ll(b-r)*(b-r);
							if (ans == -1 || ans1 < ans) ans = ans1;
						}
					}
				}
			}
		} while (next_permutation(indices, indices+3));
		cout << ans << '\n';
	}
}
