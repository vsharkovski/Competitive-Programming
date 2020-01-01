#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int cnt[10] = {};
		int sum = 0;
		for (char ch : s) {
			++cnt[ch-'0'];
			sum += ch-'0';
		}
		if (sum % 3 != 0) {
			cout << "cyan\n";
			continue;
		}
		bool found = false;
		for (int x = 0; x <= 8; x += 2) {
			if (cnt[x] == 0) continue;
			--cnt[x];
			if (cnt[0] > 0) {
				found = true;
				break;
			}
			++cnt[x];
		}
		if (!found) {
			cout << "cyan\n";
		} else {
			cout << "red\n";
		}
	}
}
