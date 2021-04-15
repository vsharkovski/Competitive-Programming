#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


template<class T>
void addnum(T &s, ll &sum, ll x) {
	s.insert(x);
	sum += x;
}

template<class T1, class T2>
void movetop(T1 &s1, ll &sum1, T2 &s2, ll &sum2) {
	auto ptr = s1.begin();
	sum1 -= *ptr;
	sum2 += *ptr;
	s2.insert(*ptr);
	s1.erase(ptr);
}

template<class T>
bool delnum(T &s, ll &sum, ll x) {
	auto ptr = s.find(x);
	if (ptr == s.end()) return false;
	sum -= x;
	s.erase(ptr);
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<ll> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	ll sumL = 0;
	ll sumR = 0;
	multiset<ll, greater<ll>> L;
	multiset<ll, less<ll>> R;
	for (int i = 0; i < n; ++i) {
		if (i >= k) {
			// remove x[i-k]
			if (delnum(L, sumL, x[i-k])) {
				if (L.size() < R.size()) {
					movetop(R, sumR, L, sumL);
				}
			} else if (delnum(R, sumR, x[i-k])) {
				if (L.size() == R.size()+2) {
					movetop(L, sumL, R, sumR);
				}
			}
		}
		// add x[i]
		addnum(L, sumL, x[i]);
		movetop(L, sumL, R, sumR);
		if (L.size() < R.size()) {
			movetop(R, sumR, L, sumL);
		}
		if (i >= k-1) {
			// print answer
			ll numL = L.size();
			ll numR = R.size();
			ll med = (k % 2 == 1) ? *L.begin() : (*L.begin() + *R.begin()) / 2;
			ll ans = 0;
			ans += med*numL - sumL;
			ans += sumR - med*numR;
//			cout << "i="<<i<<" sumL="<<sumL << " sumR="<<sumR<<"\n";
//			cout<<"L={";for(ll x:L)cout<<x<<" ";cout<<"}\n";
//			cout<<"R={";for(ll x:R)cout<<x<<" ";cout<<"}\n";
//			cout<<"med="<<med<<"\n";
			cout << ans << ' ';
		}
	}
}
