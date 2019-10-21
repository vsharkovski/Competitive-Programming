#include <bits/stdc++.h>
using namespace std;
 
const int D = 3;
 
struct point {
	int i;
	int c[D];
	bool operator < (const point& o) const {
		for (int i = D-1; i >= 0; --i) {
			if (c[i] != o.c[i]) {
				return c[i] < o.c[i];
			}
		}
		return false;
	}
};
 
void solve(vector<point> &points, int d) {
	sort(points.begin(), points.end());
	if (d > 0) {
		vector<point> points_new;
		int n = points.size();
		for (int i = 0; i < n; ++i) {
			int j = i;
			while (j < n && points[i].c[d] == points[j].c[d]) {
				++j;
			}
			// points i to j-1 have same d-th coordinate
			if (i+1 == j) {
				// only 1
				points_new.push_back(points[i]);
			} else {
				// more than 1 in group
				vector<point> points2;
				for (int k = i; k < j; ++k) {
					points2.push_back(points[k]);
					points2.back().c[d] = 0; // not considering this coordinate anymore
				}
				solve(points2, d-1);
				if (!points2.empty()) {
					points_new.push_back(points2.back());
				}
			}
			i = j-1;
		}
		// points in points_new all have different d-th coordinate
		points_new.swap(points);
	}
	while (points.size() >= 2) {
		cout << points.back().i << ' ';
		points.pop_back();
		cout << points.back().i << '\n';
		points.pop_back();
	}
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<point> points(n);
	for (int i = 0; i < n; ++i) {
		points[i].i = i+1;
		for (int j = 0; j < D; ++j) {
			cin >> points[i].c[j];
		}
	}
	solve(points, D-1);
}
