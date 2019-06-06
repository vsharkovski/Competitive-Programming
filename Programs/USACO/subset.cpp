#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
LANG: C++
TASK: subset
*/

const int maxn = 40;
const int maxsum = 800;

int main() {
    #ifndef _DEBUG
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    ll ans = 0;
    static ll dp1[maxsum][maxsum];
    static ll dp2[maxsum][maxsum];

    cin >> n;

    memset(dp1, 0, sizeof(dp1));
    dp1[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        memset(dp2, 0, sizeof(dp2));
        for (int s1 = 0; s1 < maxsum-i; ++s1) {
            for (int s2 = 0; s2 < maxsum-i; ++s2) {
                dp2[s1+i][s2] += dp1[s1][s2];
                dp2[s1][s2+i] += dp1[s1][s2];
            }
        }
        swap(dp1, dp2);
    }

    for (int s = 1; s < maxsum; ++s) {
        ans += dp1[s][s];
    }
    ans /= 2;

    cout << ans << '\n';

}
