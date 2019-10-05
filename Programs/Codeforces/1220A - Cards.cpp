#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int cnt[256] = {};
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		++cnt[ch];
	}
	while (cnt['o'] && cnt['n'] && cnt['e']) {
		cout << 1 << ' ';
		--cnt['o'], --cnt['n'], --cnt['e'];
	}
	while (cnt['z'] && cnt['e'] && cnt['r'] && cnt['o']) {
		cout << 0 << ' ';
		--cnt['z'], --cnt['e'], --cnt['r'], --cnt['o'];
	}
}
