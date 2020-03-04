
// Problem : Problem 3. Lasers and Mirrors
// Contest : USACO 2016 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=671
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;

// mirror 0 is start, mirror n is end
int n;
int mx[N], my[N];
int order1[N], order2[N];
int pos1[N], pos2[N];
bitset<N> visited[4];
const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	#endif
	cin >> n;
	++n;
	cin >> mx[0] >> my[0];
	cin >> mx[n] >> my[n];
	for (int i = 1; i < n; ++i) {
		cin >> mx[i] >> my[i];
	}
	for (int i = 0; i <= n; ++i) {
		order1[i] = order2[i] = i;
	}
	sort(order1, order1+n+1, [&] (int i, int j) {
		if (my[i] != my[j]) return my[i] < my[j];
		return mx[i] < mx[j];
	});
	sort(order2, order2+n+1, [&] (int i, int j) {
		if (mx[i] != mx[j]) return mx[i] < mx[j];
		return my[i] < my[j];
	});
	for (int i = 0; i <= n; ++i) {
		pos1[order1[i]] = i;
		pos2[order2[i]] = i;
	}
	queue<pii> queues[2];
	for (int dir = 0; dir < 4; ++dir) {
		queues[0].emplace(dir, 0);
	}
	int ans = 0, D = 0;
	while (true) {
		while (!queues[D].empty()) {
			pii top = queues[D].front();
			queues[D].pop();
			int dir = top.first, i = top.second;
			if (visited[dir][i]) continue;
			visited[dir][i] = true;
			if (i == n) {
				cout << ans << '\n';
				return 0;
			}
			int nxt[4] = {-1, -1, -1, -1};
			if (pos1[i] > 0) {
				int j = order1[pos1[i]-1];
				if (my[j] == my[i]) nxt[LEFT] = j;
			}
			if (pos1[i] < n) {
				int j = order1[pos1[i]+1];
				if (my[j] == my[i]) nxt[RIGHT] = j;
			}
			if (pos2[i] > 0) {
				int j = order2[pos2[i]-1];
				if (mx[j] == mx[i]) nxt[UP] = j;
			}
			if (pos2[i] < n) {
				int j = order2[pos2[i]+1];
				if (mx[j] == mx[i]) nxt[DOWN] = j;
			}
			for (int z = dir-1; z <= dir+1; ++z) {
				int dir1 = (z + 4) % 4;
				int j = nxt[dir1];
				if (j != -1) {
					queues[dir1 == dir ? D : 1-D].emplace(dir1, j);
				}
			}
		}
		if (queues[1-D].empty()) {
			break;
		}
		++ans;
		D = 1-D;
	}
	cout << -1 << '\n';
}
