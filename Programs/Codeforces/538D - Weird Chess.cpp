#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> poss(2*n, vector<bool>(2*n, false));
    int offs = n;
    for (int i1 = 0; i1 < n; ++i1) {
        for (int j1 = 0; j1 < n; ++j1) {
            if (grid[i1][j1] != 'o') continue;
            for (int i2 = 0; i2 < n; ++i2) {
                for (int j2 = 0; j2 < n; ++j2) {
                    if (grid[i2][j2] != 'x') continue;
                    poss[i2-i1+offs][j2-j1+offs] = true;
                }
            }
        }
    }
    vector<pii> moves;
    for (int i = -(n-1); i <= n-1; ++i) {
        for (int j = -(n-1); j <= n-1; ++j) {
            if (poss[i+offs][j+offs]) {
                moves.emplace_back(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 'o') continue;
            for (auto& p : moves) {
                int i1 = i + p.first;
                int j1 = j + p.second;
                if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && grid[i1][j1] == '.') {
                    // this move must be removed
                    poss[p.first+offs][p.second+offs] = false;
                }
            }
        }
    }
    moves.clear();
    for (int i = -(n-1); i <= n-1; ++i) {
        for (int j = -(n-1); j <= n-1; ++j) {
            if (poss[i+offs][j+offs]) {
                moves.emplace_back(i, j);
            }
        }
    }
    vector<vector<bool>> attacked(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 'o') continue;
            for (auto& p : moves) {
                int i1 = i + p.first;
                int j1 = j + p.second;
                if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
                    attacked[i1][j1] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'x' && attacked[i][j] == false) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    vector<vector<char>> ans(2*n-1, vector<char>(2*n-1, '.'));
    ans[n-1][n-1] = 'o';
    for (auto& p : moves) {
        ans[n-1+p.first][n-1+p.second] = 'x';
    }
    for (int i = 0; i < 2*n-1; ++i) {
        for (int j = 0; j < 2*n-1; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}
