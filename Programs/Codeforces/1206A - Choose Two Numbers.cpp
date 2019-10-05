#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n, m;
	cin>> n;
	vector<int>a(n);
	bool had[256] = {};
	for(int i= 0 ;i<n;++i) {
		cin>>a[i];
		had[a[i]] = true;
	}
	cin >> m;
	vector<int> b(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
		had[b[i]] = true;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(!had[a[i]+b[j]]) {
				cout << a[i]<< ' ' << b[j] << endl;
				return 0;
			}
		}
	}
	cout << "None\n";
}
