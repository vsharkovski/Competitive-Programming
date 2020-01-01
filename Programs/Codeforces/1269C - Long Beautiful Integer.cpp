// Problem : C. Long Beautiful Integer
// Contest : Codeforces Round #609 (Div. 2)
// URL : https://codeforces.com/contest/1269/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n+2), b(n+2, -1);
	int sz = n;
	bool isbeauty = true;
	int firstdiffpos = -1;
	for (int i = 1; i <= n; ++i) {
		char ch;
		cin >> ch;
		a[i] = ch - '0';
		if (i > k) {
			if (a[i] != a[i-k]) {
				isbeauty = false;
			}
			b[i] = b[i-k];
			if (b[i] != a[i] && firstdiffpos == -1) {
				firstdiffpos = i;
			}
		} else {
			b[i] = a[i];
		}
	}
	if (!isbeauty && b[firstdiffpos] < a[firstdiffpos]) {
		int i = k;
		while (i >= 1 && a[i] == 9) {
			--i;
		}
		if (i >= 1) {
			sz = n;
			for (int j = 1; j < i; ++j) {
				b[j] = a[j];
			}
			b[i] = a[i] + 1;
			for (int j = i+1; j <= k; ++j) {
				b[j] = 0;
			}
			for (int j = k+1; j <= n; ++j) {
				b[j] = b[j-k];
			}
		} else {
			sz = n+1;
			b[1] = 1;
			for (int j = 2; j <= n+1; ++j) {
				b[j] = 0;
			}
		}
	}
	cout << sz << endl;
	for (int i = 1; i <= sz; ++i) {
		cout << b[i];
	}
}
