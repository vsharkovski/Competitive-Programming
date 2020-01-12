struct MinimumQueue {
	deque<int> q;
	inline void push(int x) {
		while (!q.empty() && q.back() > x) {
			q.pop_back();
		}
		q.push_back(x);
	}
	inline void erase(int x) {
		if (!q.empty() && q.front() == x) {
			q.pop_front();
		}
	}
	inline int min() {
		return q.front();
	}
};

struct MedianFinder {
	priority_queue<int, vector<int>, less<int>> lo;
	priority_queue<int, vector<int>, greater<int>> hi;
	void push(int x) {
		lo.push(x);
		hi.push(lo.top());
		lo.pop();
		if (lo.size() < hi.size()) {
			lo.push(hi.top());
			hi.pop();
		}
	}
	inline int findmed() {
		return lo.top();
	}
	double findRealMedian() {
		return lo.size() > hi.size() ? (double)lo.top() : 0.5*(lo.top()+hi.top());
	}
};
