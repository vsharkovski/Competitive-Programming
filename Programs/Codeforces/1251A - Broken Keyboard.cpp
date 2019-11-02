#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool had[26] = {};
		bool good[26] = {};
		for (int i = 0; i < s.length(); ++i) {
			had[s[i]-'a'] = true;
			int j = i+1;
			while (j < s.length() && s[i] == s[j]) {
				++j;
			}
			if ((j-i) % 2 == 1) {
				good[s[i]-'a'] = true;
			}
			i = j-1;
		}
		for (int i = 0; i < 26; ++i) {
			if (had[i] && good[i]) {
				cout << char('a'+i);
			}
		}
		cout << endl;
	}
}
