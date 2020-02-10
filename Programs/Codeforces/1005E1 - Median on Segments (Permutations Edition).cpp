// Problem : E1. Median on Segments (Permutations Edition)
// Contest : Codeforces Round #496 (Div. 3)
// URL : https://codeforces.com/contest/1005/problem/E1
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int start;
	vector<int> p(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		if (p[i] == m) start = i;
	}
	ll ans = 0;
	map<int, int> cnt;
	int sum = 0;
	++cnt[sum];
	for (int i = start-1; i >= 1; --i) {
		sum += p[i] < m ? -1 : 1;
		++cnt[sum];
	}
	sum = 0;
	for (int i = start; i <= n; ++i) {
		if (p[i] != m) sum += (p[i] < m) ? -1 : 1;
		ans += cnt[-sum];
		ans += cnt[-sum+1];
	}
	cout << ans << endl;
}
