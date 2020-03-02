
// Problem : Problem 1. Snow Boots
// Contest : USACO 2018 February Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=813
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;
const int M = N+N;

int maxsize;
int p[N], rrank[N], size[N];

inline int get(int x) {
	return p[x] == x ? x : (p[x] = get(p[x]));
}

inline bool unite(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return false;
	if (rrank[x] < rrank[y]) swap(x, y);
	if (rrank[x] == rrank[y]) ++rrank[x];
	p[y] = x;
	size[x] += size[y];
	maxsize = max(maxsize, size[x]);
	return true;
}

int n, q, m;
int a[N];
int qans[N];
pii queries[N];
vector<int> abysnow[M];
vector<int> qbysnow[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	#endif
	maxsize = 1;
	for (int i = 0; i < N; ++i) {
		p[i] = i;
		rrank[i] = 0;
		size[i] = 1;
	}
	cin >> n >> q;
	vector<int> snows;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		snows.push_back(a[i]);
	}
	for (int i = 1; i <= q; ++i) {
		int s, d;
		cin >> s >> d;
		queries[i] = make_pair(s, d);
		snows.push_back(s);
	}
	sort(snows.begin(), snows.end());
	snows.erase(unique(snows.begin(), snows.end()), snows.end());
	m = snows.size();
	int maxa = 0;
	for (int i = 1; i <= n; ++i) {
		auto it = lower_bound(snows.begin(), snows.end(), a[i]);
		a[i] = distance(snows.begin(), it);
		maxa = max(maxa, a[i]);
		abysnow[a[i]].push_back(i);
	}
	for (int i = 1; i <= q; ++i) {
		int& s = queries[i].first;
		auto it = lower_bound(snows.begin(), snows.end(), s);
		s = distance(snows.begin(), it);
		// special case
		if (queries[i].second == 1) {
			qans[i] = maxa > s ? 0 : 1;
		} else {
			qbysnow[s].push_back(i);
		}
	}
	for (int s = m-1; s >= 0; --s) {
		for (int i : qbysnow[s]) {
			int d = queries[i].second;
			if (maxsize >= d) {
				qans[i] = 0;
			} else {
				qans[i] = 1;
			}
		}
		for (int i : abysnow[s]) {
			if (i > 1 && a[i-1] >= s) {
				unite(i, i-1);
			}
			if (i < n && a[i+1] >= s) {
				unite(i, i+1);
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << qans[i] << '\n';
	}
}
