// Problem : F. Three Paths on a Tree
// Contest : Codeforces Round #615 (Div. 3)
// URL : https://codeforces.com/contest/1294/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200010;

int n, ans, u1, u2, u3;
vector<int> adj[N];
pii down[N][3];

int counter;
int L[N], R[N];

string S(pii& p) {
	return "(" + to_string(p.first) + "," + to_string(p.second) + ")";
}

void dfs0(int u, int p) {
	L[u] = counter++;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs0(v, u);
	}
	R[u] = counter-1;
}

bool is_descendant(int a, int b) {
	// is a descendant of b ?
	return L[b] <= L[a] && L[a] <= R[b];
}

void dfs1(int u, int p) {
	down[u][0] = down[u][1] = down[u][2] = pii(0, u);
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs1(v, u);
		pii res2 = down[v][0];
		res2.first += 1;
		if (res2.first >= down[u][0].first) {
			down[u][2] = down[u][1];
			down[u][1] = down[u][0];
			down[u][0] = res2;
		} else if (res2.first >= down[u][1].first) {
			down[u][2] = down[u][1];
			down[u][1] = res2;
		} else if (res2.first > down[u][2].first) {
			down[u][2] = res2;
		}
	}
}

void dfs2(int u, int p, pii up) {
	vector<pii> options;
	options.push_back(up);
	//cout << "u=" << u << " up="<<S(up)<<endl;
	for (int j = 0; j < 3; ++j) {
		bool had = false;
		for (pii& p : options) {
			if (p.second == down[u][j].second) {
				had = true;
				break;
			}
		}
		//cout << "    dw=" << S(down[u][j]) << " ";
		//if (had) cout << "HAD\n";
		//else cout << "\n";
		if (!had) {
			options.push_back(down[u][j]);
		}
	}
	sort(options.begin(), options.end(),
	[&](const pii& a, const pii& b) {
		return a.first > b.first;
	});
	if (options.size() >= 3) {
		int res = options[0].first + options[1].first + options[2].first;
		if (res > ans) {
			ans = res;
			u1 = options[0].second;
			u2 = options[1].second;
			u3 = options[2].second;
		}
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		pii up2 = up;
		//cout << "v=" << v << "\n";
		for (int j = 0; j < 3; ++j) {
			//cout << "dw="<<S(down[u][j])<<" ";
			//if (is_descendant(down[u][j].second, v)) cout << "desc\n";
			//else cout << "\n";
			if (!is_descendant(down[u][j].second, v)) {
				if (down[u][j].first > up2.first) {
					up2 = down[u][j];
					break;
				}
			}
		}
		up2.first += 1;
		dfs2(v, u, up2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	counter = 0;
	dfs0(1, -1);
	//for (int i = 1; i <= n; ++i) {
	//	cout << i << " [" << L[i] << ","<<R[i]<<"]\n";
	//}
	ans = 2;
	u1 = 1, u2 = 2, u3 = 3;
	dfs1(1, -1);
	dfs2(1, -1, pii(0, 1));
	cout << ans << '\n' << u1 << ' ' << u2 << ' ' << u3 << '\n';
}
