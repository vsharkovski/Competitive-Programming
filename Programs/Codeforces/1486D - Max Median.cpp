#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200100;

int n, k;
int a[N];
int p[N];

bool possible(int x) {
	p[0] = 0;
	int minp = 1e9;
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i-1] + (a[i] >= x ? 1 : -1);
		if (i-k >= 0) {
			minp = min(minp, p[i-k]);
			if (p[i] - minp >= 1) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	vector<int> b(n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i-1] = a[i];
	}
	sort(b.begin(), b.end());
	int low = 0, high = b.size()-1, mid, ans = low;
	while (low <= high) {
		mid = (low + high) / 2;
		if (possible(b[mid])) {
			ans = mid;
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
	cout << b[ans] << '\n';
}
