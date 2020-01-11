// Problem : L. Lexicography
// Contest : 2019-2020 ICPC, NERC, Northern Eurasia Finals (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL : https://codeforces.com/problemset/problem/1267/L
// Memory Limit : 512.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int A = 26;
const int N = 1001;

int n, l, k;
int ans[N][N];
int cnt[A];
int AL, AR;

int small() {
	while (cnt[AL] == 0) ++AL;
	--cnt[AL];
	return AL;
}

int big() {
	while (cnt[AR] == 0) --AR;
	--cnt[AR];
	return AR;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> k;
	--k;
	fill(cnt, cnt+A, 0);
	for (int i = 0; i < n*l; ++i) {
		char ch;
		cin >> ch;
		++cnt[int(ch-'a')];
	}
	AL = 0, AR = A-1;
	int groupL = 0;
	for (int base = 0; base < l; ++base) {
		for (int i = groupL; i <= k; ++i) {
			ans[i][base] = small();
		}
		int groupL2 = k;
		for (int i = k-1; i >= groupL; --i) {
			if (ans[i][base] == ans[k][base]) {
				groupL2 = i;
				continue;
			}
			for (int j = l-1; j > base; --j) {
				ans[i][j] = big();
			}
		}
		groupL = groupL2;
	}
	for (int i = k+1; i < n; ++i) {
		for (int j = 0; j < l; ++j) {
			ans[i][j] = small();
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l; ++j) {
			cout << char(ans[i][j]+'a');
		}
		cout << '\n';
	}
}
