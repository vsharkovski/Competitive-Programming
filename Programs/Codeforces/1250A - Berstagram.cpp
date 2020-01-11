// Problem : A. Berstagram
// Contest : 2019-2020 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Teams Preferred)
// URL : https://codeforces.com/contest/1250/problem/A
// Memory Limit : 512.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	vector<int> pos(n+1), minpos(n+1), maxpos(n+1);
	vector<int> atpos(n+1);
	for (int i = 1; i <= n; ++i) {
		pos[i] = minpos[i] = maxpos[i] = i;
		atpos[i] = i;
	}
	for (int x : a) {
		int i = pos[x];
		if (i == 1) continue;
		int y = atpos[i-1];
		pos[x] = i-1;
		pos[y] = i;
		atpos[i-1] = x;
		atpos[i] = y;
		minpos[x] = min(minpos[x], pos[x]);
		maxpos[y] = max(maxpos[y], pos[y]);
	}
	for (int i = 1; i <= n; ++i) {
		cout << minpos[i] << ' ' << maxpos[i] << endl;
	}
}
