#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100010;
const int maxb = 20;

int n;
int a[maxn];
ll dp[1<<maxb];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++dp[a[i]];
        }
        for (int i = 0; i < maxb; ++i) {
            for (int m = 0; m < (1<<maxb); ++m) {
                if (m & (1 << i)) {
                    dp[m] += dp[m ^ (1<<i)];
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dp[((1<<maxb)-1) & ~a[i]];
        }
        cout << ans << endl;
    }
}
