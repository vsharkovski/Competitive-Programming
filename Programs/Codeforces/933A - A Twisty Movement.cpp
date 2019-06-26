#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    const int maxn = 2010;

    int n;
    cin >> n;

    int a[maxn];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        --a[i];
    }

    int cnt[2][maxn];
    static int dp[2][maxn][maxn];

    cnt[0][0] = cnt[1][0] = 0;
    for (int j = 0; j < 2; ++j) {
        for (int i = 1; i <= n; ++i) {
            cnt[j][i] = cnt[j][i-1] + (a[i] == j);
        }
    }

    for (int l = 1; l <= n; ++l) {
        dp[a[l]][l][l] = 1;
        dp[1-a[l]][l][l] = 0;
        for (int r = l+1; r <= n; ++r) {
            dp[1][l][r] = dp[1][l][r-1] + (a[r] == 1);
            dp[0][l][r] = max(dp[0][l][r-1], dp[1][l][r-1]) + (a[r] == 0);
        }
    }

    int ans = 0;
    ans = max(ans, dp[0][1][n]);
    ans = max(ans, dp[1][1][n]);

    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            int res = cnt[0][l-1] + dp[0][l][r] + (cnt[1][n] - cnt[1][r]);
            if (res > ans) {
                ans = res;
            }
        }
    }

    cout << ans << '\n';

}
