// Problem : D. Directed Roads
// Contest : Codeforces Round #369 (Div. 2)
// URL : https://codeforces.com/contest/711/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;
const int N = 200010;
const int unvisited = 0, explored = 1, visited = 2;

ll ans;
int n;
int nxt[N];
int status[N];
bool incycle[N];

void dfs(int u) {
	status[u] = explored;
	int v = nxt[u];
	if (status[v] == unvisited) {
		dfs(v);
	} else if (status[v] == explored) {
		int len = 0, k = v;
		ll pwr = 1;
		do {
			++len;
			pwr = (pwr * 2) % mod;
			k = nxt[k];
			incycle[k] = true;
		} while (k != v);
		ll nocycle = (pwr - 2 + mod) % mod;
		ans = (ans * nocycle) % mod;
	}
	if (!incycle[u]) {
		ans = (ans * 2) % mod;
	}
	status[u] = visited;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> nxt[i];
		status[i] = unvisited;
		incycle[i] = false;
		//cout << i << " -> " << nxt[i] << endl;
	}
	ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (status[i] == unvisited) {
			dfs(i);
		}
	}
	cout << ans << endl;
}
