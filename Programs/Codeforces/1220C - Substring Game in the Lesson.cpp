#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	int last0pos[256];
	fill(last0pos, last0pos+256, -1);
	for (int i = 0; i < n; ++i) {
		bool dp = false;
		for (int ch = 'a'; ch < s[i]; ++ch) {
			if (last0pos[ch] != -1) {
				dp = true;
				break;
			}
		}
		if (dp) {
			cout << "Ann\n";
		} else {
			cout << "Mike\n";
			last0pos[s[i]] = i;
		}
	}
}
