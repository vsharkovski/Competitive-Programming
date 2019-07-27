#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
 
bool isvalid(int x, int sum) {
	if (x <= 0) return false;
	int realsum = 0;
	while (x > 0) {
		realsum += x % 10;
		x /= 10;
	}
	return realsum == sum;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans;
	for (int sum = 1; sum <= 100; ++sum) {
		int x = n - sum;
		if (isvalid(x, sum)) {
			ans.push_back(x);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int x : ans) {
		cout << x << ' ';
	}
}
