#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	set<int> inside;
	deque<int> chats;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		bool active = inside.count(x);
		if (active) {
		
		} else if (chats.size() < k) {
			inside.insert(x);
			chats.push_back(x);
		} else {
			inside.erase(chats.front());
			chats.pop_front();
			inside.insert(x);
			chats.push_back(x);
		}
	}
	cout << chats.size() << endl;
	while (!chats.empty()) {
		cout << chats.back() << ' ';
		chats.pop_back();
	}
	cout << endl;
}
