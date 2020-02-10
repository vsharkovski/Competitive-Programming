// Problem : C. The Values You Can Make
// Contest : Codeforces Round #360 (Div. 1)
// URL : https://codeforces.com/contest/687/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int M = 501;
	int N, K;
	cin >> N >> K;
	vector<int> c(N);
	for (int i = 0; i < N; ++i) {
		cin >> c[i];
	}
	vector<bitset<M>> cur(M), nxt(M);
	cur[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < M; ++k) {
			nxt[k] = cur[k];
			if (k >= c[i]) {
				nxt[k] |= cur[k-c[i]];
				nxt[k] |= cur[k-c[i]] << c[i];
			}
		}
		swap(cur, nxt);
	}
	vector<int> ans;
	for (int x = 0; x <= K; ++x) {
		if (cur[K][x]) {
			ans.push_back(x);
		}
	}
	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << ' ';
	}
}
