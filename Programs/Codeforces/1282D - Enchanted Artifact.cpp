#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int ask(string& s, bool skip = false) {
	cout << s << endl;
	if (skip) return 0;
	int x;
	cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string t = "";
	for (int i = 0; i < 300; ++i) t += 'a';
	int numa = 300 - ask(t);
	for (int i = 0; i < 300; ++i) t[i] = 'b';
	int numb = 300 - ask(t);
	int len = numa + numb;
	t = "";
	if (numa == 0) {
		for (int i = 0; i < len; ++i) t += 'b';
		ask(t, true);
		return 0;
	} else if (numb == 0) {
		for (int i = 0; i < len; ++i) t += 'a';
		ask(t, true);
		return 0;	
	}
	for (int i = 0; i < len; ++i) t += 'a';
	for (int i = 0; i < len-1; ++i) {
		if (numb == 0) break;
		t[i] = 'b';
		int res = ask(t);
		if (res == numb-1) {
			--numb;
		} else {
			t[i] = 'a';
		}
	}
	if (numb > 0) t[len-1] = 'b';
	ask(t, true);
}
