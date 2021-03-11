
// Problem : C. Element Extermination
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (a[0] < a[n-1]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
