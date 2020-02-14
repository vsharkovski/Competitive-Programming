
// Problem : Problem 2. Convention II
// Contest : USACO 2018 December Contest, Silver
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=859
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Event {
	int t, i, type; // type: 0 (arrival), 1 (finished eating)
	Event(int t, int i, int type) : t(t), i(i), type(type) {}
	string S() {
		return "(t="+to_string(t)+",i="+to_string(i)+",type="+to_string(type)+")";
	}
};

struct CompareEvents {
	bool operator () (const Event& a, const Event& b) const {
		if (a.t != b.t) return a.t < b.t;
		if (a.type != b.type) return a.type > b.type;
		if (a.i != b.i) return a.i < b.i;
		return false;
	}
};

struct CompareCows {
	bool operator () (const Event& a, const Event& b) const {
		return a.i < b.i;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<int> eattime(n);
	set<Event, CompareEvents> events;
	for (int i = 0; i < n; ++i) {
		int arrival;
		cin >> arrival >> eattime[i];
		events.emplace(arrival, i, 0);
	}
	set<Event, CompareCows> cows;
	int ans = 0;
	bool caneat = true;
	while (!events.empty()) {
		Event ev = *events.begin();
		events.erase(events.begin());
		//cout << ev.S() << endl;
		if (ev.type == 0) {
			// cow arrived
			cows.insert(ev);
		} else {
			// finished eating
			caneat = true;
		}
		if (caneat && !cows.empty()) {
			Event c = *cows.begin();
			cows.erase(cows.begin());
			events.emplace(ev.t + eattime[c.i], c.i, 1);
			caneat = false;
			ans = max(ans, ev.t - c.t);
			//cout << "starting to eat, wait="<<ev.t-c.t<<" "<< c.S() << "\n";
		}
	}
	cout << ans << '\n';
}
