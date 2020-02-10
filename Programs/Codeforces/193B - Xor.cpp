// Problem : B. Xor
// Contest : Codeforces Round #122 (Div. 1)
// URL : https://codeforces.com/contest/193/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 32;

int n, u, r;
int a[N], b[N], k[N];
int p[N], invp[N];

ll ans;
ll arr[N];

void shift(ll x[N], int p[N]) {
	static ll y[N];
	for (int i = 1; i <= n; ++i) y[i] = x[p[i]];
	for (int i = 1; i <= n; ++i) x[i] = y[i];
}

void dfs(int steps, int prevop) {
	if (steps % 2 == 0) {
		ll res = 0;
		for (int i = 1; i <= n; ++i) {
			res += arr[i] * k[i];
		}
		ans = max(ans, res);
	}
	if (steps == 0) return;
	shift(arr, p);
	for (int i = 1; i <= n; ++i) arr[i] += r;
	dfs(steps-1, 1);
	for (int i = 1; i <= n; ++i) arr[i] -= r;
	shift(arr, invp);
	if (prevop != 2) {
		for (int i = 1; i <= n; ++i) arr[i] ^= b[i];
		dfs(steps-1, 2);
		for (int i = 1; i <= n; ++i) arr[i] ^= b[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> u >> r;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i) cin >> k[i];
	for (int i = 1; i <= n; ++i) cin >> p[i], invp[p[i]] = i;
	for (int i = 1; i <= n; ++i) arr[i] = a[i];
	ans = -1e18;
	dfs(u, 0);
	cout << ans << endl;
}
