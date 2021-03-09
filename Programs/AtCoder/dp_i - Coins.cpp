#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<double> cur(n+1), nxt(n+1);
	cur[0] = 1;
	for (int i = 0; i < n; ++i) {
		double p;
		cin >> p;
		for (int h = 0; h < n; ++h) {
			nxt[h+1] += cur[h] * p;
			nxt[h] += cur[h] * (1 - p);
		}
		swap(cur, nxt);
		nxt.assign(n+1, 0);
	}
	double ans = 0;
	for (int h = (n+1)/2; h <= n; ++h) {
		ans += cur[h];
	}
	cout << setprecision(15) << ans << '\n';
}
