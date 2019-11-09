#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			sum += a;
		}
		int x = sum/n + !!(sum % n);
		cout << x << endl;
	}
}
