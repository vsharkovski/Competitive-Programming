#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	int ansmin = 0;
	int prevpos = -1;
	for (int i : x) {
		if (prevpos != i-1 && prevpos != i && prevpos != i+1) {
			prevpos = i+1;
			++ansmin;
		}
	}
	set<int> done;
	for (int i : x) {
		for (int j = -1; j <= 1; ++j) {
			int i1 = i + j;
			if (!done.count(i1)) {
				done.insert(i1);
				break;
			}
		}
	}
	int ansmax = done.size();
	cout << ansmin << ' ' << ansmax << endl;
}
