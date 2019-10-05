#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<ll>> m(n+1, vector<ll>(n+1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> m[i][j];
		}
	}
	ll a1 = sqrt(m[1][2] * m[1][3] / m[2][3]);
	cout << a1 << ' ';
	for (int i = 2; i <= n; ++i) {
		cout << m[1][i] / a1 << ' ';
	}
}
