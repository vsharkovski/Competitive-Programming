#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 300010;

int n;
ll k;
pii range[maxn];
ll potpre[maxn];

int possible(ll mid) {
	ll s = k;
	int numsmaller = 0, numbigger = 0, numpot = 0;
	potpre[0] = 0;
	vector<pii> pot;
	for (int i = 0; i < n; ++i) {
		int l = range[i].first, r = range[i].second;
		if (l > mid) {
			++numbigger;
			s -= l;
		} else if (r < mid) {
			++numsmaller;
			s -= l;
		} else {
			++numpot;
			potpre[numpot] = potpre[numpot-1] + l; 
			pot.emplace_back(l, r);
		}
		if (s < 0) return false;
	}
	if (numsmaller > n/2) {
		return 1; // too big
	}
	if (numbigger > n/2) {
		return -1; // too small
	}
	// how much is needed
	numsmaller = n/2 - numsmaller;
	numbigger = n/2 - numbigger + 1;
	s -= potpre[numsmaller];
	s -= mid * numbigger;
	if (s < 0) {
		// not enough money for mid this big 
		return 1;
	} else {
		// managed to do it
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> range[i].first >> range[i].second;
		}
		sort(range, range+n);
		int lo = 1, hi = (int)min(k, (ll)1e9), mid;
		int ans = -1;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			int res = possible(mid);
			if (res == -1) {
				lo = mid+1;
			} else if (res == 1) {
				hi = mid-1;
			} else {
				ans = mid;
				lo = mid+1;
			}
		}
		cout << ans << endl;
	}
}
