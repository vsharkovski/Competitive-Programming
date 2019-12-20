// Problem : F. Two Bracket Sequences
// Contest : Codeforces Round #605 (Div. 3)
// URL : https://codeforces.com/contest/1272/problem/F
// Memory Limit : 512.000000MB 
// Time Limit : 2000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 201;

int n, m;
int q[N], w[N];

struct State {
	int i, j, b;
	State() : i(-1), j(-1), b(-1) {}
	State(int ii, int jj, int bb) : i(ii), j(jj), b(bb) {}
	bool operator = (const State& o) {
		i = o.i, j = o.j, b = o.b;
	}
};

static State pre[N][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	n = s.length();
	m = t.length();
	for (int i = 0; i < n; ++i) {
		q[i] = s[i] == '(' ? 1 : -1;
	}
	for (int i = 0; i < m; ++i) {
		w[i] = t[i] == '(' ? 1 : -1;
	}
	queue<State> bfs;
	bfs.emplace(0, 0, 0);
	while (!bfs.empty()) {
		State a = bfs.front();
		bfs.pop();
		if (a.b < n+m)
		if (a.i == n && a.j == m) {
			if (a.b == 0) {
				break;
			} else {
				State& pr = pre[a.i][a.j][a.b-1];
				if (pr.i == -1) {
					pr = a;
					bfs.emplace(a.i, a.j, a.b-1);
				}
			}
		} else {
			for (int k = 1; k >= -1; k -= 2) {
				int i = a.i, j = a.j, b = a.b + k;
				if (b >= 0 && b <= N-1) {
					if (i < n && q[i] == k) ++i;
					if (j < m && w[j] == k) ++j;
					State& pr = pre[i][j][b];
					if (pr.i == -1) {
						pr = a;
						bfs.emplace(i, j, b);
					}
				}
			}
		}
	}
	string ans = "";
	State f(n, m, 0);
	while (pre[f.i][f.j][f.b].i != -1) {
		State p = pre[f.i][f.j][f.b];
		ans += p.b < f.b ? '(' : ')';
		f = p;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
