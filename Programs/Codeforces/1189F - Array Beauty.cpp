#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
 
const int mod = 998244353;
const int maxval = 1e5;
const int maxn = 1001;
const int maxk = 1001;
 
inline int add(int x, int y) {
    int res = x + y;
    if (res >= mod) res -= mod;
    return res;
}
 
inline int subt(int x, int y) {
    int res = x - y;
    if (res < 0) res += mod;
    return res;
}
 
inline int mult(int x, int y) {
    return (1LL * x * y) % mod;
}
 
int N, K, ans;
int a[maxn];
int dp[maxn][maxk];
 
int solve(int D) {
    int i = 0;
    for (int n = 0; n < N; ++n) {
        while (i+1 < n && a[i+1]+D <= a[n]) {
            ++i;
        }
        dp[n][0] = 0;
        for (int k = 1; k <= K; ++k) {
            dp[n][k] = 0;
            if (k == 1) {
                dp[n][k] = add(dp[n][k], 1);
            }
            if (n > 0) {
                dp[n][k] = add(dp[n][k], dp[n-1][k]);
            }
            if (i < n && a[i]+D <= a[n]) {
                dp[n][k] = add(dp[n][k], dp[i][k-1]);
            }
        }
    }
    return dp[N-1][K];
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;
    int maxa = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    sort(a, a+N);
    ans = 0;
    // beauty can't exceed max/(K-1)
    for (int d = 1; d <= maxa/(K-1); ++d) {
        ans = add(ans, solve(d));
    }
    cout << ans << '\n';
}
