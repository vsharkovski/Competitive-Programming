nclude <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<pii> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		cout << a[i].second+1 << ' ';
	}
}
