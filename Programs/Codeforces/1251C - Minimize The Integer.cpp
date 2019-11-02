#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	while (Q--) {
		string s;
		cin >> s;
		int n = s.length();
		vector<int> v(n);
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			v[i] = s[i] - '0';
			int a = v[i];
			if (a % 2 == 1) {
				q.push(a);
			}
		}
		for (int i = 0; i < n; ++i) {
			int a = v[i];
			if (a % 2 == 0) {
				while (!q.empty() && q.front() < a) {
					cout << q.front();
					q.pop();
				}
				cout << a;
			}
		}
		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
		cout << endl;
	}
}
