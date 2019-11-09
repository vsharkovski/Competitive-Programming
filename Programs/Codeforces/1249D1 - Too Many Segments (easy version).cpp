#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 200010;

int n, k, minL, maxR;
int L[maxn], R[maxn];
set<pii> active;
set<int> seg1[maxn], seg2[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	minL = maxn;
	maxR = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> L[i] >> R[i];
		seg1[L[i]].insert(i);
		seg2[R[i]].insert(i);
		minL = min(minL, L[i]);
		maxR = max(maxR, R[i]);
	}
	vector<int> removed;
	for (int x = minL; x <= maxR; ++x) {
		for (int i : seg1[x]) {
			active.emplace(R[i], i);
		}
		while (active.size() > k) {
			pii bk = *prev(active.end());
			active.erase(prev(active.end()));
			removed.push_back(bk.second);
		}
		for (int i : seg2[x]) {
			active.erase(pii(R[i], i));
		}
	}
	cout << removed.size() << endl;
	for (int i : removed) {
		cout << i << ' ';
	}
	cout << endl;
}
