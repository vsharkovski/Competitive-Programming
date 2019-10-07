#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		string s, t;
		cin >> s >> t;
		bool had[26][2] = {};
		for (char ch : s) {
			had[ch-'a'][0] = 1;
		}
		for (char ch : t) {
			had[ch-'a'][1] = 1;
		}
		bool found = false;
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			if (had[ch-'a'][0] && had[ch-'a'][1]) {
				found = true;
				break;
			}
		}
		if (found) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
