#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 101;
const int maxk = 27;
const int m = 3;

int n, k;
char grid[m][maxn];

int id[256];
int row[maxk];
int initcol[maxk];
int len[maxk];

int dp[m][maxn];

int dfs(int i, int j) {
    int& res = dp[i][j];
    if (res != -1) return res;
    if (j == n) return res = 1;
    res = 0;
    bool hit = false, good;
    for (int t = 0; t < k; ++t) {
        if (row[t] != i) continue;
        int l = initcol[t] - 2*j;
        int r = l + len[t] - 1;
        if (l <= j+1 && j+1 <= r) {
            hit = true;
            break;
        }
    }
    if (hit) return res;
    for (int i1 : {i-1, i, i+1}) {
        if (i1 < 0 || i1 >= m) continue;
        good = true;
        for (int t = 0; t < k; ++t) {
            if (row[t] != i1) continue;
            int l = initcol[t] - 2*j;
            int r = l + len[t] - 1;
            hit = false;
            for (int step = 0; step < 3; ++step) {
                if (l <= j+1 && j+1 <= r) {
                    hit = true;
                    break;
                }
                --l;
                --r;
            }
            if (hit) {
                good = false;
                break;
            }
        }
        if (!good) continue;
        res |= dfs(i1, j+1);
        if (res) break;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        k = 0;
        int startrow = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch;
                cin >> ch;
                grid[i][j] = ch;
                if (ch == 's') {
                    startrow = i;
                    grid[i][j] = '.';
                } else if (ch != '.') {
                    if (j == 0 || grid[i][j-1] != ch) {
                        id[ch] = k;
                        row[k] = i;
                        initcol[k] = j;
                        len[k] = 1;
                        ++k;
                    } else {
                        ++len[id[grid[i][j-1]]];
                    }
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        int ans = dfs(startrow, 0);
        if (ans == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
