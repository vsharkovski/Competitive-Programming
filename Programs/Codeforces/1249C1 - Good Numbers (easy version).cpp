#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		ll n0 = n;
		// cout << "n=" << n << endl;
		vector<int> base3;
		bool has2 = false;
		while (n > 0) {
			base3.push_back(n % 3);
			n /= 3;
			if (base3.back() == 2) {
				has2 = true;
			}
		}
		if (has2 == false) {
			cout << n0 << endl;
			continue;
		}
		base3.push_back(0);
		int last0pos = 0;
		for (int i = base3.size()-1; i >= 0; --i) {
			if (base3[i] == 0) {
				last0pos = i;
			} else if (base3[i] == 2) {
				base3[last0pos] = 1;
				for (int j = last0pos-1; j >= 0; --j) {
					base3[j] = 0;
				}
				break;
			}
		}
		ll m = 0, pw = 1;
		for (int i = 0; i < (int)base3.size(); ++i) {
			m += pw * base3[i];
			pw *= 3;
		}
		cout << m << endl;
	}
}
