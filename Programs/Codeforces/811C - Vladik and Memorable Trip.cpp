#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 5001;

int n;
int a[maxn];
int lm[maxn];
int rm[maxn];
int dp[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    memset(lm, -1, sizeof(lm));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (lm[a[i]] == -1) lm[a[i]] = i;
        rm[a[i]] = i;
    }
    int ans = 0;
    dp[n] = 0;
    for (int i = n-1; i >= 0; --i) {
        dp[i] = dp[i+1];
        int comfort = 0;
        for (int j = i; j < n; ++j) {
            if (lm[a[j]] < i) {
                break;
            }
            comfort ^= a[j];
            int target = rm[a[j]];
            if (j < target) {
                ++j;
            }
            while (j < target) {
                if (lm[a[j]] < i) {
                    j = n;
                    break;
                } else if (lm[a[j]] == j) {
                    comfort ^= a[j];
                }
                target = max(target, rm[a[j]]);
                ++j;
            }
            if (j == n) {
                break;
            }
            dp[i] = max(dp[i], comfort + dp[j+1]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
