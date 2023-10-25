template<typename T>
struct Mapper {
	vector<T> uniqueValues;

	Mapper(const vector<T>& values) {
		uniqueValues.assign(values.begin(), values.end());
		sort(uniqueValues.begin(), uniqueValues.end());

		auto endIterator = unique(uniqueValues.begin(), uniqueValues.end());
		uniqueValues.erase(endIterator, uniqueValues.end());
	}

	inline int get(const T& x) {
		auto iterator = lower_bound(uniqueValues.begin(), uniqueValues.end(), x);
		return (int)distance(uniqueValues.begin(), iterator);
	}
};
