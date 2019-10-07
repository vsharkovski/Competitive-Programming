#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	string pre = "", cur = "";
	pre += s[0];
	int ans = 1;
	for (int i = 1; i < s.length(); ++i) {
		cur += s[i];
		if (cur != pre) {
			pre = cur;
			++ans;
			cur = "";
		} else {
			
		}
	}
	cout << ans << endl;
}
