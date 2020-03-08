#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, C;
    cin >> R >> C;
    int grid[110][110] = {};
    for (int r = 0; r < 110; ++r) {
        for (int c = 0; c < 110; ++c) {
            grid[r][c] = 1e9;
        }
    }
    for (int r = 1; r <= R; ++r) {
        for (int c= 1 ; c <= C; ++c) {
            cin >> grid[r][c];
        }
    }
    vector<int> res;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            int mn = min(grid[r-1][c], min(grid[r+1][c], min(grid[r][c-1], grid[r][c+1])));
            if (grid[r][c] < mn) {
                res.push_back(mn - grid[r][c]);
            }
        }
    }
    sort(res.begin(), res.end());
    //res.erase(unique(res.begin(), res.end()), res.end());
    reverse(res.begin(), res.end());
    for (int x : res) {
        cout << x << ' ';
    }
    if (res.empty()) {
        cout << -1;
    }
}
