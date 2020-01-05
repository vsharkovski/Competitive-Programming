
// Problem : E. New Year and Castle Construction
// Contest : Hello 2020
// URL : https://codeforces.com/contest/1284/problem/E
// Memory Limit : 1024.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


// is the cross product of these 2 vectors positive?
// see https://en.wikipedia.org/wiki/Cross_product#Computational_geometry
inline ll prod(const pii& a, const pii& b) {
	return (ll)a.first*b.second - (ll)a.second*b.first;
}

inline ll CHS(ll a, int b) {
	if (b == 3) {
		return (a-2)*(a-1)*a/6;
	} else if (b == 4) {
		return (a-3)*(a-2)*(a-1)*a/24;
	} else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	ll ans = n * CHS(n-1, 4); // all combinations, will subtract bad ones
	for (int i = 0; i < n; ++i) {
		vector<pii> points;
		for (int j = 0; j < n; ++j) {
			if (j == i) continue;
			points.emplace_back(x[j]-x[i], y[j]-y[i]);
		}
		sort(points.begin(), points.end(), [&](const pii& a, const pii& b) {
			int aUp = (a.second > 0) || (a.second == 0 && a.first > 0);
			int bUp = (b.second > 0) || (b.second == 0 && b.first > 0);
			if (aUp && !bUp) return true;
			if (!aUp && bUp) return false;
			ll vp = prod(a, b);
			if (vp > 0) return true;
			return false;
		});
		points.resize(2*(n-1));
		for (int i = 0; i < n-1; ++i) {
			points[i+n-1] = points[i];
		}
		int R = 0;
		for (int L = 0; L < n-1; ++L) {
			R = max(R, L+1);
			while (R-L < n-1 && prod(points[L], points[R]) > 0) {
				++R;
			}
			int cnt = R-L-1; // point L is ignored
			ans -= CHS(cnt, 3);
		}
	}
	cout << ans << endl;
}
