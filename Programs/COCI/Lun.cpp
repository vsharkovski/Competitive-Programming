#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		a[i] = ch == 'x' ? -1 : ch-'0';
	}
	int ans = 10;
	for (int x = 0; x <= 9; ++x) {
		int sum = 0;
		for (int i = n-2, j = 1; i >= 0; --i, j = 1-j) {
			int d = a[i] == -1 ? x : a[i];
			if (j) d *= 2;
			if (d >= 10) d = d/10 + d%10;
			sum += d;
		}
		sum *= 9;
		sum %= 10;
		if (sum == (a[n-1] == -1 ? x : a[n-1])) {
			ans = x;
			break;
		}
	}
	cout << ans << endl;
}
