#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	bool hasSorted = false;
	int lastDecrease = 0;

	for (int i = 1; i < n; i++) {
		if (p[i-1] > p[i]) {
			lastDecrease = i;
		}
		if (i - lastDecrease == k - 1) {
			hasSorted = true;
			break;
		}
	}

	if (!hasSorted) {
		int head = n - k;
		while (head > 0 && p[head - 1] < p[head]) {
			head--;
		}

		sort(p.begin() + head, p.begin() + head + k);
	}

	for (int i = 0; i < n; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
}
