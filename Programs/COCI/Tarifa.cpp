#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int x, n, p;
	cin >> x >> n;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += x;
		cin >> p;
		cur -= p;
	}
	cur += x;
	cout << cur << '\n';
}
