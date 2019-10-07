#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e16;

int n, m, k, q, maxr;
vector<ll> lt, rt, nxtsafe, presafe;
vector<bool> safe;
ll cur[2], nxt[2];

inline ll dist(int x, int y, bool nxtrow) {
	if (nxtrow == false) {
		return abs(x-y);
	} else {
		return 1 + min(abs(x-presafe[x]) + abs(presafe[x]-y),
			           abs(x-nxtsafe[x]) + abs(nxtsafe[x]-y));
	}
}

inline ll dist(int x, int y, int z, bool nxtrow1, bool nxtrow2) {
	return dist(x, y, nxtrow1) + dist(y, z, nxtrow2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> q;
	lt.assign(n+1, inf), rt.assign(n+1, -inf);
	maxr = 0;
	while (k--) {
		int r;
		ll c;
		cin >> r >> c;
		maxr = max(maxr, r);
		lt[r] = min(lt[r], c);
		rt[r] = max(rt[r], c);
	}
	safe.assign(m+1, false);
	while (q--) {
		int b;
		cin >> b;
		safe[b] = true;
	}
	nxtsafe.resize(m+1);
	presafe.resize(m+1);
	{
		ll pre = -inf;
		for (int i = 1; i <= m; ++i) {
			if (safe[i]) pre = i;
			presafe[i] = pre;
		}
		pre = inf;
		for (int i = m; i >= 1; --i) {
			if (safe[i]) pre = i;
			nxtsafe[i] = pre;
		}
	}
	int i = 1;
	while (i < maxr && lt[i] == inf) {
		++i;
	}
	if (i == 1) {
		cur[0] = dist(1, rt[i], lt[i], false, false);
		cur[1] = dist(1, lt[i], rt[i], false, false);
	} else {
		cur[0] = i-2 + dist(1, rt[i], lt[i], true, false);
		cur[1] = i-2 + dist(1, lt[i], rt[i], true, false);
	}
	nxt[0] = nxt[1] = inf;
	for (i = i; i <= maxr; ++i) {
		if (i == maxr) {
			break;
		}
		if (lt[i+1] == inf) {
			lt[i+1] = lt[i];
			rt[i+1] = rt[i];
			cur[0] = cur[0] + 1;
			cur[1] = cur[1] + 1;
			continue;
		} else {
			nxt[0] = min(nxt[0], cur[0] + dist(lt[i], rt[i+1], lt[i+1], true, false));
			nxt[0] = min(nxt[0], cur[1] + dist(rt[i], rt[i+1], lt[i+1], true, false));
			nxt[1] = min(nxt[1], cur[0] + dist(lt[i], lt[i+1], rt[i+1], true, false));
			nxt[1] = min(nxt[1], cur[1] + dist(rt[i], lt[i+1], rt[i+1], true, false));
			// swap dp[i], dp[i+1]
			cur[0] = nxt[0];
			cur[1] = nxt[1];
			nxt[0] = nxt[1] = inf;
		}
	}
	cout << min(cur[0], cur[1]) << endl;
}
