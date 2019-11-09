#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    const int N = 20;
    const int ALL = (1 << N) - 1;
    static int dp[1<<N] = {};
    for (int i = 0; i < n; ++i) {
        int m = 0;
        for (int j = i; j < i+20 && j < n; ++j) {
            int x = s[j] - 'a';
            if (m & (1 << x)) {
                break;
            }
            m |= (1 << x);
            dp[m] = max(dp[m], j-i+1);
        }
    }
    for (int m = 0; m < (1 << N); ++m) {
        for (int i = 0; i < N; ++i) {
            if (m & (1 << i)) {
                dp[m] = max(dp[m], dp[m ^ (1<<i)]);
            }
        }
    }
    int ans = 0;
    for (int m = 0; m < (1 << N); ++m) {
        ans = max(ans, dp[m]);
        ans = max(ans, dp[m] + dp[ALL ^ m]);
    }
    cout << ans << endl;
}
