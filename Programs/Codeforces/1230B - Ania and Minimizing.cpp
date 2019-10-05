#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (k > 0) {
		if (n == 1) {
			s[0] = '0';
		} else {
			if (s[0] != '1') {
				--k;
				s[0] = '1';
			}
			for (int i = 1; i < n && k > 0; ++i) {
				if (s[i] != '0') {
					--k;
					s[i] = '0';
				}
			}
		}
	}
	cout << s << endl;
}
