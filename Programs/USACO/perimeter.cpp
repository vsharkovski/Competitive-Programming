
// Problem : Problem 2. Icy Perimeter
// Contest : USACO 2019 January Contest, Silver
// URL : http://usaco.org/index.php?page=viewproblem2&cpid=895
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;

int n;
bool grid[N][N];
bool visited[N][N];
int area, peri;
int maxarea, minperi;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void dfs(int i, int j) {
	visited[i][j] = true;
	++area;
	for (int d = 0; d < 4; ++d) {
		int i1 = i + dr[d], j1 = j + dc[d];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n) {
			if (grid[i1][j1]) {
				if (!visited[i1][j1]) {
					dfs(i1, j1);
				}
			} else {
				++peri;
			}
		} else {
			++peri;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifndef _DEBUG
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	#endif
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char ch;
			cin >> ch;
			grid[i][j] = ch == '#' ? 1 : 0;
			visited[i][j] = false;
		}
	}
	maxarea = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (grid[i][j] && !visited[i][j]) {
				area = peri = 0;
				dfs(i, j);
				if (area > maxarea) {
					maxarea = area;
					minperi = peri;
				} else if (area == maxarea && peri < minperi) {
					minperi = peri;
				}
			}
		}
	}
	cout << maxarea << ' ' << minperi << '\n';
}
