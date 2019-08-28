#include <bits/stdc++.h>
using namespace std;

const int maxn = 51;

int n;
int grid[maxn][maxn];
int sum[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

inline int Sum(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
}

int dfs(int r1, int c1, int r2, int c2) {
    int &res = dp[r1][c1][r2][c2];
    if (res != -1) return res;
    if (Sum(r1, c1, r2, c2) == 0) return res = 0;
    if (r1 == r2 && c1 == c2) return res = 1;
    res = max(r2-r1+1, c2-c1+1);
    for (int r = r1; r < r2; ++r) {
        res = min(res, dfs(r1, c1, r, c2) + dfs(r+1, c1, r2, c2));
    }
    for (int c = c1; c < c2; ++c) {
        res = min(res, dfs(r1, c1, r2, c) + dfs(r1, c+1, r2, c2));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char ch;
            cin >> ch;
            grid[i][j] = ch == '#';
            sum[i][j] = grid[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 1, n, n) << endl;
}
