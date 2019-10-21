#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int h, n;
int p[maxn];
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		cin >> h >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
		}
		p[++n] = 0;
		int ans = 0;
		for (int i = 1; i < n; ) {
			if (p[i] > p[i+1] + 1) {
				p[i] = p[i+1] + 1;
			}
			if (i+1 == n) {
				i = i+1;
				continue;
			}
			if (p[i] == p[i+2] + 2) {
				i = i+2;
				continue;
			}
			++ans;
			p[i+1] = p[i+2] + 1;
			i = i+1;
		}
		cout << ans << endl;
	}
}
