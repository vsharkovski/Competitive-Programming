// Problem : B. New Year and Ascent Sequence
// Contest : Hello 2020
// URL : https://codeforces.com/contest/1284/problem/B
// Memory Limit : 1024.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> minval(n), maxval(n);
	vector<int> mins, maxs;
	vector<bool> ascentself(n);
	ll numself = 0;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		bool ascent_here = false;
		int mini = 1e9, maxi = -1;
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			mini = min(mini, x);
			maxi = max(maxi, x);
			if (mini < x) {
				ascent_here = true;
			}
		}
		ascentself[i] = ascent_here;
		if (ascent_here) {
			++numself;
		} else {
			mins.push_back(mini);
			maxs.push_back(maxi);
			minval[i] = mini;
			maxval[i] = maxi;
		}
	}
	ll ans = 0;
	ans += numself*numself + numself*2*(n-numself);
	ll ans2 = 0;
	sort(mins.begin(), mins.end());
	sort(maxs.begin(), maxs.end());
	for (int i = 0; i < n; ++i) {
		if (ascentself[i]) continue;
		auto it = lower_bound(mins.begin(), mins.end(), maxval[i]);
		ans2 += distance(mins.begin(), it);
		it = upper_bound(maxs.begin(), maxs.end(), minval[i]);
		ans2 += distance(it, maxs.end());
	}
	ans2 /= 2;
	ans += ans2;
	cout << ans << endl;
}
