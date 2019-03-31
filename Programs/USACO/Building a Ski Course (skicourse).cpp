#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void print(vector<vi>& v, string s) {
    cout << s << ":\n";
    for (int r = 0; r < v.size(); ++r) {
        for (int c = 0; c < v[0].size(); ++c) {
            cout << v[r][c] << ' ';
        }
        cout << '\n';
    }
}

void Main() {
    int R, C;
    cin >> R >> C;
    vector<vi> grid(R, vi(C));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            char ch;
            cin >> ch;
            grid[r][c] = ch == 'R' ? 1 : 2;
//            grid[r][c] = ch - '0';
        }
    }
    int minB = min(R, C);
    while (true) {
        vector<vector<vi>> dp(3, vector<vi>(R, vi(C)));
        bool has1 = false, has2 = false;
        int fd = 1, fr = 0, fc = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 0) {
                    dp[0][r][c] = dp[1][r][c] = dp[2][r][c] = 1;
                } else if (grid[r][c] == 1) {
                    has1 = true;
                    dp[1][r][c] = 1;
                } else {
                    has2 = true;
                    dp[2][r][c] = 1;
                }
            }
        }
        if (!has1 && !has2) break;
        for (int r = 1; r < R; ++r) {
            for (int c = 1; c < C; ++c) {
                int cnt[3] = {};
                ++cnt[grid[r][c]];
                ++cnt[grid[r-1][c]];
                ++cnt[grid[r][c-1]];
                ++cnt[grid[r-1][c-1]];
                if (cnt[1] == 0 && cnt[2] == 0) {
                    dp[0][r][c] = max(2, 1 + min({dp[0][r-1][c], dp[0][r][c-1], dp[0][r-1][c-1]}));
                }
                if (cnt[1] == 0) {
                    dp[2][r][c] = max(2, 1 + min({max(dp[0][r-1][c], dp[2][r-1][c]),
                                                  max(dp[0][r][c-1], dp[2][r][c-1]),
                                                  max(dp[0][r-1][c-1], dp[2][r-1][c-1])}));
                }
                if (cnt[2] == 0) {
                    dp[1][r][c] = max(2, 1 + min({max(dp[0][r-1][c], dp[1][r-1][c]),
                                                  max(dp[0][r][c-1], dp[1][r][c-1]),
                                                  max(dp[0][r-1][c-1], dp[1][r-1][c-1])}));
                }
                if (dp[1][r][c] > dp[fd][fr][fc] && dp[0][r][c] < dp[1][r][c]) {
                    fd = 1, fr = r, fc = c;
                }
                if (dp[2][r][c] > dp[fd][fr][fc] && dp[0][r][c] < dp[2][r][c]) {
                    fd = 2, fr = r, fc = c;
                }
            }
        }
//        print(grid, "grid");
//        print(dp[0], "dp0");
//        print(dp[1], "dp1");
//        print(dp[2], "dp2");
//        cout << "best size = " << dp[fd][fr][fc] << "\n";
//        cout << '\n';
        for (int r = fr - dp[fd][fr][fc] + 1; r <= fr; ++r) {
            for (int c = fc - dp[fd][fr][fc] + 1; c <= fc; ++c) {
                grid[r][c] = 0;
            }
        }
        minB = min(minB, dp[fd][fr][fc]);
    }
    cout << minB << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    #ifndef _DEBUG
    freopen("skicourse.in", "r", stdin);
    freopen("skicourse.out", "w", stdout);
    #endif
    Main();
}
