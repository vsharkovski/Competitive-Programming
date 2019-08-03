#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1000010;
const int maxb = 22;

int n;
int a[maxn];
int dp[1<<maxb];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[a[i]] = a[i];
    }
    for (int i = 0; i < maxb; ++i) {
        for (int m = 0; m < (1<<maxb); ++m) {
            if ((m & (1<<i)) && dp[m] == -1) {
                dp[m] = dp[m ^ (1<<i)];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dp[~a[i] & ((1<<maxb)-1)] << ' ';
    }
}
