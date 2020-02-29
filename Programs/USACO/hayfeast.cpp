
// Problem : Problem 3. Haybale Feast
// Contest : USACO 2017 December Contest, Gold
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=767
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100100;
const ll inf = 1e9;

int n, ans;
ll M;
ll P[N];
int S[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
	#endif
	cin >> n >> M;
	P[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> P[i] >> S[i];
		P[i] += P[i-1];
	}
	ans = inf;
	multiset<int> sette;
	int l = 0;
	for (int r = 1; r <= n; ++r) {
		sette.insert(S[r]);
		while (l < r && P[r] >= M + P[l]) {
			if (l) sette.erase(sette.find(S[l]));
			++l;
		}
		// P[r] >= M + P[l-1]
		// let s[i] = max(S[i], S[i+1], ..., S[r])
		// then we need min(s[i]) for 1 <= i <= l
		// this is always s[l], which is the max of the sette
		if (l && P[r] >= M + P[l-1] && !sette.empty()) {
			ans = min(ans, *sette.rbegin());
		}
	}
	cout << ans << '\n';
}
