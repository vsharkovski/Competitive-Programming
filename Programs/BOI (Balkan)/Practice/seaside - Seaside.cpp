#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	vector<int> stk;
	char ch;
	while (cin >> ch) {
		if (ch == 'a') {
			int h;
			cin >> h;
			while (!stk.empty() && stk.back() <= h) {
				stk.pop_back();
			}
			stk.push_back(h);
		} else if (ch == 'q') {
			cout << stk.size() << endl;
		} else {
			break;
		}
	}
}
