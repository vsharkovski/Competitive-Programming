#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


const int maxn = 100010;

int n, m;
int L[maxn], R[maxn], C[maxn];
int order[maxn];

int num_unique;
vector<int> unique_stations;
unordered_map<int, int> newid;

int bestlast;
int dp[maxn], ps[maxn];
int tree[4*maxn]; // for every position keeps max dp for a segment that has R there

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		if (dp[val] > dp[tree[v]]) {
			tree[v] = val;
		}
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm) {
			update(2*v, tl, tm, pos, val);
		} else {
			update(2*v+1, tm+1, tr, pos, val);
		}
		if (dp[tree[2*v]] >= dp[tree[2*v+1]]) {
			tree[v] = tree[2*v];
		} else {
			tree[v] = tree[2*v+1];
		}
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) return n;
	if (l <= tl && tr <= r) {
		return tree[v];
	} else {
		int tm = (tl + tr) / 2;
		int lidx = query(2*v, tl, tm, l, min(r, tm));
		int ridx = query(2*v+1, tm+1, tr, max(l, tm+1), r);
		if (dp[lidx] >= dp[ridx]) {
			return lidx;
		} else {
			return ridx;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> L[i] >> R[i] >> C[i];
		order[i] = i;
		unique_stations.push_back(R[i]);
	}

	sort(unique_stations.begin(), unique_stations.end());
	num_unique = 0;

	for (int i = 0; i < (int)unique_stations.size(); ++i) {
		if (i == 0 || unique_stations[i] != unique_stations[i-1]) {
			newid[unique_stations[i]] = num_unique;
			++num_unique;
		}
	}

	for (int i = 0; i < n; ++i) {
		R[i] = newid[R[i]];
	}

	sort(order, order+n, [&] (int x, int y) {
		return L[x] != L[y] ? L[x] < L[y] : R[x] < R[y];
	});

	bestlast = 0;
	dp[n] = -1;
	fill(tree, tree+4*n, n);

	for (int i = 0; i < n; ++i) {
		int bestprev = query(1, 0, n-1, 0, R[order[i]]);
		if (bestprev == n) {
			dp[i] = C[order[i]];
			ps[i] = -1;
		} else {
			dp[i] = C[order[i]] + dp[bestprev];
			ps[i] = bestprev;
		}
		update(1, 0, n-1, R[order[i]], i);
		if (dp[i] > dp[bestlast]) {
			bestlast = i;
		}
	}
	
	vector<int> taken;
	for (int i = bestlast; i >= 0; i = ps[i]) {
		taken.push_back(order[i]);
	}
	reverse(taken.begin(), taken.end());
	
	cout << dp[bestlast] << endl << taken.size() << endl;
	for (int x : taken) {
		cout << x+1 << ' ';
	}
	cout << endl;

}
