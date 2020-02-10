// Problem : C. Square Subsets
// Contest : Codeforces Round #448 (Div. 2)
// URL : https://codeforces.com/contest/895/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

void add(int& x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int mult(int x, int y) {
	return (ll)x * y % mod;
}

int powmod(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = mult(res, x);
		x = mult(x, x);
		y /= 2;
	}
	return res;
}

const int N = 1e5 + 10;
const int M = 19;

int fact[N];
int invfact[N];

vector<int> primes;
int msk[71];
int cnt[71];
int evenways[71];
int oddways[71];
int cur[1<<M], nxt[1<<M];

inline int CHS(int a, int b) {
	return mult(mult(fact[a], invfact[b]), invfact[a-b]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int x = 2; x <= 70; ++x) {
		bool prime = true;
		for (int y = 2; y*y <= x; ++y) {
			if (x % y == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			primes.push_back(x);
		}
	}
	for (int x = 1; x <= 70; ++x) {
		msk[x] = 0;
		int y = x;
		for (int i = 0; i < M; ++i) {
			int p = primes[i];
			while (y % p == 0) {
				msk[x] ^= (1 << i);
				y /= p;
			}
		}
	}
	memset(cnt, 0, sizeof(cnt));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
	}
	fact[0] = invfact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mult(fact[i-1], i);
		invfact[i] = powmod(fact[i], mod-2);
	}
	for (int a = 1; a <= 70; ++a) {
		if (cnt[a] == 0) {
			evenways[a] = 1;
			oddways[a] = 0;
			continue;
		}
		evenways[a] = 0;
		for (int c = 0; c <= cnt[a]; c += 2) {
			add(evenways[a], CHS(cnt[a], c));
		}
		oddways[a] = 0;
		for (int c = 1; c <= cnt[a]; c += 2) {
			add(oddways[a], CHS(cnt[a], c));
		}
		//cout << "a=" << a << " cnt=" << cnt[a] << " ev="<<evenways[a] << " od="<<oddways[a] << endl;
	}
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = 1;
	for (int a = 1; a <= 70; ++a) {
		for (int m = 0; m < (1 << M); ++m) {
			cur[m] = nxt[m];
			nxt[m] = 0;
		}
		for (int m = 0; m < (1 << M); ++m) {
			add(nxt[m], mult(cur[m], evenways[a]));
			add(nxt[m^msk[a]], mult(cur[m], oddways[a]));
		}
	}
	int ans = nxt[0];
	ans = (ans - 1 + mod) % mod;
	cout << ans << endl;
}
