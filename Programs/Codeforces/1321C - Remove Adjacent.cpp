
// Problem : C. Remove Adjacent
// Contest : Codeforces Round #625 (Div. 2, based on Technocup 2020 Final Round)
// URL : https://codeforces.com/contest/1321/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int initlen;
	cin >> initlen;
	string s;
	cin >> s;
	for (char ch = 'z'; ch > 'a'; --ch) {
		int n = s.length();
		string t = "";
		for (int i = 0; i < n; ++i) {
			if (s[i] != ch) {
				t += s[i];
				continue;
			}
			int j = i;
			while (j < n && s[j] == ch) ++j;
			bool adj = false;
			if (i > 0 && s[i-1] == ch-1) adj = true;
			if (j < n && s[j] == ch-1) adj = true;
			if (!adj) {
				for (int k = i; k < j; ++k) {
					t += ch;
				}
			}
			i = j-1;
		}
		s = t;
		//cout << "ch="<<ch<<" t="<<t<<endl;
	}
	cout << initlen - (int)s.length() << '\n';
}
