#include <bits/stdc++.h>
using namespace std;

const int N = 9;

int final_ans;
int n, m;
int grid[N][N];

void solve() {
    int ans = 0;
    for (int c = 0; c < m; ++c) {
        int count[3] = {};
        for (int r = 0; r < n; ++r) {
            count[grid[r][c]]++;
        }
        ans += max(count[0], max(count[1], count[2]));
    }
    final_ans = max(final_ans, ans);
}

void recurse(int r) {
    if (r == n) {
        solve();
    } else {
        for (int increments = 0; increments < 3; ++increments) {
            for (int c = 0; c < m; ++c) {
                grid[r][c] = (grid[r][c] + 1) % 3;
            }
            recurse(r+1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            grid[i][j] %= 3;
        }
    }
    final_ans = 0;
    recurse(0);
    cout << final_ans << endl;
}
