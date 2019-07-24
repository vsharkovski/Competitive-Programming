#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 9;
const ll p = 37;
const ll pinv = 297297300;

const int MAXN = 2000010;

int N, ans1, ans2;
int S[MAXN];
ll h[MAXN];
ll ppow[MAXN];
ll ppowinv[MAXN];

ll subhash(int a, int b) {
	if (a > b) return 0;
	ll res = h[b] - h[a-1];
	if (res < 0) res += mod;
	res = (res * ppowinv[a]) % mod; 
	return res;
}

ll combine(int a, int b, int c, int d) {
	ll x = subhash(a, b);
	ll y = subhash(c, d);
	y = (y * ppow[b-a+1]) % mod;
	return (x + y) % mod;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	if (N % 2 == 0) {
		cout << "NOT POSSIBLE\n";
		return 0;
	}
	for (int i = 1; i <= N; ++i) {
		char ch;
		cin >> ch;
		S[i] = ch - 'A' + 1;
	}
	ppow[0] = ppowinv[0] = 1;
	for (int i = 1; i <= N; ++i) {
		ppow[i] = (ppow[i-1] * p) % mod;
		ppowinv[i] = (ppowinv[i-1] * pinv) % mod;
	}
	h[0] = 0;
	for (int i = 1; i <= N; ++i) {
		h[i] = (h[i-1] + ppow[i]*S[i]) % mod;
	}
	ans1 = -1;
	for (int i = 1; i <= N; ++i) {
		if (i <= N/2) {
			if (combine(1, i-1, i+1, (N/2)+1) == subhash((N/2)+2, N)) {
				if (ans1 != -1 && subhash(ans1, ans2) != subhash((N/2)+2, N)) {
					cout << "NOT UNIQUE\n";
					return 0;
				}
				ans1 = (N/2)+2;
				ans2 = N;
			}
		} else if (i == (N/2)+1) {
			if (subhash(1, i-1) == subhash(i+1, N)) {
				if (ans1 != -1 && subhash(ans1, ans2) != subhash(1, i-1)) {
					cout << "NOT UNIQUE\n";
					return 0;
				}
				ans1 = 1;
				ans2 = N/2;
			}
		} else {
			if (subhash(1, N/2) == combine((N/2)+1, i-1, i+1, N)) {
				if (ans1 != -1 && subhash(ans1, ans2) != subhash(1, N/2)) {
					cout << "NOT UNIQUE\n";
					return 0;
				}
				ans1 = 1;
				ans2 = N/2;
			}
		}
	}
	if (ans1 == -1) {
		cout << "NOT POSSIBLE\n";
	} else {
		for (int i = ans1; i <= ans2; ++i) {
			cout << char(S[i] + 'A' - 1);
		}
		cout << "\n";
	}
}
