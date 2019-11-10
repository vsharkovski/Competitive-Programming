#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int K = 15;
const int N = K * 51000;

int k;
ll S;

int sz[K];
ll sum[K];
vector<ll> numbers[K];

// compressing the numbers
vector<ll> uniq;
unordered_map<ll, int> newid;

// graph
int n;
int origin[N]; // group this compressed number is in
int adj[N];

int source[1<<K]; // the node this mask starts from
int dp[1<<K];
// dp[m] = m if m exists
// or dp[m] = g, such that g exists and m^g exists
// or dp[m] = 0

const int unvisited = 0, explored = 1, visited = 2;
int status[N];

void dfs(int u) {
	status[u] = explored;
	int v = adj[u];
	if (v != -1) {
		if (status[v] == unvisited) {
			dfs(v);
		} else if (status[v] == explored) {
			int mask = 0;
			int w = u;
			// cout << "cycle: ";
			do {
				// cout << w << "(" << uniq[w] << "),";
				if (mask & (1 << origin[w])) {
					mask = -1;
					break;
				}
				mask |= (1 << origin[w]);
				w = adj[w];
			} while (w != u);
			if (mask == -1) {
				// cout << " bad mask!\n";
			} else {
				// cout << " mask=" << bitset<K>(mask) << endl;
				source[mask] = u;
				dp[mask] = mask;
			}
		}
	}
	status[u] = visited;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	S = 0;
	for (int i = 0; i < k; ++i) {
		cin >> sz[i];
		numbers[i].resize(sz[i]);
		sum[i] = 0;
		for (int j = 0; j < sz[i]; ++j) {
			ll x;
			cin >> x;
			numbers[i][j] = x;
			S += x;
			sum[i] += x;
			uniq.push_back(x);
		}
	}
	if (S % k != 0) {
		cout << "No\n";
		return 0;
	}
	S /= k;
	// cout << "S=" << S << endl;
	sort(uniq.begin(), uniq.end());
	n = uniq.size();
	for (int i = 0; i < n; ++i) {
		newid[uniq[i]] = i;
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < sz[i]; ++j) {
			ll x = numbers[i][j];
			int x1 = newid[x];
			origin[x1] = i;
			ll y = S - sum[i] + x;
			if (newid.count(y)) {
				int y1 = newid[y];
				adj[x1] = y1;
			} else {
				adj[x1] = -1;
			}
		}
	}
	// for (int u = 0; u < n; ++u) {
	// 	cout << "u=" << u << "(" << uniq[u] << ") origin=" << origin[u] << " adj=" << adj[u] << "(" << ((adj[u]==-1)?(-1):(uniq[adj[u]])) << ")\n";
	// }
	for (int m = 0; m < (1 << K); ++m) {
		dp[m] = 0;
	}
	for (int i = 0; i < n; ++i) {
		status[i] = unvisited;
	}
	for (int i = 0; i < n; ++i) {
		if (status[i] == unvisited) {
			dfs(i);
		}
	}
	for (int m = 0; m < (1 << k); ++m) {
		if (dp[m]) continue;
		for (int g = m-1; g > 0; g = (g - 1) & m) {
			if (dp[g] && dp[m ^ g]) {
				dp[m] = g;
				break;
			}
		}
	}
	if (dp[(1 << k)-1] == 0) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	int c[K];
	int p[K];
	queue<int> masks;
	masks.push((1 << k)-1);
	while (!masks.empty()) {
		int m = masks.front();
		masks.pop();
		if (dp[m] != m) {
			masks.push(dp[m]);
			masks.push(m ^ dp[m]);
		} else {
			int u = source[m];
			int w = u;
			do {
				int v = adj[w];
				c[origin[v]] = uniq[v]; // the original value
				p[origin[v]] = origin[w];
				w = v;
			} while (w != u);
		}
	}
	for (int i = 0; i < k; ++i) {
		cout << c[i] << ' ' << p[i]+1 << endl;
	}
}
