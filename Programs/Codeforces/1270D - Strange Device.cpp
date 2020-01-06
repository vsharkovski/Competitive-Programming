
// Problem : D. Strange Device
// Contest : Good Bye 2019
// URL : https://codeforces.com/contest/1270/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


pii ask(set<int>& s) {
	cout << '?';
	for (int x : s) cout << ' ' << x;
	cout << endl;
	int p, a;
	cin >> p >> a;
	return pii(p, a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	set<int> s;
	for (int i = 1; i <= k+1; ++i) {
		s.insert(i);
	}
	map<int, int> mp;
	for (int i = 1; i <= k+1; ++i) {
		s.erase(i);
		pii res = ask(s);
		mp[res.second] += 1;
		s.insert(i);
	}
	cout << "! " << mp.rbegin()->second << endl;
}
