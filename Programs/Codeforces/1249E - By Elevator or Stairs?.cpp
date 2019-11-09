#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	vector<int> a(n+1), b(n+1), p(n+1), q(n+1);
	for (int i = 1; i <= n-1; ++i) {
		cin >> a[i];
		p[i] = p[i-1] + a[i];
	}
	for (int i = 1; i <= n-1; ++i) {
		cin >> b[i];
		q[i] = q[i-1] + b[i];
	}
	set<int> s1, s2;
	cout << 0 << ' '; // for floor 1
	s1.insert(0);
	s2.insert(0);
	for (int i = 2; i <= n; ++i) {
		int dp = 1e9;
		dp = min(dp, p[i-1] + *s1.begin());
		dp = min(dp, c + q[i-1] + *s2.begin());
		s1.insert(dp - p[i-1]);
		s2.insert(dp - q[i-1]);
		cout << dp << ' ';
	}
}
