#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200010;

int soldiers, n, numtraps, maxtime;
int agilities[N];
vector<pii> traps[N];

bool possible(int a) {
	// a : min agility of soldiers brought
	// disarm all traps with d[trap] > a
	// total time = (time with squad) + (time alone disabling traps)
	// t = n+1 + (time alone)
	int t = n+1;
	int minl = n+2, maxr = -1;
	for (int x = 1; x <= n; ++x) {
		for (pii& trap : traps[x]) {
			int r = trap.first;
			int d = trap.second;
			if (d > a) {
				minl = min(minl, x);
				maxr = max(maxr, r);
			}
		}
		if (x == maxr) {
			t += 2*(maxr - (minl-1));
			minl = n+2;
			maxr = -1;
		}
	}
	return t <= maxtime;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> soldiers >> n >> numtraps >> maxtime;
	for (int i = 0; i < soldiers; ++i) {
		cin >> agilities[i];
	}
	sort(agilities, agilities+soldiers, greater<int>());
	for (int i = 0; i < numtraps; ++i) {
		int l, r, d;
		cin >> l >> r >> d;
		traps[l].emplace_back(r, d);
	}
	int lo = 0, hi = soldiers-1, mid, ans = -1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (possible(agilities[mid])) {
			ans = mid;
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	cout << ans+1 << endl;
}
