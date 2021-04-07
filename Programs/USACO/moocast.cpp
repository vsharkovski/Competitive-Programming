#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1010;

int n;
ll xc[N], yc[N];
int last[N];
int posscalls, numvis;

inline ll node_dist(int u, int v) {
	return (xc[u]-xc[v])*(xc[u]-xc[v]) + (yc[u]-yc[v])*(yc[u]-yc[v]);
}

void dfs(int u, ll maxd) {
	last[u] = posscalls;
	++numvis;
	for (int v = 0; v < n; ++v) {
		if (last[v] != posscalls && node_dist(u, v) <= maxd) {
			dfs(v, maxd);
		}
	}
}

bool possible(ll maxd) {
	++posscalls;
	numvis = 0;
	dfs(0, maxd);
	return numvis == n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> xc[i] >> yc[i];
		last[i] = -1;
	}
	posscalls = 0;
	ll low = 0, high = 1e12, mid, ans = high;
	while (low <= high) {
		mid = (low + high) / 2;
		if (possible(mid)) {
			ans = mid;
			high = mid-1;
		} else {
			low = mid+1;
		}
	}
	cout << ans;
}
