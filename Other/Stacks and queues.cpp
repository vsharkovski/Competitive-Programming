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
