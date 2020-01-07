// Problem : E. The Cake Is a Lie
// Contest : Codeforces Round #610 (Div. 2)
// URL : https://codeforces.com/contest/1282/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		map<pii, int> data2;
		map<tuple<int, int, int>, int> data3;
		for (int i = 1; i <= n-2; ++i) {
			int t[3];
			for (int j = 0; j < 3; ++j) {
				cin >> t[j];
				for (int k = 0; k < j; ++k) {
					++data2[pii(min(t[j], t[k]), max(t[j], t[k]))];
				}
			}
			sort(t, t+3);
			do {
				data3[make_tuple(t[0], t[1], t[2])] = i;
			} while (next_permutation(t, t+3));
		}
		vector<vector<int>> adj(n+1);
		for (auto& kvp : data2) {
			if (kvp.second == 1) {
				int a = kvp.first.first;
				int b = kvp.first.second;
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
		vector<int> order(n+1), L(n+1), R(n+1);
		{
			int i = 1, u = 1;
			while (i <= n) {
				order[i] = u;
				for (int v : adj[u]) {
					if (i == 1 || order[i-1] != v) {
						u = v;
						break;
					}
				}
				++i;
			}
			L[order[1]] = order[n];
			R[order[n]] = order[1];
			for (i = 1; i <= n; ++i) {
				if (i > 1) L[order[i]] = order[i-1];
				if (i < n) R[order[i]] = order[i+1];
			}
			for (int i = 1; i <= n; ++i) {
				cout << order[i] << ' ';
			}
			cout << endl;
		}
		{
			int u = 1;
			while (!data3.count(make_tuple(u, R[u], R[R[u]]))) {
				u = R[u];
			}
			int cnt = 0;
			while (true) {
				int idx = data3[make_tuple(u, R[u], R[R[u]])];
				if (idx == 0) {
					u = R[u];
					idx = data3[make_tuple(u, R[u], R[R[u]])];
					if (idx == 0) {
						u = L[u];
					}
				}
				while (idx == 0) {
					u = L[u];
					idx = data3[make_tuple(u, R[u], R[R[u]])];
				}
				//cout << "u=" << u << " R=" << R[u] << " RR=" << R[R[u]] << " idx=";
				cout << idx << ' ';
				//cout << endl;
				++cnt;
				if (cnt == n-2) {
					break;
				}
				// remove node R[u]
				R[u] = R[R[u]];
				L[R[u]] = u;
			}
			cout << endl;
		}
	}
}
