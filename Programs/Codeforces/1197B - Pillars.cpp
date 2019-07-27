#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
 
 
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int npos = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == n) {
			npos = i;
		}
	}
	for (int j = npos-1; j >= 0; --j) {
		if (a[j] > a[j+1]) {
			cout << "NO\n";
			return 0;
		}
	}
	for (int j = npos+1; j < n; ++j) {
		if (a[j] > a[j-1]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}
