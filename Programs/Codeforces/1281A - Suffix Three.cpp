// Problem : A. Suffix Three
// Contest : Codeforces Round #607 (Div. 2)
// URL : https://codeforces.com/contest/1281/problem/A
// Memory Limit : 256.000000MB 
// Time Limit : 1000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool endswith(string& s, string t) {
	if (s.length() < t.length()) return false;
	for (int i = s.length()-1, j = t.length()-1; j >= 0; --i, --j) {
		if (s[i] != t[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (endswith(s, "po")) {
			cout << "FILIPINO\n";
		} else if (endswith(s, "desu") || endswith(s, "masu")) {
			cout << "JAPANESE\n";
		} else {
			cout << "KOREAN\n";
		}
		
	}
}
