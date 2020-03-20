// Japanese Olympiad in Informatics Spring Camp Online Contest
// Day 1, Problem 1

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 500500;

int n;
int a[2][2*N];
bool reach_left[2][2*N];
bool reach_right[2][2*N];
int mn[2][2*N][2];
int mx[2][2*N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= 2*n; ++i) {
			cin >> a[j][i];
			reach_left[j][i] = false;
			reach_right[j][i] = false;
		}
	}
	reach_left[0][1] = true;
	reach_left[1][1] = true;
	for (int i = 1; i < 2*n; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (!reach_left[j][i]) continue;
			for (int k = 0; k < 2; ++k) {
				if (a[j][i] <= a[k][i+1]) {
					reach_left[k][i+1] = true;
				}
			}
		}
	}
	reach_right[0][2*n] = true;
	reach_right[1][2*n] = true;
	for (int i = 2*n-1; i >= 1; --i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (!reach_right[k][i+1]) continue;
				if (a[j][i] <= a[k][i+1]) {
					reach_right[j][i] = true;
				}
			}
		}
	}
	for (int j = 0; j < 2; ++j) {
		if (!reach_left[j][2*n] || !reach_right[j][2*n]) {
			for (int c = 0; c < 2; ++c) {
				mn[j][2*n][c] = 2*N;
				mx[j][2*n][c] = -1;
			}
		} else {
			for (int c = 0; c < 2; ++c) {
				mn[j][2*n][c] = (j == c);
				mx[j][2*n][c] = (j == c);
			}
		}
	}
	for (int i = 2*n-1; i >= 1; --i) {
		int cnt_bad = 0;
		for (int j = 0; j < 2; ++j) {
			for (int c = 0; c < 2; ++c) {
				mn[j][i][c] = 2*N;
				mx[j][i][c] = -1;
			}
			if (!reach_left[j][i] || !reach_right[j][i]) continue;
			for (int k = 0; k < 2; ++k) {
				if (!reach_left[k][i+1] || !reach_right[k][i+1]) continue;
				if (a[j][i] > a[k][i+1]) continue;
				for (int c = 0; c < 2; ++c) {
					mn[j][i][c] = min(mn[j][i][c], (j == c) + mn[k][i+1][c]);
					mx[j][i][c] = max(mx[j][i][c], (j == c) + mx[k][i+1][c]);
				}
			}
			if (mn[j][i][0] == 2*N) {
				++cnt_bad;
			}
		}
		if (cnt_bad == 2) {
			cout << -1 << '\n';
			return 0;
		}
	}
	/*
	cout << "reach_left:\n";
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= 2*n; ++i) {
			cout << reach_left[j][i] << ' ';
		}
		cout << "\n";
	}
	cout << "reach_right:\n";
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= 2*n; ++i) {
			cout << reach_right[j][i] << ' ';
		}
		cout << "\n";
	}
	cout << "counts:\n";
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= 2*n; ++i) {
			if (mn[j][i][0]==2*N)cout<<"(x-x,x-x) ";
			else {
				cout<<"("<<mn[j][i][0]<<"-"<<mx[j][i][0]<<",";
				cout<<mn[j][i][1]<<"-"<<mx[j][i][1]<<") ";
			}
		}
		cout << "\n";
	}
	*/
	int rem[2] = {n, n};
	int prev_j = -1;
	for (int i = 1; i <= 2*n; ++i) {
		bool found = false;
		for (int j = 0; j < 2; ++j) {
			if (!reach_left[j][i] || !reach_right[j][i]) continue;
			if (i > 1 && a[prev_j][i-1] > a[j][i]) continue;
			// if arriving at (j, i)
			bool good = true;
			for (int c = 0; c < 2; ++c) {
				if (mn[j][i][c] <= rem[c] && rem[c] <= mx[j][i][c]) {
					
				} else {
					good = false;
					break;
				}
			}
			if (good) {
				// can arrive at (j, i);
				--rem[j];
				//cout << "\ni="<<i<<" rem={"<<rem[0]<<","<<rem[1]<<"}\n";
				cout << (j == 0 ? 'A' : 'B');
				prev_j = j;
				found = true;
				break;
			}
		}
		if (!found) {
			//cout << "\ni="<<i<<" didnt find\n";
			if (i == 1) {
				cout << -1 << '\n';
				return 0;
			} else {
				while (true) {}
			}
		}
	}
	//cout << "\n{"<<rem[0]<<","<<rem[1]<<"}\n";
}
