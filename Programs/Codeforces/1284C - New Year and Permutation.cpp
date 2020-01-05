// Problem : C. New Year and Permutation
// Contest : Hello 2020
// URL : https://codeforces.com/contest/1284/problem/C
// Memory Limit : 1024.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll mod;
	cin >> n >> mod;
	vector<ll> fact(n+1);
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (fact[i-1] * i) % mod;
	}
	ll ans = 0;
	for (int x = 0; x <= n-1; ++x) {
		ll res = 1;
		res = (res * (n-x)) % mod;
		res = (res * fact[n-x]) % mod;
		res = (res * fact[x+1]) % mod;
		ans = (ans + res) % mod;
	}
	cout << ans << endl;
}
