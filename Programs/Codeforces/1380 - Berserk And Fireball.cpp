
// Problem : D. Berserk And Fireball
// Contest : Codeforces - Educational Codeforces Round 91 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1380/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200100;

ll k, x, y, ans;
int a[N], posa[N];

void solve(int L, int R) {
	//cout << "solve("<<L<<","<<R<<")\n";
	// remove all elements with indices from L to R
	if (ans == -1 || L > R) return;
	bool bigger = false;
	for (int i = L; i <= R; ++i) {
		if (a[i] > a[L-1] && a[i] > a[R+1]) {
			bigger = true;
			break;
		}
	}
	int n = R-L+1;
	if (n < k) {
		// must berserk all
		if (bigger) {
			ans = -1;
			return;
		}
		ans += y*n;
		return;
	}
	if (bigger) {
		// must use at least 1 fireball at the end
		ans += y*(n%k); // the mandatory
		n -= n%k;
		if (x*(n/k) <= y*(n-k) + x) {
			// fireball all
			ans += x*(n/k);
		} else {
			// berserk all except last k 
			ans += y*(n-k) + x;
		}
		return;
	}
	// all are smaller than edges
	if (y*(n%k) + x*(n/k) <= y*n) {
		// berserk minimum possible, then fireball all else
		ans += y*(n%k) + x*(n/k);
	} else {
		// berserk all
		ans += y*n;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ans = 0;
	int n, m;
	cin >> n >> m >> x >> k >> y;
	if (m > n) {
		cout << -1 << '\n';
		return 0;
	}
	ans = 0;
	a[0] = -1;
	a[n+1] = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		posa[a[i]] = i;
	}
	int pb = -1;
	while (m--) {
		int b;
		cin >> b;
		if (pb == -1) {
			solve(1, posa[b]-1);
		} else {
			if (posa[pb] >= posa[b]) {
				cout << -1 << '\n';
				return 0;
			}
			solve(posa[pb]+1, posa[b]-1);
		}
		pb = b;
	}
	solve(posa[pb]+1, n);
	cout << ans << '\n';
}
