#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
	int n;
	cin >> n;
	vector<int> a(2*n);
	multiset<int> base_set;
	for (int i = 0; i < 2*n; ++i) {
		cin >> a[i];
		base_set.insert(a[i]);
	}
	sort(a.begin(), a.end());
	for (int first = 0; first < 2*n-1; ++first) {
		vector<pair<int, int>> ops;
		multiset<int> cur = base_set;
		bool bad = false;
		int first_x = a[first] + a[2*n-1];
		int x = first_x;
		//cout << "first_x="<<first_x<<"\n";
		//cout<<"base:";for(int x:base_set)cout<<x<<' ';cout<<"\n";
		while (!cur.empty()) {
			// z + y = x
			auto yit = prev(cur.end());
			int y = *yit;
			auto zit = cur.lower_bound(x - y);
			if (zit == cur.end() || zit == yit || *zit != x - y) {
				bad = true;
				break;
			}
			int z = *zit;
			//cout<<"z="<<z<<" y="<<y<<" x="<<x<<'\n';
			ops.emplace_back(z, y);
			cur.erase(yit);
			cur.erase(cur.lower_bound(z));
			//cout<<"cur:";for(int x:cur)cout<<x<<' ';cout<<"\n";
			//return;
			x = y;
		}
		if (!bad) {
			cout << "YES\n";
			cout << first_x << '\n';
			for (auto p : ops) {
				cout << p.first << ' ' << p.second << '\n';
			}
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		solve();
	}
}
