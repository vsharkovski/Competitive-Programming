#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int maxn = 100010;
 
int n;
vector<int> adj[maxn];
ll c[3][maxn];
ll fc[maxn];
int maxch = 0;
 
void dfs(int i, int p) {
	int ch = 0;
	for (int j : adj[i]) {
		if (j == p) {
 
		} else {
			++ch;
			dfs(j, i);
		}
	}
	maxch = max(maxch, ch);
}
 
ll dfs2(int u, int p, int pclr, int cclr) {
	ll res = c[cclr][u];
	fc[u] = cclr;
	for (int v : adj[u]) {
		if (v != p) {
			for (int nclr = 0; nclr < 3; ++nclr) {
				if (nclr != pclr && nclr != cclr) {
					res += dfs2(v, u, cclr, nclr);
					break;
				}
			}
		}
	}
	return res;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int j = 0; j < 3; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> c[j][i];
		}
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int root = -1;
	maxch = 0;
	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() == 1) {
			root = i;
			dfs(i, -1);
			break;
		}
	}
	if (root == -1 || maxch > 1) {
		cout << "-1\n";
		return 0;
	}
	ll res = 1e18;
	int bpc, bcc;
	for (int pc = 0; pc < 3; ++pc) {
		for (int cc = 0; cc < 3; ++cc) {
			if (pc != cc) {
				ll res1 = dfs2(root, -1, pc, cc);
				if (res1 < res) {
					res = res1;
					bpc = pc;
					bcc = cc;
				}
			}
		}
	}
	dfs2(root, -1, bpc, bcc);
	cout << res << endl;
	for (int i = 1; i <= n; ++i) {
		cout << fc[i]+1 << ' ';
	}
	cout << endl;
}
