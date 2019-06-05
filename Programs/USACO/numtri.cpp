#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
LANG: C++
TASK: numtri
*/

const int maxn = 1005;

int n;
int val[maxn][maxn];
int dp[maxn][maxn];

int main() {
    #ifndef _DEBUG
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> val[i][j];
            dp[i][j] = -1;
        }
    }

    dp[0][0] = val[0][0];

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] != -1) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + val[i+1][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + val[i+1][j+1]);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < n; ++j) {
        ans = max(ans, dp[n-1][j]);
    }

    cout << ans << '\n';

}
