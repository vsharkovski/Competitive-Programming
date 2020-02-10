// Problem : C. Duff in the Army
// Contest : Codeforces Round #326 (Div. 1)
// URL : https://codeforces.com/contest/587/problem/C
// Memory Limit : 512.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int K = 17;
const int M = 10;

int n, m, q;
vector<int> adj[N];

int depth[N];
int P[N][K];

vector<int> self[N];
vector<int> data[N][K];

void dfs(int u, int p, int d) {
	depth[u] = d;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, d+1);
		P[v][0] = u;
	}
}

void Merge(vector<int>& a, vector<int>& b) {
	vector<int> c;
	int n = a.size(), m = b.size();
	int i = 0, j = 0;
	while (c.size() < M && (i < n || j < m)) {
		if (i == n) {
			c.push_back(b[j++]);
		} else if (j == m) {
			c.push_back(a[i++]);
		} else if (a[i] < b[j]) {
			c.push_back(a[i++]);
		} else if (a[i] > b[j]) {
			c.push_back(b[j++]);
		} else {
			c.push_back(a[i++]);
			++j;
		}
	}
	a = c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= m; ++i) {
		int a;
		cin >> a;
		self[a].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		P[i][0] = -1;
	}
	dfs(1, -1, 0);
	for (int i = 1; i <= n; ++i) {
		data[i][0] = self[i];
		if (P[i][0] != -1) {
			Merge(data[i][0], self[P[i][0]]);
		}
	}
	for (int j = 1; j < K; ++j) {
		for (int i = 1; i <= n; ++i) {
			int k = P[i][j-1];
			if (k == -1) {
				P[i][j] = -1;
			} else {
				P[i][j] = P[k][j-1];
				data[i][j] = data[i][j-1];
				Merge(data[i][j], data[k][j-1]);
			}
		}
	}
	/*
	for (int i = 1; i <= n; ++i) {
		cout << "i=" << i << " {";
		for (int x : self[i]) cout << x << ',';
		cout << "}\n";
		for (int j = 0; j < K; ++j) {
			if (data[i][j].empty()) continue;
			if (P[i][j] == -1) continue;
			cout << "  j=" << j << "{";
			for (int x : data[i][j]) cout << x << ',';
			cout << "}\n";
		}		
	}
	/*/
	while (q--) {
		int a, b, sz;
		cin >> a >> b >> sz;
		vector<int> res;
		if (depth[a] < depth[b]) swap(a, b);
		//cout << "a=" << a << " b=" << b << " sz=" << sz << endl;
		Merge(res, self[a]);
		Merge(res, self[b]);
		for (int j = K-1; j >= 0; --j) {
			if (depth[a] - (1<<j) >= depth[b]) {
				//cout << "moving " << a << " up " << (1<<j) <<", now "<<P[a][j]<<"\n";
				Merge(res, data[a][j]);
				a = P[a][j];
			}
		}
		if (a != b) {
			for (int j = K-1; j >= 0; --j) {
				if (P[a][j] != -1 && P[a][j] != P[b][j]) {
					//cout << "moving up " << (1<<j) << ", " << a << " -> " << P[a][j] << ", " << b << " -> " << P[b][j] << "\n";
					Merge(res, data[a][j]);
					Merge(res, data[b][j]);
					a = P[a][j];
					b = P[b][j];
				}
			}
			Merge(res, self[P[a][0]]);
		}
		sz = min(sz, (int)res.size());
		cout << sz << ' ';
		for (int i = 0; i < sz; ++i) {
			cout << res[i] << ' ';
		}
		cout << '\n';
	}
}
