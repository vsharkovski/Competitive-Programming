
// Problem : Problem 2. Triangles
// Contest : USACO 2020 February Contest, Silver
// URL : http://usaco.org/current/index.php?page=viewproblem&cpid=1003
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
	return x;
}

inline int mult(int x, int y) {
	return (ll)x * y % mod;
}

const int LIM = 1e4;
const int OFS = LIM + 50;
const int M = 2*OFS;
const int N = 1e5 + 50;

int n;
int fX[N], fY[N];
vector<pii> byX[M], byY[M];

void getsums(vector<pii>& vec, int fval[N]) {
	int n = vec.size();
	sort(vec.begin(), vec.end());
	//cout << "vals: ";
	//for (int i = 0; i < n; ++i) cout << "("<<vec[i].first<<","<<vec[i].second<<"),";
	//cout << '\n';
	vector<int> pre(n);
	for (int i = 0; i < n; ++i) { 
		pre[i] = vec[i].first;
		if (i) pre[i] = add(pre[i], pre[i-1]);
	}
	for (int i = 0; i < n; ++i) {
		int xi = vec[i].first;
		int res = 0;
		res = add(res, mult(i+1, xi));
		res = add(res, -pre[i]);
		res = add(res, -mult(n-i-1, xi));
		res = add(res, pre[n-1]);
		res = add(res, -pre[i]);
		int realid = vec[i].second;
		//cout << "realid="<<realid<<" res="<<res<<"\n";
		fval[realid] = add(fval[realid], res);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		fX[i] = 0;
		fY[i] = 0;
		byX[OFS+x].emplace_back(y, i);
		byY[OFS+y].emplace_back(x, i);
		//cout << "i="<<i<< " x="<<x<< " y="<<y<<"\n";
	}
	for (int x = -LIM; x <= LIM; ++x) {
		if (byX[OFS+x].empty()) continue;
		//cout << "x="<<x<<"\n";
		getsums(byX[OFS+x], fY);
	}
	for (int y = -LIM; y <= LIM; ++y) {
		if (byY[OFS+y].empty()) continue;
		//cout << "y="<<y<<"\n";
		getsums(byY[OFS+y], fX);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		//cout << "i="<<i<<" fx="<<fX[i]<<" fy="<<fY[i]<<"\n";
		ans = add(ans, mult(fX[i], fY[i]));
	}
	cout << ans << '\n';
}
